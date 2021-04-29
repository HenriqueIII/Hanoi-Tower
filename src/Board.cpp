#include "Board.h"
#include "Tetris.h"

Board * Board::instance = 0;

Board::Board() {
    assert(!instance);
    instance = this;
    for (int y = 0; y < HEIGHT; ++y)
        lines[ y ] = new Line;
    // Ultima linha sem nenhum elemento preenchido
    lastline = HEIGHT;
}

bool Board::isFilled( Point loc ) {
    return lines[loc.getY()]->isFilled( loc.getX() );
}

// Caracter bloco
static const wint_t FILL_CHAR = L'\u2588';

void Board::display( Point loc, int col ) {
    // Modificar a cor de escrita para col
    dsp.setForeground( col );
    // Posicionar o cursor
    dsp.setCursor( loc.getX() + Board::X, loc.getY() + Board::Y );
    // Escrever o caracter
    dsp.putc( FILL_CHAR );
    dsp.resetColor();
}

void Board::show() {
    // Desenha os lados
    for ( int y = Y+4; y < HEIGHT; ++y ) {
        dsp.putc(X-2, Y+y, FILL_CHAR, Display::BBLACK);
        dsp.putc(FILL_CHAR);
        dsp.putc(X+WIDTH, Y+y, FILL_CHAR, Display::BBLACK);
        dsp.putc(FILL_CHAR);
    }
    // Desenha o fundo
    dsp.setCursor( X-2, Y+HEIGHT );
    for ( int x = -2; x <= WIDTH+1; ++x)
        dsp.putc( FILL_CHAR );
}

void Board::addBlock( Point p, int color ) {
    lines[p.getY()]->setColor(p.getX(), color);
    if ( p.getY() < lastline )
        lastline = p.getY();
}

bool Board::allLinesOcupated() {
    for (int y = HEIGHT -1; y >= lastline; --y )
        if ( lines[y]->isFilled() )
           deleteLine( y++ );
    return lastline < 4; 
}

void Board::deleteLine( int y ) {
    lines[y]->blink( y );       // Intermitencia da linha
    lines[y]->hide( y );        // Por precaução
    TETRIS->addPoints( 1 );     // Aumenta a pontuação do jogo
    delete lines[y];            // Destroi a linha
    for ( ; y > lastline; --y)  // Desloca as ocupadas
        moveLine( y-1, y );
    lines[y] = new Line;        // Constroi linha vazia nova
    ++lastline;                 // Menos uma linha ocupada
}

void Board::moveLine( int from, int to ) {
    lines[from]->hide( from );
    lines[to] = lines[from];
    lines[to]->show( to );
}