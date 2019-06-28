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
#include <vector>
#include "Matriz.h"


/*
int ebanisto(matriz, i, j, vector){
if(i==j+1) return 0
else {
ebanisto(i,j) = min(2*(m[j]-m[i] + ebanisto(i,k) + ebanisto(k,j));
}
*/

/*El coste de tiempo de rellenar la mitad de la matriz (pues la diagonal inferior izquierda se queda rellena con solo 0)
es de O((2+cortes)^3) (aproximadamente) siendo cortes el número de cortes a realizar
El coste de memoria es ((2+cortes)*(2+cortes)) + (2+cortes), debido a que usamos una matriz de dimensión 2+cortes  (siendo cortes el número 
de cortes a realizar en el tronco) y a que usamos un vector de tamaño 2+cortes.
*/


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tamTab, cortes;
	std::cin >> tamTab >> cortes;
	if (tamTab == 0 && cortes == 0)
		return false;
	std::vector<int>v;
	v.push_back(0);
	int dato;
	for (int i = 0; i < cortes; i++){
		std::cin >> dato;
		v.push_back(dato);
	}
	v.push_back(tamTab);

	Matriz<int> m(v.size(), v.size(), 0);

	for (int i = 0; i < v.size(); i++){
		for (int f = 0, c = i + 2; f < v.size(), c < v.size(); f++, c++){
			m[f][c] = 2 * (v[c] - v[f]);
			int min = m[f][f + 1] + m[f + 1][c];
			for (int k = f + 2; k < c; k++)
				if (min>(m[f][k] + m[k][c])) min = m[f][k] + m[k][c];
			
			m[f][c] += min;
		}
	}
	std::cout << m[0][v.size()-1] << '\n';
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