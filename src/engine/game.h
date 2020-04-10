#ifndef GAME_H
#define GAME_H

#include"gameobject.h"
#include<string>
class Game : protected GameObject{
public:
    explicit Game(const char* name);
    virtual void run() = 0;
    bool get_paused();
    void set_paused(bool value);
private:
    bool _isPaused;

};

#endif // GAME_H
