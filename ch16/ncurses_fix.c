#define _XOPEN_SOURCE_EXTENDED 1
#include <locale.h>
#include <ncursesw/curses.h>
#include <stdlib.h> /* rand() と srand() のために必要 */
#include <time.h>   /* time() のために必要 */

int main(void) {
  /* 1. 環境の初期化 */
  setlocale(LC_ALL, "");
  initscr();
  start_color();
  curs_set(0); /* カーソルを消して没入感を出す */

  /* 乱数の種を現在時刻で初期化（実行するたびに星の配置が変わります） */
  srand((unsigned int)time(NULL));

  /* カラーペアの設定 (1: 水色/黒, 2: 黄色/黒) */

  init_pair(1, COLOR_CYAN, COLOR_BLACK);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);

  /* 2. 星空の背景を描画 (VRAM背景のシミュレーション) */
  /* 画面全体の文字数分ループを回します */
  for (int i = 0; i < LINES * COLS; i++) {
    /* 5%の確率で星 '*' を描き、それ以外は空白を入れる */
    if (rand() % 100 > 95) {
      attron(COLOR_PAIR(2)); /* 星を黄色にする */
      addch('*');
      attroff(COLOR_PAIR(2));
    } else {
      addch(' ');
    }
  }

  /* 3. メッセージウィンドウの作成 (不透明なレイヤー) */
  int height = 7, width = 60;

  int start_y = (LINES - height) / 2; /* 画面中央付近に配置 */
  int start_x = (COLS - width) / 2;
  WINDOW *msg_win = newwin(height, width, start_y, start_x);

  /* ウィンドウ内を黒色(COLOR_PAIR(1))で塗りつぶして背景の星を隠す */
  wbkgd(msg_win, COLOR_PAIR(1));
  werase(msg_win);

  /* 枠線とタイトルの描画 */
  box(msg_win, 0, 0);
  wattron(msg_win, A_BOLD | COLOR_PAIR(1));
  mvwprintw(msg_win, 0, 2, "[ STARGAZING SYSTEM ]");
  wattroff(msg_win, A_BOLD);

  /* メッセージ本文 */
  mvwaddstr(msg_win, 2, 2, "Look at the stars!");
  mvwaddstr(msg_win, 3, 2, "The background is filled with random pixels,");

  mvwaddstr(msg_win, 4, 2, "but this window covers them perfectly.");

  /* 4. 画面の反映 */
  refresh();         /* 背景(stdscr)を描画 */
  wrefresh(msg_win); /* その上にウィンドウを重ねる */

  /* 入力待ち */
  getch();

  /* 終了処理 */
  delwin(msg_win);

  endwin();

  return 0;
}
