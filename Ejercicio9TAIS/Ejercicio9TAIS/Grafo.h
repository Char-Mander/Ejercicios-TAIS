//
// Grafo.h
//
// implementaci�n de grafos no dirigidos y clases que los explorar
//
// Facultad de Inform�tica
// Universidad Complutense de Madrid
//
// Created by Alberto Verdejo on 26/6/15
//Copyright (c) 2015 Alberto Verdeo. All rights reserved.
//

#ifndef GRAFO_H_
#define GRAFO_H_

#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>

using Adys = std::vector<size_t>; //lista de adyacentes a un vertice
using Path = std::deque<size_t>; //para representar caminos

class Grafo {
	size_t _V; //n�mero de v�rtices
	size_t _E; //n�mero de aristas
	std::vector<Adys>_adj; //vector de listas de adyacentes

public:
	/**
	*	Crea un grafo con V v�rtices
	*/
	Grafo(size_t v) : _V(v), _E(0), _adj(_V){}

	/**
	*Devuelve el n�mero de v�rtices del grafo
	*/
	size_t V() const { return _V; }

	/**
	*Devuelve el n�mero de aristas del grafo
	*/

	size_t E() const { return _E; }


	/**
	*A�ade la arista v-w al grafo.
	* @throws invalid_argument si alg�n v�rtice no existe
	*/

	void ponArista(size_t v, size_t w){
		if (v >= _V || w >= _V)
			throw std::invalid_argument("Vertice inexistente");
			++_E;
			_adj[v].push_back(w);
			_adj[w].push_back(v);
	}




	/**
	*Devuelve la lista de adyacencia de v.
	*@throws invalid_argument si v no existe
	*/

	const Adys& adj(size_t v) const {
		if (v >= _V)
			throw std::invalid_argument("Vertice inexistente");
		return _adj[v];
	}


	/**
	*Muestra el grafo en el stream de salida o (para depurar)
	*/

	void print(std::ostream &o = std::cout) const{
		o << _V << " v�rtices, " << _E << "aristas\n";
		for (auto v = 0; v < _V; ++v){
			o << v << ": ";
			for (auto w : _adj[v]){
				o << w << " ";
			}
			o << "\n";
		}
	}


};