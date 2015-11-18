#include "Container.hpp"

Container::Container(char* nombre, const unsigned int& peso, const unsigned int&  visible, Object * obj)
	: Object(nombre, peso, visible){
	_obj = obj;
	setType(CONTAINER);
}

Container::~Container(){

}

const Object * Container::getObject(){
	return _obj;
}
