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

using prioridad = std::pair<int, int>;
using inicial = int;

// Esta funcion tiene coste O(NlogN) respecto al numero de elementos del vector
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;

	std::cin >> n;
	if (n == 0)
		return false;
	IndexPQ<std::pair<prioridad, inicial>> cola(n+1);
	int usuario, periodo, k;
	for (int i = 1; i <= n; i++) {
		std::cin >> usuario >> periodo;
		cola.push(i, { {periodo, usuario}, periodo });
	}
	// escribir sol
	std::cin >> k;
	for (int i = 0; i < k; i++) {
		std::cout << cola.top().prioridad.first.second << '\n';
		cola.update(cola.top().elem, { { (cola.top().prioridad.first.first + cola.top().prioridad.second), cola.top().prioridad.first.second}, cola.top().prioridad.second });
	}

	std::cout << "----\n";
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