#ifndef Header_h
#define Header_h

#include <iostream>
#include <memory>   // shared_ptr, make_shared
#include <stdexcept>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include "bintree_eda.h"

template <class T>
bintree<T> cargarArbol(T const& dato) {
	T raiz;
	std::cin >> raiz;

	if (raiz == dato)
		return{};
	else {

		bintree<T> izq = cargarArbol(dato);
		bintree<T> der = cargarArbol(dato);

		return{ izq, raiz, der };
	}
}

//El problema se va resolviendo de abajo a arriba, de las hojas a la raiz
template <class T>
bool resolver(bintree<T> const& arbol, int &nivel) {
	if (arbol.empty())
		return true;
	else {
		nivel++;
		int nivelizq=nivel, nivelder = nivel;
		bool izq = resolver(arbol.left(), nivelizq);
		bool der = resolver(arbol.left(), nivelder);
		if (abs(nivelizq - nivelder) > 1 && izq && der) return false;
		else return true;

	}
}


#endif //Header_h