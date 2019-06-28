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
#include <queue>
#include "Matriz.h"

class FreeLove {
public:
	FreeLove(Matriz<int> const& a, Matriz<bool> const& m, std::pair<int, int> en, std::pair<int, int> pa)
		: amor(a), marcado(m), edgeTo(a.numfils(), a.numcols()), encontrado(false), cont(0), e(en), p(pa) {}

	void colocarLaser(const std::vector<std::pair<int, int>> & laser) {
		for (int i = 0; i < laser.size(); i++)
			rellenarLaberinto(laser[i].first, laser[i].second);
	}

	int recorrerLaberinto() {
		recorrido();
		return cont;
	}
private:
	Matriz<int> amor;
	Matriz<bool> marcado;
	Matriz<std::pair<int,int>> edgeTo;
	bool encontrado;
	int cont;
	std::pair<int, int> e, p;

	//Esta funcion tiene coste O(n+n) siendo n el tamano de la matriz
	//Una parte O(n) sale de recorrer la matriz buscando la p
	//La otra parte O(n) sale de hacer el recorrido que cuenta los pasos
	void recorrido() {
		std::queue<std::pair<int, int>> cola;
		marcado[e.first][e.second] = true; // Mark the source
		if (amor[e.first][e.second] == -1)
			cola.push(e); // and put it on the queue.
		while (!cola.empty() && !encontrado)
		{
			auto v = cola.front(); // Remove next vertex from the queue.
			cola.pop();
			if (v.first - 1 >= 0 && !marcado[v.first - 1][v.second] && amor[v.first - 1][v.second] == -1) {
				edgeTo[v.first - 1][v.second] = v;
				if (v.first - 1 == p.first && v.second == p.second)
					encontrado = true;
				else {
					marcado[v.first - 1][v.second] = true;
					cola.push({ v.first - 1, v.second });
				}
			}
			if (v.second + 1 < amor.numcols() && !marcado[v.first][v.second + 1] && amor[v.first][v.second + 1] == -1) {
				edgeTo[v.first][v.second + 1] = v;
				if (v.first == p.first && v.second + 1 == p.second)
					encontrado = true;
				else {
					marcado[v.first][v.second + 1] = true;
					cola.push({ v.first, v.second + 1 });
				}
			}
			if (v.first + 1 < amor.numfils() && !marcado[v.first + 1][v.second] && amor[v.first + 1][v.second] == -1) {
				edgeTo[v.first + 1][v.second] = v;
				if (v.first + 1 == p.first && v.second == p.second)
					encontrado = true;
				else {
					marcado[v.first + 1][v.second] = true;
					cola.push({ v.first + 1, v.second });
				}
			}
			if (v.second - 1 >= 0 && !marcado[v.first][v.second - 1] && amor[v.first][v.second - 1] == -1) {
				edgeTo[v.first][v.second - 1] = v;
				if (v.first == p.first && v.second - 1 == p.second)
					encontrado = true;
				else {
					marcado[v.first][v.second - 1] = true;
					cola.push({ v.first, v.second - 1 });
				}
			}
		}

		if (encontrado) {
			std::pair<int, int> pos = p;
			while (pos != e) {
				pos = edgeTo[pos.first][pos.second];
				cont++;
			}
		}
		else
			cont = -1;
	}


	void rellenarLaberinto(int f, int c) {
		bool ar = true, ab = true, dr = true, iz = true;
		int num = amor[f][c];
		for (int i = 0; i <= num; i++) {
			if (ar && f + i < amor.numfils() && amor[f + i][c] != 10) {
				if (amor[f + i][c] == -1)
					amor[f + i][c] = 11;
			}
			else
				ar = false;
			if (dr && c + i < amor.numcols() && amor[f][c + i] != 10) {
				if (amor[f][c + i] == -1)
					amor[f][c + i] = 11;
			}
			else
				dr = false;
			if (ab && f - i >= 0 && amor[f - i][c] != 10) {
				if (amor[f - i][c] == -1)
					amor[f - i][c] = 11;
			}
			else
				ab = false;
			if (iz && c - i >= 0 && amor[f][c - i] != 10) {
				if (amor[f][c - i] == -1)
					amor[f][c - i] = 11;
			}
			else
				iz = false;
		}
	}
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int c, f;

	std::cin >> c >> f;
	std::vector<std::pair<int, int>> laser;
	Matriz<int> a(f, c);
	Matriz<bool> m(f, c);
	char celda; int valor;
	std::pair<int, int> e, p;
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			std::cin >> celda;
			if (celda == '.')
				a[i][j] = -1;
			else if (celda == '#')
				a[i][j] = 10;
			else if (celda == 'E') {
				e = { i, j };
				a[i][j] = -1;
			}
			else if (celda == 'P') {
				p = { i, j };
				a[i][j] = -1;
			}
			else {
				a[i][j] = atoi(&celda);
				laser.push_back({ i, j });
			}
			m[i][j] = false;
		}
	}
	FreeLove love(a, m, e, p);
	love.colocarLaser(laser);
	int cont = love.recorrerLaberinto();
	if (cont == -1)
		std::cout << "NO\n";
	else
		std::cout << cont << '\n';
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}