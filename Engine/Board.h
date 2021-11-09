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
		int offCell = 1;

		gfx.DrawRectDim(loc.x * dimension + offCell, loc.y * dimension + offCell, dimension - offCell, dimension - offCell, c);
	}
	int GetWidth() const
	{
		return width;
	}
	int GetHeight() const
	{
		return height;
	}
	bool IsInsideBoard(const Vei2& pos) const
	{
		return pos.x >= 0 && pos.y >= 0 &&
			pos.x <= width && pos.y <= height;
	}
	void Border()
	{
		const int top = y;
		const int left = x;
		const int right = left + width * dimension;
		const int bottom = top + height * dimension;
		//gfx.DrawRect(x0,y0,x1,y1,c)
		//top
		gfx.DrawRect(left, top, right, top + borderWidth, borderColor);
		//left
		gfx.DrawRect(left, top + borderWidth, left + borderWidth, bottom - borderWidth, borderColor);
		//right
		gfx.DrawRect(right - borderWidth, top + borderWidth, right, bottom, borderColor);
		//bottom
		gfx.DrawRect(left, bottom - borderWidth, right - borderWidth, bottom, borderColor);
	}


private:
	Color borderColor = Colors::LightGray;
	int x = 0;
	int y = 0;
	int borderWidth = 10;
	static constexpr int width = 40;
	static constexpr int height = 50;
	static constexpr int dimension = 10;
	Graphics& gfx;
};