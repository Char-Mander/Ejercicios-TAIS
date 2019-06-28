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
#include "Matriz.h"


/*
int palindromo(palabra, i, j, valor){
if(j-1<i) return valor 
else {
if(palabra.at(i) == palabra.at(j)) 
return palindromo(palabra, i+1, j-1, valor);
else 
return std::min(palindromo(palabra, i+1, j, valor)+1, palindromo(palabra, i, j-1, valor)+1);
	}
}
*/

/*El coste de tiempo de rellenar la mitad de la matriz (pues la diagonal inferior izquierda se queda rellena con solo 0)
es de O(n*n/2 - n/2), siendo n la longitud de la palabra. (sale este coste debido a que recorremos la matriz desde la diagonal (sin contar esta)
hasta la esquina superior derecha. 
El coste de memoria es n*n, debido a que usamos una matriz de dimensión n.
*/


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	std::string palabra; 
	std::cin >> palabra;
	if (!std::cin)
		return false;
	
	Matriz<int> m(palabra.length(), palabra.length(), 0);
	for (int i = 0; i < palabra.length() - 1; i++){
		for (int f = 0, c = i + 1; c < palabra.length();c++){
			if (palabra.at(f) == palabra.at(c)) m[f][c] = m[f+1][c - 1];
			else m[f][c] = std::min(m[f + 1][c] + 1, m[f][c - 1] + 1);
			f++;
		}
	}
	std::cout << m[0][palabra.size()-1] << '\n';
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