#include "Snake.h"

void Snake::Segment::Head(const Vei2& in_pos)
{
	pos = in_pos;
	c = Snake::headColor;
}

void Snake::Segment::Body()
{
	Color body = Snake::bodyColor;
}

void Snake::Segment::Draw(Board& brd) const
{
	brd.DrawCell(pos, c);
}

void Snake::Segment::MoveBy(const Vei2& in_pos)
{
	pos.add(in_pos);
}

void Snake::Segment::Follow(Segment& body)
{
	//error
	pos = body.pos;
}

Snake::Snake(const Vei2& loc)
{
	segment[0].Head(loc);
}

void Snake::Draw(Board& brd) const 
{
	for (int i = 0; i < nSegment; i++)
	{
		segment[i].Draw(brd);
	}
}

void Snake::Grow()
{
	//when it grows the segment doesnt know the location to move
	if (nSegment < maxSegment)
	{
		nSegment++;
		segment[nSegment].Body();
	}
}

void Snake::MoveBy(const Vei2& delta_pos)
{
	//for (int i = nSegment - 1; i < maxSegment; i++); this process the head too thats why it doesnt move
	for (int i = nSegment - 1; i > 0; i++)
	{
		segment[i].Follow(segment[i - 1]);
	}
	//segment[0] is the head of the snake
	segment[0].MoveBy(delta_pos);
}
