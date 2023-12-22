#pragma once

struct vector2D
{
	int x = 0;
	int y = 0;

	vector2D() {};
	vector2D(int x, int y) : x{ x }, y{ y } {};

	void set(int x, int y) { this->x = x; this->y = y; };

	vector2D operator+(vector2D B) { return vector2D( x += B.x, y += B.y ); };
	vector2D operator-(vector2D B) { return vector2D( x -= B.x, y -= B.y ); };
	vector2D operator*(int a) { return vector2D(x * a, y * a); };
	bool operator==(vector2D B) { if (x == B.x && y == B.y) return true; else return false; };
	bool operator!=(vector2D B) { return !operator==(B); };

	vector2D& operator=(const vector2D B) {
		this->x = B.x;
		this->y = B.y;
		return *this;
	}
};

