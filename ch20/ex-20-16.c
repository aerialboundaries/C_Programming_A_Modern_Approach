// 2026-06-10

/*
Starting with the 386 processor, x86 CPUs have 32-bit registers named EAX, EBX,
ECX, and EDX. The second half (the least significant bits) of these registers is
the same as AX, BX, CX, and DX, respectively. Modify the regs union so that it
includes these registers as well as the older ones. Your union should be set up
so that modifying EAX changes AX and modifying AX changes the second half of
EAX. (The other new registers will work in a sim- ilar fashion.) You'll need to
add some "dummy" members to the word and byte structures, corresponding to the
other half of EAX, EBX, ECX, and EDX. Declare the type of the new registers to
be DWORD (double word), which should be defined as unsigned long. Don't forget
that the x86 architecture is little-endian.

*/
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;

union {
  struct {
    DWORD eax, ebx, ecx, edx;
  } dword;

  struct {
    struct {
      WORD ax;
      WORD dummy;
    } eax_w;
    struct {
      WORD bx;
      WORD dummy;
    } ebx_w;
    struct {
      WORD cx;
      WORD dummy;
    } ecx_w;
    struct {
      WORD dx;
      WORD dummy;
    } edx_w;
  } word;

  struct {
    struct {
      BYTE al;
      BYTE ah;
      WORD dummy;
    } eax_b;
    struct {
      BYTE bl;
      BYTE bh;
      WORD dummy;
    } ebx_b;
    struct {
      BYTE cl;
      BYTE ch;
      WORD dummy;
    } ecx_b;
    struct {
      BYTE dl;
      BYTE dh;
      WORD dummy;
    } edx_b;
  } byte;

} regs;

/*
正しい共用体の設計（解説）
x86のリトルエンディアン環境において、EAX（32ビット）はメモリ上で以下のように配置されます。

[低アドレス] AL (8bit) → AH (8bit) [ここまでがAX] → ダミー領域 (16bit)
[高アドレス]

つまり、各レジスタごとに「下位16ビット（AXなど）」と「上位16ビット（ダミー）」がセットになった構造体を作ってあげる必要があります。

これを綺麗に解決するために、word構造体やbyte構造体の中を、それぞれのレジスタごとに独立した構造体としてネストさせるのが最もスマートで実務的な方法です。

そのまま動かせる完全なコード全文
問題の要求通りに動作し、実際に EAX を書き換えると AX や AL、AH
が連動して変わることを確認できる検証コードです。

C
#include <stdio.h>

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD; // 問題文の指示通り、32ビット整数として定義

union {
    // 1. 32ビットレジスタとしてのアクセス
    struct {
        DWORD eax, ebx, ecx, edx;
    } dword;

    // 2. 16ビットレジスタとしてのアクセス
    //
各レジスタごとに、下位16ビット(WORD)と上位16ビット(ダミーWORD)をペアにします
    struct {
        struct { WORD ax; WORD dummy; } eax_w;
        struct { WORD bx; WORD dummy; } ebx_w;
        struct { WORD cx; WORD dummy; } ecx_w;
        struct { WORD dx; WORD dummy; } edx_w;
    } word;

    // 3. 8ビットレジスタとしてのアクセス
    // リトルエンディアンなので、低い方から AL -> AH ->
残り16ビット(ダミーWORD)の順に並べます struct { struct { BYTE al; BYTE ah; WORD
dummy; } eax_b; struct { BYTE bl; BYTE bh; WORD dummy; } ebx_b; struct { BYTE
cl; BYTE ch; WORD dummy; } ecx_b; struct { BYTE dl; BYTE dh; WORD dummy; }
edx_b; } byte;

} regs;

// 教科書の記述スタイル（regs.word.ax
のようにアクセスするため）に合わせるためのマクロ定義
// これがあると、まるで1つのフラットな構造体のようにアクセスできて便利です
#define ax regs.word.eax_w.ax
#define bx regs.word.ebx_w.bx
#define cx regs.word.ecx_w.cx
#define dx regs.word.edx_w.dx

#define al regs.byte.eax_b.al
#define ah regs.byte.eax_b.ah
#define bl regs.byte.ebx_b.bl
#define bh regs.byte.ebx_b.bh
#define cl regs.byte.ecx_b.cl
#define ch regs.byte.ecx_b.ch
#define dl regs.byte.edx_b.dl
#define dh regs.byte.edx_b.dh

int main(void)
{
    // テスト1: EAXに32ビットの値を代入してみる
    regs.dword.eax = 0x12345678;

    printf("--- Test 1: Modify EAX to 0x12345678 ---\n");
    printf("EAX : 0x%08X\n", regs.dword.eax);
    printf("AX  : 0x%04X (Expected: 0x5678)\n", ax);
    printf("AH  : 0x%02X   (Expected: 0x56)\n", ah);
    printf("AL  : 0x%02X   (Expected: 0x78)\n\n", al);

    // テスト2: AXを変更して、EAXの下位半分が変わるかテスト
    ax = 0xAAAA;
    printf("--- Test 2: Modify AX to 0xAAAA ---\n");
    printf("EAX : 0x%08X (Expected: 0x1234AAAA)\n", regs.dword.eax);
    printf("AX  : 0x%04X\n\n", ax);

    // テスト3: AHを変更して、EAXやAXが連動するかテスト
    ah = 0xFF;
    printf("--- Test 3: Modify AH to 0xFF ---\n");
    printf("EAX : 0x%08X (Expected: 0x1234FFAA)\n", regs.dword.eax);
    printf("AX  : 0x%04X (Expected: 0 FFAA)\n", ax);

    return 0;
}
コードのポイント
個別ラップ構造の採用
元のコードのように WORD ax, bx, cx, dx とフラットに並べてしまうと、ax の直後に
bx がメモリ上に配置されてしまいます。しかし、問題の要求は「EAX の中に ax
があり、EBX の中に bx
がある」という構成です。そのため、レジスタ単位で構造体を小分けにして、それぞれに
dummy（16ビット分）を配置することで、DWORD
4つ分のサイズ（合計16バイト）と完全に一致させています。

リトルエンディアンの順序
eax_b の中身が al（下位8ビット）→
ah（上位8ビット）の順番になっていることで、Intel製CPUの実際のメモリ配置と完全に同じ挙動を再現できています。

この問題は、C言語の共用体が低レイヤのハードウェア（CPUのエミュレータやデバイスドライバなど）を記述する際に、いかに強力で便利に使われているかを実感できる素晴らしい課題ですね。手元でもぜひ動かして、レジスタがパズルのように噛み合う感覚を楽しんでみてください！*/
