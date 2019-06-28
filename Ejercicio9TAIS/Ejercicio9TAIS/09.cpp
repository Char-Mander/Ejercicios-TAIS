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
#include "Grafo.h"

class Amigos {
public:
	Amigos(Grafo const& g) : marcado(g.V(), false), maxi(0) {
		for (size_t v = 0; v < g.V(); ++v) {
			if (!marcado[v]) {
				size_t tam = 0;
				dfs(g, v, tam);
				if (tam > maxi)
					maxi = tam;
			}
		}
	}
	size_t maximo() const {
		return maxi;
	}
private:
	std::vector<bool> marcado;
	size_t maxi;

	void dfs(Grafo const& g, size_t v, size_t & tam) {
		marcado[v] = true;
		++tam;
		for (size_t w : g.adj(v))
			if (!marcado[w])
				dfs(g, w, tam);
	}
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int V, E;
	std::cin >> V >> E;//Vértices y aristas

	Grafo grafo(V);//O(V)

	int v, w;
	for (int i = 0; i < E; ++i) { //O(E)
		std::cin >> v >> w;
		grafo.ponArista(v - 1, w - 1);
	}

	Amigos amigos(grafo); //O(V+E)

	std::cout << amigos.maximo() << '\n';
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