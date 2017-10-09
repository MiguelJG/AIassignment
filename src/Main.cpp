#include "Mapa.h"
#include "coche.h"

int main() {
	int n,m,ii,ij,fi,fj,type,alg;
	bool control;
	cout<< "Introduzca altura mapa:";
	cin >> n;
	cout <<"Introduzca amplitud mapa:";
	cin >> m;
	cout<<"Introduzca inicio i coche:";
	cin >> ii;
	cout << "Introduzca inicio j coche:";
	cin >> ij;
	cout<<"Introduzca fin i:";
	cin >> fi;
	cout <<"Introduzca fin j:";
	cin >> fj;
	cout <<"Introduzca 1 para obstaculos manuales, 2 para aleatorios:";
	cin >> type;
	Mapa map(n,m,ii, ij, fi,fj,type);
	cout <<"Algoritmo 1, Agoritmo 2, Algoritmo 3";
	cin >> alg;
	alg = 1;//temporal
	coche car(ii,ij);
	do{
		cout << "----------------------------"<< endl;
		map.imprimirmapa();
		control = car.algoritmo(alg);
		map.actualizarmapa(car.i,car.j);
	}while(control);

}
