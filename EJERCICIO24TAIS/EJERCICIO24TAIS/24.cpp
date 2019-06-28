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
#include "Hora.h"

using pelicula = std::pair <hora, hora>;
/*resolver tiene un coste lineal respecto al n�mero de pel�culas que hay, O(N)
resuelveCaso, en cambio, tiene coste nlog(N) respecto al n�mero de elementos que tiene el vector, pues se ordena.

Teniendo el vector con la soluci�n voraz XN (donde N es el n�mero total de pel�culas disponibles) y el vector con la soluci�n �ptima YN, donde en cada posici�n se comprueba
el contador vistas (que acumula el n�mero de pel�culas que ha podido ver).

X1 ... Xk ... XN			-Nunca se podr�a dar el caso de que Xk < Yk (es decir, que el vector con la soluci�n voraz indicara que ha visto menos pel�culas
										que el vector de la soluci�n �ptima)
=	   !=					
							-Si Xk > Yk : Entonces, se podr�a mejorar la soluci�n �ptima, ya que seg�n la soluci�n voraz se pueden ver m�s pel�culas.
Y1 ... Yk ... YN
*/
int resolver(std::vector<pelicula> const &peliculas, int numPeliculas) {
	int N = peliculas.size();
	int vistas = 1;
	hora descanso = descanso.convertirMinutos(10);
	
	for (int i = 1; i < N; i++){
			if ((peliculas[i - 1].first + descanso) < peliculas[i].second ||
				(peliculas[i - 1].first + descanso) == peliculas[i].second){
				vistas++;
			}
		
	}
		
	return vistas;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio�n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nPeliculas; 
	std::cin >> nPeliculas;
	if (nPeliculas == 0)
		return false;
	std::vector<pelicula> p(nPeliculas);
	pelicula sacarDatos;
	hora horafin;
	int d;
	for (int i = 0; i < nPeliculas; i++){
		std::cin >> sacarDatos.second >> d;
		sacarDatos.first = sacarDatos.second + horafin.convertirMinutos(d);
		p[i] = sacarDatos;
	}
	
	

	std::sort(p.begin(), p.end());

	int sol = resolver(p, nPeliculas);

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