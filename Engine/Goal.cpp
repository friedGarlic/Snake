#include "Goal.h"
Goal::Goal(Board& brd, Snake& snek)
{
	Respawn(brd, snek);
}
void Goal::Respawn(Board& brd, Snake& snek)
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> xDist(0, brd.GetWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, brd.GetHeight() - 1);

	Vei2 randomPos;
	do
	{
		randomPos = { xDist(rng), yDist(rng) };
	} 
	while (snek.GetHeadNextLocation(randomPos) == goalPos);

}

void Goal::Draw(Board& brd)
{
	brd.DrawCell(goalPos, goalColor);
}

Vei2 Goal::GetPos() const
{
	return goalPos;
}
