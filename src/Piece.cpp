#include "Piece.h"
#include "utils/Display.h"
#include "utils/Random.h"
#include "utils/DeltaTime.h"
#include "utils/Keyboard.h"
#include "Tetris.h"
#include "Board.h"

Piece::Piece( int col, Point b1, Point b2, Point b3 ):
base( Board::WIDTH/2, 2 ), color( col )
{
    relative[0] = Point( 0,0 );
    relative[1] = b1;
    relative[2] = b2;
    relative[3] = b3;
}

static Piece pieces[ Piece::MAX_PIECES ] = {
    Piece( Display::BYELLOW, Point( -1,0 ), Point( 1,0 ), Point( 0,1 ) ),   // T
    Piece( Display::BCYAN, Point( 0,1 ), Point( -1,0 ), Point( -1,1 ) ),    // SQUARE
    Piece( Display::BMAGENTA, Point( 0,1 ), Point( -1,-1 ), Point( -1,0 ) ),// S
    Piece( Display::BGREEN, Point( 0,1 ), Point( 0,1 ), Point( 1,-1 ) ),    // Z
    Piece( Display::BRED, Point( 0,-1 ), Point( 0,1 ), Point( 0,2 ) ),      // Line
    Piece( Display::BWHITE, Point( 0,1 ), Point( 0,-1 ), Point( -1,-1 ) ),  // LINVERT
    Piece( Display::BBLUE, Point( 0,1 ), Point( 0,-1 ), Point( 1,-1 ) ),    // L 
};

Piece::Piece() {
    Random::init();
    *this = ::pieces[ Random::get( MAX_PIECES )];
}

bool Piece::validPosition( Point p ) {
    return (p.getX() >= 0 && p.getX() < Board::WIDTH && p.getY() < Board::HEIGHT && ! BOARD->isFilled( p ));
}

bool Piece::canRotate() {
    Point p;
    for (int i=0; i < MAX_BLOCKS; ++i) {
        p = relative[i];    // Posição Relativa
        if ( !validPosition( base.add ( p.rotateRight() ) ))
            return false;
    }
    return true;
}

void Piece::rotate() {
    hide();
    for (int i = 0; i < MAX_BLOCKS; ++i)
        relative[i].rotateRight();
    show();
}

void Piece::moveBy( Point delta ) {
    hide();
    base.addEqual( delta );
    show();
}

bool Piece::canMoveBy( Point delta ) {
    Point newBase = base.add( delta );
    for ( int i=0; i < MAX_BLOCKS; ++i)
        if( !validPosition( newBase.add( relative[i] ) ) )
            return false;
    return true;
}

void Piece::show() {
    for (int i=0; i<MAX_BLOCKS; ++i)
        Board::showBlock( base.add( relative[i] ), color );
}

void Piece::hide() {
    for (int i=0; i<MAX_BLOCKS; ++i)
        Board::hideBlock( base.add( relative[i] ) );
}

void Piece::addToBoard() {
    for (int i=0; i<MAX_BLOCKS; ++i)
        BOARD->addBlock( base.add( relative[i] ), color );
}

// Tempo de descida de um degrau (altura caracter)
static const float SECONDS_BY_MOVE = 0.6;

void Piece::drop() {
    DeltaTime gap( SECONDS_BY_MOVE );   // Cronometro
    bool flag = true;

    while( canMoveDown() ) {            // Enquanto for possivel descer
        if ( flag )
            gap.start();                // Iniciar contagem de tempo
        do {
            int key = kbd.get();        // Testar o teclado
            // Executar a acção correspondente a tecla
            switch( key ) {
                case SHIFT_LEFT:        tryMoveLeft();  break;
                case SHIFT_RIGHT:       tryMoveRight(); break;
                case ROTATE:            tryRotate();    break;
                case TERMINATE:         TETRIS->exit(); return;
                case DROP_DOWN:         flag = false;   break;
                default: break;
            }
        // Enquanto o tempo determinado por gap não se
        // Esgotar e não foi actuada a tecla space
        } while( flag && !gap.dttimeout() );
        tryMoveDown();
    }
}