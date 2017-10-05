#include <iostream>
#include <vector>
//casillas vacias: ░ ~
//coche: X
//meta: #
//obstaculo █ 0
using namespace std;

class mapa{
  vector< vector<char> > matriz;
  int m, n, inicioi, inicioj, fini, finj;
//  Coche coche(inicioi,inicioj); <---- hay que ver que hacemos con esto

  void obstaculo_a_mano(){//completo
    int num;
    do{
      cout<<"Introduzca el numero de obstaculos: ";
      cin >> num;
      cout << endl;
      if(num > (m * n)){
        cout << "Numero de obstaculos mayor que numero de celdas." << endl;
      }
    }while (num > (m * n));
    for(int i = 0; i < num; i++){
      int a ,b;
      cout << "Introduzca las coordenadas i: ";
      cin >> a;
      cout << "Introduzca las coordenadas j: ";
      cin >> b;
      matriz[a][b] = '0';
    }
  };

  void obstaculos_aleatorios();

public:

  mapa(int _m, int _n, int _inicioi, int _inicioj, int _fini, int _finj, int control){
    m = _m; n = _n;
    inicioi = _inicioi; inicioj = _inicioj;
    fini = _fini; finj =  _finj;
    matriz.resize(m);//se hace la matriz del tamaño correcto
    for(int i = 0; i < m; i++){
      matriz[i].resize(n);
    }
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
        matriz[i][j] = '~';
      }
    }
    switch (control) {
      case 1:
        obstaculo_a_mano();
        break;
      case 2:
        //obstaculos_aleatorios();
        break;
    }
    matriz[inicioi][inicioj] = 'X';
    matriz[fini - 1][finj - 1] = '#';
  };

  void imprimirmapa(){
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
        cout << matriz[i][j];
      }
      cout << endl;
    }
  };

//funcion que se le pasa la nueva posicion del coche y actualiza el mapa
  void actualizarmapa(int a, int b){
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
        if(matriz[i][j] == 'X'){
          matriz[i][j] == 'x';
        }
      }
    }
    matriz[a][b] == 'X';
  };

//funcion que retorna los datos leidos por el sensor del coche
  vector<int> Sensor(int i, int j){
    vector<int> v;
    v.resize(4);
    if(i == 0){//norte
      v[0] = 1;
    } else{
      if(matriz[i - 1][j] == '0'){
        v[0] = 1;
      } else{
        v[0] = 0;
      }
    }
    if(i == (n - 1)){//sur
      v[1] = 1;
    } else{
      if(matriz[i + 1][j] == '0'){
        v[1] = 1;
      } else{
        v[1] = 0;
      }
    }
    if(j == 0){//ester
      v[2] = 1;
    } else{
      if(matriz[i][j - 1] == '0'){
        v[2] = 1;
      } else{
        v[2] = 0;
      }
    }
    if(i == (m - 1)){//oeste
      v[3] = 1;
    } else{
      if(matriz[i][j + 1] == '0'){
        v[3] = 1;
      } else{
        v[3] = 0;
      }
    }
    return v;
  };
  void getinicio(int &a, int &b){  // la posicion inicial para el coche
    a = inicioi;
    b = inicioj;
  }

};
