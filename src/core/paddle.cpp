#include "paddle.h"


Paddle::Paddle(const char *name, PaddleSide side, Controls controls)
        : GameObject(name), _side(side), _controls(controls), _position(Vector2{0, 0}), _size(Vector2{10, 64}), _speed(256)
{
    _position.x = (side == LEFT_SIDE) ? 10 : 790;
    _position.y = 300;
}

void Paddle::update(float delta) {
    if (IsKeyDown(_controls._down))
        _position.y += this->_speed*delta;
    if (IsKeyDown(_controls._up))
        _position.y -= this->_speed*delta;


    if (_position.y < _size.y/2) {
        _position.y = _size.y/2;
    }
    if (_position.y > 600 - _size.y/2) {
        _position.y = 600 - _size.y/2;
    }
}

void Paddle::draw() {
    DrawRectangle(_position.x - 5, _position.y - 32, 10, 64, WHITE);
}


