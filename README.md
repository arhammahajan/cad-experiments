# CAD Lab Experiments
This repository contains all the code for the various experiments performed in the lab of CAD (MEMEC601) at NSUT, Delhi.

## Setting up build environment
The recommended tool for these experiemnts as given in the lab manual is `graphics.h` (Borderland Graphics Interface). BGI was orignally written for DOS systems using the Turbo C/C++ compiler. It was the simplest way to implement presentation graphics in C programs. While, there are no official ways of running BGI on modern machines, many community projects make it possible.

### Setting up on linux
While there are many ways of running `grahpics.h` on c, I am highlighting the way that i used. 

I was able to run BGI on linux using the amazing [SDL_bgi library](https://sdl-bgi.sourceforge.io/). This library provides the BGI graphics api on top of SDL2 or SDL3. In simple words, any `graphics.h` programs written in c will call underlying SDL functions. With that out of the way, let me preface by saying this method was very easy to get working. Install instructions have been provided along with prebuilt binaries for some OSs. Refer to the website for the same.

Once you have written a code, you can compile and run it by the following:
```sh
gcc main.c -o main -Wall -Wextra -lSDL_bgi -lSDL2 -lm
```
The `-Wall` and `-Wextra` flags are used to display warnings. Useful for debugging.

`-lSDL_bgi` and `-lSDL2` are used to link the SDL library along with the BGI graphics interface.

The `-lm` flag is used to link the `math.h` c library.

```sh
./main
```