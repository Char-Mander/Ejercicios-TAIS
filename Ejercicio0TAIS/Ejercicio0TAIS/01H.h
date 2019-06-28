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
int resolver(bintree<T> const& arbol, int h) {

	if (arbol.empty())
		return 0;
	else {
		int izq, der;
		 izq = 1 + resolver(arbol.left(), h+1);
		 der = 1 + resolver(arbol.right(), h+1);

		return std::max(izq, der);

	}
}

#endif //Header_h