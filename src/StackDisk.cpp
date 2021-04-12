#include "Disk.h"
#include "StackDisk.h"

// Mostra os discos apontados pelos apontadores no stack.
void StackDisk::show() const {
    for ( int i = 0 ; i < n ; ++i){
        data[i]->show();
    }
}