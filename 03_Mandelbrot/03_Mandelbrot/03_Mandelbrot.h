// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56
#ifndef COMPLEJO
#define COMPLEJO

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <iomanip>
#include <cmath>

template <typename T>
class Complejo {
private:
	T real;
	T imaginario;

public:
	Complejo(): real(0), imaginario(0) {}
	Complejo(T r, T i) : real(r), imaginario(i) {}

	T get_real() const { return real; }
	T get_imaginario() const { return imaginario; }

	Complejo operator +(Complejo const& other) const
	{
		T r, i;
		r = this->real + other.real;
		i = this->imaginario + other.imaginario;
		Complejo ret = Complejo<T>(r, i);
		return ret;
	}

	Complejo operator *(Complejo const& other) const
	{
		T r, i;
		r = real * other.real - imaginario * other.imaginario;
		i = real * other.imaginario + imaginario * other.real;
		Complejo ret = Complejo<T>(r, i);
		return ret;
	}

	Complejo& operator =(const Complejo& c)
	{
		if (this != &c)
		{
			this->real = c.real;
			this->imaginario = c.imaginario;
		}
		return *this;
	}

	int modulo()
	{
		return sqrt(real * real + imaginario * imaginario);
	}
};

inline std::istream& operator >> (std::istream& in, Complejo<double>& c)
{
	double r, i;
	in >> r >> i;
	c = Complejo<double>(r, i);
	return in;
}

inline std::ostream& operator << (std::ostream& out, Complejo<double> const& c)
{
	double r = c.get_real(), i = c.get_imaginario();
	out << r << i;
	return out;
}

#endif