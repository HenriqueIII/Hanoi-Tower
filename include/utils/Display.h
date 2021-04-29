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
    // Returna se é bright ou nao
    int is_bold(int fg);
    
public:
    enum {
        // Cores escuras
        BLACK=0,RED,GREEN,YELLOW,BLUE,MAGENTA,CYAN,WHITE,
        // Cores claras
        BBLACK=8,BRED,BGREEN,BYELLOW,BBLUE,BMAGENTA,BCYAN,BWHITE
    };
    enum {MIN_X=0,MIN_Y=0,MAX_X=79,MAX_Y=30};
    // Programar a carta de video em modo texto 80x24, 8 cores e ocultar o cursor.
    Display();
    // Repoe as cores e retira o bold
    void resetColor();
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
    void putc(wint_t chr);
    // Escrever o caracter chr no ponto de coordenadas (x,y) com a cor col.
    void putc(int x, int y, int chr, int col = WHITE);
    void putc(int x, int y, wint_t chr, int col = WHITE);
    // Escrever a string str com inicio na posição corrente do cursor.
    void puts(const char * str);
    // Escrever o buffer com inicio na posição corrente do cursor.
    void puts(const wint_t * buffer);
    // Limpar a window
    void windowClear();
    // Retorna um ponteiro para my_win
    WINDOW * getWindow(){
        return my_win;
    }
    ~Display();
    void resizeWin(){
        wclear(my_win);
        clear();
        wresize(my_win, MAX_Y, MAX_X);
        mvwin(my_win, (LINES - MAX_Y+1)/2 , (COLS - MAX_X+1)/2);
        refresh();
        wrefresh(my_win);
    }
};

extern Display dsp;

#endif
