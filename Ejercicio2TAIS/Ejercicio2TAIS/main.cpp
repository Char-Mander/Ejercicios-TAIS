// Grupo E 
// TAIS09
//Laura Jiménez Fernández
//Pablo de Torre Barrio

/*Comentario funcionamiento*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "bintree_eda.h"
#include "01H.h"


/*El coste del problema es lineal respecto al los nodos del árbol, n, O(n), ya que se recorren todos los nodos
del árbol para comprobar si es AVL. */


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree<int> arbol = cargarArbol(-1);
	int nivel = 0, max = 0, min = 0;
	bool sol = resolver(arbol, nivel, max, min);
	if (sol) std::cout << "SI";
	else std::cout << "NO";
	std::cout << '\n';

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}