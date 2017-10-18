#include "Mapa.h"
#include "coche.h"
#include <ncurses.h>

void* resizeHandler(int);
void init(int& height, int& width);
int scr_h, scr_w;

#define Default "\x1B[49m"

using namespace std;

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
	coche car(ii,ij,fi,fj);
	cout << scr_h<<" " << scr_w<<" "<< car.i<<" "<< car.j << endl;
	init(scr_h, scr_w);  //Inicialización de pantalla
	//signal(SIGWINCH, resizeHandler); //Detección de ajustado de pantalla para ajustar el mapa de forma acorde
	do{
		//car.actualizar_coche(map.sensor());
		//cout << "----------------------------"<< endl;
		//map.imprimirmapa();
		cout << scr_h<<" " << scr_w<<" "<< car.i<<" "<< car.j << endl;
		map.imprimirmapabien(scr_h, scr_w, car.i, car.j);
		control = car.algoritmo(alg,n,m);
		map.actualizarmapa(car.i,car.j);
	}while(control);
	endwin();  //Restauración configuración por defecto pantalla
	cout << Default;
}

void init(int& height, int& width) {
        initscr();
				cout << scr_h<<" " << scr_w<<" "<<" f " << endl;
        clear();
				cout << scr_h<<" " << scr_w<<" "<< " b " << endl;
        noecho();
				cout << scr_h<<" " << scr_w<<" "<<" v "<<  endl;
        cbreak();
				cout << scr_h<<" " << scr_w<<" c " << endl;
        //keypad(stdscr, TRUE);
        //curs_set(0);
				cout << scr_h<<" " << scr_w<<" "<< " - " << endl;
        getmaxyx(stdscr, height, width);
				cout << scr_h<<" " << scr_w<<" + " << endl;
}


/*void* resizeHandler(int sig){
	getmaxyx(stdscr, scr_h, scr_w);
}*/
