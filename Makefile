BIN_NAME := graph
TEST_BIN_NAME := $(BIN_NAME)_test

SRC_PATH := src
TEST_PATH := tests
BIN_PATH := bin
BUILD_PATH := build

INCLUDES = -I $(SRC_PATH)/ -I thirdparty/

SRC_WILD := $(notdir $(wildcard $(addsuffix /*.c, $(SRC_PATH))))
TEST_SRC_WILD := $(notdir $(wildcard $(addsuffix /*.c, $(TEST_PATH))))

CC = gcc

.PHOMY: all
all: dirs $(BIN_PATH)/$(BIN_NAME) $(BIN_PATH)/$(TEST_BIN_NAME)

$(BIN_PATH)/$(BIN_NAME): $(patsubst %.c, %.o, $(addprefix $(BUILD_PATH)/$(SRC_PATH)/, $(SRC_WILD)))
	$(CC) -Wall $^ -o $@

$(BIN_PATH)/$(TEST_BIN_NAME): $(patsubst %.c, %.o, $(addprefix $(BUILD_PATH)/$(TEST_PATH)/, $(TEST_SRC_WILD)))
	$(CC) -Wall $^ -o $@
	$(BIN_PATH)/$(TEST_BIN_NAME)

$(BUILD_PATH)/$(SRC_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) -Wall $(INCLUDES) -MD -c $< -o $@

$(BUILD_PATH)/$(TEST_PATH)/%.o: $(TEST_PATH)/%.c
	$(CC) -Wall $(INCLUDES) -MD -c $< -o $@

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
