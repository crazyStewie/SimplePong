#ifndef BALL_H
#define BALL_H

#include <src/engine/gameobject.h>
#include <raylib.h>
#include "paddle.h"
class Ball: public GameObject {
public:
    explicit Ball(const char* name, std::vector<Paddle*> paddles);
    void update(float delta) override;
    void draw() override;
private:
    Vector2 _position;
    Vector2 _velocity;
    float  _radius;
    std::vector<Paddle*> _paddles;
};


#endif