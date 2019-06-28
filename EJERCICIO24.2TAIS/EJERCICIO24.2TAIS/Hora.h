//
//  Header.h
//

#ifndef Hora_h
#define Hora_h

#include <cstddef>    // size_t
#include <stdexcept>  // std::domain_error
#include <utility>    // std::move
#include <iostream>
#include <iomanip>
using namespace std;

class hora {
private:
	int _horas;
	int _minutos;
	static bool check(int h, int m) {
		return 0 <= h && h < 24 && 0 <= m && m < 60;
	}
public:
	// constructor
	hora() : _horas(0), _minutos(0) {}
	hora(int h, int m) {
		if (check(h, m)) {
			_horas = h; _minutos = m;
		}
		else
			throw invalid_argument("ERROR\n");
	}

	hora convertirMinutos(int min){
		hora h;
		if (min >= 60){
			int ho = min / 60;
			int m = min % 60;
			h = hora(ho, m);
		}
		else h = hora(0, min);
			return h;
	}
	// operador de comparación
	bool operator<(hora const& hora) const {
		if (_horas < hora._horas)
			return true;
		else if (_horas == hora._horas && _minutos < hora._minutos)
			return true;
		else
			return false;
	}

	bool operator==(hora const & hora)const{
		return (_horas == hora._horas && _minutos == hora._minutos);
	}

	hora operator+(hora const& ho) const {
		int h, m;
		m = _minutos + ho._minutos;
		h = _horas + ho._horas + (m / 60);
		m %= 60;
		if (h > 23)
			throw invalid_argument("nos pasamos de dia");
		else
			return hora(h, m); //Se podría poner "return {h, m, s}" 
				//que sería como decirle a la fumción que intente crear una hora con esos valores.
	}

	int horas() const { return _horas; }
	int minutos() const { return _minutos; }


	void read(istream& input = cin) {
		int h, m; char c;
		input >> h >> c >> m;
		if (check(h, m)) {
			_horas = h; 
			_minutos = m; 
		}
		else
			throw invalid_argument("ERROR\n");
	}

	void print(ostream& o = cout) const {
		o << setfill('0') << setw(2) << _horas << ':'
			<< setfill('0') << setw(2) << _minutos;
	}
};

inline ostream & operator<<(ostream & salida, hora const& h) {
	h.print(salida);
	return salida;
}

inline istream & operator>>(istream & entrada, hora & h) {
	h.read(entrada);
	return entrada;
}


#endif // Hora_h
