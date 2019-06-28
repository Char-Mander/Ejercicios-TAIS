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



/*Este problema tiene un coste lineal respecto al n�mero de agujeros que tiene cada manguera O(N)

Teniendo el vector con la soluci�n voraz XN (donde N es la longitud de la manguera) y el vector con la soluci�n �ptima YN, donde en cada posici�n se comprueba
el contador nParches (que acumula el n�mero de parches usados).

X1 ... Xk ... XN			-Nunca se podr�a dar el caso de que Xk > Yk (es decir, que el vector con la soluci�n voraz acumulara m�s parches que el vector de la soluci�n �ptima)
=	   !=					-Si Xk < Yk : Entonces, se podr�a mejorar la soluci�n �ptima, ya que seg�n la soluci�n voraz se pueden usar menos parches.
Y1 ... Yk ... YN



*/
int resolver(std::vector<int> const &parches, int longitud) {
	int N = parches.size();
	int nParches = 1, acumulado = parches[0]+longitud;
	
	for (int i = 1; i < N; i++){
		if (acumulado < parches[i]){
			++nParches;
			acumulado = parches[i] + longitud;
		}
	}

	return nParches;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio�n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n; 
	std::cin >> n;
	if (!std::cin)
		return false;
	int l, pos;
	std::vector<int>parches(n);
	std::cin >> l;

	for (int i = 0; i < n; i++){
		std::cin >> pos;
		parches[i] = pos;
	}

	int sol = resolver(parches, l);

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