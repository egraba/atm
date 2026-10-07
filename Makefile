CC     = clang
CFLAGS = -Wall -Wextra -g -MMD -MP -Isrc -Ivendor/tomlc17/src
LDLIBS = -lncurses

SRCS      = $(wildcard src/*.c) vendor/tomlc17/src/tomlc17.c
OBJS      = $(SRCS:.c=.o)
TEST_OBJS = src/screen.o test/display.o vendor/tomlc17/src/tomlc17.o

all: build/atm
test: build/display

build/atm: $(OBJS)
build/display: $(TEST_OBJS)

build/atm build/display:
	@mkdir -p build
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

clean:
	rm -rf build $(OBJS) $(TEST_OBJS) $(OBJS:.o=.d) $(TEST_OBJS:.o=.d)

-include $(OBJS:.o=.d) $(TEST_OBJS:.o=.d)

.PHONY: all test clean
