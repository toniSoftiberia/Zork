#ifndef LIGHT_H
#define LIGHT_H
#include <iostream>
#include <string>
#include "Object.hpp"
using namespace std;

class Light : public Object {
	int _duration;
	int _on;
public:
	Light(char* nombre, const unsigned int& peso, const unsigned int&  visible, const int duration);

	~Light();

	const int & getDuration();

	void lesLesDuration();

	void turnLamp(const int &state);

	const int & isOn();

};
#endif //LIGHT_H