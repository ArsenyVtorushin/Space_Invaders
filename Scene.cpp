#include "Scene.hpp"

Scene::PlacedObject::PlacedObject(GameObject* obj, Coord coord)
	:obj_(obj), coord_(coord)
{}



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
	int result{};
	for (auto& el : placed_)
	{
		if (el.Where() == place_object)
		{
			return result;
		}
		result++;
	}
	return -1;
}



void Scene::Remove(int index)
{
	auto victim = placed_.begin();
	for (size_t i = 0; i < index; i++)
	{
		++victim;
	}
	placed_.erase(victim);
}



Scene::PlacedObject& Scene::operator[](int i)
{
	auto el = placed_.begin();
	for (size_t k = 0; k < i; k++)
	{
		++el;
	}

	return *el;
}
