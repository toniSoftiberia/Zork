#include "Location.hpp"

Location::Location(char* nombre, const unsigned int& peso, const unsigned int&  visible, const Room* location)
	: Object(nombre, peso, visible){
	_location = location;
	setType(LOCATION);
}

Location::~Location(){

}

const Room* Location::getLocation(){ 
	return _location;
}