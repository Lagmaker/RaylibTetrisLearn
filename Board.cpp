#include "Board.h"
#include <assert.h>

/* Cell Realizations */
Board::Cell::Cell()
	:
	bExists(false),
	color(WHITE)
{
}

void Board::Cell::SetColor(Color color)
{
	this->color = color;
	bExists = true;
}

// Method to remove the Cell	// We do not care about color because removed tile is not even shown up
void Board::Cell::Remove()
{
	bExists = false;
}

Color Board::Cell::GetColor() const
{
	return color;
}

/* Board Realizations */
Board::Board(Vec2<int> screenPos, Vec2<int> widthHeight, int cellSize, int padding)
	:
	screenPos(screenPos),
	width(widthHeight.GetX()),
	height(widthHeight.GetY()),
	cellSize(cellSize),
	padding(padding)
{
	assert(this->width > 0 && this->height > 0); // If assertion triggers : The width or height is smaller than 0
	assert(this->cellSize > 0); // If assertion triggers : The cellSize is smaller than 0
	cells.resize(this->width * this->height);
}

void Board::SetCell(Vec2<int> pos, Color color)
{
	assert(pos.GetX() >= 0 && pos.GetY() >= 0 && pos.GetX() < width && pos.GetY() < height); // If assertion triggers : x or y is out of bounds
	cells[pos.GetY() * width + pos.GetX()].SetColor(color);	// translate position on 2d board to 1d vector
}

void Board::DrawCell(Vec2<int> pos) const 
{
	assert(pos.GetX() >= 0 && pos.GetY() >= 0 && pos.GetX() < width && pos.GetY() < height); // If assertion triggers : x or y is out of bounds
	Color c = cells[pos.GetY() * width + pos.GetX()].GetColor();
	Vec2<int> topLeft = screenPos + padding + (pos * cellSize);

	raycpp::DrawRectangle(topLeft, Vec2{ cellSize ,cellSize } - padding, c);
}

void Board::Draw() const
{
	for (int iY = 0; iY < height; iY++)
	{
		for (int iX = 0; iX < width; iX++)
		{
			DrawCell({ iX, iY });
		}
	}
}
