#ifndef ACTION_HPP
#define ACTION_HPP

#include "Scene.hpp"
#include "Coord.hpp"
#include "GameObject.hpp"

#include <functional>

class Action
{
public:
	Action(GameObject& who, Coord where, std::function<void(Scene& obj)> action)
		:who_(who), where_(where), action_(action)
	{}

	~Action() = default;

	//another gift score for students
	virtual void operator()(Scene& obj);

private:
	GameObject& who_;
	Coord where_;
	Scene* place_; 
	std::function<void(Scene& obj)> action_;
};

#endif // !ACTION_HPP
