#ifndef BOARD_H
#define BOARD_H

#include "utils/Display.h"
#include "utils/Point.h"
#include "Line.h"
#include <cassert>

class Board {
    // Apontador para singleton
    static Board * instance;
public:
    enum {
        HEIGHT = 20+4, WIDTH = Line::WIDTH,
        X = ( Display::MAX_X - WIDTH ) / 2,     // Abcissa do Board
        Y = 1,//( Display::MAX_Y - HEIGHT ) / 2,    // Ordenada do Board
        COLOR = Display::BLACK
    };
private:
    // Ultima linha que contem algum bloco
    int lastline;
    // Array de apontadores para linhas
    Line * lines[HEIGHT];
    // Colorir uma célula caracter do ecra
    static void display( Point pos, int color );
    // Remover e destruir a linha da coordenada y.
    void deleteLine( int y );
    // Deslocar uma linha de from para to
    void moveLine( int from, int to );
public:
    Board();
    void addBlock( Point p, int color );
    bool allLinesOcupated();
    void show();
    bool isFilled( Point loc );
    static void showBlock( Point pos, int color ){
        display( pos, color );
    }
    static void hideBlock( Point pos ) {
        display( pos, Board::COLOR );
    }
    // Devolve o apontador para objecto solitário
    static Board * getInstance(){
        assert(instance);
        return instance;
    }
};

#define BOARD Board::getInstance()

#endif