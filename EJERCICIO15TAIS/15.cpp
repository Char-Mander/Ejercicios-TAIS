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
#include <queue>
#include "GrafoValorado.h"
#include "IndexPQ.h"

class BarroCity {
public:
	BarroCity(GrafoValorado<int> const& g, long long int c) : marcado(g.V(), false), cola(), prioridades(g.E()), camino(0), cont(0), vertices(0) {	}

	int pavimentar(GrafoValorado<int> const& g) {
		caminoMinimo(g, 0, 0);
		return camino;
	}


private:
	std::vector<bool> marcado;
	std::queue<Arista<int>> cola;
	IndexPQ<Arista<int>> prioridades;
	long long int camino;
	int cont, vertices;


	//Tiene coste lineal respecto al numero de aristas O(E) ya que cada arista se mira una vez y se elimina
	void caminoMinimo(GrafoValorado<int> const& g, size_t v, int c) {
		visitar(g, 0);

		while (!prioridades.empty() && cola.size() < g.V() - 1) {

			auto arista = prioridades.top().prioridad;
			prioridades.pop();

			int v = arista.uno(), w = arista.otro(v);

			if (!marcado[v] || !marcado[w]) 
				cola.push(arista);
			if (!marcado[v])
				visitar(g, v);
			if (!marcado[w])
				visitar(g, w);
		}

		if (vertices == g.V()) {
			while (!cola.empty()) {
				camino += cola.front().valor();
				cola.pop();
			}
		}
		else
			camino = -1;
	}

	void visitar(GrafoValorado<int> const& g, size_t v) {
		marcado[v] = true;
		vertices++;
		for (auto w : g.adj(v)) {
			if (!marcado[w.otro(v)]) {
				prioridades.push(cont, w);
				cont++;
			}
		}
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

	GrafoValorado<int> grafo(V);//O(V)
	size_t v, w;
	int valor;
	long long int casoPeor = 0;
	for (int i = 0; i < E; ++i) { //O(E)
		std::cin >> v >> w >> valor;
		casoPeor += valor;
		grafo.ponArista({v - 1, w - 1, valor});
	}

	BarroCity barro(grafo, casoPeor); //O(V+E)
	
	int sol = barro.pavimentar(grafo);
	if (sol == -1)
		std::cout << "Imposible\n";
	else
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

		while(resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}