CC = clang
CFLAGS = -Wall -Wextra -g
CFLAGS += -I $(SRC_DIR)   # To include headers in test files.
CFLAGS += -I $(DEPS_DIR)
LDFLAGS = -L$(DEPS_DIR)

SRC_DIR = src
DEPS_DIR = deps
TEST_DIR = test
BUILD_DIR = build

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)
LIBS = -lncurses -ltomlc17
TARGET = $(BUILD_DIR)/atm

SRCS_DISPLAY = $(SRC_DIR)/screen.c $(TEST_DIR)/display.c
OBJS_DISPLAY = $(SRC_DIR)/screen.o $(TEST_DIR)/display.o
TARGET_DISPLAY = $(BUILD_DIR)/display

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBS) $^ -o $@

test: $(TARGET_DISPLAY)

$(TARGET_DISPLAY): $(OBJS_DISPLAY)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBS) $^ -o $@

clean:
	rm -f $(OBJS) $(TARGET)
	rm -f $(OBJS_DISPLAY) $(TARGET_DISPLAY)

.PHONY: all test clean
