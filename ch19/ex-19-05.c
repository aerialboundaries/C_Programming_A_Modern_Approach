/* C_Programming_A_Modern_Approach
ex-19-05.c
2026-05-21

*/

/* queue.h */
#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

// data type to store in queue
typedef int Item;

// incomplete declaration of queue structure
typedef struct queue_type *Queue;

// function to create queue
Queue create(void);

// function to destroy and free memory
void destroy(Queue q);

// add item to the last of queue (Insert)
void enqueue(Queue q, Item i);

// Remove item from top of queue (Remove)
// The oldest item is returned and deleted from queue
Item dequeue(Queue q);

// peek first item (Return first)
// return the oldest item, but not delete
Item peek_first(Queue q);

// peek the last item (Return last)
// returns the latest item, but not delete
Item peek_last(Queue q);

// test if the queue is empty (Test empty)
// if empty returns true, if not false
bool is_empty(Queue q);

#endif

不完全宣言（不完全型）である typedef struct queue_type *Queue;
を使って、完全にカプセル化されたキュー（抽象データ型
    : ADT）を実装する問題ですね。

          ご提示いただいたヘッダーファイル queue.h
          に基づき、(a)
              の仕様である「配列によるラップアラウンド（循環配列）」を適用して、複数のキューを個別に作成・破棄できる実装ファイルを記述します。問題19
    - 03(a)と同様に、first_empty、next_item、num_items
      の3つの状態管理変数を、構造体のメンバーとして持たせる設計がベストプラクティスです。

      nvimでそのまま作成してコンパイルできるように、実装ファイル（queue
          .c）と動作確認用のメインファイル（main.c）の全文を提案します。

      抽象データ型（ADT）の実装ファイル キューの具体的な構造体定義（struct
      queue_type）をこのファイル内に隠蔽することで、利用側から内部の配列や変数に直接アクセスできないようにします。

      C
/* queue.c */
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 100

      /*
         キューの具体的な構造を定義します。
         この中身はヘッダー側には見えないため、情報の隠蔽が完全に保たれます。
      */
      struct queue_type {
    Item contents[QUEUE_SIZE];
    int first_empty;
    int next_item;
    int num_items;
};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue create(void)
{
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL) {
        terminate("Error in create: queue could not be created.");
    }

    q->first_empty = 0;
    q->next_item = 0;
    q->num_items = 0;

    return q;
}

void destroy(Queue q)
{
    /* createで割り当てたメモリを解放します */
    free(q);
}

bool is_empty(Queue q)
{
    return q->num_items == 0;
}

static bool is_full(Queue q)
{
    return q->num_items == QUEUE_SIZE;
}

void enqueue(Queue q, Item i)
{
    if (is_full(q)) {
        terminate("Error in enqueue: queue is full.");
    }

    q->contents[q->first_empty] = i;

    q->first_empty++;
    if (q->first_empty == QUEUE_SIZE) {
        q->first_empty = 0;
    }

    q->num_items++;
}

Item dequeue(Queue q)
{
    Item i;

    if (is_empty(q)) {
        terminate("Error in dequeue: queue is empty.");
    }

    i = q->contents[q->next_item];

    q->next_item++;
    if (q->next_item == QUEUE_SIZE) {
        q->next_item = 0;
    }

    q->num_items--;
    return i;
}

Item peek_first(Queue q)
{
    if (is_empty(q)) {
        terminate("Error in peek_first: queue is empty.");
    }
    return q->contents[q->next_item];
}

Item peek_last(Queue q)
{
    if (is_empty(q)) {
        terminate("Error in peek_last: queue is empty.");
    }

    /*
       最後に挿入された位置は first_empty の1つ手前です。
       0の手前は配列の末尾（QUEUE_SIZE -
       1）になるようにラップアラウンドを考慮します。
    */
    int last_idx = q->first_empty - 1;
    if (last_idx < 0) {
        last_idx = QUEUE_SIZE - 1;
    }

    return q->contents[last_idx];
}
動作確認用のメイン関数
不完全宣言によって、同一プログラム内で複数の独立したキュー（q1,
    q2）を生成して個別に操作できる利点を確認できるコードにしています。

        C
/* main.c */
#include "queue.h"
#include <stdio.h>

    int
    main(void)
{
    printf("--- ADT Queue Test Start ---\n");

    /* 2つの異なるキューを作成 */
    Queue q1 = create();
    Queue q2 = create();

    /* キュー1への操作 */
    enqueue(q1, 10);
    enqueue(q1, 20);
    enqueue(q1, 30);

    /* キュー2への操作 */
    enqueue(q2, 500);
    enqueue(q2, 600);

    /* peekの確認 */
    printf(
        "[q1] First item: %d, Last item: %d\n", peek_first(q1), peek_last(q1));
    printf(
        "[q2] First item: %d, Last item: %d\n", peek_first(q2), peek_last(q2));

    /* 要素の取り出し */
    printf("[q1] Dequeue: %d\n", dequeue(q1));
    printf("[q1] Dequeue: %d\n", dequeue(q1));

    enqueue(q1, 40);
    printf("[q1] New Last item after enqueue(40): %d\n", peek_last(q1));

    printf("\n--- Emptying q1 ---\n");
    while (!is_empty(q1)) {
        printf("[q1] Dequeue remaining: %d\n", dequeue(q1));
    }

    printf("\n--- Emptying q2 ---\n");
    while (!is_empty(q2)) {
        printf("[q2] Dequeue remaining: %d\n", dequeue(q2));
    }

    /* メモリの解放 */
    destroy(q1);
    destroy(q2);

    printf("--- ADT Queue Test End ---\n");
    return 0;
}
コンパイルと実行方法
WSL上のUbuntuの環境で、ヘッダーとソースファイルを同じディレクトリに配置し、以下のコマンドを実行してビルドしてください。

        Bash gcc
    - Wall - Wextra main.c queue.c
    - o queue_adt_test.
        / queue_adt_test 今回のポイントは、peek_last を実装する際に first_empty
            が 0 の場合を考慮して、配列のインデックスが負の数にならないようにラップアラウンドの逆計算を行う部分です。オブジェクト指向言語のクラスのようなカプセル化がC言語でどのように実現されているか、構造に注目してみてくださいね。
