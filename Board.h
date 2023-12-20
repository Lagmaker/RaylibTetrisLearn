#pragma once
#include "raylibCpp.h"
#include <vector>
#include "Vec2.h"

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
	Board(Vec2<int> screenPos, Vec2<int> widthHeight, int cellSize, int padding);

	/* Public Methods | Board */
	void SetCell(Vec2<int> pos, Color color);
	void DrawCell(Vec2<int> pos) const;
	void DrawBorder() const;
	void Draw() const;
private:
	/* Private Fields | Board */
	std::vector<Cell> cells;
	const int width;
	const int height;
	const int cellSize;
	const int padding; // separators between cells
	Vec2<int> screenPos;


};