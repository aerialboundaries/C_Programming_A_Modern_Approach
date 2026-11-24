CC := gcc
CFLAGS := -Wall -Wextra -std=c99 -pedantic
TARGET := calc

.PHONY: all clean

all: $(TARGET)

$(TARGET): calc.o stack.o
	$(CC) $(CFLAGS) -o $@ $^

calc.o: calc.c stack.h
	$(CC) $(CFLAGS) -c -o $@ $<

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) *.o

