#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <string>
#include "object.hpp"
using namespace std;
#define NUM_DIRECTIONS 8
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
#define UP 4
#define DOWN 5
#define IN 6
#define OUT 7
#define EXTERIOR 0
#define INTERIOR 1
#define NONE 0
#define VERBOSE 1
#define SUPERBRIEF 2

/*
- Podemos mover en todas las direcciones.
- Puede tener luces apagadas o encendidas.
- Puede contener objetos/contenedores/localizaciones.
- Al descubrir una sala se nos mostrará su descripción.
- Al entra en una sala nos indica que objetos hay.
*/
//podemos tener puertas cerradas//struct char object_name
class Room {
	string _name;
	string _desc;
	string _hide_desc;
	int _light;
	Room** _rooms;
	Object** _objects;
	int _num_objects;
	int _closed;
	int _visited;
	int _visible;
	int _level;

public:
	Room(const string& name, const string& desc, const int& ligth, Room** rooms, const int closed, const int& num_objects, Object** objects);

	~Room();

	const string& getName();

	const string& getDesc(const int& desc_mode);

	void setHideDesc(const string& hide_desc);

	const string& getHideDesc();

	const int& getLight();

	const int& getNumObjects();

	const Room * getRooms();
	
	const int& isClosed();

	Object* getObject(const int& pos);

	Object* obtainObject(const int& pos);

	Object* getObject(const char* name);

	const Room& get() const;
	
	Room* getDirection(const int& dir);

	void setDirection(Room* room, const int& dir);

	void showObjects();

	void setObjectsVisibles();
};
#endif //ROOM_H