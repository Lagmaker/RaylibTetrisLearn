#include <assert.h>
#include "Game.h"
#include <raylib.h>
#include "Settings.h"


Game::Game(int width, int height, int fps, std::string title)
	:
	board(settings::boardPosition,
		  settings::boardWidthHeight,
		  settings::cellSize,
		  settings::padding),
		 tetromino(board)
{
	assert(!GetWindowHandle());	// If assertion triggers : Window is already opened
	SetTargetFPS(fps);
	InitWindow(width, height, title.c_str());
}

Game::~Game() noexcept // We promise to compilator that exception is never thrown here	// If it is : std::terminate() is called
{
	assert(GetWindowHandle());	// If assertion triggers : Window is already closed
	CloseWindow();
}

bool Game::GameShouldClose() const	// We promise that we do not change the returnable value	// Good practice to use it for getters that return value how it is
{
	return WindowShouldClose();
}

void Game::Tick()
{
	SetWindowTitle(TextFormat("Tetris Raylib | %d fps",GetFPS()));
	BeginDrawing();
	Update();
	Draw();
	EndDrawing();
}	

void Game::Update()
{
	if(IsKeyPressed(KEY_E))
	{
		tetromino.RotateClockwise();
	}

	if(IsKeyPressed(KEY_Q))
	{
		tetromino.RotateCounterClockwise();
	}

}

void Game::Draw()
{
	ClearBackground(BLACK);
	board.Draw();
	tetromino.Draw();
}







