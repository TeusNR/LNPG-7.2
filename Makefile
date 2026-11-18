CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic
BUILD = build
LABS = l1 l2 l3 l4 l5

.PHONY: all clean run-l1 run-l2 run-l3 run-l4 run-l5

all: $(addprefix $(BUILD)/,$(LABS))

$(BUILD):
	mkdir -p $(BUILD)

$(BUILD)/l1: parte_b/l1.c | $(BUILD)
	$(CC) $(CFLAGS) $< -o $@ -lm

$(BUILD)/l%: parte_b/l%.c | $(BUILD)
	$(CC) $(CFLAGS) $< -o $@

run-l1: $(BUILD)/l1
	./$(BUILD)/l1
run-l2: $(BUILD)/l2
	./$(BUILD)/l2
run-l3: $(BUILD)/l3
	./$(BUILD)/l3
run-l4: $(BUILD)/l4
	./$(BUILD)/l4
run-l5: $(BUILD)/l5
	./$(BUILD)/l5

clean:
	rm -rf $(BUILD)
