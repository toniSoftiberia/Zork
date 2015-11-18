#include "Light.hpp"

Light::Light(char* nombre, const unsigned int& peso, const unsigned int&  visible, const int duration)
	: Object(nombre, peso, visible){
	_duration = duration;
	_on = 0;
	setType(LIGHT);
}

const int & Light::getDuration(){
	return _duration;
}

void Light::lesLesDuration(){
	--_duration;
}

void Light::turnLamp(const int &state){
	if (state == 1 || (state == 0 && _duration > 0))
		_on = state;
}

const int & Light::isOn(){
	return _on;
}