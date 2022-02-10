IMPLEMENTATION_FILES=$(wildcard src/*.c)
HEADER_FILES=$(wildcard src/*.h)
OUTPUT_BIN=merge_files
CC=gcc
C_FLAGS=-Og -ggdb3

.PHONY: all run clean

all: $(OUTPUT_BIN)

run: $(OUTPUT_BIN)
	@./$< input1/ input2/ output/

clean:
	@rm -rf $(OUTPUT_BIN)

$(OUTPUT_BIN): $(IMPLEMENTATION_FILES) $(HEADER_FILES)
	@$(CC) $(C_FLAGS) -o $@ $(IMPLEMENTATION_FILES)
