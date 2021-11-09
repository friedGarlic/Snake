#pragma once
#include "Board.h"
#include "Vei2.h"
#include <random>
#include "Snake.h"

class Goal
{
public:
	Goal(Board& brd, Snake& snek);
	void Respawn(Board& brd, Snake& snek);
	void Draw(Board& brd);
	Vei2 GetPos() const;
private:
	static constexpr Color goalColor = Colors::Yellow;
	Vei2 goalPos;
};