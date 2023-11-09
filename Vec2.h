#pragma once



template <typename T>
class Vec2
{
public:
	/*Special Member Functions | Vec2 */
	Vec2() = default; 
	Vec2(T x, T y) // Because of TEMPLATE we need to implement it in header. We cant use .cpp file
		:
		x(x),
		y(y)
	{}

	/* Getters | Vec2 */
	T GetX() const { return x; }
	T GetY() const { return y; }

	/* Setters | Vec2 */
	T SetX(T x) const { this->x = x; }
	T SetY(T y) const { this->y = y; }
	
public:
	/* Operators Overload | Vec2 */
	bool operator== (const Vec2& rhs)
	{
		return (x == rhs.x && y = rhs.y);
	}
	bool operator!= (const Vec2& rhs)
	{
		return !(*this == rhs);
	}
	/* 
There is more optimized way to implement this. But its harder to read
Why faster? Because we are not using already implemented features.
We doing it through basics of language

		Vec2 operator+ (const Vec2& rhs)
		{
			return { x + rhs.x, y + rhs.y };
		}
		Vec2& operator+= (const Vec2& rhs)
		{
			x += rhs.x;
			y += rhs.y;
			return *this; // We use return here to allow us to A += B += C
			
		}
	*/

	Vec2 operator+ (const Vec2& rhs) const
	{
		return { x + rhs.x, y + rhs.y };
	}
	Vec2& operator+= (const Vec2& rhs)
	{
		// We use return here to allow us to A += B += C
		return *this = *this + rhs;
	}
	Vec2 operator+ (const int rhs) const
	{
		return { x + rhs, y + rhs };
	}

	Vec2 operator- (const Vec2& rhs) const
	{
		return { x - rhs.x, y - rhs.y };
	}
	Vec2& operator-= (const Vec2& rhs)
	{
		return *this = *this - rhs;
	}
	Vec2 operator- (const int rhs) const
	{
		return { x - rhs, y - rhs };
	}

	Vec2 operator* (const Vec2& rhs) const
	{
		return { x * rhs.x, y * rhs.y };
	}
	Vec2& operator*= (const Vec2& rhs)
	{
		return *this = *this * rhs;
	}
	Vec2 operator* (const int rhs) const
	{
		return { x * rhs, y * rhs };
	}

	
	
	

private:	
	/* Private Fields | Vec2 */
	T x;
	T y;
};
