CC := gcc
CFLAGS := -Wall -Wextra -std=c99 -pedantic
TARGET := calc

.PHONY: all clean

all: $(TARGET)

$(TARGET): calc.o stack.o token.o operate.o
	$(CC) $(CFLAGS) -o $@ $^

calc.o: calc.c token.h
	$(CC) $(CFLAGS) -c -o $@ $<

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c -o $@ $<

token.o: token.c token.h stack.h operate.h 
	$(CC) $(CFLAGS) -c -o $@ $<

operate.o: operate.c operate.h 
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) *.o

