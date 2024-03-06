# Compiler and flags
CC = g++
CFLAGS = -Wall -Wextra -I$(INC_DIR)

# Directories
INC_DIR = ./

# Source files
SRCS = CalculationFactory.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

# Executable name
BINS = calculation

# Dependencies
DEPS = $(INC_DIR)/*.hpp

# Default target
all: $(BINS)

# Build target
calculation: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	rm -f $(OBJS)

# Compile source files to object
%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean up
clean:
	rm -f calculation $(OBJS)

