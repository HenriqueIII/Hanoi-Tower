#include "Game.h"
#include "utils/DeltaTime.h"
#include <cassert>
#include "Arena.h"
#include "Status.h"

Game * Game::instance = new Game;

bool Game::endGame() const{
    return kbd.getLast()==27 || snake.isDead() || mice.noMore();
}
Game::Game(){
    assert(!instance);
    instance = this;
}
void Game::play(){
    // Tempo de um ciclo
    const float SECONDS_PER_MOVE=0.4F;
    // Definir temporizador
    DeltaTime timer(SECONDS_PER_MOVE);
    // Definir kbd em modo view
    kbd.setMode(Keyboard::VIEW);
    STATUS->show();
    ARENA->show();
    snake.show();
    mice.show();
    do{
        // Inicia a contagem de tempo
        timer.start();
        // Movimento unitário da cobra
        snake.move();
        // Aguardar fim de tempo
        timer.wait();
    }while(!endGame());
    // Mensagem fim de jogo
    STATUS->showAndWait("Game Over");
}
Game * Game::getInstance(){
    assert(instance!=NULL);
    return instance;
}
Mouse * Game::getMouse(){
    return &mice;
}