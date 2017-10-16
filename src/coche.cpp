#include "coche.h"

bool coche::Dist_Manhattan(vector <vector <int> > &costos){
	
		for(int p=0;p<costos.size();p++){
			for(int q=0;q<costos.size();q++){
				costos[p][q] =  (fabs(fi -i) + fabs(fj -j));
			}
		}
	
	
}

bool coche::Dist_euclidea(vector <vector <int> > &costos){}

bool coche::Dist_Mahalanobis(vector <vector <int> > &costos){}

bool coche::algoritmo(int dummy, int n,int m){
	vector <vector <int> > costos;	//generar matriz de costos que se rellena con las funciones heuristicas
	costos.resize(n);
	for(int i=0; i<n ; i++){
		costos[i].resize(m);
	}
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
	i = a; 
	j = b;
	fi = c; 
	fj=d;
}

