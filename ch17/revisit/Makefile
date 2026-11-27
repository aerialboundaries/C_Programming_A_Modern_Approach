CC := gcc
SRC :=
TARGET := a.out
CFLAGS := -Wall -Wextra -pedantic-errors -g -O0

:PHONY: all clean
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

