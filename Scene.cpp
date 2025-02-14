#include "Scene.hpp"

Scene::PlacedObject::PlacedObject(GameObject* obj, Coord coord)
	:obj_(obj),
	coord_(coord)
{
}



Scene::PlacedObject::~PlacedObject()
{
	delete obj_;
}



bool Scene::PlacedObject::Interact(const PlacedObject& other) const
{
	return coord_ == other.coord_;
}



Coord Scene::PlacedObject::Where() const
{
	return coord_;
}



GameObject* Scene::PlacedObject::Who() const
{
	return obj_;
}



void Scene::PlacedObject::SetCoord(Coord coord)
{
	this->coord_ = coord;
}




int Scene::Size() const
{
	return placed_.size();
}



void Scene::Add(GameObject* obj, Coord coord)
{
	placed_.emplace_back(obj, coord);
}



int Scene::Find(Coord place_object) const
{
	return 0;
}



void Scene::Remove(int index)
{
}



Scene::PlacedObject& Scene::operator[](int i)
{
	auto el = placed_.begin();
	for (int k = 0; k < i; k++)
	{
		++el;
	}

	return *el;
}
