#include "coche.h"

bool coche::Dist_Manhattan(){}

bool coche::Dist_euclidea(){}

bool coche::Dist_Mahalanobis(){}

bool coche::algoritmo(int dummy){
	//generar matriz de costos que se rellena con las funciones heuristicas
	switch (dummy) {
	case 1:
		return Dist_Manhattan();
		break;
	case 2:
		return Dist_euclidea();
		break;
	case 3:
		return Dist_Mahalanobis();
		break;
	}
	/*
		Algoritmo de busqueda que utiliza la matriz de costos
	*/
}

coche::coche(int a, int b, int c, int d){
	Sensor.resize(4);
	i = a; j = b;
	fi = c; fj=d;
}

coche::~coche(){}
