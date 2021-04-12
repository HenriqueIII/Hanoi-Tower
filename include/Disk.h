#ifndef DISK_H
#define DISK_H

#include "utils/Rect.h"
#include "utils/Display.h"
#include "consts.h"

class Post;

// Valor impar igual ou imediatamente inferior ao indicado.
#define ODD_DOWN( x ) ( ( x ) - ( ( x )%2==0 ) ) // Macro-instrução
// Valor menor dos dois indicados.
#define MIN( x,y ) ( ( x ) > ( y ) ? ( y ) : ( x ) ) // Macro instrução

class Disk {
    int number;     // De 0 a MAX_DISKS-1
    int color;      // De 2 (GREEN) a 7 (WHITE)
    Rect r;         // Area de ecra onde o disco se situa
    // Promover um deslocamento delta sobre o poste p.
    void pull( const Point & delta, Post * p );
    // Mover até à coordenada dest sobre o poste p.
    void moveTo( Point dest, Post * p );
public:
    enum {
        // Maior diâmetro dos discos.
        BIGGER_WIDTH =  ODD_DOWN( ( Display::MAX_X-4 )/3 ),
        // Altura de cada disco.
        HEIGHT = DISK_HEIGHT,
        // Numero máximo de discos
        MAX_DISKS = MIN( ( Display::MAX_Y*4/5 ) / HEIGHT, ( BIGGER_WIDTH-POST_WIDTH-2 ) /2 ),
        // Até onde os discos sobem em altura.
        FLY_Y = HEIGHT/2
    };
    Disk( int num, const Point & pos ) : 
    number( num ),
    color( num % 6+2 ),
    r (pos, HEIGHT, BIGGER_WIDTH-num*2){}
    // Mostrar o disco.
    void show() {
        r.show( color );
    }
    // Mover o disco desde a estaca src até à dst
    void move ( Post * src, Post * dst );
};

#endif