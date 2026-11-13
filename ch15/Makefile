# コンパイラとフラグの設定
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# ディレクトリ内のすべての .c ファイルを自動取得し、対応する名前を生成
SRCS = $(wildcard *.c)
TARGETS = $(SRCS:.c=)
OBJS = $(SRCS:.c=.o)

# デフォルトターゲット：すべてのプログラムをビルドする
all: $(TARGETS)

# パターンルール：%.c から同名の実行ファイル % を生成する
%: %.c
	$(CC) $(CFLAGS) $< -o $@

# クリーンアップ：生成された実行ファイルと .o ファイルを削除する
.PHONY: clean
clean:
	rm -f $(TARGETS) $(OBJS)
