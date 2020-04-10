#ifndef PADDLE_H
#define PADDLE_H

#include "src/engine/gameobject.h"
#include<raylib.h>

enum PaddleSide {
    LEFT_SIDE,
    RIGHT_SIDE
};

struct Controls{
     KeyboardKey _up;
     KeyboardKey _down;
};

class Paddle : public GameObject {
public:
    Paddle(const char* name, PaddleSide side, Controls controls);
    void update(float delta) override;
    void draw() override;
    Vector2 get_position() {return _position;}
    Vector2 get_size() {return _size;}
    PaddleSide get_side() {return _side;}
private:
    PaddleSide _side;
    Controls _controls;
    Vector2 _position;
    Vector2 _size;
    float _speed;

};


#endif
