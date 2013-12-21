#ifndef VECTOR2D_H_
#define VECTOR2D_H_
#include <iostream>

 struct Vector2D
{
	float x;
	float y;

	inline Vector2D operator + (const Vector2D &rhs)
	{
		Vector2D result;
		result.x = x+rhs.x;
		result.y = y+rhs.y;
		return result;
	}
	inline Vector2D operator - (const Vector2D &rhs)
	{
		Vector2D result;
		result.x = x-rhs.x;
		result.y = y-rhs.y;
		return result;
	}
	inline Vector2D operator * (const float &v)
	{
		Vector2D result;
		result.x = x*v;
		result.y = y*v;
		return result;
	}
	inline void operator += (const Vector2D &rhs)
	{
		//Vector2D result;
		x+=rhs.x;
		y += rhs.y;

	}
	inline void operator -= (const Vector2D &rhs)
	{
		//Vector2D result;
		x -= rhs.x;
		y -= rhs.y;

	}
};

#endif
