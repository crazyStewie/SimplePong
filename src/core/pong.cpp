#include"pong.h"
#include<iostream>
#include<raylib.h>
#include "paddle.h"
#include "ball.h"
Pong::Pong()
    :Game("Pong")
{
    std::cout << "Initializing Pong" << std::endl;
    auto left_paddle = new Paddle("RIGHT", RIGHT_SIDE, Controls{KEY_UP, KEY_DOWN});
    auto right_paddle = new Paddle("LEFT", LEFT_SIDE, Controls{KEY_W, KEY_S});
    this->add_child(left_paddle);
    this->add_child(right_paddle);

    std::vector<Paddle*> paddles;
    paddles.push_back(left_paddle);
    paddles.push_back(right_paddle);
    this->add_child(new Ball("BALL", paddles));
}

void Pong::run() {
    while (!WindowShouldClose()) {
        this->_update(GetFrameTime());
        BeginDrawing();
        ClearBackground(BLACK);
        this->_draw();
        EndDrawing();
    }
}

void Pong::update(float delta) {

}

void Pong::draw() {
    DrawFPS(10, 10);
}
