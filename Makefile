# Determine the preferred compiler
CC := $(if $(shell command -v clang 2> /dev/null),clang,gcc)
CFLAGS := -Wall -Wextra -pedantic

RELEASE_FLAGS = -O2
DEBUG_OUT = debug.out
RELEASE_OUT = %.out

.PHONY: all
all:
	@echo "Error: no target specified. Specify a .c file name without extension. For example, use 'make array-binary-search' for array-binary-search.c"
	@exit 1

%: %.c
	$(CC) $(CFLAGS) $< -o $(DEBUG_OUT)

release-%: %.c
	$(CC) $(CFLAGS) $(RELEASE_FLAGS) $< -o $(RELEASE_OUT)

.PHONY: all run clean
