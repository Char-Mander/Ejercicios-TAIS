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
#include "PriorityQueue.h"

using artistas = std::pair<int, int>;
using partituras = int;

// Esta funcion tiene coste O(NlogN + KlogN) siendo N el numero de instrumentos distintos y K el numero de partituras
// a asignar sin tener en cuenta las que se asignan al principio (ya que cada tipo de intrumento tiene que tener por lo menos una)
bool resuelveCaso() {
	int p;
	std::cin >> p;
	if (!std::cin) return false;
	int m, restantes = p, aux;
	std::cin >> m;
	PriorityQueue <artistas, std::greater <int>> cola;
	for (int i = 0; i < m; i++){
		std::cin >> aux;
		cola.push({ aux, 1 });
		restantes--;
	}
	std::pair<int, int> paux;
	int valor, nuevoGrupo;
	while(restantes>0){
		paux = cola.top();
		cola.pop();
		valor = paux.first / cola.top().first;
		if (paux.first % cola.top().first != 0) valor++;
		if (valor > restantes) valor = restantes;
	
		nuevoGrupo = paux.first / valor;
		if (paux.first % valor != 0)nuevoGrupo++;
		paux.first = nuevoGrupo;
		paux.second += valor;
		cola.push(paux);
		restantes -= valor;

	}
	std::cout << cola.top().first << '\n';
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


/*// Esta funcion tiene coste O(NlogN) respecto al numero de elementos del vector
bool resuelveCaso() {
	// leer los datos de la entrada
	int p;

	std::cin >> p;
	if (!std::cin)
		return false;
	PriorityQueue<int, std::greater<int>> cola;
	int n, e;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> e;
		cola.push(e);
	}
	int restante = p - n, auxP, temp, aux;

	while (restante > 0) {
		auxP = cola.top(); //guarda el top actual en una variable auxiliar
		cola.pop();	//Saca el elemento para compararlo con el siguiente
		temp = auxP / cola.top(); //Cuántas veces cabe el siguiente elemento en el primero, para saber cuántas veces hay que dividir
								  //el elemento más grande de la cola para que deje de ser prioritario
		if (auxP % cola.top() != 0) temp++; //si el resto no es cero, debemos sumarle uno, pues los enteros truncan el número

		if (temp >= restante) { //si hay que dividirlo el mismo número de veces que partituras nos sobran (o más), solo habrá que dar las partituras
								//a estos instrumentos
			temp = restante;	//guardamos en temp las partituras restantes, pues no se puede repartir de lo que no hay
			aux = auxP / temp;	//guardamos en aux la cantidad de partituras a la que tocan los instrumentos
			if (auxP%temp != 0) aux++; //si el resto no es cero, sumamos uno por el tema de los enteros

			if (aux > cola.top()) cola.push(aux); //si resulta que el resultado de dividir las partituras entre el instrumento nos sigue dejando		
												  //un número mayor que el actual top en la cola, volvemos a meterlo, pues será lo que mostraremos.
			restante = 0; //para salir del bucle
		}
		else {
			int resto;
			aux = auxP / temp; //guardamos en aux la cantidad de partituras a la que tocan los instrumentos
			resto = auxP%temp;

			for (int i = 0; i < temp; i++) {  //volvemos a introducir los instrumentos divididos por las partituras, por si los necesitamos después
				if (resto == 0) cola.push(aux - 1); //si el resto de la división no es 0, no es exacta, por lo que se va añadiendo el número+1  
													// resultante de la división hasta que el resto esté a 0 (pues le sumamos uno por el tema de los enteros). 
													//Entonces, será el número tal cual.
				else {
					cola.push(aux);
					resto--;
				}
			}
			restante -= (temp - 1); //las partituras restantes son las veces que  has dividido el número -1, pues sacaste un elemento que ya tenía partitura de la cola.
		}

	}
	std::cout << cola.top() << '\n'; //muestra el elemento más grande de la cola restante.
	return true;

}*/