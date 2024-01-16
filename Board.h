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
		bool Exists() const;
	private:
		/* Private Fields | Cell */
		bool bExists;
		Color color;

	};
public:

	/* Special Member Functions | Board */
		/** 
	  @param 1. screePos // space from border of window to board
	  @param 2. widthHeight // amount of cells in board
	  @param 3. cellSize // param for both x,y
	  @param 4. padding // space between cells
	  */
	Board(Vec2<int> screenPos, Vec2<int> widthHeight, int cellSize, int padding);

	/* Public Methods | Board */
	void SetCell(Vec2<int> pos, Color color);
	void DrawCell(Vec2<int> pos) const;
	void DrawBorder() const;
	void Draw() const;
	bool CellExists(Vec2<int> pos) const;
private:
	/* Private Fields | Board */
	std::vector<Cell> cells;
	const int width;
	const int height;
	const int cellSize;
	const int padding; // separators between cells
	Vec2<int> screenPos;


};