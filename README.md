# Snake Game
A simple snakes game made with game library created in the chapter 6 of *Programação em C++ - Conceitos Básicos e Algoritmos* by *Pimenta Rodrigues, Pedro Pereira e Manuela Sousa*.

## Intro
This game consists in the emulation in screen, text mode(TUI), of the movement of a snake **####O** within a arena, mouses **@** that appear in random places and obstacles that difficult the snake movement and are fatal if it colides with them.

The **####O** has a predefined dimension and grows eating the **@**.

The goal of this game is to eat as many **@** as you can in order to get more points.

## Rules

* The **####O** moves at a constant speed, in the direction of the last key pressed.
* The border of the arena is made of obstacles.
* As you eat a **@**, another one spawns in some random place within the limits of the arena.
* The game ends if you collide with an obstacle or with the snake itself.

## Movements
You play using the following controls:
```
Up arrow    -> moves up
Down arrow  -> moves down
Left arrow  -> moves left
Right arrow -> moves right
ESC key     -> Quit
```
## Dependencies for compiling
Linux - Ubuntu
```
sudo apt install g++
sudo apt install libncurses5-dev libncursesw5-dev
```
For windows users you just need MinGW32

## Compiling

```
git clone https://github.com/HenriqueIII/Snake-Game.git
cd Snake-Game
make
```
## Download
Download at: (choose the version to your os)
> https://github.com/HenriqueIII/Snake-Game/releases/latest

## Start
```
bin/main
```
## Questions
If you have any question about the code, or some improvements please contact me at:
> paulogoncalves.m@gmail.com
