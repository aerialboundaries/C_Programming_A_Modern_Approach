/* C Programming A Modern Approach pp6-08.c
 * 2025-11-07
 *
 * Write a program that prints a one-month calendar. The user specifies
 * the number of days in the month and the day of the week on which the
 * month begings:
 *
 * Enter number of days in month: 31
 * Enter starting day of the week (1=Sun, 7=Sat): 3
 *
 *         1   2   3   4   5
 *  6  7   8   9  10  11  12
 * 13 14  15  16  17  18  19
 * 29 21  22  23  24  25  26
 * 27 28  29  30  31
 *
 * Hint: This program isn't as hard as it looks. The most important part
 * is a for statement that uses a variable i to count from 1 to n, where
 * n is the number of days in the month, printing each value of i. Inside
 * the loop, an if statement tests whether i is the last day in a week; if
 * so, it prints a new-line character.
 */

/* My Answer -- worked ayway
#include <stdio.h>

int main(void) {
  int i, n, end_week, starting_day, remaining_days;
  printf("Enter number of days in month:");
  scanf("%d", &n);
  printf("Enter starting day of the week (1=Sun, 7=Sat):");
  scanf("%d", &starting_day);
  end_week = 7 - starting_day + 1;

  // for the first week
  for (i = 1; i < starting_day; i++)
    printf("%4s", " ");

  for (i = 1; i <= 7; ++i) {
    if (i != end_week) {
      printf("%4d", i);
    } else {
      printf("%4d\n", i);
      end_week += 7;
      i++;
      break;
    }
  }

  // for the second and after week
  for (; i <= n; ++i) {
    if (i != end_week) {
      printf("%4d", i);
    } else {
      printf("%4d\n", i);
      end_week += 7;
    }
  }

  return 0;
}
end of my answer */

/* -- GEmini's Answer
✦ はい、実行すれば正しいカレンダーが作成されます
  。ロジックは機能しています。

  しかし、問題のヒントが示唆しているようにもっ
  とシンプルに書くことができ、現在のコードは少
  し複雑になっています。具体的には、3つのforル
  ープに分かれている点や、ループ内でカウンタ変
  数iを直接変更している (i++ と break)
  点が挙げられます。

  ヒントに従って、1からnまでを数える1つのforル
  ープと、週の最後の日に改行を入れるif文を使う
  と、以下のようにすっきりとしたコードになりま
  す。

    1 #include <stdio.h>
    2
    3 int main(void) {
    4   int num_days, starting_day;
    5
    6   printf("Enter number of days in month: "
      );
    7   scanf("%d", &num_days);
    8   printf("Enter starting day of the week
      (1=Sun, 7=Sat): ");
    9   scanf("%d", &starting_day);
   10
   11   // 最初の週の開始日までの空白を出力
   12   for (int i = 1; i < starting_day; i++) {
   13     printf("    ");
   14   }
   15
   16   // 1日から最終日までを出力
   17   for (int i = 1; i <= num_days; i++) {
   18     printf("%4d", i);
   19     // (空白の日 + 実際の日付)
      が7で割り切れるなら、それは土曜日なので改
   20     if ((starting_day + i - 1) % 7 == 0) {
   21       printf("\n");
   22     }
   23   }
   24
   25   //
      最後の週が土曜日で終わらない場合に備えて改
      行
   26   printf("\n");
   27
   28   return 0;
   29 }

  こちらのコードのポイント:

   * 最初のforループで、月の開始曜日に応じて必要
     な数の空白を出力します。
   * 2つ目のforループがメインの処理です。1日から
     最終日までを順番に出力します。
   * if ((starting_day + i - 1) % 7 == 0)
     という条件式が重要です。
       * starting_day - 1
         は、1日の前にある空白の数です。
       * それに現在の日付 i
         を足したものが、カレンダー上のマスの総
         になります。
       * この総数が7で割り切れるとき、その日は土
         曜日なので改行します。

  この方法だと、コードが短くなり、何をしている
  かが分かりやすくなります。

-- end of Gemini Answer */

///* KN's answer
//* #include <stdio.h>
//*
//* int main(void)
//* {
//*   int i, n, start_day;
//*
//*   printf("Enter number of days in month: ");
//*   scanf("%d", &n);
//*   printf("Enter starting day of the week (1=Sun, 7=Sat): ");
//*   scanf("%d", &start_day);
//*
//*   /* print any leading "blank dates" */
//*   for (i = 1; i < start_day; i++)
//*     printf("   ");
//*
//*   /* now print the calendar */
//*   for (i = 1; i <= n; i++) {
//*     printf("%3d", i);
//*     if ((start_day + i - 1) % 7 == 0)
//*       printf("\n");
//*   }
//*
//*   return 0;
//* }
//*/
//
