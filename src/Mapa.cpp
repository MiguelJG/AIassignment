#include "Mapa.h"
#include <cstdlib>
#include <time.h>

#define BVerde "\x1B[102m" //colores
#define FVerde "\x1B[32m"
#define FNegro "\x1B[30m"
#define FRojo "\x1B[31m"
#define FMagenta "\x1B[35m"
#define FRosa "\x1B[95m"

void Mapa::muestra(char a){ //funcion para mostrar los colores
		if(a == 'X')
			cout << BVerde << FRojo << a;
		else if(a == '~')
			cout << BVerde << FVerde << a;
		else if(a == '0')
			cout << BVerde << FNegro << a;
		else if(a == '*')
			cout << BVerde << FMagenta << a;
		else if(a == '#')
				cout << BVerde << FRosa << a;
};

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
	cout << "Introduzca el porcentaje de obstaculos: ";
	cin >> num;
	cout << endl;
	num = m * n * num / 100;
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
	matriz[fini][finj] = '#';
}

void Mapa::imprimirmapa(){
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << matriz[i][j];
		}
		cout << endl;
	}
}


void Mapa::imprimirmapabien(int h, int w, int car_i, int car_j){
	for (int i = h/2-h; i < h-h/2; i++){
		cout << endl << "\r";
		if(car_i + i < 0 || car_i + i >= matriz.size())
			for (int j = 0; j < w; j++)
				cout << BVerde << " ";
		else
			for (int j = w/2-w; j < w-w/2; j++){
				while(car_j + j < 0){
					cout << BVerde << " ";
					j++;
				}
				if (car_j + j >= matriz[0].size()){
					while(j < w-w/2){
						cout << BVerde << " ";
						j++;
					}
				}
				else
					muestra(matriz[car_i + i][car_j + j]);
			}
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

vector<int> Mapa::Sensor(int i, int j){ //1 obstaculo 0 libre
	vector<int> v;
	v.resize(4);
	if (i == 0) {//norte
		v[0] = 1;
		cout << "1" << endl;
	}
	else {
		if (matriz[i - 1][j] == '0') {
			v[0] = 1;
			cout << "2" << endl;
		}
		else {
			v[0] = 0;
			cout << "3" << endl;
		}
	}
	if (i == (n - 1)) {//sur
		v[1] = 1;
		cout << "4" << endl;
	}
	else {
		if (matriz[i + 1][j] == '0') {
			v[1] = 1;
			cout << "5" << endl;
		}
		else {
			v[1] = 0;
			cout << "6" << endl;
		}
	}
	if (j == 0) {//este
		v[2] = 1;
		cout << "7" << endl;
	}
	else {
		if (matriz[i][j - 1] == '0') {
			v[2] = 1;
			cout << "8" << endl;
		}
		else {
			v[2] = 0;
			cout << "9" << endl;
		}
	}
	if (i == (m - 1)) {//oeste
		v[3] = 1;
		cout << "10" << endl;
	}
	else {
		if (matriz[i][j + 1] == '0') {
			v[3] = 1;
			cout << "11" << endl;
		}
		else {
			v[3] = 0;
			cout << "12" << endl;
		}
	}
	return v;
}

void Mapa::getinicio(int & a, int & b){
	a = inicioi;
	b = inicioj;
}
