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
		void Follow(const Segment& body);
		const Vei2& GetPos() const; 
		/* returning  a reference is no problem here!
		but in the GetHeadLocation(),
		the var we're returning is a local,
		so it dies when the fuction returns, and thus if we return as ref
		there, we'd be returning an invalid reference */
	private:
		Vei2 pos;
		Color c;
	};
public:
	Snake(const Vei2& loc);
	void Draw(Board& brd) const;
	void Grow();
	void MoveBy(const Vei2& delta_pos);
	bool CollidingToBody(const Vei2& pos) const;
	Vei2 GetHeadNextLocation(const Vei2& pos) const;

private:
	static constexpr Color headColor = Colors::Red;
	static constexpr Color bodyColor = Colors::Green;
	static constexpr int maxSegment = 100;
	int nSegment = 1;
	Segment segment[maxSegment];
};