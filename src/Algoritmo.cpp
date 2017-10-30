#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>

#define BVerde "\x1B[102m" //colores
#define FVerde "\x1B[32m"
#define FNegro "\x1B[30m"
#define FRojo "\x1B[31m"
#define FMagenta "\x1B[35m"
#define FRosa "\x1B[95m"
#define Default "\x1B[49m"

using namespace std;

const int n = 25; // tamaño horizontal del mapaa
const int m = 25; // tamaño vertical del mapaa
static int mapa[n][m];
static int lista_cerrada_nodos[n][m]; // aquí es donde se van guardando los nodos que se ya se han intentado en un mapaa
static int lista_abierta_nodos[n][m]; // mapaa de los nodos abiertos (no se han tocado)
static int dircc_padres_mapa[n][m]; // mapaa de las direcciones para saber después donde han ido los padres e hijos.
const int dir = 4; 		  // numero de direcciones posibles

static int dx[dir]={1, 0, -1, 0};
static int dy[dir]={0, 1, 0, -1};
				    	// if dir==8
//static int dx[dir] = { 1, 1, 0, -1, -1, -1, 0, 1 };
// int dy[dir] = { 0, 1, 1, 1, 0, -1, -1, -1 };

class nodos{
	// posiciones actuales
	int xPos;
	int yPos;
	// distancia que ya se ha recorrido hasta el nodo.
	int distancia;
	// prioridad = nivel + estimación de la distancia restante LA MAS IMPORTANTE ES EL QUE TENGA LA PRIORIDAD MÁS BAJA
	int prioridad;

public:
	nodos(int xp, int yp, int d, int p){ //pillamos el inicio y el final aqui
		xPos = xp;
		yPos = yp;
		distancia = d;
		prioridad = p;
	}

	int getxPos() const { return xPos; }
	int getyPos() const { return yPos; }
	int getdistancia() const { return distancia; }
	int getprioridad() const { return prioridad; }

	void updateprioridad(const int& xDest, const int& yDest){ //funcion que va actualizando las prioridades de los nodos
																//gracias a las distancias
		prioridad = distancia + estimate(xDest, yDest) * 10; //A*   //CUANTO MENOR SEA LA PRIORIDAD MEJOR
	}

	// solo se usa si se va en diagonal o si se usa la distancia euclidiana para el calculo y comparacion de las distancias de las casillas subyacentes
	void nextdistancia(const int & i){
		distancia += (dir == 8 ? (i % 2 == 0 ? 10 : 14) : 10);
	}

	// Distancias para el final estoy usando la euclídea
	const int & estimate(const int& xDest, const int& yDest) const{
		static int xd, yd, d;
		xd = xDest - xPos;
		yd = yDest - yPos;
		// Euclídea
		d = static_cast<int>(sqrt(xd*xd + yd*yd));
		// Manhattan
		//d=abs(xd)+abs(yd);
		// Mahalanobich
		//d=max(abs(xd), abs(yd));
		return(d);
	}
};

// Determina la prioridad en la cola, para eso, hay que sobrecargar el operador <
bool operator<(const nodos& a, const nodos& b){
	return a.getprioridad() > b.getprioridad();
}

