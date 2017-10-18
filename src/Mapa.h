/**
 * @file   Mapa.h
 * @Author Miguel Jiménez Gomis , German y Daniel
 * @date   Octubre, 2017
 * @brief  Fichero de cabecera de la clase Mapa
 *
 * En este fichero se encuentra la descirpcion de la clase Mapa , asi como sus cabeceras y documentacion de las mismas
 */
#pragma once
#include <iostream>
#include <vector>
#include <cstring>
#include "coche.h"
//casillas vacias: ░ ~
//coche: X
//meta: #
//obstaculo █ 0

using namespace std;

class Mapa{

	int m, n, inicioi, inicioj, fini, finj;

	void muestra(char a);

	/**
	* @name obstaculo_a_mano
	* @brief Introduce a mano los diferentes obstaculos en el mapa
	*/
	void obstaculo_a_mano();

	/**
	* @name obstaculos_aleatorios
	* @brief Se inicializan de manera aleatoria los obstaculos en el mapa
	*/
	void obstaculos_aleatorios();

public:
	vector< vector<char> > matriz;

	/**
	* @name Constructor
	* @brief Inicializa un objeto cuyos valores son dados por los parámetros
	*
	* @param [in] int _m anchura matriz
	* @param [in] int _n altura matriz
	* @param [in] int _inicioi posicion i inicial del coche
	* @param [in] int _inicioj posicion j inicial del coche
	* @param [in] int _fini posicion i inicial de la meta
	* @param [in] int _finj posicion j inicial de la meta
	* @param [in] int control indica la amera de generar obstaculos (1 a mano, 2 aleatorios)
	*/
	Mapa(int _m, int _n, int _inicioi, int _inicioj, int _fini, int _finj, int control);

	/**
	* @name imprimirmapa
	* @brief Muestra por pantalla la matriz
	*/
	void imprimirmapa();

	/**
	* @name actualizarmapa
	* @brief actualiza la posicion del coche en el mapa
	*
	* @param [in] int a nueva posicion i del coche
	* @param [in] int b nueva posicion j del coche
	*/
	void actualizarmapa(int a, int b); //funcion que se le pasa la nueva posicion del coche y actualiza el mapa

	/**
	* @name Sensor
	* @brief Retorna un vector con la deteccion de obstaculos en el alrededor del coche
	*
	* @param [in] int i posicion i del coche
	* @param [in] int j posicion j del coche
	* @retval Retorna un vector de enteros (vector<int>) con los 4 datos
	*/
	vector<int> Sensor(int i, int j); //funcion que retorna los datos leidos por el sensor del coche

	/**
	* @name Constructor
	* @brief Retorna por referencia la posicion inicial del coche
	*/
	void getinicio(int &a, int &b);  // la posicion inicial para el coche

	void imprimirmapabien(int h, int w, int car_i, int car_j);
};
