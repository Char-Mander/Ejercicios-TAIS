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
#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"

class CaminoAlCole {
public:
	CaminoAlCole(GrafoDirigidoValorado<int> const& g, long long int c) : marcado(g.V(), false), edgeTo(g.V()),
		first(g.V(), false), distTo(g.V()), cola(g.V()), cont(0), casoPeor(), encontrado(false), contC(g.V(), 0) {
		casoPeor = c;
	}

	long long int contarCaminos(GrafoDirigidoValorado<int> const& g) {
		caminos(g, 0);
		if (g.V() == 1)
			cont = 1;

		return cont;
	}


private:
	long long int cont, casoPeor;
	std::vector<AristaDirigida<int>> edgeTo;
	std::vector<long long int> distTo;
	std::vector<long long int> contC;
	std::vector<bool> marcado;
	std::vector<bool> first;
	bool encontrado;
	IndexPQ<int> cola;

	//Tiene coste lineal respecto al numero de aristas O(E) ya que cada arista se mira una vez y no se vuelve a pasar por ella
	void caminos(GrafoDirigidoValorado<int> const& g, size_t s) {
		
		for (int v = 0; v < g.V(); v++)
			distTo[v] = casoPeor;
		distTo[s] = 0;
		cola.push(s, 0);
		marcado[s] = true;
		contC[s] = 1;

		while (!cola.empty()) {
			int v = cola.top().elem;
			cola.pop();
			marcado[s] = false;
			for (auto e : g.adj(v)) {
				relax(e, g.V());
			}
		}

		if (encontrado) {
			cont = contC[g.V() - 1];
		}
		else
			cont = 0;
	}

	void relax(AristaDirigida<int> e, int fin) {
		int v = e.from(), w = e.to();
		//int aux;
		if (distTo[w] > distTo[v] + e.valor())
		{
			distTo[w] = distTo[v] + e.valor();
			//if(marcado[w])
				//aux = edgeTo[w].from();
			edgeTo[w] = e;
			if (w == fin - 1)
				encontrado = true;
			if (marcado[w]) {
				cola.update(w, distTo[w]);
				contC[w] = contC[v];
				//[v] = 1;
				first[w] = false;
			}
			else {
				contC[w] += contC[v];
				cola.push(w, distTo[w]);
				marcado[w] = true;
			}
		}
		else if (distTo[w] == distTo[v] + e.valor()) {
			contC[w] += contC[v];
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

	GrafoDirigidoValorado<int> grafo(V);//O(V)
	size_t v, w;
	int valor, casoPeor = 0;
	for (int i = 0; i < E; ++i) { //O(E)
		std::cin >> v >> w >> valor;
		grafo.ponArista({ v - 1, w - 1, valor });
		grafo.ponArista({ w - 1, v - 1, valor });
		casoPeor += valor;
	}

	CaminoAlCole camino(grafo, casoPeor + 1); //O(V+E)
	
	std::cout << camino.contarCaminos(grafo) << '\n';
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