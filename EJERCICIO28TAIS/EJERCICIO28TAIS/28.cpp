// Grupo TAIS09
// Laura Jiménez Fernández
// Pablo de Torre Barrio
/*Comentario funcionamiento*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>

using info = std::pair<int, int>; //el primer valor será el tiempo + 2*tiempo, y el segundo será el valor del tesoro

int resolver(std::vector<std::pair<int, info>> const &tesoros, int pos, int tTotal, int valorAcumulado) {
	if (tTotal - tesoros[pos].second.first >= 0 && tesoros.size()>pos){
		return resolver(tesoros, pos + 1, tTotal - tesoros[pos].second.first, valorAcumulado + tesoros[pos].second.second);
	}
	else
		return valorAcumulado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tTotal; 
	std::cin >> tTotal;
	if (!std::cin)
		return false;
	int numTesoros, valor, t;
	std::cin >> numTesoros;
	std::vector<std::pair<int, info>> tesoro;
	std::pair<int, info> datos;
	for (int i = 0; i < numTesoros; i++){
		std::cin >> t >> valor;
		datos.first = (t + t * 2) / valor;
		datos.second.first = (t + t * 2);
		datos.second.second = valor;
		tesoro.push_back(datos);
	}
	
	std::sort(tesoro.begin(), tesoro.end());
	
	int sol = resolver(tesoro, 0, tTotal, 0);

	std::cout << sol << '\n';

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