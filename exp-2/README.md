# DDA Line Algorithm

## Introduction
Implementation of the DDA line drawing algorithm in c using the BGI api. The Borderland Graphics Interface (BGI) was used for graphics drawing in DOS using the Turbo C/C++ compiler. In this program I'm using a BGI api build on top of SDL2. The library used has been linked in the references.

## Build Steps
```sh
gcc main.c -o main -Wall -Wextra -lSDL_bgi -lSDL2 -lm
```
The `-Wall` and `-Wextra` flags are used to display warnings. Useful for debugging.

`-lSDL_bgi` and `-lSDL2` are used to link the SDL library along with the BGI graphics interface.

The `-lm` flag is used to link the `math.h` c library.

```sh
./main
```

## References
[https://github.com/sergev/SDL_bgi](https://github.com/sergev/SDL_bgi)