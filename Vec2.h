#pragma once



template <typename T>
class Vec2
{
public:
	/*Special Member Functions | Vec2 */
	Vec2() = default; 
	Vec2(T x, T y)	// Because of TEMPLATE we need to implement it right here. We cant use .cpp file
		x(x),
		y(y)
	{}

	/* Getters | Vec2 */
	T GetX() const {return x};
	T GetY() const {return y};

	/* Setters | Vec2 */


private:
	/* Private Fields | Vec2 */
	T x;
	T y;
};
