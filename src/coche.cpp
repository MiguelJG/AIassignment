#include "coche.h"


void coche::funcheuristica1(){}

void coche::funcheuristica2(){}

void coche::funcheuristica3(){}

void coche::algoritmo(int dummy){
	switch (dummy) {
	case 1:
		funcheuristica1();
		break;
	case 2:
		funcheuristica2();
		break;
	case 3:
		funcheuristica3();
		break;
	}
}

coche::coche(int a, int b){
	Sensor.resize(4);
	i = a; j = b;
}

coche::coche(){}

coche::~coche(){}
