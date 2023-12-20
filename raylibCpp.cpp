#include "raylibCpp.h"
#include <assert.h>

void raycpp::DrawRectangle(Vec2<int> pos, Vec2<int> widthHeight, Color color)
{
	assert(pos.GetX() >= 0 && pos.GetY() >= 0 &&
		   pos.GetX() < GetScreenWidth() &&
		   pos.GetY() < GetScreenHeight());
	DrawRectangle(pos.GetX(), pos.GetY(), widthHeight.GetX(), widthHeight.GetY(), color);
}

void raycpp::DrawRectangleLinesEx(Vec2<int> pos, Vec2<int> widthHeight, float lineThick, Color color)
{
	assert(pos.GetX() >= 0 && pos.GetY() >= 0 &&
		   pos.GetX() < GetScreenWidth() &&
		   pos.GetY() < GetScreenHeight());
	assert(lineThick > 0);
	DrawRectangleLinesEx({(float)pos.GetX(), (float)pos.GetY(), (float)widthHeight.GetX(), (float)widthHeight.GetY()}, lineThick, color);
}
