// Modify the stackADT3. c file of Section 19.4 by adding an int member named
// len to the stack_type structure. This member will keep track of how many
// items are currently stored in a stack. Add a new function named length that
// has a Stack parameter and returns the value of the len member. (Some of the
// existing functions in stackADT3.c will need to be modified as well.) Modify
// stackclient. c so that it calls the length function (and displays the value
// that it returns) after each operation that modifies a stack.

#include <stdio.h>
#include <stdlib.h>

#include "stackADT3.h"

struct node {
    Item data;
    struct node *next;
};

struct stack_type {
    int len;
    struct node *top;
};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack create(void)
{
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL)
        terminate("Error in create: stack could not be created.");
    s->len = 0;
    s->top = NULL;
    return s;
}

void destroy(Stack s)
{
    make_empty(s);
    free(s);
}

void make_empty(Stack s)
{
    while (!is_empty(s))
        pop(s);
}

bool is_empty(Stack s)
{
    return s->top == NULL;
}

bool is_full(Stack s)
{
    return false;
}

void push(Stack s, Item i)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in push: stack is full.");

    new_node->data = i;
    new_node->next = s->top;
    s->top = new_node;
    s->len++;
}

Item pop(Stack s)
{
    struct node *old_top;
    Item i;

    if (is_empty(s))
        terminate("Error in pop: stack is empty.");

    old_top = s->top;
    i = old_top->data;
    s->top = old_top->next;
    free(old_top);
    s->len--;
    return i;
}

int length(Stack s)
{
    return s->len;
}

Item pop(Stack s)

{

    struct node *old_top;

    Item i;

    if (is_empty(s))

        terminate("Error in pop: stack is empty.");

    old_top = s->top;

    i = old_top->data;

    s->top = old_top->next;

    free(old_top);

    s->len--;

    return i;
}

// i = s->old_top->data;
//
//
// とはならない？
//
//
// 結論からお伝えすると、i = s->old_top->data; とはなりません。
//
// C言語のポインタと構造体の仕組みにおいて、なぜそうならないのか、そしてなぜ元のコードの書き方をする必要があるのかを2つの理由に分けて詳しく解説します。
//
// 理由1：old_top は s（struct stack_type）のメンバーではない
// ->（アロー演算子）は、「左側にあるポインタが指す構造体の中の、右側にあるメンバーを指す」
// という役割を持っています。kk
//
// ここで、stackADT3.c で定義されている2つの構造体の形を思い出してみましょう。
//
//
// C
// struct node {
//     Item data;
//     struct node *next;
// };
//
// struct stack_type {
//     int len;
//     struct node *top;
// };
// s は struct stack_type を指すポインタです。この構造体の中にあるメンバーは len
// と top の2つだけです。old_top というメンバーは存在しません。
//
// そのため、s->old_top と書いてしまうと、コンパイラは「struct stack_type の中に
// old_top
// というメンバーは見当たりません」というコンパイルエラーを出してしまいます。
//
// 理由2：old_top は pop 関数の中で新しく作った「独立したポインタ変数」
// pop 関数の冒頭を見てみると、次のように宣言されています。
//
//
// C
//
// struct node *old_top;
// これはスタック構造体（s）の中身とは関係なく、pop
// 関数が実行されている間だけ一時的に使える独立したローカル変数（ポインタ）
// です。
//
//
// そして、次の行で代入が行われています。
//
// C
// old_top = s->top;
// これにより、s->top（現在の先頭ノードのアドレス）が、一時変数である old_top
// にコピーされます。この時点で、old_top
// は先頭ノードを直接指すポインタになります。
//
// old_top 自体がすでにノードを指すポインタになっているため、s->
// を経由する必要はなく、直接 old_top->data
// と書くことでそのノードのデータにアクセスできるのです。
//
// もし old_top を使わずに1行で書くとしたら？
// 一時変数 old_top を使わずに、s から一気にノードのデータにアクセスして変数 i
// に代入するコードを書くとしたら、次のようになります。
//
// C
//
// i = s->top->data;
// これなら構造体の繋がり（s が指すスタックの、top
// が指すノードの、data）として正しい表現になります。
//
// なぜ元のコードではわざわざ old_top を使っているの？
// それなら最初から i = s->top->data;
// と書けばいいのではないか、と感じるかもしれません。ここで old_top
// という一時変数が必要になるのは、ノードをメモリから解放（free）しなければならないから
// です。
//
// pop 関数では、データを取得した後にそのノードを消去する必要があります。
// もし以下のように old_top を使わずに処理を進めようとすると問題が発生します。
//
// C
// /* old_top を使わない場合の失敗例 */
// i = s->top->data;
//
// s->top = s->top->next; /* 先頭を次のノードに進める */
//
// /* ここで元の先頭ノードを free したいけれど、
//    すでに s->top は次のノードに移動してしまったため、
//    元の先頭ノードのアドレスが分からなくなり free できない！ */
//
// このように、先頭ノードをスタックから切り離してしまうと、そのノードのメモリ領域を指すポインタが消えてしまい、free
// することができなくなってしまいます（メモリリークの原因になります）。
//
// そのため、元のコードでは、
//
// 消えてしまう前に old_top = s->top; とアドレスを控えておく
//
// s->top = old_top->next; でスタックの先頭を次に進める
//
//
// 控えておいた old_top を使って安全に free(old_top); する
//
// という手順を踏んでいます。ポインタの指し先が今どこにあるのかを意識すると、この構造がとてもすっきりと理解できるようになりますよ。
