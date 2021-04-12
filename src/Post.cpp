#include "Post.h"

void Post::showMove( Post & dest ) {
    Disk * d = pop();           // Remove o disco da estaca origem.
    d->move( this, &dest );     // Desloca visualmente o disco.
    dest.push( d );             // Insere o disco na estaca destino
}