// El algoritmo A* en si
// Retorna un string de direcciones
string pathFind(const int& xStart, const int& yStart,
	const int& xFinish, const int& yFinish){
	static priority_queue<nodos> pq[2]; // lista de nodos no visitados
	static int pqi; // para ver la lista
	static nodos* n0;
	static nodos* m0;
	static int i, j, x, y, xdx, ydy;
	static char c;
	pqi = 0;
	// limpieza del mapaa
	for (y = 0; y<m; y++)	{
		for (x = 0; x<n; x++)	{
			lista_cerrada_nodos[x][y] = 0;
			lista_abierta_nodos[x][y] = 0;
		}
	}
	// Se crea el primer nodo y se mete en la lista, se mete el punto inicial
	n0 = new nodos(xStart, yStart, 0, 0);
	n0->updateprioridad(xFinish, yFinish); //aquí inicializamos la prioridad a 0
	pq[pqi].push(*n0);
	lista_abierta_nodos[x][y] = n0->getprioridad(); // y empezamos el calculo

											  // Aquí empieza la busqueda A*
	while (!pq[pqi].empty()){ //mientras las listas no estén vacías se sigue iterando
		n0 = new nodos(pq[pqi].top().getxPos(), pq[pqi].top().getyPos(),  //pillamos el nodo con la prioridad más alta de la lista abierta
		pq[pqi].top().getdistancia(), pq[pqi].top().getprioridad());
		x = n0->getxPos(); y = n0->getyPos();
		pq[pqi].pop(); 														//Una vez examinado se pasa de la lista abierta a la cerrada
		lista_abierta_nodos[x][y] = 0;
		lista_cerrada_nodos[x][y] = 1;
		if (x == xFinish && y == yFinish)	{									//la búsqueda se acaba si se llega a la meta
			string path = "";										//sino es el final se guarda una cadena vacía
			while (!(x == xStart && y == yStart))			{
				j = dircc_padres_mapa[x][y];
				c = '0' + (j + dir / 2) % dir;
				path = c + path;
				x += dx[j];
				y += dy[j];
			}
			delete n0;
																	// se vacian los nodos que sobran
			while (!pq[pqi].empty()) pq[pqi].pop();
			return path;
		}

																// se generan movimientos en todas las posibles direcciones (n)odos hijos)
		for (i = 0; i<dir; i++)	{
			xdx = x + dx[i]; ydy = y + dy[i];
			if (!(xdx<0 || xdx>n - 1 || ydy<0 || ydy>m - 1 || mapa[xdx][ydy] == 1 || lista_cerrada_nodos[xdx][ydy] == 1))	{
																// se genera un nodo hijo
				m0 = new nodos(xdx, ydy, n0->getdistancia(),
				n0->getprioridad());
				m0->nextdistancia(i);
				m0->updateprioridad(xFinish, yFinish);
																// si no está el nodo en la lista abierta se añade a la misma
				if (lista_abierta_nodos[xdx][ydy] == 0)	{
					lista_abierta_nodos[xdx][ydy] = m0->getprioridad();
					pq[pqi].push(*m0);
																//marcar la dirección del nodo padre
					dircc_padres_mapa[xdx][ydy] = (i + dir / 2) % dir;
				}
				else if (lista_abierta_nodos[xdx][ydy]>m0->getprioridad()){
																// Actualizar las prioridades
					lista_abierta_nodos[xdx][ydy] = m0->getprioridad();
																	// Actualizar las direcciones de los nodos padres
					dircc_padres_mapa[xdx][ydy] = (i + dir / 2) % dir;
					// reemplazar el nodo
					// vaciando un pq al otro
					// excepto que el nodo a ser reemplazado será ignorado
					// y el nuevo nodo se insertará en su lugar
					while (!(pq[pqi].top().getxPos() == xdx && pq[pqi].top().getyPos() == ydy)){
						pq[1 - pqi].push(pq[pqi].top());
						pq[pqi].pop();
					}
					pq[pqi].pop(); 					//se borra el nodo objetivo
								   					// Se cambia el nodo mas grande por el mas pequeño (sus heuristicas)
					if (pq[pqi].size()>pq[1 - pqi].size()) pqi = 1 - pqi;
					while (!pq[pqi].empty()){
						pq[1 - pqi].push(pq[pqi].top());
						pq[pqi].pop();
					}
					pqi = 1 - pqi;
					pq[pqi].push(*m0); 				// Se añade el mejor nodo
				}
				else delete m0;
			}
		}
		delete n0;
	}
	return ""; 										// No se ha encontrado ruta
}

