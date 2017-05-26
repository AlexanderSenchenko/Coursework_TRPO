BIN_NAME := graph
TEST_BIN_NAME := $(BIN_NAME)_test

SRC_PATH := src
TEST_PATH := tests
BIN_PATH := bin
BUILD_PATH := build

CC = gcc
INCLUDES = -I $(SRC_PATH)/ -I thirdparty/ -std=c99

SRC_WILD := $(addprefix $(BUILD_PATH)/$(SRC_PATH)/, $(notdir $(wildcard $(addsuffix /*.c, $(SRC_PATH)))))
TEST_SRC_WILD := $(addprefix $(BUILD_PATH)/$(TEST_PATH)/, $(notdir $(wildcard $(addsuffix /*.c, $(TEST_PATH)))))
TEST_SRC_WILD += $(BUILD_PATH)/$(TEST_PATH)/graph.c $(BUILD_PATH)/$(TEST_PATH)/vald.c

.PHOMY: all
all: dirs $(BIN_PATH)/$(BIN_NAME) $(BIN_PATH)/$(TEST_BIN_NAME)

$(BIN_PATH)/$(BIN_NAME): $(patsubst %.c, %.o, $(SRC_WILD))
	$(CC) -Wall  $^ -o $@

$(BUILD_PATH)/$(SRC_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) -Wall $(INCLUDES) -MMD -c $< -o $@

$(BIN_PATH)/$(TEST_BIN_NAME): $(patsubst %.c, %.o, $(TEST_SRC_WILD))
	$(CC) -Wall $^ -o $@
	$(BIN_PATH)/$(TEST_BIN_NAME)

VPATH := $(SRC_PATH) $(TEST_PATH)
$(BUILD_PATH)/$(TEST_PATH)/%.o: %.c
	$(CC) -Wall $(INCLUDES) -MMD -c $< -o $@

-include &(wildcard *.d)

.PHONY: dirs
dirs:
	@mkdir -p $(BUILD_PATH)/$(SRC_PATH)
	@mkdir -p $(BUILD_PATH)/$(TEST_PATH)
	@mkdir -p $(BIN_PATH)

.PHOMY: clean
clean:
	$(RM) -r $(BUILD_PATH)
	$(RM) -r $(BIN_PATH)
