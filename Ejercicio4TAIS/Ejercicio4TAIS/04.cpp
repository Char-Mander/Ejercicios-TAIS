﻿// Grupo TAIS09 
//Laura Jiménez Fernández y Pablo de Torre Barrio
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "04H.h"



// función que resuelve el problema
// La función que resuelve el problema tiene coste O(logN), comentado en el TreeMap_AVL.h


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	std::cin >> n;
	if (n == 0)
		return false;

	map<int, int> arbol;
	int raiz;
	for (int i = 0; i < n; i++){
		std::cin >> raiz;
		if(!arbol.contains(raiz))
			arbol.insert({ raiz, raiz });
	}

	int k, num, sol;
	std::cin >> k;
	for (int i = 0; i < k; i++) {
		std::cin>>num;
		try {
			arbol.kesimo(num, sol);
			std::cout << sol << '\n';
		}
		catch (std::domain_error) {
			std::cout << "??\n";
		}
	}
	std::cout << "----\n";

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("prueba.txt");
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