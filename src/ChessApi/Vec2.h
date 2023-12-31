#pragma once
struct Vec2
{
	void operator =(const Vec2& rhs){
		this->x = rhs.x;
		this->y = rhs.y;
	}
	void operator += (const Vec2& rhs){
		this->x += rhs.x;
		this->y += rhs.y;
	}

	bool operator == (const Vec2& rhs) {
		return((this->x == rhs.x) && (this->y == rhs.y));
	}
	Vec2 operator + (const Vec2& rhs) {
		return {this->x + rhs.x, this->y + rhs.y};
	}
	Vec2 operator * (int n) {
		return {this->x * n, this->y *n};
	}
	int x = -1, y = -1;
};

