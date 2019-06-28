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



/*La función resolver tiene un coste lineal respecto al número de usuarios que esperan a subir en la cabina O(N)
La función resuelveCaso tiene coste nlog(N) dado que hay que ordenar el vector de N elementos*/
int resolver(std::vector<int> const &usuarios, int peso) {
	int j = usuarios.size() - 1;
	int i = 0;
	int nCabinas = 0;
	while (j > i){
		if ((usuarios[i] + usuarios[j]) > peso){
			j--;
			nCabinas++;
		}
		else{
			i++;
			j--; 
			nCabinas++;
		}

		if (i == j){
			nCabinas++;
			i++;
		}
	}

	return nCabinas;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int max; 
	std::cin >> max;
	if (!std::cin)
		return false;

	int usuarios, peso;
	std::cin >> usuarios;
	std::vector<int>cola(usuarios);
	

	for (int i = 0; i < usuarios; i++){
		std::cin >> peso;
		cola[i] = peso;
	}
	

	std::sort(cola.begin(), cola.end());
	int sol = resolver(cola, max);

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