#include "Room.hpp"

/*
- Podemos mover en todas las direcciones.
- Puede tener luces apagadas o encendidas.
- Puede contener objetos/contenedores/localizaciones.
- Al descubrir una sala se nos mostrará su descripción.
- Al entra en una sala nos indica que objetos hay.
//podemos tener puertas cerradas//struct char object_name
*/

	Room::Room(const string& name, const string& desc, const int& ligth, Room** rooms, const int closed, const int& num_objects, Object** objects){
		_name = name;
		_desc = desc;
		_light = ligth;
		_level = EXTERIOR;
		_visited = 0;
		_visible = 0;
		_closed = closed;
		_hide_desc = " ";

		_rooms = new Room*[NUM_DIRECTIONS];
		for (int i = 0; i<NUM_DIRECTIONS; ++i)
			_rooms[i] = rooms[i];

		_num_objects = num_objects;
		_objects = new Object*[_num_objects];
		for (int i = 0; i<_num_objects; ++i)
			_objects[i] = objects[i];
	}

	Room::~Room(){
		for (int i = 0; i<NUM_DIRECTIONS; ++i)
			delete _rooms[i];
		delete[] _rooms;
	}

	const string& Room::getName(){
		return _name;
	}

	const string& Room::getDesc(const int& desc_mode){
		string* res;
		char* full_desc = new char[255];
		strcpy_s(full_desc, sizeof(char[255]), "");
		if ((++_visited == 1) || (desc_mode == VERBOSE)){
			strcpy_s(full_desc, sizeof(char[255]), _desc.c_str());
			if (_visible == 1){
				strcat_s(full_desc, sizeof(char[255]), _hide_desc.c_str());
			}
			res = &_desc;
		}

		res = new string(full_desc);
		delete full_desc;
		return *res;
	}

	void Room::setHideDesc(const string& hide_desc){
		_hide_desc = hide_desc;
	}

	const string& Room::getHideDesc(){
		_visible = 1;
		return _hide_desc;
	}

	const int& Room::getLight(){
		return _light;
	}

	const int& Room::getNumObjects(){
		return _num_objects;
	}

	const Room * Room::getRooms(){
		return *_rooms;
	}

	const int& Room::isClosed(){
		return _closed;
	}

	Object* Room::getObject(const int& pos){
		return _objects[pos];
	}

	Object* Room::obtainObject(const int& pos){
		return getObject(_objects[pos]->getName());
	}

	Object* Room::getObject(const char* name){
		Object* res = NULL;
		
		for (int i = 0; i < _num_objects; ++i)
			if (getObject(i) != NULL && getObject(i)->getVisible() == 1 && strcmp(getObject(i)->getName(), name) == 0 && getObject(i)->getWeigth() < 40){
				res = _objects[i];
				--_num_objects;
				for (int j = i; j < _num_objects; ++j){
					_objects[j] = _objects[j+1];
				}
			}				
		return res;
	}
	
	Room* Room::getDirection(const int& dir){
		Room * res = NULL;
		if (_rooms[dir]!=NULL)
			res = _rooms[dir];
		return res;
	}	

	void Room::setDirection(Room* room, const int& dir){
		_rooms[dir] = room;
		int a = 0;
		a++;
	}

	const Room& Room::get() const { return *this; }

	void Room::showObjects(){
		for (int i = 0; i < _num_objects; ++i)
			if (getObject(i)->getVisible() == 1)
				cout << " - " << getObject(i)->getName() << endl;
	}

	void Room::setObjectsVisibles(){
		for (int i = 0; i < _num_objects; ++i)
			getObject(i)->setVisible(1);
	}