CC := gcc
CPPFLAGS := -I.
CFLAGS = -Wall -Wextra -std=c99 -pedantic-errors -MMD -MP
LDLIBS :=

SRC_DIR := src
BUILD_DIR := build

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
DEPS := $(OBJS:.o=.d)

TARGET := $(BUILD_DIR)/inventory

.PHONY: all run clean fclean re debug

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(DEPS)

fclean:
	rm -rf $(BUILD_DIR)

re: fclean all

debug: CFLAGS += -g -O0

debug: re

-include $(DEPS)
