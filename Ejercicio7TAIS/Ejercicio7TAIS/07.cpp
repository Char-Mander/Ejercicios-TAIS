// Grupo TAIS09
// Laura Jiménez Fernández
// Pablo de Torre Barrio
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "PriorityQueue.h"

using prioridad = std::pair<int, int>;
using inicial = int;
bool resuelveCaso() {
	//leer los datos de la entrada
	int medio, parejas;
	std::cin >> medio >> parejas;
	if (medio == 0 && parejas==0)
		return false;

	PriorityQueue<int, std::greater<int>> colaiz;
	PriorityQueue<int, std::less<int>> colader;

	int iz, der, aux;
	for (int i = 0; i < parejas; i++){
		std::cin >> iz >> der;
		if (iz > der) {
			aux = iz;
			iz = der;
			der = aux;
		}
		if (i == 0){
			if (iz > medio){
				colaiz.push(medio);
				colader.push(der);
				medio = iz;
			}
			else if (medio > der){
				colader.push(medio);
				colaiz.push(iz);
				medio = der;
			}
			else{
				colaiz.push(iz);
				colader.push(der);
			}
		}
		else{
			if (iz > medio){
				colaiz.push(medio);
				colader.push(iz);
				colader.push(der);
				medio = colader.top();
				colader.pop();
			}
			else if(der<medio){
				colaiz.push(iz);
				colaiz.push(der);
				colader.push(medio);
				medio = colaiz.top();
				colaiz.pop();
			}
			else{
				colader.push(der);
				colaiz.push(iz);
			}
		}
		std::cout << medio << " ";
	}



	std::cout << '\n';
	
	return true;
}

//
int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}