#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
#include <string>
#include "Object.hpp"
using namespace std;

class Container : public Object{
	Object * _obj;

public:
	Container(char* nombre, const unsigned int& peso, const unsigned int&  visible, Object * obj);

	~Container();

	const Object * getObject();
};
#endif //CONTAINER_H