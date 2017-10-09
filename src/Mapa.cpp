#include "Mapa.h"
#include <cstdlib>
#include <time.h>

Mapa::Mapa(){}

Mapa::~Mapa(){}

void Mapa::obstaculo_a_mano(){
	int num;
	do {
		cout << "Introduzca el numero de obstaculos: ";
		cin >> num;
		cout << endl;
		if (num > (m * n)) {
			cout << "Numero de obstaculos mayor que numero de celdas." << endl;
		}
	} while (num > (m * n));
	for (int i = 0; i < num; i++) {
		int a, b;
		cout << "Introduzca las coordenadas i: ";
		cin >> a;
		cout << "Introduzca las coordenadas j: ";
		cin >> b;
		matriz[a][b] = '0';
	}
}

void Mapa::obstaculos_aleatorios(){
	int num,i,j;
	cout << "Introduzca el numero de obstaculos: ";
	cin >> num;
	cout << endl;
	srand (time(NULL));
	for(int c = 0; c <= num; c++){
		i = rand() % m + 0;
		j = rand() % n + 0;
		matriz[i][j] = '0';
	}
}

Mapa::Mapa(int _m, int _n, int _inicioi, int _inicioj, int _fini, int _finj, int control){
	m = _m; n = _n;
	inicioi = _inicioi; inicioj = _inicioj;
	fini = _fini; finj = _finj;
	matriz.resize(m);//se hace la matriz del tama�o correcto
	for (int i = 0; i < m; i++) {
		matriz[i].resize(n);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matriz[i][j] = '~';
		}
	}
	switch (control) {
	case 1:
		obstaculo_a_mano();
		break;
	case 2:
		obstaculos_aleatorios();
		break;
	}
	matriz[inicioi][inicioj] = 'X';
	matriz[fini - 1][finj - 1] = '#';
}

void Mapa::imprimirmapa(){
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << matriz[i][j];
		}
		cout << endl;
	}
}

void Mapa::actualizarmapa(int a, int b){
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (matriz[i][j] == 88) {
				matriz[i][j] = '*';
			}
		}
	}
	matriz[a][b] = 'X';
}

vector<int> Mapa::Sensor(int i, int j){
	vector<int> v;
	v.resize(4);
	if (i == 0) {//norte
		v[0] = 1;
	}
	else {
		if (matriz[i - 1][j] == '0') {
			v[0] = 1;
		}
		else {
			v[0] = 0;
		}
	}
	if (i == (n - 1)) {//sur
		v[1] = 1;
	}
	else {
		if (matriz[i + 1][j] == '0') {
			v[1] = 1;
		}
		else {
			v[1] = 0;
		}
	}
	if (j == 0) {//este
		v[2] = 1;
	}
	else {
		if (matriz[i][j - 1] == '0') {
			v[2] = 1;
		}
		else {
			v[2] = 0;
		}
	}
	if (i == (m - 1)) {//oeste
		v[3] = 1;
	}
	else {
		if (matriz[i][j + 1] == '0') {
			v[3] = 1;
		}
		else {
			v[3] = 0;
		}
	}
	return v;
}

void Mapa::getinicio(int & a, int & b){
	a = inicioi;
	b = inicioj;
}