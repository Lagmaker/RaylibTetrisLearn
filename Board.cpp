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
Board::Board(int screenX, int screenY, int width, int height, int cellSize, int padding)
	:
	screenX(screenX),
	screenY(screenY),
	width(width),
	height(height),
	cellSize(cellSize),
	padding(padding)
{
	assert(this->width > 0 && this->height > 0); // If assertion triggers : The width or height is smaller than 0
	assert(this->cellSize > 0); // If assertion triggers : The cellSize is smaller than 0
	cells.resize(this->width * this->height);
}

void Board::SetCell(int x, int y, Color color)
{
	assert(x >= 0 && y >= 0 && x < width && y < height); // If assertion triggers : x or y is out of bounds
	cells[y * width + x].SetColor(color);	// translate position on 2d board to 1d vector
}

void Board::DrawCell(int x, int y) const
{
	assert(x >= 0 && y >= 0 && x < width && y < height); // If assertion triggers : x or y is out of bounds
	Color c = cells[y * width + x].GetColor();
	DrawRectangle(screenX + x * cellSize + padding, screenY + y * cellSize + padding, cellSize - padding, cellSize - padding, c);
}

void Board::Draw() const
{
	for (int iY = 0; iY < height; iY++)
	{
		for (int iX = 0; iX < width; iX++)
		{
			DrawCell(iX, iY);
		}
	}
}
