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
		bool der, izq;
		int nivder = nivel, nivizq=nivel;
		izq = resolver(arbol.left(), nivizq);
		der = resolver(arbol.right(), nivder);
		if (izq && der && abs(nivder - nivizq) <= 1){
			nivel = std::max(nivizq, nivder);
			return true;
		}
		else return false;
	}
}


#endif //Header_h