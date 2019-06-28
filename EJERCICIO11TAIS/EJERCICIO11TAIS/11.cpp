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
#include "GrafoDirigido.h"

class Arborescencia {
public:
	Arborescencia(GrafoDirigido const& g) : marcado(g.V(), false), cont(), root(),ciclo() {
		cont = 0;
		root = 0;
		ciclo = false;
		rizq = false;
	}

	//Esta funcion es lineal respecto al numero de vertices del grafo O(V) ya que solo se recorre cada uno una vez 
	bool esArborescente(GrafoDirigido const& g) {
		if (g.V() <= g.E())
			return false;
		for (size_t v = 0; v < g.V(); ++v) {
			if (!marcado[v]) {
				root = v;
				rizq = true;
				dfs(g, v);
			}
		}
		return (cont == (g.V()-1)) && !marcado[root] && !ciclo;
	}

	int raiz() const  { return root; }
private:
	std::vector<bool> marcado;
	int root, cont;
	bool ciclo, rizq;


	//Esta funcion es lineal respecto al numero de nodos del grafo O(V)
	void dfs(GrafoDirigido const& g, size_t v) {

		for (size_t w : g.adj(v)) {
			if (!marcado[w]) {
				rizq = false;
				marcado[w] = true;
				cont++;
				dfs(g, w);
			}
			else if (marcado[w] && rizq) {
				ciclo = true;
			}
		//	rizq = false;
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

	GrafoDirigido grafo(V);//O(V)
	int v, w;

	for (int i = 0; i < E; ++i) { //O(E)
		std::cin >> v >> w;
		grafo.ponArista(v, w);
	}

	Arborescencia sol(grafo); //O(V+E)

	if (sol.esArborescente(grafo))//O(V)
		std::cout << "SI " << sol.raiz();
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