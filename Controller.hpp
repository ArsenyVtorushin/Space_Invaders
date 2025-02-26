#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "GameObject.hpp"

class Controller
{
public:
	virtual Coord make_move(GameObject&) = 0;
};

#endif // !CONTROLLER_HPP
