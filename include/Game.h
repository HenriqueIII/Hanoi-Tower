#ifndef GAME_H
#define GAME_H

#include "Post.h"
#include "Disk.h"

const int NUMDISKSDEFAULT = Disk::MAX_DISKS;

class Game{
    int numDisks;               // Numero de discos
    bool exit;                  // Flag que assinala o fim da animação
    Post postA, postB, postC;   // As 3 estacas
    // Algoritmo recursivo que satisfaz as condições do
    // problema quanto à movimentação óptima dos discos.
    void hanoi( int n, Post & orig, Post & dest, Post & aux );
public:
    enum Colors {
        LIGHT = 8,  // Para converter em lightcolor.
        ARENA_COLOR = Display::BBLUE,
        BASE_COLOR = Display::BLACK,
        BASE_HEIGHT = Post::BASE_HEIGHT
    };
    Game( int disks );
    void play(); // Unico método publico invocado em main()
};

#endif