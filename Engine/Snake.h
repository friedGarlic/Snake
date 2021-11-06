#pragma once
#include "Vei2.h"
#include "Board.h"

class Snake
{
private:
	class Segment
	{
	public:
		void Head(const Vei2& pos);
		void Body();
		void Draw(Board& brd) const;
		void MoveBy(const Vei2& pos);
		void Follow(Segment& body);
	private:
		Vei2 pos;
		Color c;
	};
public:
	Snake(const Vei2& loc);
	void Draw(Board& brd) const;
	void Grow();
	void MoveBy(const Vei2& delta_pos);

private:
	static constexpr Color headColor = Colors::Red;
	static constexpr Color bodyColor = Colors::Green;
	static constexpr int maxSegment = 100;
	int nSegment = 1;
	Segment segment[maxSegment];
};