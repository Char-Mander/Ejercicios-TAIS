// Grupo TAIS09
// Laura Jim�nez Fern�ndez
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
#include "PriorityQueue.h"

using horario = std::pair<int, int>;
/*resolver  tiene un coste Nlog(N) respecto al n�mero de conferencias que hay, O(N)
resuelveCaso tiene coste Nlog(N) respecto al n�mero de elementos que tiene el vector, pues se ordena.

Teniendo el vector con la soluci�n voraz XN (donde N es el n�mero total de conferencias) y el vector con la soluci�n �ptima YN, donde en cada posici�n se comprueba
el tama�o de la cola de prioridad.

X1 ... Xk ... XN			-Nunca se podr�a dar el caso de que Xk > Yk (es decir, que el vector con la soluci�n voraz indicara que ha ocupado m�s salas
										que el vector de la soluci�n �ptima)
=	   !=					
							-Si Xk < Yk : Entonces, se podr�a mejorar la soluci�n �ptima, ya que seg�n la soluci�n voraz se pueden ocupar menos salas.
Y1 ... Yk ... YN
*/
int resolver(std::vector<std::pair<int, int>> const &conferencias) {
	int N = conferencias.size();
	PriorityQueue <horario> cola;
	cola.push({ conferencias[0].second, conferencias[0].first });
	
	for (int i = 1; i < N; i++){
			if (cola.top().first <= conferencias[i].first){
				cola.pop();
			}
			cola.push({ conferencias[i].second, conferencias[i].first });
		
	}
		
	return cola.size();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio�n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nConferencias; 
	std::cin >> nConferencias;
	if (nConferencias == 0)
		return false;
	std::vector<std::pair<int, int>> c(nConferencias);
	for (int i = 0; i < nConferencias; i++){
		std::cin >> c[i].first >> c[i].second;
	}
	
	std::sort(c.begin(), c.end());

	int sol = resolver(c);

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