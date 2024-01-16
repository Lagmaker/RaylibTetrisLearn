#pragma once

#include <assert.h>
#include "Vec2.h"
#include "raylibCpp.h"
#include "Board.h"


// Tetromino
class Tetromino
{
public:
	enum class Rotation
	{
		UP,
		RIGHT,
		DOWN,
		LEFT
	};
public:
	Tetromino(const bool* shape, int dimension, Color color, const Board& board);
	void RotateClockwise();
	void RotateCounterClockwise();
	void Draw() const;

private:
	Vec2<int> boardPos;
	Rotation currentRotation;
	const bool* shape;
	const int dimension;
	const Color color;
	const Board& board;
};



// Straight
class Straight : public Tetromino
{
public: 
	Straight(const Board& board) 
		: 
		Tetromino(shape, dimension, color, board)
	{
		// If false --> compile time error
		static_assert(sizeof(shape) / sizeof(shape[1]) == dimension * dimension);
	}
private:
	static constexpr bool shape[]{
		0, 0, 0, 0,
		1, 1, 1, 1,
		0, 0, 0, 0,
		0, 0, 0, 0,
	};
	static constexpr int dimension = 4;
	static constexpr Color color = SKYBLUE;
};


// Square
class Square : public Tetromino
{
public: 
	Square(const Board& board) 
		: 
		Tetromino(shape, dimension, color, board)
	{
		// If false --> compile time error
		static_assert(sizeof(shape) / sizeof(shape[1]) == dimension * dimension);
	}
private:
	static constexpr bool shape[]{
		1, 1,
		1, 1,
	};
	static constexpr int dimension = 2;
	static constexpr Color color = YELLOW;
};


// Tee
class Tee : public Tetromino
{
public: 
	Tee(const Board& board) 
		: 
		Tetromino(shape, dimension, color, board)
	{
		// If false --> compile time error
		static_assert(sizeof(shape) / sizeof(shape[1]) == dimension * dimension);
	}
private:
	static constexpr bool shape[]{
		0, 1, 0,
		1, 1, 1,
		0, 0, 0,
	};
	static constexpr int dimension = 3;
	static constexpr Color color = MAGENTA;
};


// Jay
class Jay : public Tetromino
{
public: 
	Jay(const Board& board) 
		: 
		Tetromino(shape, dimension, color, board)
	{
		// If false --> compile time error
		static_assert(sizeof(shape) / sizeof(shape[1]) == dimension * dimension);
	}
private:
	static constexpr bool shape[]{
		1, 0, 0,
		1, 1, 1,
		0, 0, 0,
	};
	static constexpr int dimension = 3;
	static constexpr Color color = DARKBLUE;
};


// El
class El : public Tetromino
{
public: 
	El(const Board& board) 
		: 
		Tetromino(shape, dimension, color, board)
	{
		// If false --> compile time error
		static_assert(sizeof(shape) / sizeof(shape[1]) == dimension * dimension);
	}
private:
	static constexpr bool shape[]{
		0, 0, 1,
		1, 1, 1,
		0, 0, 0,
	};
	static constexpr int dimension = 3;
	static constexpr Color color = ORANGE;
};


// SkewS
class SkewS : public Tetromino
{
public: 
	SkewS(const Board& board) 
		: 
		Tetromino(shape, dimension, color, board)
	{
		// If false --> compile time error
		static_assert(sizeof(shape) / sizeof(shape[1]) == dimension * dimension);
	}
private:
	static constexpr bool shape[]{
		0, 1, 1,
		1, 1, 0,
		0, 0, 0,
	};
	static constexpr int dimension = 3;
	static constexpr Color color = GREEN;
};


// SkewZ
class SkewZ : public Tetromino
{
public: 
	SkewZ(const Board& board) 
		: 
		Tetromino(shape, dimension, color, board)
	{
		// If false --> compile time error
		static_assert(sizeof(shape) / sizeof(shape[1]) == dimension * dimension);
	}
private:
	static constexpr bool shape[]{
		1, 1, 0,
		0, 1, 1,
		0, 0, 0,
	};
	static constexpr int dimension = 3;
	static constexpr Color color = RED;
};
