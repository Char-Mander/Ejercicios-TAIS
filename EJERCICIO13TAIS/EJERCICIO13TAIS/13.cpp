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
#include "Matriz.h"

class ovejaNegra {
public:
	ovejaNegra(Matriz<char> const& a, Matriz<bool> const& m)
		: oveja(a), marcado(m) {
	}

	//La función tiene coste lineal respecto al tamaño de la matriz O(n)
	// Siendo n = f*c
	void cuentaBlancas(int &ovejasBlancas) {
		for (int i = 0; i < oveja.numfils(); i++){
			for (int j = 0; j < oveja.numcols(); j++){
				if (!marcado[i][j] && oveja[i][j] == '.') {
					recorrido(i, j);
					ovejasBlancas++;
				}
			}
		}
	}

private:
	Matriz<char> oveja;
	Matriz<bool> marcado;
	int mejSol;
	void recorrido(int i, int j) {
		marcado[i][j] = true;

		if (i - 1 >= 0 && !marcado[i - 1][j] && oveja[i - 1][j] == '.')
			recorrido(i - 1, j);
		if (j + 1 < oveja.numcols() && !marcado[i][j + 1] && oveja[i][j + 1] == '.')
			recorrido(i, j + 1);
		if (i + 1 < oveja.numfils() && !marcado[i + 1][j] && oveja[i + 1][j] == '.')
			recorrido(i + 1, j);
		if (j - 1 >= 0 && !marcado[i][j - 1] && oveja[i][j - 1] == '.')
			recorrido(i, j - 1);
	}

	
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int c, f;

	std::cin >> c;
	if (!std::cin) return false;
	std::cin>> f;
	Matriz<char> a(f, c);
	Matriz<bool> m(f, c);
	char celda; 
	int ovejasBlancas=0;


	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			std::cin >> a[i][j];
		}
	}
	ovejaNegra blanca(a, m);
	blanca.cuentaBlancas(ovejasBlancas);
	std::cout << (ovejasBlancas - 1) << '\n';
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