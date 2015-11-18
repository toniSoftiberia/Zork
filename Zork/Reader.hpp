#ifndef READER_H
#define READER_H
#include <iostream>
#include <string>
#include "Stage.hpp"
#define MAX_PALABRAS 10
//Directions
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
#define UP 4
#define DOWN 5
#define IN 6
#define OUT 7

using namespace std;

class Reader{

	static int isDirection(const char* & orden);

	static void executeSimpleAction(Stage* mapa,const char* &orden);

	static int Reader::executeCompostActionDouble(Stage* mapa, const char** &orden, const int total_palabras);

	static int Reader::executeCompostActionTriple(Stage* mapa, const char** &orden, const int total_palabras);

	static int Reader::executeCompostActionFourth(Stage* mapa, const char** &orden, const int total_palabras);

	static int Reader::executeCompostActionFifth(Stage* mapa, const char** &orden, const int total_palabras);

	static int isObject(Stage* mapa, const char* & orden, int type);

	static int isItem(Stage* mapa, const char* & orden, int type);

public:
	static void executeOrder(Stage* mapa, const char** &orden, const int total_palabras);

	static const char** getWords(char* orden, int &totalPalabras);
};
#endif //READER_H
