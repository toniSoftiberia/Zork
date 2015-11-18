#ifndef LOCATION_H
#define LOCATION_H
#include <iostream>
#include <string>
#include "Object.hpp"
#include "Room.hpp"
using namespace std;

class Location : public Object {
	const Room * _location;
public:
	Location(char* nombre, const unsigned int& peso, const unsigned int&  visible, const Room* location);

	~Location();

	const Room* getLocation();

};
#endif //LOCATION_H