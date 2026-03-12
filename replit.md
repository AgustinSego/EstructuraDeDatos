# C Lab: Lists and Stacks (Listas y Pilas)

## Project Overview
A C programming lab exercise focused on implementing list (ArrayList) and stack data structures. Students complete exercises in `exercises.c`.

## Project Structure
- `exercises.c` — Student code (the only file students should modify)
- `arraylist.h` / `arraylist.c` — ArrayList TDA implementation
- `stack.h` — Stack TDA interface
- `test.c` — Test suite
- `test.sh` — Script to compile and run tests

## How to Run
Open the Shell and run:
```bash
bash test.sh
```

The workflow "Start application" also runs `bash test.sh` automatically.

## Language & Build
- Language: C (GCC 14.3.0)
- Build: `gcc -g test.c -Wall -Werror -o a.out`
- No package manager or dependencies needed

## Notes
- Only `exercises.c` should be modified by students
- No web frontend or backend — this is a CLI/terminal project
