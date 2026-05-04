/* C Programming A Modern Approach
 * pp-17-07.c
 * 2026-05-01
 *
 * (C99) Modify the remind2. c program of Section 17.2 so that each element of
 * the reminders array is a pointer to a vstring structure (see Section 17.9)
 * rather than a pointer to an ordinary string.
 */

/* C Programming A Modern Approach
 * 13.5 remind.c rewrited as 17.2 remind2.c
 * 2026-02-26 revisited 2026-04-14
 *
 * Prints a one-month reminder list */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMIND 50 /* maximum number of reminders */
#define MSG_LEN 60    /* max length of reminder message */

// 構造体の定義はmainの外かmainの戦闘で行う
struct vstring {
  int len;
  char chars[]; // 中う何な配列メンバ（C99)
};

int read_line(char str[], int n);

int main(void) {

  // ポインタの配列を構造体へのポインタに変更
  struct vstring *reminders[MAX_REMIND];

  char day_str[3], msg_str[MSG_LEN + 1];
  int day, i, j, num_remind = 0;

  for (;;) {
    if (num_remind == MAX_REMIND) {
      printf("-- No space left --\n");
      break;
    }

    printf("Enter day and reminder: ");
    if (scanf("%2d", &day) != 1)
      break;
    ;
    if (day == 0)
      break;
    sprintf(day_str, "%2d", day);

    // バッファに残った改行文字を読み飛ばす処理
    while (getchar() != '\n')
      ;

    read_line(msg_str, MSG_LEN);

    // 比較対象をreminders[i]->charsへ変更
    for (i = 0; i < num_remind; i++)
      if (strcmp(day_str, reminders[i]->chars) < 0)
        break;

    for (j = num_remind; j > i; j--)
      reminders[j] = reminders[j - 1];

    // 必要な長さ（日付２文字＋メッセージ＋終端文字）を計算
    int full_msg_len = strlen(day_str) + strlen(msg_str);

    // reminders[i] = malloc(2 + strlen(msg_str) + 1); // day(2) + '\0' (1)
    // 構造体のサイズ＋配列部分のサイズを確保
    struct vstring *new_remind =
        malloc(sizeof(struct vstring) + full_msg_len + 1);

    if (new_remind == NULL) {
      printf("-- No space left --\n");
      break;
    }

    new_remind->len = full_msg_len;
    strcpy(new_remind->chars, day_str);
    strcat(new_remind->chars, msg_str);

    reminders[i] = new_remind;
    num_remind++;
  }

  printf("\nDay Reminder\n");
  for (i = 0; i < num_remind; i++)
    printf(" %s\n", reminders[i]->chars);

  // free memory
  for (i = 0; i < num_remind; i++) {
    free(reminders[i]);
  }

  return 0;
}

int read_line(char str[], int n) {
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}
