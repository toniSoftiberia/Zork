#ifndef SWITCH_H
#define SWITCH_H
#include <iostream>
#include <string>
#include "Object.hpp"
using namespace std;

class Switch : public Object {
	int _activated;
	char* _activator;
public:
	Switch(char* nombre, const unsigned int& peso, const unsigned int&  visible, char* activator);

	~Switch();

	void setActivated(const char * name);

	const char * getActivator();
};
#endif //SWITCH_H