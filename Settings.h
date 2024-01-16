#pragma once
#include "Vec2.h"


namespace settings
{
	// Window settings
	inline constexpr int screenWidth = 800;
    inline constexpr int screenHeight = 600;
	inline constexpr int fps = 60;

	// Board settings
	inline constexpr int cellSize = 25;
	inline constexpr int padding = 2;
	inline constexpr Vec2<int> boardPosition { 250, 70 };
	inline constexpr Vec2<int> boardWidthHeight { 10, 20 };
}

/*
constexpr - calculate the result on compile-time instead of run-time 

inline - forces the variable to become externally linked & forces linker to pick only one instance of it // C++ 17 feature
*/