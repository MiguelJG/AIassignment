#include "coche.h"


bool coche::funcheuristica1(){
	if (contadortemporal < 4){
		i += 1;
		j += 1;
		contadortemporal++;
	}
	else{
		i = i - 4;
		j = j - 4;
		contadortemporal = 0;
	}
	return 1;
}

bool coche::funcheuristica2(){}

bool coche::funcheuristica3(){}

bool coche::algoritmo(int dummy){
	switch (dummy) {
	case 1:
		return funcheuristica1();
		break;
	case 2:
		return funcheuristica2();
		break;
	case 3:
		return funcheuristica3();
		break;
	}
}

coche::coche(int a, int b){
	Sensor.resize(4);
	i = a; j = b;
}

coche::~coche(){}
