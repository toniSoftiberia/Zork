#include "Object.hpp"

Object::Object(char* name, const unsigned int& weight, const unsigned int& visible){
	_name = name;
	_weight = weight;
	_visible = visible;
}

Object::~Object(){

}

const char * Object::getName(){
	return _name;
}

void Object::setName(const char * name){
	strcpy_s(_name, sizeof(_name), name);
}

const unsigned int& Object::getWeigth(){
	return _weight;
}


void Object::setWeight(const unsigned int& weight){
	_weight = weight;
}

const unsigned int& Object::getType(){
	return _weight;
}


void Object::setType(const unsigned int& type){
	_type = type;
}

const unsigned int& Object::getVisible(){
	return _visible;
}


void Object::setVisible(const unsigned int& visible){
	_visible = visible;
}