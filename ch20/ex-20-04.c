// 2026-06-09

/*
In computer graphics, colors are often stored as three numbers, representing
red, green, and blue intensities. Suppose that each number requires eight bits,
and we'd like to store all three values in a single long integer. Write a macro
named MK_COLOR with three parameters (the red, green, and blue intensities).
MK_COLOR should return a long in which the last three bytes contain the red,
green, and blue intensities, with the red value as the last byte and the green
value as the next-to-last byte.

My Answer:
#define MK_COLOR(r, g, b) (((long)(b) << 16) | ((long)(g) << 8) | (long)(r))

 */

/* mk_color_demo.c */

#include <stdio.h>

/* 問題の要求を満たすカラーパックマクロ */

#define MK_COLOR(r, g, b) (((long)(b) << 16) | ((long)(g) << 8) | (long)(r))

int main(void)
{
  /* 各色の輝度（0〜255）を設定 */
  long red_in = 0xFF;   /* 255 (2進数: 11111111) */
  long green_in = 0xAA; /* 170 (2進数: 10101010) */
  long blue_in = 0x55;  /* 85 (2進数: 01010101) */

  /* マクロを使って1つのlong整数にパック */

  long packed_color = MK_COLOR(red_in, green_in, blue_in);

  /* 16進数で表示すると、メモリ上の配置がパッと視覚的に分かります */
  printf("パックされたカラー値: 0x%08lX\n\n", packed_color);

  /* パックされたデータから、ビット演算を使って逆に色を取り出して検証 */

  long red_out = packed_color & 0xFF;
  long green_out = (packed_color >> 8) & 0xFF;
  long blue_out = (packed_color >> 16) & 0xFF;

  printf("--- デコード（復元）結果 ---\n");
  printf("Red  : 0x%02LX (%LD)\n", red_out, red_out);
  printf("Green: 0x%02LX (%LD)\n", green_out, green_out);
  printf("Blue : 0x%02LX (%LD)\n", blue_out, blue_out);

  return 0;
}
