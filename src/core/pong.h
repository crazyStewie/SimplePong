#ifndef PONG_H
#define PONG_H

#include "src/engine/game.h"

class Pong : Game {
public:    
    Pong();
    ~Pong() = default;
    void run() override;
    void update(float delta) override;
    void draw() override;
private:
};

#endif
