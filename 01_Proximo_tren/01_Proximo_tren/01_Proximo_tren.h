//Nombre del autor: Jaime Pastrana García
//Ususario en el juez: A56
#ifndef FECHA
#define FECHA

//#include <iostream>
//#include <stdexcept>
#include <iomanip>
class Fecha {
private:
	const int HORAS_DIA = 24;
	const int MINUTOS_HORA = 60;
	const int SEGUNDOS_MINUTO = 60;
	int hora, minuto, segundo;
public:
	//Constructores
	//Fecha() {}
	Fecha(int h = 0, int m = 0, int s = 0): segundo(s), minuto(m), hora(h) {
		if (m < 0 || m >= MINUTOS_HORA || s < 0 || s >= SEGUNDOS_MINUTO || h <0 || h >= HORAS_DIA)
			throw std::invalid_argument("ERROR");
	}

	Fecha& operator =(Fecha const& other) { // operador de asignación
		if (this != &other) {
			segundo = other.segundo; minuto = other.minuto; hora = other.hora;
		}
		return *this;
	}

	int get_segundo() const { return segundo; }
	int get_minuto() const { return minuto; }
	int get_hora() const { return hora; }
	
	// operadores de comparación
	bool operator <= (Fecha const& f) const {
		if (hora < f.hora) return true;
		else if (hora > f.hora) return false;
		else if (minuto < f.minuto) return true;
		else if (minuto > f.minuto) return false;
		else if (segundo <= f.segundo) return true;
		else return false;
	}
	bool operator == (Fecha const& f) const {
		return hora == f.hora && minuto == f.minuto && segundo == f.segundo;
	}
	bool operator < (Fecha const& f) const {
		return *this <= f && !(*this == f);
	}
	bool operator > (Fecha const& f) const {
		return !(*this <= f);
	}
	bool operator >= (Fecha const& f) const {
		return !(*this < f);
	}
};
inline std::ostream& operator << (std::ostream& out, Fecha const& f) {
	
	out << std::setw(2) << std::setfill('0') << f.get_hora() << 
		':' << std::setw(2) << std::setfill('0') << f.get_minuto()<< 
		':' << std::setw(2) << std::setfill('0') << f.get_segundo();

	return out;
}
inline std::istream& operator >> (std::istream& in, Fecha& f) {
	std::string fecha;
	in >> fecha;
	int h = (fecha[0] - '0') * 10 + (fecha[1] - '0');
	int m = (fecha[3] - '0') * 10 + (fecha[4] - '0');
	int s = (fecha[6] - '0') * 10 + (fecha[7] - '0');
	f = Fecha(h, m, s);
	return in;
}


#endif