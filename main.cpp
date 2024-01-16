#include "Game.h"
#include "raylib.h"
#include "Settings.h"

int main(void)
{
    Game game{ settings::screenWidth,
               settings::screenHeight, 
               settings::fps,"Tetris Raylib" };

    

    
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