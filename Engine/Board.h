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
		const int left = y;
		const int right = x;
		const int bottom = x + width + borderWidth;
		const int top = y + height + borderWidth;

		//gfx.DrawRect(left, top, bottom, right, color)
		//top
		gfx.DrawRect(left, borderWidth,top,right, borderColor);
		//left
		gfx.DrawRect(left, top, borderWidth, right, borderColor);
		//right
		gfx.DrawRect(top - left, top, bottom, borderWidth, borderColor);
		//bottom
		gfx.DrawRect(borderWidth, top, bottom , bottom - right, borderColor);
	}


private:
	Color borderColor = Colors::LightGray;
	int x = 15;
	int y = 15;
	int borderWidth = 10;
	static constexpr int width = 500;
	static constexpr int height = 500;
	static constexpr int dimension = 10;
	Graphics& gfx;
};