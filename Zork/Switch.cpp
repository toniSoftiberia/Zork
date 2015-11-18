#include "Switch.hpp"

Switch::Switch(char* nombre, const unsigned int& peso, const unsigned int&  visible, char* activator)
	: Object(nombre, peso, visible){
	_activated = 0;
	_activator = activator;
	setType(SWITCH);
}

Switch::~Switch(){

}

void Switch::setActivated(const char * name){
	if (_activated == 1)
		cout << "The interruptor is activated" << std::endl << std::endl;
	_activated = 1;
}

const char * Switch::getActivator(){
	return _activator;
}