CC := gcc
CPPFLAGS := -I. -I./include
CFLAGS := -Wall -Wextra -std=c99 -pedantic-errors -MMD -MP
DEBUG_CFLAGS := -g -O0
LDFLAGS := -lm

SRC_DIR := .
BUILD_DIR := build

SRCS := $(wildcard $(SRC_DIR)/*.c)
TARGETS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%, $(SRCS))
DEPS := $(TARGETS:=.d) $(TARGETS:=_dbg.d)

NAME ?= $(basename $(notdir $(firstword $(SRCS))))

.PHONY: all clean fclean re run debug-build

all: $(TARGETS)

$(BUILD_DIR)/%: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(BUILD_DIR)/%_dbg: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(DEBUG_CFLAGS) $< -o $@ $(LDFLAGS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

run: $(BUILD_DIR)/$(NAME)
	./$<

debug-build: $(BUILD_DIR)/$(NAME)_dbg
	@echo "Built debug binary: $<"

re: fclean all

clean:
	rm -rf $(BUILD_DIR)/*

fclean:
	rm -rf $(BUILD_DIR)

-include $(DEPS)
