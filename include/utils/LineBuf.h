#ifndef LINEBUF_H
#define LINEBUF_H

#include <cstring>
#include "Display.h"

// Caracter Bloco
static const wint_t FILL_CHAR = L'\u2588';

class LineBuf{
    enum{MAX_BUF = Display::MAX_X - Display::MIN_X + 1};
    wint_t mem[MAX_BUF+1];
public:
    LineBuf();
    void set (int idx, wint_t val);
    wint_t * getPtr();
};

#endif