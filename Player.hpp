#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "GameObject.hpp"
#include "Action.hpp"

class Player : public GameObject
{
public:
	Coord Move() override
	{
		return controller_->make_move(*this);
	}

	bool IsHarmable()const override
	{ 
		return true; 
	}
	void TakeHarm(int amount) override
	{
		hitpoint_ -= amount;
	}

private:
	int hitpoint_;
};

#endif // !PLAYER_HPP
