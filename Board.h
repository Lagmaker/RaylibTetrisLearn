#pragma once
#include <raylib.h>
#include <vector>

class Board
{
private:
	class Cell
	{
	public:
		/* Special Member Functions | Cell */
		Cell();

		/* Public Methods | Cell */
		void SetColor(Color color);
		void Remove();

		/* Getters | Cell*/
		Color GetColor() const;
	private:
		/* Private Fields | Cell */
		bool bExists;
		Color color;

	};
public:

	/* Special Member Functions | Board */
	Board(int screenX, int screenY, int width, int height, int cellSize, int padding);

	/* Public Methods | Board */
	void SetCell(int x, int y, Color color);
	void DrawCell(int x, int y) const;
	void Draw() const;
private:
	/* Private Fields | Board */
	std::vector<Cell> cells;
	const int width;
	const int height;
	const int cellSize;
	const int padding; // separators between cells
	int screenX;
	int screenY;


};