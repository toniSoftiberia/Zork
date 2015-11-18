#include "Food.hpp"
#include "Guy.hpp"

Food::Food(char* nombre, const unsigned int& peso, const unsigned int&  visible, const int points)
	: Object(nombre, peso, visible){
	_points = points;
	setType(FOOD);
}

Food::~Food(){

}

void Food::eat(Guy * sheriff){
	sheriff->setLive(_points);
}