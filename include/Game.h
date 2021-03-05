#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Mouse.h"
#include "Arena.h"
#include "Status.h"

class Game{
    Arena arena;
    Status status;
    Snake snake;
    Mouse mice;

    // Testa se ocorreu condição terminal do jogo.
    bool endGame() const;
    // Instancia do objecto singleton de game
    static Game * instance;
public:
    Game();
    void play();
    Mouse * getMouse();
    static Game * getInstance();
};

#define GAME Game::getInstance()

#endif