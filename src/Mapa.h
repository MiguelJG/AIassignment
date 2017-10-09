#pragma once

#include <iostream>
#include <vector>
//casillas vacias: ░ ~
//coche: X
//meta: #
//obstaculo █ 0
using namespace std;

class Mapa{
	vector< vector<char> > matriz;
	int m, n, inicioi, inicioj, fini, finj;
	//  Coche coche(inicioi,inicioj); <---- hay que ver que hacemos con esto

	void obstaculo_a_mano();					//completo

	void obstaculos_aleatorios();

public:

	Mapa(int _m, int _n, int _inicioi, int _inicioj, int _fini, int _finj, int control);

	void imprimirmapa();

	void actualizarmapa(int a, int b); //funcion que se le pasa la nueva posicion del coche y actualiza el mapa

	vector<int> Sensor(int i, int j); //funcion que retorna los datos leidos por el sensor del coche

	void getinicio(int &a, int &b);  // la posicion inicial para el coche

	Mapa();

	~Mapa();
};
