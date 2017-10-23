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
	if (i == 0) {//norte
		Distancia[0] =  2147483647;
	}
	else {
		if (Sensor[0] == 1) {
			Distancia[0] =  2147483647;
		}
		else {
			Distancia[0] = seleccion(dummy, i - 1, j);//aqui va el switch
		}
	}
	if (i == (n - 1)) {//sur
		Distancia[1] = 2147483647;
	}
	else {
		if (Sensor[1] == 1) {
			Distancia[1] = 2147483647;
		}
		else {
			Distancia[1] = seleccion(dummy, i + 1, j);//aqui va el switch
		}
	}
	if (j == 0) {//este
		Distancia[2] = 2147483647;
	}
	else {
		if (Sensor[2] == 1) {
			Distancia[2] =2147483647;
		}
		else {
			Distancia[2] = seleccion(dummy, i , j - 1);//switch
		}
	}
	if (i == (m - 1)) {//oeste
		Distancia[3] = 2147483647;
	}
	else {
		if (Sensor[3] == 1) {
			Distancia[3] = 2147483647;
		}
		else {
			Distancia[3] = seleccion(dummy, i, j + 1);//switch
		}
	}
}

bool coche::algoritmo(int dummy,int n,int m){
	Distancia.clear();
	Distancia.resize(4);
	act_distancias(dummy,n,m);
	int min = Distancia[0];
	int minindex = 0;
	for(int i = 0; i < Distancia.size(); i++){
		if(Distancia[i] < min){
			min = Distancia[i];
			minindex = i;
		}
	}
	switch (i) {
		case 0:
			i = i -1;
			break;
		case 1:
		i = i +1;
			break;
		case 2:
		j = j-1;
			break;
		case 3:
		j = j+1;
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
