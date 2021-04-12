//#include "Disk.h"
#include "Game.h"
#include <cmath>
#include "utils/DeltaTime.h"

void Disk::move( Post * src, Post * dst) {
    // Desloca disco na vertical ascendente
    moveTo( Point( src->getX(), FLY_Y ), src );
    // Desloca disco na horizontal
    moveTo( Point( dst->getX(), FLY_Y ), NULL );
    // Desloca o disco na vertical descendente
    const int base = Post::BOTTOM - ( HEIGHT )/2;
    Point p( dst->getX(), base-dst->getNDisk()*HEIGHT );
    moveTo( p, dst );
}
void Disk::moveTo( Point dest, Post * p ) {
    Point center = r.getCenter();           // Coordenada de origem
    Point delta( 0,0 );                     // Deslocamento unitário
    int iter;
    if ( center.getX() != dest.getX() ) {   // Deslocamento horizontal
        delta.setX( center.getX() > dest.getX() ? -1 : +1 );
        iter = abs( dest.getX()-center.getX() );
    } else {                                // Deslocamento vertical
        delta.setY( center.getY() > dest.getY() ? -1 : +1 );
        iter = abs( dest.getY() - center.getY() );
    }
    static const float SEC_PER_PULL = 0.016F;
    DeltaTime t( SEC_PER_PULL );            // Tempo por deslocamento
    while ( iter-- ) {
        t.start();
        pull( delta, p );                   // Deslocamento unitario
        t.wait();
    }
     

}
void Disk::pull( const Point & delta, Post * p ){
    Rect aux = r;                           // Guarda o rectangulo anterior
    r.addEqual( delta );                    // Desloca o actual
    Rect toHide = aux.intersectNot( r );    // Area de onde saiu
    toHide.show ( Game::ARENA_COLOR );
    if ( p )
        p->showSegment( toHide );           // Mostra poste
    r.intersectNot(aux).show( color );      // Area nova ocupada
}