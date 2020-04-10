#include "ball.h"

#include <utility>
#include <iostream>

Ball::Ball(const char* name, std::vector<Paddle*> paddles)
    : _position(Vector2{400, 300}), _velocity(Vector2{96, 0}), _radius(12), GameObject(name)
{
    _paddles = std::move(paddles);
}

void Ball::update(float delta) {
    _position.x += delta*_velocity.x;
    _position.y += delta*_velocity.y;

    if (_position.y < _radius) {
        _velocity.y *= -1;
        _position.y = _radius;
    }

    if (_position.y > 600 - _radius) {
        _velocity.y *= -1;
        _position.y = 600 - _radius;
    }

    for (auto paddle : _paddles) {
        Rectangle paddle_rect = Rectangle {
            paddle->get_position().x - paddle->get_size().x/2,
            paddle->get_position().y - paddle->get_size().y/2,
            paddle->get_size().x,
            paddle->get_size().y};
        if (CheckCollisionCircleRec(_position, _radius, paddle_rect)) {
            if(paddle->get_side() == LEFT_SIDE && _velocity.x < 0) {
                _velocity.x *= -1.1;
                _velocity.y += 4 * (_position.y - paddle->get_position().y);
            }
            if(paddle->get_side() == RIGHT_SIDE && _velocity.x > 0) {
                _velocity.x *= -1.1;
                _velocity.y += 4 * (_position.y - paddle->get_position().y);
            }
        }
    }

}

void Ball::draw() {
    DrawCircle(_position.x, _position.y, _radius, WHITE);
}

