# CSV Parser & Statistical Engine
A command-line data analysis tool written in C that reads a CSV file
and computes summary statistics. Built as a capstone project to
consolidate core C programming concepts.

---

## What This Project Does
- Reads a CSV file containing student records
- Parses each row into a structured data type
- Computes the following statistics:
  - Mean score
  - Maximum score
  - Minimum score
  - Standard deviation

---

## Project Structure
```bash
csv-parser
├── Makefile
├── README.md
├── csv-parser
├── data
│   └── students.csv
├── include
│   ├── parser.h
│   └── stats.h
├── src
│   ├── main.c
│   ├── parser.c
│   └── stats.c
└── tests
```
---

## How to Build and Run

### Build
```bash
make
```

### Run
```bash
./csv-parser
```

### Clean compiled files
```bash
make clean
```

---

## Makefile Reference
This is my personal reference for Makefile commands.

### Full Makefile explained line by line
```makefile
# Compiler and flags
CC = gcc                        # compiler to use
CFLAGS = -Wall -I include/      # -Wall: show all warnings
                                # -I include/: where to find headers
LIBS = -lm                      # link math library for sqrt()

# Default target — what 'make' builds
all: csv-parser

# Build rule — link all source files into one binary
csv-parser: src/main.c src/parser.c src/stats.c
	$(CC) $(CFLAGS) src/main.c src/parser.c src/stats.c -o csv-parser $(LIBS)

# Clean rule — remove compiled binary
clean:
	rm -f csv-parser
```

### Key Makefile concepts
| Term | Meaning |
|---|---|
| `CC` | The compiler (gcc) |
| `CFLAGS` | Compiler flags — extra instructions for gcc |
| `LIBS` | Libraries to link at the end |
| `all` | Default target — runs when you type `make` |
| `clean` | Removes compiled files — type `make clean` |
| `$(CC)` | References the CC variable — expands to `gcc` |
| `-Wall` | Show all compiler warnings — always use this |
| `-I include/` | Tell gcc where header files live |
| `-lm` | Link math library — needed for sqrt() |
| `-o csv-parser` | Name the output binary `csv-parser` |

---

## Concepts I Struggled With and How I Understood Them

### 1. Pointers
**What confused me:** I initially thought dereferencing meant
copying a value. I confused `*ptr` with `ptr`.

**How I understood it:**
- `ptr` = the address (house number on a street)
- `*ptr` = the value at that address (what's inside the house)
- `&age` = give me the address of age

**The moment it clicked:** When I modified `age` through `*ptr`
and saw `age` change without touching it directly.

### 2. File I/O
**What confused me:** Why `FILE *fp` exists and why we never
dereference it directly like other pointers.

**How I understood it:** `FILE *fp` is a special pointer to a
complex internal structure. C gives you dedicated functions
(fprintf, fscanf, fclose) to interact with it — like a steering
wheel instead of reaching into the engine directly.

### 3. CSV Parsing with fscanf
**What confused me:** The format string `%49[^,]` looked like
random characters.

**How I understood it:**
- `%49` = read maximum 49 characters (leave 1 for `\0`)
- `[^,]` = read everything EXCEPT a comma
- Together: read a field up to the next comma

**The bug I fixed:** I forgot to include commas between format
specifiers in fscanf — so it read zero rows. Adding debug prints
helped me find it.

### 4. Header Guards
**What confused me:** Why three lines just to include a file?

**How I understood it:** Without guards, including the same header
twice causes duplicate definition errors. The guard checks if the
header was already included and skips it if so.

```c
#ifndef STATS_H    // if STATS_H not defined yet
#define STATS_H    // define it now
...                // header content
#endif             // end of guard
```

---

## Git Workflow Reference
```bash
git status                    # check what has changed
git add filename.c            # stage one file
git add .                     # stage everything
git commit -m "message"       # save a snapshot
git push origin main          # push to GitHub
git log --oneline             # see commit history
git diff                      # see what changed
```

---

## Author
**Evans Njagi**
MSc. Data Science — Year 1, Semester 1

GitHub: github.com/evansnjagi