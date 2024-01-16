#pragma once
#include <string>
#include "Board.h"
#include "Tetrominoes.h"


class Game
{
/*
	Rule of 5 telling us that if we have created on of its members, than you need to implement them all		
	Here is the list of all 5 Special Member Functions:	
	0)	Game();									// Default Constructor 
	1)	~Game();								// Destructor
	2)	Game(const Game& other);				// Copy Constructor
	3)	Game& operator= (const Game& other);	// Copy Assignment Operator
	4)	Game(Game&& other);						// Move Constructor
	5)	Game& operator= (Game&& other);			// Move Assignment Operator

	Check what is implemented by default and other stuff: https://www.foonathan.net/images/special-member-functions.png

	If 2 and 3 are DELETED, compiler Fallback the behavior of 4 and 5 so them are also DELETED.
	But if 2 and 3 are DECLARED(Even without realization), compiler implement 4 and 5 in Fallback Style so they will act like Coping instead of Move
	{
	 Game(Game&& other){}; // Move Constructor : Falls back to Copy so DELETED
	 Game& operator= (Game&& other){}; // Move Assignment Operator : Falls back to Copy so DELETED
	}
*/
public:
	/* Special Member Functions | Game */
	Game(int width, int height, int fps, std::string title);
	Game(const Game& other) = delete; // Tells the compiler to delete the default realization of Copy Ctor
	Game& operator= (const Game& other) = delete; // Tells the compiler to delete the default realization of Copy Assignment
	~Game() noexcept;

	/* Public Methods | Game */
	bool GameShouldClose() const;
	void Tick();
private:
	/* Private Methods | Game */
	void Update();
	void Draw();

	/* Private Fields | Game */
	Board board;
	Jay tetromino;
};

