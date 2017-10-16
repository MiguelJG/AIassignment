#include "Mapa.h"
#include "coche.h"
//#include <ncurses.h>

/*void* resizeHandler(int);
void init(int& height, int& width);
int scr_h, scr_w;
*/
int main() {
	/*init(scr_h, scr_w);
	signal(SIGWINCH, resizeHandler)
	*/
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
	do{
		cout << "----------------------------"<< endl;
		map.imprimirmapa();
		//car.actualizar_coche(map.sensor());
		control = car.algoritmo(alg);
		map.actualizarmapa(car.i,car.j);
	}while(control);

}

/*void init(int& height, int& width) {
        initscr();
        clear();
        noecho();
        cbreak();
        //keypad(stdscr, TRUE);
        curs_set(0);
        getmaxyx(stdscr, height, width);
}


void* resizeHandler(int sig){
	getmxyx(stdscre, scr_h, scr_w);
}*/
