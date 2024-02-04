# Determine the compiler, Clang preferred
CC := $(if $(shell command -v clang 2> /dev/null),clang,gcc)
# Set default compiler flags
CFLAGS := -Wall -Wextra -pedantic -std=c17
# Set linker flags
LDLIBS := -lm -ldl
# For release builds
RELEASE_FLAGS := -O2

# Determine the OS, and set the executable extension accordingly
ifeq ($(OS),Windows_NT)
    EXE_EXT := exe
else
    EXE_EXT := out
endif

DEBUG_OUT := debug.$(EXE_EXT)

.PHONY: all
# Error if no target is specified
all:
	$(error "Error: no target specified. Specify a .c file name without extension. \
	For example, use 'make array-binary-search' for array-binary-search.c")
	@exit 1

# make hello-world, generates a debug build (debug.out) from hello-world.c
%: %.c
	$(info Generating debug build for $<...)
	$(CC) $< $(CFLAGS) $(LDLIBS) -o $(DEBUG_OUT)

# make release-hello-world, generates a release build (hello-world.out) from hello-world.c
release-%: %.c
	$(info Generating release build for $<...)
	$(CC) $< $(CFLAGS) $(LDLIBS) $(RELEASE_FLAGS) -o $(basename $<).$(EXE_EXT)

# make clean, removes all executables in the current directory
clean:
	$(info Cleaning up the workspace...)
	rm -f *.$(EXE_EXT) */*.$(EXE_EXT)

.PHONY: all run clean
