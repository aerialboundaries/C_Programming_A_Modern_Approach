CC := gcc
SRC_DIR := ./src
OBJ_DIR := ./obj

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
DEPS := $(OBJS: .o = .d)

CPPFLAGS := -I. -I./include
CFLAGS := -Wall -Wextra -std=c99 -Wpedantic -MMD -MP
LDFLAGS :=
TARGET := inventory

.PHONY: all clean fclean re run debug

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -rm $(OBJ_DIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all

run: $(TARGET)
	./$(TARGET)

debug: CFLAGS += -g -O0
debug: re


