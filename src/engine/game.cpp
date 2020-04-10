#include "game.h"
#include<raylib.h>
Game::Game(const char* name)
    : GameObject(name), _isPaused(false)
{
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(800, 600, this->get_name().c_str());

}

bool Game::get_paused() {
    return this->_isPaused;
}

void Game::set_paused(bool value) {
    this->_isPaused = value;
}
