#ifndef LINE_H
#define LINE_H

class Line {
public:
    enum {
        NONE = -1,          // Cor ficticia para inexistência de bloco
        WIDTH = 20,         // Número de células da linha
        // Número de intermitencias de visibilidade a provocar na linha a remover
        BLINK_DELETE = 10   
    };
private:
    int line[WIDTH];        // Cores dos blocos desta linha.
public:
    Line();
    void setColor( int x, int color ) {
        line[x] = color;
    }
    bool isFilled( int x ) {
        return line[x] != NONE;
    }
    void blink( int y );
    void show( int y );
    void hide( int y );
    bool isFilled();
};
    
#endif