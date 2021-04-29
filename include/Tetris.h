#ifndef TETRIS_H
#define TETRIS_H

#include <cassert>
#include "utils/Display.h"
#include "Board.h"



class Tetris{
    static Tetris * instance;   // Singleton
    Board board;                // Receptaculo de blocos
    int points;                 // Pontuação do Jogador
    bool end;                   // Flag de fim de jogo
    void play();                // Ciclo de vida de uma peça
    void showMessage( char * msg );
    void showPoints();
    bool isOver() {
        return end || board.allLinesOcupated();
    }
public:
    static Tetris * getInstance() { // Singleton
        assert(instance);
        return instance;
    }
    // Pontuação a zero. Flag fim de jogo iniciada a false
    Tetris(): points( 0 ), end( false ) {
        assert(!instance);
        instance = this;
        dsp.resizeWin();
    }
    // Sequencia completa de ações que decorrem desde
    // o inicio até ao fim de um jogo
    void go();
    // Apenas usado por Board
    void addPoints( int val ) {
        points += val;
        showPoints();
    }
    // Apenas usado por Piece
    void exit() {
        end = true;
    }
};

#define TETRIS Tetris::getInstance()

#endif