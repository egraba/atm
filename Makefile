CC = clang
CFLAGS = -Wall -Wextra -g
TARGET = atm
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
LDLIBS = -lncurses

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -rdf $(TARGET).dSYM
	rm -f $(TARGET)

.PHONY: all clean