int main(void){
	int eleccion;
	srand(time(NULL));
	// Se crea un mapaa vacío
	for (int y = 0; y<m; y++)	{
		for (int x = 0; x<n; x++) mapa[x][y] = 0;
	}
			// poner los obstáculos
	cout<<"ELija si quiere obstaculos aleatorios o ponerlos (1,2)"<<endl;
	cin>>eleccion;
	if(eleccion == 1)	{
		int num,i,j;
	cout << "Introduzca el porcentaje de obstaculos: ";
	cin >> num;
	cout << endl;
	num = m * n * num / 100;
	srand (time(NULL));

	for(int c = 0; c <= num; c++){
		i = rand() % m + 0;
		j = rand() % n + 0;
		mapa[i][j] = 1;
	}
    }else if(eleccion == 2){
    	int num2;
	do {
		cout << "Introduzca el numero de obstaculos: ";
		cin >> num2;
		cout << endl;
		if (num2 > (m * n)) {
			cout << "Numero de obstaculos mayor que numero de celdas." << endl;
		}
	} while (num2 > (m * n));
	for (int i = 0; i < num2; i++) {
		int a, b;
		cout << "Introduzca las coordenadas i: ";
		cin >> a;
		cout << "Introduzca las coordenadas j: ";
		cin >> b;
		mapa[a][b] = 1;
	}
    }else {
	cout<<"opcion incorrecta"<<endl;
	return(-1);
}
	// Seleccionar inicio y fin
	int xA, yA, xB, yB;
	cout<<"introduce principio x"<<endl;
	cin>>xA;
	cout<<"introduce principio y"<<endl;
	cin>>yA;
	cout<<"introduce final x"<<endl;
	cin>>xB;
	cout<<"introduce final y"<<endl;
	cin>>yB;
	cout << "mapa Size (X,Y): " << n << "," << m << endl;
	cout << "Start: " << xA << "," << yA << endl;
	cout << "Finish: " << xB << "," << yB << endl;
	// pillar la ruta
	clock_t start = clock();
	string route = pathFind(xA, yA, xB, yB); //constructor
	if (route == "") cout << "No se ha encontrado ruta" << endl;
	clock_t end = clock();
	double time_elapsed = double(end - start);
	cout << "Time to calculate the route (s): " << time_elapsed/1000000 << endl;
	// mostrar la ruta
	if (route.length()>0)	{
		int j; char c;
		int x = xA;
		int y = yA;
		mapa[x][y] = 2;
		for (int i = 0; i<route.length(); i++){
			c = route.at(i);
			j = atoi(&c);
			x = x + dx[j];
			y = y + dy[j];
			mapa[x][y] = 3;
			for (int y = 0; y<m; y++)	{
				for (int x = 0; x<n; x++)
					if (mapa[x][y] == 0)
						cout << BVerde << FVerde << "~";
					else if (mapa[x][y] == 1)
						cout << BVerde << FNegro << "0"; //obstaculo
					else if (mapa[x][y] == 2)
						cout << BVerde << FRojo << "S"; //inicio
					else if (mapa[x][y] == 3)
						cout << BVerde << FMagenta<< "*"; //ruta
					else if (mapa[x][y] == 4)
						cout << BVerde << FRosa << "F"; //final
				cout << endl;
			}
			cout << "------------------------------------------------------"<<endl;
			usleep(500*1000);
		}
		mapa[x][y] = 4;
		for (int y = 0; y<m; y++)	{
			for (int x = 0; x<n; x++)
			if (mapa[x][y] == 0)
				cout << BVerde << FVerde << "~";
			else if (mapa[x][y] == 1)
				cout << BVerde << FNegro << "0"; //obstaculo
			else if (mapa[x][y] == 2)
				cout << BVerde << FRojo << "S"; //inicio
			else if (mapa[x][y] == 3)
				cout << BVerde << FMagenta<< "*"; //ruta
			else if (mapa[x][y] == 4)
				cout << BVerde << FRosa << "F"; //final
			cout << endl;
		}
		cout << Default;
	}
	return(0);
}
