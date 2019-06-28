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

class Bipartito {
public:
	Bipartito(Grafo const& g) : color(g.V(), 0), bipartito(true) {	}

	bool esBipartito(Grafo const& g) {
		for (size_t v = 0; v < g.V() && bipartito; ++v) {
			if (color[v] == 0) {
				color[v] = 1;
				bipartito = dfs(g, v);
			}
		}
		return bipartito;
	}
private:
	std::vector<int> color;
	bool bipartito;

	//Esta funcion es lineal respecto al numero de nodos del grafo O(V)
	bool dfs(Grafo const& g, size_t v) {
		bool bipartito = true;
		for (size_t w : g.adj(v)) {
			if (color[w] == 0 && color[v] == 1) {
				color[w] = 2;
				bipartito *= dfs(g, w);
			}
			else if (color[w] == 0 && color[v] == 2) {
				color[w] = 1;
				bipartito *= dfs(g, w);
			}
			else if (color[v] == color[w] && color[v] != 0)
				bipartito *= false;
		}
		return bipartito;
	}


};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int V, E;
	std::cin >> V >> E;//Vértices y aristas
	if (!std::cin)
		return false;

	Grafo grafo(V);//O(V)
	int v, w;
	for (int i = 0; i < E; ++i) { //O(E)
		std::cin >> v >> w;
		grafo.ponArista(v, w);
	}

	Bipartito Bipartito(grafo); //O(V+E)

	if (Bipartito.esBipartito(grafo))
		std::cout << "SI";
	else
		std::cout << "NO";
	std::cout << '\n';

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

		while(resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}