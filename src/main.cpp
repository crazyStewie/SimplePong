#include <iostream>
#include <raylib.h>
#include "src/core/pong.h"

using namespace std;

int main()
{   
    Pong pongGame = Pong();
    
    cout << "Hello World!" << endl;

    pongGame.run();
    return 0;
}
