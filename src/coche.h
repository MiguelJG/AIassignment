#pragma once

#include <iostream>
#include <vector>
using namespace std;

class coche{
	int contadortemporal = 0;//para pruebas
	vector<int> Sensor;//0 norte 1 sur, 2este, 3 oeste
	bool funcheuristica1();

	bool funcheuristica2();

	bool funcheuristica3();



public:
	int i, j;//posicion del coche

	bool algoritmo(int dummy);

	coche(int a, int b);

	~coche();
};
