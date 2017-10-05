#include <iostream>
#include "Mapa.cpp"
using namespace std;

class Coche{
  vector<int> Sensor;//0 norte 1 sur, 2este, 3 oeste
  int i,j;

  Coche(int a, int b){//hay que revisar lo relacionado con coche
    Sensor.resize(4);
    i = a; j = b;
  }

  void funcheuristica1();
  void funcheuristica2();
  void funcheuristica3();

  void algoritmo(int dummy){
    switch (dummy) {
      case 1:
        funcheuristica1();
        break;
      case 2:
        funcheuristica2();
        break;
      case 3:
        funcheuristica3();
        break;
    }
  }

};
