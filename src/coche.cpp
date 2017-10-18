#include "coche.h"

bool coche::Dist_Manhattan(int i, int j){
					return fabs(fi -i) + fabs(fj -j);
}

bool coche::Dist_euclidea(int i, int j){
			return sqrt(pow((i - fi),2) + pow((j - fj),2));
}

bool coche::Dist_Mahalanobis(int i, int j){
			int A = fabs(i - fi);
			int B = fabs(j	- fj);
			if(A > B)
				return A;
			else
				return B;
}

bool coche::algoritmo(int dummy,int n,int m){
	/*Todo esto sobra.en este punto, solo se utiliza cuando se necesiten distancias
	switch (dummy) {
	case 1:
		return Dist_Manhattan(costos);
		break;
	case 2:
		return Dist_euclidea(costos);
		break;
	case 3:
		return Dist_Mahalanobis(costos);
		break;
	}
	*/
	/*
		Algoritmo de busqueda que utiliza la matriz de costos
	*/
	return false;
}

coche::coche(int a, int b, int c, int d){
	Sensor.resize(4);
	i = a;
	j = b;
	fi = c;
	fj=d;
}
