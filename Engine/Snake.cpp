#include "Snake.h"

void Snake::Segment::Head(const Vei2& in_pos)
{
	pos = in_pos;
	c = Snake::headColor;
}

void Snake::Segment::Body()
{
	//Color body = Snake::bodyColor;
	c = Snake::bodyColor;
}

void Snake::Segment::Draw(Board& brd) const
{
	brd.DrawCell(pos, c);
}

void Snake::Segment::MoveBy(const Vei2& in_pos)
{
	pos.add(in_pos);
}

void Snake::Segment::Follow(const Segment& body)
{
	pos = body.pos;
}

const Vei2& Snake::Segment::GetPos() const
{
	return pos;
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
		segment[nSegment].Body();
		nSegment++;
	}
}

void Snake::MoveBy(const Vei2& delta_pos)
{
	//for (int i = nSegment - 1; i < maxSegment; i++); this process the head too thats why it doesnt move
	//(int i = nSegment - 1; i < maxSegment; i++) 
	for (int i = nSegment - 1; i > 0; i--) //decrement i, until reach head and stop, not processing the head
	{
		segment[i].Follow(segment[i - 1]);
	}
	//segment[0] is the head of the snake
	segment[0].MoveBy(delta_pos);
}

bool Snake::CollidingToBody(const Vei2& target) const
{
	for (int i = 0; i < nSegment; i++)
	{
		//if (segment[0].GetPos() == target) miss
		if (segment[i].GetPos() == target)
		{
			return true;
		}
	}
	return false;
}

Vei2 Snake::GetHeadNextLocation(const Vei2& pos) const
{
	Vei2 l = segment[0].GetPos();
	l.add(pos);
	return l;
}
