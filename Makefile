# Determine the preferred compiler
CC := $(if $(shell command -v clang 2> /dev/null),clang,gcc)
CFLAGS := -Wall -Wextra -pedantic

ifdef TARGET
    # If defined, print its value
    $(info Building $(TARGET)...)
else
    # If not defined, print a message
    $(info TARGET is not defined)
endif

# Determine the platform
ifeq ($(OS),Windows_NT)
	PLATFORM := windows
	EXECUTABLE_EXT := .exe
else
	PLATFORM := linux
	EXECUTABLE_EXT := .out
endif

# Default target
all: $(TARGET)$(EXECUTABLE_EXT)

$(TARGET)$(EXECUTABLE_EXT): $(TARGET).c
	$(CC) $(CFLAGS) -o $@ $<

run: $(TARGET)$(EXECUTABLE_EXT)
	./$(TARGET)$(EXECUTABLE_EXT)

clean:
	rm -f *$(EXECUTABLE_EXT)

.PHONY: all run clean
