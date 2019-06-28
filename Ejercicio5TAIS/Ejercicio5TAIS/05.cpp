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
#include "IndexPQ.h"


// Esta funcion tiene coste O(NlogN) respecto al numero de elementos del vector
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;

	std::cin >> n;
	if (n == 0)
		return false;
	IndexPQ<long int> cola(n + 1);
	long int aux, ini, cont = n, nGorras = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> ini;
		cola.push(i, ini);
	}

	// escribir sol
	while (cont>1){
		aux = cola.top().prioridad;
		cola.pop();
		nGorras += cola.top().prioridad+aux;
		cola.update(cola.top().elem, (cola.top().prioridad + aux));
		cont--;
	}

	std::cout << nGorras << '\n';

	return true;

}

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