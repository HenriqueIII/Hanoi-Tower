#ifndef POST_H
#define POST_H

#include "StackDisk.h"
#include "Disk.h"

class Post {
    StackDisk st;                   // Stack de apontadores para disco.
    Rect r;                         // Area ocupada pela estaca
    int color;                      // Cor da Estaca
public:
    enum {
        // Altura da base das estacas.
        BASE_HEIGHT = ( Display::MAX_Y*1/10 ),
        // Coordenada Y do inicio dos postes
        BOTTOM = Display::MAX_Y-BASE_HEIGHT,
        // Altura de cada poste.
        HEIGHT = Disk::MAX_DISKS*Disk::HEIGHT+1,
        // Espessura do poste ( deve ser impar )
        WIDTH = POST_WIDTH
    };
    
    Post (int disks, int n, int col ) :
    r( n-WIDTH/2, BOTTOM-HEIGHT, n+WIDTH/2, BOTTOM),
    st ( disks ),
    color( col )
    {
    }

    void show() const {
        r.show( color );
        st.show();
    }
    int getX() const {
        return r.left+WIDTH/2;
    }
    void push( Disk * p ) {
        st.push( p );
    }
    int getNDisk() const {
        return st.numOfDisks();
    }
    Disk * pop() {
        //return st.pop();
        return st.pop();
    }
    void showSegment( Rect seg ) const {
        seg.intersect( r ).show( color );
    }
    void showMove( Post & dest );
};
#endif