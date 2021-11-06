#pragma once
class Vei2 {
public:
	void add(const Vei2& in_pos)
	{
		x += in_pos.x;
		y += in_pos.y;
	}

public:
	int x;
	int y;
};