#ifndef DISPLAY_H
#define DISPLAY_H
#include <curses.h>

class Display{
    int foreground, background;
    WINDOW * my_win;
    // Iniciar os pares das cores.
    void initColor();
    // Converte numeros para cores do curses
    short curs_color(int fg);
    // Converte num número previsivel de par de cor
    int colornum(int fg, int bg);
public:
    enum {
        // Cores escuras
        BLACK=0,RED,GREEN,YELLOW,BLUE,MAGENTA,CYAN,WHITE,
        // Cores claras
        BBLACK=8,BRED,BGREEN,BYELLOW,BBLUE,BMAGENTA,BCYAN,BWHITE
    };
    enum {MIN_X=0,MIN_Y=0,MAX_X=48,MAX_Y=23};
    // Programar a carta de video em modo texto 80x24, 8 cores e ocultar o cursor.
    Display();
    // Alterar a cor dos caracteres a escrever, para uma das 16 cores disponiveis.
    void setForeground(int color);
    // Alterar a cor de fundo dos caracteres, para uma das 16 cores disponiveis.
    void setBackground(int color);
    // Ocultar cursor.
    void cursorOff();
    // Mostrar cursor.
    void cursorOn();
    // Posicionar o cursor no ponto do ecrã de coordenadas (x,y).
    void setCursor(int x, int y);
    // Escrever o caracter chr na posição corrente do cursor.
    void putc(int chr);
    // Escrever o caracter chr no ponto de coordenadas (x,y) com a cor col.
    void putc(int x, int y, int chr, int col = WHITE);
    // Escrever a string str com inicio na posição corrente do cursor.
    void puts(const char * str);
    // Limpar a window
    void windowClear();
    // Retorna um ponteiro para my_win
    WINDOW * getWindow(){
        return my_win;
    }
    ~Display();
};

extern Display dsp;

#endif