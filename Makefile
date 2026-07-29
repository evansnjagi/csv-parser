# Compiler and flags
CC = gcc
CFLAGS = -Wall -I include/
LIBS = -lm

# Target
all: csv-parser

# Link everything together
csv-parser: src/main.c src/stats.c src/parser.c 
	$(CC) $(CFLAGS) src/main.c src/stats.c src/parser.c -o csv-parser $(LIBS)

# Clean compiled files
clean:
	rm -f csv-parser