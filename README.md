*This project has been created as part of the 42 curriculum by ewaltz*.

## Description

`get_next_line` implements a function that returns the next line read from a given file descriptor.  
A “line” is defined as a sequence of characters ending with `\n` (included in the returned string) or ending at EOF.

This project focuses on:
- low-level I/O with `read()`,
- dynamic memory allocation,
- handling partial reads and buffering,
- (bonus) handling multiple file descriptors simultaneously.

## Instructions

### Requirements
- A C compiler (clang or gcc)
- The project must be compiled following the subject rules (flags and defines).

### Compile (mandatory)
Compile your `get_next_line.c` and `get_next_line_utils.c` with your tester / main:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
  get_next_line.c get_next_line_utils.c main.c -o gnl
````

### Run (mandatory)

```bash
./gnl txt/multi.txt
```

### Compile (bonus: multiple file descriptors)

To test reading from multiple fds interleaved, compile the bonus version:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
  get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus
```

### Run (bonus)

The provided `main.c` supports an interleaving test with two files:

```bash
./gnl_bonus txt/multi.txt txt/mix.txt
```

### Test files

The repository contains a `txt/` folder with various edge cases:

* empty file
* no trailing newline
* only newlines
* long lines (much larger than `BUFFER_SIZE`)
* many small lines
* mixed content

## Algorithm Explanation and Justification

The function keeps a “rest” string that stores unread leftover data between calls.

1. **Buffered reading**
   Read `BUFFER_SIZE` bytes at a time into a temporary buffer using `read()`.

2. **Accumulate into rest**
   Append the newly read chunk to `rest` until:

   * a newline `\n` is found in `rest`, or
   * EOF is reached.

3. **Extract the line**

   * If a newline exists, return `rest[0..newline]`.
   * Otherwise (EOF), return the remaining `rest` as the last line.

4. **Update rest**
   Keep the substring after the extracted line as the new `rest`. If nothing remains, set it to `NULL`.

5. **Bonus: multiple file descriptors**
   Use one static array `rest[1024]` so each file descriptor has its own independent buffer state, allowing interleaved calls without mixing data.

This approach is simple, efficient (reads in fixed-size chunks), and matches the project constraints while keeping memory usage under control.

## Resources

* `man read`

## AI Usage

AI was used for:

* drafting this `README.md`,
* understanding how static variables behave in C (persistence across function calls, and the rationale behind using a static array for the bonus multi-fd requirement).

No AI-generated code was used to implement `get_next_line`.

```
```

