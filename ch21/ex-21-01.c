/*
Locate where header files are kept on your system. Find the nonstandard headers
and determine the purpose of each.

My Anser:
1. ヘッダファイルの配置場所
Linux（Ubuntu）において、C言語のヘッダファイルは主に以下のディレクトリに保管されています。

/usr/include/
最も中心となるディレクトリです。stdio.h や stdlib.h
などの標準ヘッダ、および多くの非標準（システム固有・サードパーティ製）ヘッダがここに配置されます。

/usr/include/x86_64-linux-gnu/
64bit
Linux環境に依存するヘッダファイル（アーキテクチャ固有の設定など）が置かれる場所です。システムによっては、bits/
ディレクトリの中に標準ヘッダの実体（内部実装）が隠されていることもあります。

/usr/local/include/
ユーザーが手動でソースコードからビルドしてインストールした、サードパーティ製のライブラリのヘッダファイルが置かれる場所です。初期状態では空のことが多いです。

2. 非標準ヘッダファイルの探し方と目的
/usr/include/
の中を探索すると、C言語の仕様（C89/C99）で定義されていない、LinuxやPOSIX（Unix系OSの共通規格）固有の「非標準ヘッダ」が数多く見つかります。

Neovimやターミナル（Bash）を使ってこれらを探し、その目的を調べる方法を解説します。

代表的な非標準ヘッダ（Linux/POSIX固有）とその目的
これらは教科書「C Programming: A Modern
Approach」の範囲外（標準Cライブラリ外）ですが、Linux環境で高度なシステムプログラミング（プロセス管理、ネットワーク、低レベルI/O）を行う際によく使われます。

ヘッダファイル名	主な目的・用途
<unistd.h>	POSIX標準のOS APIへのアクセス（ファイル記述子の操作 read, write,
プロセス生成 fork, スリープ sleep など）。 <sys/types.h>
システム特有の基本データ型（プロセスIDを表す pid_t や、ファイルサイズを表す
off_t など）の定義。 <sys/stat.h>
ファイルの属性（パーミッション、サイズ、更新日時など）を取得する stat
関数の定義。 <sys/socket.h>
ネットワーク通信（ソケットプログラミング）を行うための関数や構造体の定義。
<fcntl.h>
ファイルのオープン時の挙動（読み込み専用、追記モードなど）を制御するフラグの定義。
<arpa/inet.h>
インターネットアドレスの変換（文字列のIPアドレスをバイナリ形式に変換するなど）を行う関数の定義。
3. 実際にシステムで探して目的を調べるコマンド
WSLのターミナルから、以下のBashコマンドを使ってヘッダファイルの存在やその目的を調べることができます。

ヘッダファイルの実体（コード）を検索する
例えば、<unistd.h> がどこにあるかを探したい場合は、find コマンドが有効です。

Bash
find /usr/include -name "unistd.h"
ヘッダや関数の目的を調べる（manページの活用）
非標準ヘッダや、そこに含まれる関数の正確な目的を調べるには、Linuxのオンラインマニュアルである
man コマンドを使うのがベストプラクティスです。

Bash
# unistd.h 全体の目的や定義されている機能の概要を調べる
man unistd.h

# 例: unistd.h に含まれる fork 関数の仕様を調べる（セクション2はシステムコール）
man 2 fork
実践：非標準ヘッダ（unistd.h）を使用したコード例
以下は、POSIX非標準ヘッダである <unistd.h>
を使用して、LinuxのプロセスIDを取得し、画面を一時的にスリープさせるプログラムの全文です。標準Cライブラリ（printfなど）と組み合わせて使用します。

C
#include <stdio.h>
#include <unistd.h> // POSIX非標準ヘッダ: getpidやsleepを使用するために必要

int main(void)
{
    // getpid() は現在のプロセスのID（PID）を返します
    pid_t my_pid = getpid();

    printf("現在のプロセスのPIDは %d です。\n", my_pid);
    printf("3秒間スリープします...\n");

    // sleep() は指定された秒数だけプログラムを一時停止します
    sleep(3);

    printf("プログラムを終了します。\n");

    return 0;
}
コンパイルと実行
WSL上のUbuntu環境で通常通りコンパイルして実行できます。

Bash
gcc -Wall -Wextra main.c -o main
./main
C言語の標準ライブラリ（Chapter
21）を理解した上で、これらの非標準ヘッダに触れると、C言語がいかにOS（Linux）と密接に関わっているかがより深く理解できるようになります。

*/
