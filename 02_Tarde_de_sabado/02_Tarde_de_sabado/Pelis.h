//Nombre del autor: Jaime Pastrana García
//Ususario en el juez: A56
#ifndef PELI
#define PELI

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <iomanip>
#include <string>
#include "02_Tarde_de_sabado.h"

//TAD para las películas
class Pelicula {
private:
	Hora inicio, duracion;
	std::string titulo;

	Hora fin(Hora ini, Hora dur)const
	{
		return ini + dur;
	}
public:
	Pelicula() {}
	Pelicula(Hora ini, Hora dur, std::string t) : inicio(ini), duracion(dur), titulo(t) {}

	Hora get_ini() const { return inicio; }
	Hora get_dur() const { return duracion; }
	std::string get_titulo() const { return titulo; }

	bool operator <(const Pelicula& p)
	{
		Hora pfin = p.inicio + p.duracion, tfin = inicio + duracion;
		if (tfin < pfin)
			return true;
		else if (this->titulo < p.titulo && tfin == pfin)
			return true;
		else
			return false;
	}
	/*bool operator <=(const Pelicula& p) { return this->fin <= p.fin; }
	bool operator ==(const Pelicula& p) { return this->fin == p.fin; }
	bool operator >(const Pelicula& p) { return this->fin > p.fin; }
	bool operator >=(const Pelicula& p) { return this->fin >= p.fin; }*/

};

inline std::istream& operator >> (std::istream& in, Pelicula& p)
{
	Hora ini, dur;
	std::string tit;

	in >> ini >> dur;
	std::cin.get();//Ignorar el espacio que hay antes del título
	std::getline(in, tit);

	p = Pelicula(ini, dur, tit);
	return in;
}

inline std::ostream& operator << (std::ostream& out, const Pelicula& p)
{
	out << p.get_ini() + p.get_dur() << " " << p.get_titulo();

	return out;
}

#endif