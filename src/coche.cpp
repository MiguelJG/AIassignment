#include "coche.h"

bool coche::Dist_Manhattan(vector<vector <int> > &costos){}

bool coche::Dist_euclidea(vector<vector <int> > &costos){
	for(int i = 0; i < costos.size(); i++){
		for(int j = 0; j < costos[i].size();j++){
			costos[i][j] = sqrt(pow((i - fi),2) + pow((j - fj),2))
		}
	}
}

bool coche::Dist_Mahalanobis(vector<vector <int> > &costos){}

bool coche::algoritmo(int dummy,int n,int m){
	//generar matriz de costos que se rellena con las funciones heuristicas
	vector<vector <int> > costos;
	costos.resize(n);
	for (int i = 0; i < n; i++){
		costos[i].resize(m);
	}
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
	/*
		Algoritmo de busqueda que utiliza la matriz de costos
	*/
}

coche::coche(int a, int b, int c, int d){
	Sensor.resize(4);
	i = a; j = b;
	fi = c; fj=d;
}
