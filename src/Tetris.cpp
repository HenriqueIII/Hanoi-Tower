#include "Tetris.h"
#include "utils/Keyboard.h"
#include "utils/Common.h"
#include "Piece.h"

Tetris * Tetris::instance = 0;

void Tetris::go() {
    // Programar teclado para não esperar actuação de tecla.
    kbd.setMode(Keyboard::VIEW);
    board.show();   // Refrescar a imagem do receptaculo.
    showPoints();   // Actualizar a mensagem de pontuação.
    do
        play();     // Provocar um ciclo de vida de uma peça.
    while ( !isOver() );    // Enquanto for possivel criar peças
    char msg[]="GAME OVER";
    showMessage(msg);
    // Programar teclado para esperar atuação de tecla.
    kbd.setMode( Keyboard::WAIT );
    // Aguardar atuação da tecla Enter
    while ( kbd.get() != 10 );
}

void Tetris::play() {   // Ciclo de vida de uma peça
    Piece piece;        // Objecto local
    piece.show();      // Mostrar a peça no ecrã
    piece.drop();      // Promover queda da peça
    piece.addToBoard();// Adicionar ao receptaculo os blocos constitutivos da peça
}

void Tetris::showMessage( char * msg ){
    dsp.setCursor( Board::X-1, Board::Y+Board::HEIGHT + 2 );
    dsp.setBackground( Display::BLACK );
    dsp.setForeground( Display::WHITE );
    dsp.puts( msg );
}

void Tetris::showPoints() {
    static char str[] = " POINTS = ";
    showMessage( str );
    dsp.puts(Common::itoa(points));
}