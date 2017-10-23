/**
 * @file   coche.h
 * @Author Miguel Jiménez Gomis ,German y Daniel
 * @date   Octubre, 2017
 * @brief  Fichero de cabecera de la clase coche
 *
 * En este fichero se encuentra la descirpcion de la clase coche , asi como sus cabeceras y documentacion de las mismas
 */
#pragma once

#include <cmath>
#include <iostream>
#include <vector>
#include <math.h>
#include <limits>

using namespace std;

class coche{
	int contadortemporal = 0;//para pruebas



	/**
	* @name Distancia Manhattan
	* @brief ejecuta 1 iteración de la funcion heurística en concreto
	* @retval bool que indica 1 si todo correcto, 0 si debe parar
	*/
	int Dist_Manhattan(int i, int j);

	/**
	* @name Distancia Euclidea
	* @brief ejecuta 1 iteración de la funcion heurística en concreto
	* @retval bool que indica 1 si todo correcto, 0 si debe parar
	*/
	int Dist_euclidea(int i, int j);

	/**
	* @name Distancia Mahalanobis
	* @brief ejecuta 1 iteración de la funcion heurística en concreto
	* @retval bool que indica 1 si todo correcto, 0 si debe parar
	*/
	int Dist_Mahalanobis(int i, int j);



public:
	int i, j;//posicion del coche
	int ia, ja; // posicion anterior;
	int fi,fj;//posicion meta
	bool fin;

vector<int> Distancia; //distancias de las posicion que le rodean con respecto a la meta
vector<int> Sensor;//0 norte 1 sur, 2este, 3 oeste
	/**
	* @name algoritmo
	* @brief Ejecuta 1 iteracion de 1 funcion heuristica en concreto
	*
	* @param [in] int dummy , valor que selecciona una de las 3 funciones heuristicas
	* @retval bool que indica 1 si todo correcto, 0 si debe parar
	*/
	bool algoritmo(int dummy, int n, int m);

	/**
	* @name Constructor
	* @brief Inicializa un objeto cuyos valores son dados por los parámetros
	*
	* @param [in] int a posicion i inicial del coche
	* @param [in] int b posicion j inicial del coche
	* @param [in] int c posicion i inicial de la meta
	* @param [in] int d posicion j inicial de la meta
	*/
	coche(int a, int b, int c, int d);

	int seleccion(int dummy, int i, int j);

	void act_distancias(int dummy,int n, int m);

};
