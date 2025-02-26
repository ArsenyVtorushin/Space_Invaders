#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <iostream>
#include "Coord.hpp"
#include "Status.hpp"
#include "Controller.hpp"
#include "Action.hpp"

class GameObject
{
public:
	virtual ~GameObject() = default;

	virtual bool IsHarmable()const = 0;
	virtual Action Action(int tick) = 0;
	virtual Coord Move() = 0;
	virtual void Modify(GameObject& obj) = 0;
	virtual void TakeHarm(int amount) = 0;
	virtual Status* GetStatus() = 0;
	virtual void SetController(const Controller* obj) = 0;
	
protected:
	Controller* controller_;
};

#endif // !GAMEOBJECT_HPP
