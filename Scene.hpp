#ifndef SCENE_HPP
#define SCENE_HPP

#include <list>
#include "GameObject.hpp"
#include "Coord.hpp"

class Scene
{
	class PlacedObject;

public:
	int Size()const;
	void Add(GameObject* obj, Coord coord);

	int Find(Coord place_object)const;
	void Remove(int index);

	PlacedObject& operator[](int i);
	
private:

	class PlacedObject
	{
	public:
		PlacedObject(GameObject* obj, Coord coord);

		~PlacedObject();

		// if do this, we'll have to make things really complicated :(
		//PlacedObject(const PlacedObject& other);
		//PlacedObject& operator=(const PlacedObject& other);
		//// "rule of three" - if you have a method that works with data 
		//// outside the class then you need to make a defenition of all the 3 methods
		//// it provides correct storage and data moving in the "obj_" field

		bool Interact(const PlacedObject& other)const;

		Coord Where()const;
		GameObject* Who()const;

		void SetCoord(Coord coord);

	private:
		GameObject* obj_;
		Coord coord_;
	};

	std::list<PlacedObject> placed_;
};

#endif // !SCENE_HPP
