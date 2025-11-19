/* C Programming A Modern Approach pp07-12.c - FINAL VERSION
 * 左から右へ順に式を評価します（無限ループ対策済み）
 */
#include <stdio.h>

// バッファに残ったゴミ（改行文字など）をクリアする関数
void clear_input_buffer(void) {
  int ch;
  // EOFまたは改行文字が来るまで、文字を読み捨てる
  while ((ch = getchar()) != '\n' && ch != EOF) {
    ;
  }
}

int main(void) {
  float operand;
  float result;
  char operator_ch;

  printf("Enter an expression (e.g., 1+2.5*3): ");

  // 1. 最初の数値だけを読み込む (結果の初期値)
  if (scanf("%f", &result) != 1) {
    printf("Error: Could not read initial number.\n");
    clear_input_buffer(); // エラー時もバッファをクリア
    return 1;
  }

  // 2. ループで「演算子と次の数値」のペアを繰り返し読み込む
  // scanf(" %c%f", ...) は、2つの値を読み込めたら 2 を返します。
  // 読み込みに失敗するか、ファイル終端に達するとループを抜けます。
  while (scanf(" %c%f", &operator_ch, &operand) == 2) {

    switch (operator_ch) {
    case '+':
      result += operand;
      break;
    case '-':
      result -= operand;
      break;
    case '*':
      result *= operand;
      break;
    case '/':

      // ゼロ除算のチェック
      if (operand == 0.0f) {
        printf("Error: Division by zero.\n");
        clear_input_buffer();
        return 1;
      }
      result /= operand;
      break;
    default:
      printf("Error: Invalid operator ('%c').\n", operator_ch);
      clear_input_buffer();

      return 1;
    }
  }

  // 3. 【重要】ループを抜けた後、バッファに残ったゴミ（改行文字など）をクリア
  clear_input_buffer();

  printf("Value of expression: %.2f\n", result);

  return 0;
}
