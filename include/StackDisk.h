#ifndef STACKDISK_H
#define STACKDISK_H

class Disk;

class StackDisk {
    // Apontador para o array de apontadores para discos.
    Disk ** data;
    // Numero de apontadores presentes no stack.
    int n;
public:
    // Criar um stack com a dimensão máxima indicada em len.
    StackDisk( int len ) {
        n = 0;
        data = new Disk * [ len ];
    }
    // O destrutor, devolve o espaço ocupado pelo stack.
    ~StackDisk() {
        delete [] data;
    }
    // Insere apontador c no topo do stack
    void push ( Disk * c ) {
        data[ n++ ] = c;
    }
    // Remove e retorna apontador contido no topo de stack.
    Disk * pop() {
        return data[ --n ];
    }
    // Retorna sem remover o apontador situado no topo.
    Disk * top() const {
        return data[ n-1 ];
    }
    // Mostra os discos contidos no stack.
    void show() const;
    // Indica quantos discos tem o stack.
    int numOfDisks() const {
        return n;
    }
};

#endif