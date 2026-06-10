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
