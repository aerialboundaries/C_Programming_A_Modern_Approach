#include <locale.h>
#include <ncurses.h>

int main(void) {
  /* 日本語（マルチバイト文字）を表示するための設定 */
  setlocale(LC_ALL, "");

  /* ncursesの初期化 */
  initscr();
  start_color();
  init_pair(1, COLOR_CYAN, COLOR_BLACK);

  /* 1. 背景っぽく適当に文字を埋める（VRAM背景風） */
  for (int i = 0; i < LINES; i++) {
    mvprintw(i, 0, "BACKGROUND-DATA-SECTION-%d", i);
  }

  /* 2. メッセージウィンドウを作成（セリフ背景風） */
  int height = 5, width = 60;
  int start_y = LINES - 7, start_x = (COLS - width) / 2;
  WINDOW *msg_win = newwin(height, width, start_y, start_x);

  /* ウィンドウに枠線を引く */
  box(msg_win, 0, 0);
  wattron(msg_win, COLOR_PAIR(1) | A_BOLD);
  mvwprintw(msg_win, 0, 2, "[ MESSAGE ]");

  /* 3. 文字を流す（Text RAM風） */
  mvwprintw(msg_win, 2, 2, "イースのセリフ表示のように...");
  mvwprintw(msg_win, 3, 2, "枠はそのままに文字だけを書き換えます。");

  /* 画面に反映 */
  refresh();
  wrefresh(msg_win);

  /* 入力待ち */

  getch();

  /* 終了処理 */
  delwin(msg_win);
  endwin();

  return 0;
}
