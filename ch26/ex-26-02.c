/*
Write a simplified version of printf in which the only conversion
specification is %d, and all arguments after the first are assumed
to have int type. If the function encounters a % character that's
not immediately followed by a d character, it should ignore both
characters. The function should use calls of putchar to produce all output.
You may assume that the format string doesn't contain escape sequences.
*/

#include <stdarg.h>
#include <stdio.h>

#include <stdarg.h>
#include <stdio.h>

void int_printf(const char *format, ...)
{
  va_list ap;
  const char *p;
  int digit, i, power, temp;

  va_start(ap, format);

  for (p = format; *p != '\0'; p++) {
    if (*p != '%') {
      putchar(*p);
      continue;
    }

    /* % の次の文字をチェック */
    p++;

    if (*p == 'd') {
      i = va_arg(ap, int);

      /* 負の数の処理（符号を出力して正の数にする） */
      if (i < 0) {
        putchar('-');
        /*
         * 厳密な INT_MIN 対策をするなら unsigned int を使うか
         * 特例処理をしますが、ここでは簡易的に絶対値化します
         */
        i = -i;
      }

      /* 最上位の桁の重み（power）を求める */
      temp = i;
      power = 1;
      while (temp > 9) {
        temp /= 10;
        power *= 10;
      }

      /*
       * power が 0 になるまで（＝1の位まで）ループする。
       * i > 0 にしてしまうと 100 などの末尾の 0 が表示されなくなる。
       */
      do {
        digit = i / power;
        putchar(digit + '0');
        i -= digit * power;
        power /= 10;
      } while (power > 0);

    } else if (*p == '\0') {
      /* %
       * の直後に文字列が終わっていた場合、ポインタを行き過ぎさせないよう戻して抜ける
       */
      break;
    }
    /* % の直後が d 以外（%x など）の場合は、何もしない（ignore）で次の文字へ */
  }

  va_end(ap);
}

int main(void)
{
  /* 動作テスト */
  int_printf("He is %d years old and has %d yen.\n", 20, 500);
  int_printf("Testing zero and trailing zeros: %d, %d, %d\n", 0, 100, 2050);
  int_printf("Testing ignore: Hello %x World!\n");

  return 0;
}
