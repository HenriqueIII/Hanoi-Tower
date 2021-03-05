#ifndef KEYBOARD_H
#define KEYBOARD_H

enum Keys{
    KEY_NONE = 0,
};

class Keyboard{
public:
    enum KeyAcess{WAIT,VIEW};
private:
    KeyAcess mode;
    int last;
public:
    Keyboard(); //Fica em modo WAIT.
    void setMode(KeyAcess m);
    int getLast();
    int get();
};

extern Keyboard kbd;

#endif