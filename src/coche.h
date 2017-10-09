#pragma once

#include <iostream>
#include <vector>
using namespace std;

class coche{
	vector<int> Sensor;//0 norte 1 sur, 2este, 3 oeste
	int i, j;

	coche(int a, int b);//hay que revisar lo relacionado con coche

	void funcheuristica1();

	void funcheuristica2();

	void funcheuristica3();

	void algoritmo(int dummy);

public:
	coche();
	~coche();
};
