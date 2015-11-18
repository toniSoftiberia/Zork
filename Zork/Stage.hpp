#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <string>
#include "Room.hpp"
#include "Guy.hpp"
#include "Object.hpp"

#define NUM_DIRECTIONS 8
#define LEVELS 3
#define NONE 0
#define VERBOSE 1
#define SUPERBRIEF 2

using namespace std;

/*
- Podemos mover en todas las direcciones.
- Puede tener luces apagadas o encendidas.
- Puede contener objetos/contenedores/localizaciones.
- Al descubrir una sala se nos mostrará su descripción.
- Al entra en una sala nos indica que objetos hay.
*/
class Stage {
	Room* _start;
	Room* _position;
	int _level;
	Guy* _sheriff;
	int _score;
	int _desc_mode;

public:
	Stage();

	~Stage();

	Room * getStart();

	Room * getPosition();

	Guy* getSheriff();
	
	void move(const int& dir);

	void restart(const char* &orden);

	void quit(const char* &orden);

	void superbrief();

	void vervose();
	
	void addScore(const int& score);

	void showScore();

	const int& getMode();

	void examine();
};
#endif //MAP_H