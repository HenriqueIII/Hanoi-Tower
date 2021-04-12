#include "Game.h"
#include "utils/Keyboard.h"
#include "utils/Display.h"

#define POS_X_POST(i) (((Display::MAX_X-1)*(i*2+1))/6)

Game::Game( int ndisks ):
postA( ndisks, POS_X_POST( 0 ), dsp.BLACK ),
postB( ndisks, POS_X_POST( 1 ), dsp.WHITE ),
postC( ndisks, POS_X_POST( 2 ), dsp.RED ),
numDisks( ndisks ),
exit( false )   // flag de interrupção da animação
{   // Cria os discos e insere-os na estaca A
    Point pos( postA.getX(), (Post::BOTTOM)-(Disk::HEIGHT-1)/2 );
    for ( int i=0; i<numDisks; ++i ) {
        postA.push( new Disk( i,pos ) );
        pos.setY( pos.getY()-Disk::HEIGHT );
    }
}

void Game::play() {
    dsp.windowClear();
    Point lt( dsp.MIN_X, dsp.MIN_Y );   // left top
    Point rb( dsp.MAX_X, dsp.MAX_Y );   // right Bottom
    // Mostrar um rectangulo que ocupa todo o ecrã
    Rect(lt, rb).show(ARENA_COLOR);
    // Mostrar o rectangulo que forma a base das estacas
    Rect base( lt.getX(), rb.getY()-BASE_HEIGHT+1, rb.getX(), rb.getY() );
    base.show( BASE_COLOR );
    // Mostrar os postes.
    postA.show();
    postB.show();
    postC.show();
    // Esperar a tecla Enter para iniciar animação
    kbd.get();
    // Colocar o teclado com get() não bloqueante
    kbd.setMode(Keyboard::VIEW);
    // Animação: Mover numDisks da estaca postA para a
    // postB usando postC como auxiliar.
    hanoi(numDisks,postA, postB, postC);
    // A flag exit fica a true, se for actuada qualquer
    // tecla durante a execução de hanoi()
    while (!exit && kbd.get() != 10);
}

void Game::hanoi( int n, Post & orig, Post & dest, Post & aux ) {
    // Se uma tecla foi ou está premida terminar
    if (exit || kbd.get() != KEY_NONE) {
        exit = true;
        return;
    }
    if ( n==1 )
        orig.showMove( dest ); // Movimentar de orig para dest
    else {
        hanoi( n-1, orig, aux, dest );
        hanoi( 1, orig, dest, aux );
        hanoi( n-1, aux, dest, orig );
    }
}