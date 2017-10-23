#include "coche.h"

int coche::Dist_Manhattan(int i, int j){
					return fabs(fi -i) + fabs(fj -j);
}

int coche::Dist_euclidea(int i, int j){
			return sqrt(pow((i - fi),2) + pow((j - fj),2));
}

int coche::Dist_Mahalanobis(int i, int j){
			int A = fabs(i - fi);
			int B = fabs(j	- fj);
			if(A > B)
				return A;
			else
				return B;
}

int coche::seleccion(int dummy, int i, int j){
	switch (dummy) {
	case 1:
		return Dist_Manhattan(i,j);
		break;
	case 2:
		return Dist_euclidea(i,j);
		break;
	case 3:
		return Dist_Mahalanobis(i,j);
		break;
	}
}


void coche::act_distancias(int dummy,int n, int m){
		if (Sensor[0] == 1) {
			Distancia[0] =  10000;
		}
		else {
			Distancia[0] = seleccion(dummy, i - 1, j);//aqui va el switch
		}

		if (Sensor[1] == 1) {
			Distancia[1] = 10000;
		}
		else {
			Distancia[1] = seleccion(dummy, i + 1, j);//aqui va el switch
		}

		if (Sensor[2] == 1) {
			Distancia[2] =10000;
		}
		else {
			Distancia[2] = seleccion(dummy, i , j - 1);//switch
		}
		if (Sensor[3] == 1) {
			Distancia[3] = 10000;
		}
		else {
			Distancia[3] = seleccion(dummy, i, j + 1);//switch
		}

}

bool coche::algoritmo(int dummy,int n,int m){
	Distancia.clear();
	Distancia.resize(4);
	act_distancias(dummy,n,m);
	int min = Distancia[0];
	int minindex = 0;

	for(int a = 0; a < Distancia.size(); a++){
		if(Distancia[a] < min){
			min = Distancia[a];
			minindex = a;
		}
	}
	ia = i; ja = j;
	switch (minindex) {
		case 0:
			i = i - 1;
			break;
		case 1:
		i = i + 1;
			break;
		case 2:
		j = j - 1;
			break;
		case 3:
		j = j + 1;
			break;
	}
	if (i == fi && j == fj){
		fin = false;
	}
	/*
		Algoritmo de busqueda que utiliza la matriz de costos
	*/
	return fin;
}

coche::coche(int a, int b, int c, int d){
	Sensor.resize(4);
	Distancia.resize(4);
	i = a;
	j = b;
	fi = c;
	fj=d;
	fin = true;
}
