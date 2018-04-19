# Conway's Game of Life simulator
A programming language project that consists on the implementation of Conway's Game of Life using C++ language.

Even with the word "game" in the name, it's not a iteractive play, instead, it's a simulation which we can observe the behavior of a given *config* of cells.

## Rules of the game
1. If a cell is alive, but the number of nearby cells is **≤ 1**, on next generation it will **die by loneliness**.
2. If a cell is alive and and **4+** nearby cells are alive, on next generation it will **die suffocated**.
3. If an alive cell has 2 ≥ **X** ≥ 3 nearby cells alive, on next generation it will **remain alive**.
4. If a cell is current dead and has **exacly** **3** nearby cells alive, on next generation it will **born**.
5. All the events needs to happen on the exact same time, therefore, cells that are dying can help others to born, but can't prevent the death of others by reducing overpopulation. On the same way, cells that are being born will not help to preserve or kill alive cells on the previous generation.

## Compile and execute

First of all, you need to make sure that have these dependencies installed onto your computer:

+ `g++`
+ `git`

If you're on a debian-based distro (such as ubuntu), you can use the following command to install both:

```bash
sudo apt-get install git g++
```

Then, you can clone this repo. For doing it, type the command:

```bash
git clone https://github.com/FelipeCRamos/conway-simulator.git;
cd conway-simulator
```
And then you can execute `make` to compile the entire program, then `./conway` to run the simulate.



### Authorship

This project was entirely made by Felipe Ramos with MIT license for the discipline of programming language I for the computer science course on [UFRN](http://ufrn.br).

*13/04/2018*
