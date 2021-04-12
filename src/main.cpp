#include "Game.h"
#include "utils/Common.h"
#include "cstdlib"

int main( int argc, char ** argv ) {
    int disks = 0;
    // Se for indicado o número de discos converter em inteiro
    if ( argc > 1 )
        disks = atoi( argv[1] );
    // Validar o número de discos.
    if ( disks < 1 || disks > Disk::MAX_DISKS )
        disks = NUMDISKSDEFAULT;
    // Criar um jogo e resolve-lo
    Game game(disks);
    game.play();
    return 0;
}