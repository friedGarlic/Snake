#pragma once
class Vei2 {
public:
	void add(const Vei2& in_pos)
	{
		x += in_pos.x;
		y += in_pos.y;
	}
	//Vei2& operator==(const Vei2& rhs) const made a mistake here
	bool operator==(const Vei2& rhs) const
	{
		return x == rhs.x && y == rhs.y;
	}
public:
	int x;
	int y;
};