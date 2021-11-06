#pragma once
#include "Graphics.h"
#include "Vei2.h"

class Board
{
public:
	Board(Graphics& in_gfx)
		:
		gfx(in_gfx)
	{
	}
	void DrawCell(const Vei2& loc, Color c) const
	{
		gfx.DrawRectDim(loc.x * dimension, loc.y * dimension, dimension, dimension, c);
	}
	int GetWidth() const
	{
		return width;
	}
	int GetHeight() const
	{
		return height;
	}
private:
	static constexpr int width = 14;
	static constexpr int height = 20;
	static constexpr int dimension = 10;
	Graphics& gfx;
};