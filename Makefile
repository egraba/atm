CC = clang
CFLAGS = -Wall -Wextra -g
CFLAGS += -I $(SRC_DIR)   # To include headers in test files.

SRC_DIR = src
TEST_DIR = test
BUILD_DIR = build

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)
LIBS = -lncurses
TARGET = $(BUILD_DIR)/atm

SRCS_TEST = $(wildcard $(TEST_DIR)/*.c)
OBJS_TEST = $(filter-out $(SRC_DIR)/atm.o, $(OBJS)) $(SRCS_TEST:.c=.o)
TARGET_TEST = $(BUILD_DIR)/test_screens

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@

test: $(TARGET_TEST)

$(TARGET_TEST): $(OBJS_TEST)
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@

clean:
	rm -f $(OBJS) $(TARGET)
	rm -f $(OBJS_TEST) $(TARGET_TEST)

.PHONY: all test clean
