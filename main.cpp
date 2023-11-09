#include "Game.h"
#include "raylib.h"


int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    Game game{ screenWidth, screenHeight, 60, "Tetris Raylib" };

    
    //Game game2 = game;  // Coping with default ctor means that dtor will clean same memory both times. That causes crash
    
    while (!game.GameShouldClose())
    {
        game.Tick();
    }


    return 0;
}

/* Tutorial #1 : Why we need rule of 5
int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    Game game{ screenWidth, screenHeight, "Tetris Raylib" };

    {
        Game game2 = game;  // Coping with default ctor means that dtor will clean same memory both times. That causes crash
    }
    
    return 0;
}

*/