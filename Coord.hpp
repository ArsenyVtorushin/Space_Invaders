#ifndef COORD_HPP
#define	COORD_HPP

#include <iostream>
#include <type_traits>
// library of traits of different types
// via this lib you're able to understand what a type can do and what it can't

class Coord
{
public:
	Coord();
	Coord(int x, int y, int z);

	void SetX(int x);
	void SetY(int y);
	void SetZ(int z);

	auto GetX()const->int;
	auto GetY()const->int;
	auto GetZ()const->int;

	friend bool operator==(const Coord& lsv, const Coord& rsv);
	friend bool operator!=(const Coord& lsv, const Coord& rsv);

	// allows to work with unordered_map and unordered_set
	// contains an algorythm that encrypts different 
	size_t hash()const;

	friend std::ostream& operator<<(std::ostream& out, const Coord& rsv);
	friend std::istream& operator>>(std::istream& in, const Coord& rsv);

private:
	int x_;
	int y_;
	int z_;
};

#endif // !COORD_HPP
