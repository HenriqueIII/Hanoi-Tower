#ifndef PIECE_H
#define PIECE_H

#include "utils/Point.h"

class Piece {
public:
    enum {
        MAX_BLOCKS = 4, MAX_PIECES = 7,
        SHIFT_LEFT = 'i', SHIFT_RIGHT = 'p',
        ROTATE = 'o', TERMINATE = 27,
        DROP_DOWN = 32
    };
private:
    Point base; // Coordenadas do bloco de referência.
    int color;  // Cor da peça
    // Coordenadas dos quatro blocos relativas à base
    Point relative[ MAX_BLOCKS ];
    // Metodos Basicos
    void hide();                // Ocultar a peça.
    void rotate();              // Promove a rotação
    void moveBy( Point delta ); // Desloca de delta
    // Metodos de teste
    bool validPosition( Point p );  // Testa se p livre
    bool canRotate();               // Testa se pode rodar
    bool canMoveBy( Point delta );  // Testa se pode deslocar-se
    // Testar se pode mover-se para baixo
    bool canMoveDown() {
        return canMoveBy( Point( 0,1 ));
    }
    // Metodos de acções condicionantes por teste
    void tryRotate(){
        if (canRotate())
            rotate();
    }
    void tryMoveBy( Point delta ) {
        if( canMoveBy( delta ) )
            moveBy( delta );
    }
    void tryMoveLeft() {
        tryMoveBy( Point( -1,0 ) );
    }
    void tryMoveRight() {
        tryMoveBy( Point( 1,0 ) );
    }
    void tryMoveDown() {
        tryMoveBy( Point( 0,1 ) );
    }
public:
    // Para construir as peças modelo
    Piece( int color, Point b1, Point b2, Point b3 );
    Piece();            // Constroi uma peça aleatória.
    void show();        // Mostra a peça no ecrã.
    void addToBoard();  // Adiciona os blocos ao board
    void drop();        // Executa o ciclo de queda
};

#endif
