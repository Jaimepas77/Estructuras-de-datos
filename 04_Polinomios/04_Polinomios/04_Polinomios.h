#ifndef POLINOMIO
#define POLINOMIO

// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

typedef long long int lli;

class Polinomio {
private:
	//Vector de monomios del polinomio (está ordenado según el exponente, los exponentes no se repiten y los coeficientes 0 no se guardan)
	std::vector<std::pair<int, int>> polinomio;// pair <coeficiente, exponente>

	int lowerBound(int exp) const//Retorna la posición de un exponente o su inferior si no se encuentra
	{
		int ini = 0, fin = polinomio.size();
		int medio = (ini+fin)/2;

		while (fin > ini && polinomio[medio].second != exp)//Búsqueda binaria iterativa
		{
			if (polinomio[medio].second > exp)//Izq
				fin = medio;
			else//Dcha
				ini = medio+1;
			medio = (ini + fin) / 2;
		}
		return medio;
	}

public:
	Polinomio() 
	{
		polinomio.resize(0);
	}
	Polinomio(std::pair<int, int> p) 
	{
		polinomio.resize(0);
		polinomio.push_back(p);
	}

	void addElem(std::pair<int, int> m)
	{
		if (polinomio.size() != 0)
		{
			int pos = lowerBound(m.second);//Lower bound propio pq no supe usar el de la librería correctamente

			if (pos < polinomio.size() && polinomio[pos].second == m.second)//Si el exponente ya existe...
			{
				polinomio[pos].first += m.first;//Se suman los coeficientes
			}
			else//Si no...
			{
				//Insertamos el elmento
				polinomio.resize(polinomio.size() + 1);
				for (int i = polinomio.size() - 1; i > pos; i--)
					polinomio[i] = polinomio[i - 1];
				polinomio[pos] = m;
			}
		}
		else
			polinomio.push_back(m);
	}

	lli evaluar(int a) const
	{
		std::pair<int, lli> pot = { 0, 1 };//Par <exponente, potencia en sí>
		lli res = 0;//resultado
		for (std::pair<int, int> x : polinomio)
		{
			for (int i = pot.first; i < x.second; i++)//Calcular potencia
			{
				pot.second *= a;
				pot.first++;
			}
			res += x.first * pot.second;
		}

		return res;
	}
};

inline std::istream& operator >>(std::istream& in, Polinomio& p)
{
	std::pair<int, int> entrada;
	in >> entrada.first >> entrada.second;
	while ((entrada.first != 0 || entrada.second != 0) && std::cin)
	{
		p.addElem(entrada);
		in >> entrada.first >> entrada.second;
	}

	return in;
}

class ordenarExp//Comparar monomios por exponente
{
public:
	ordenarExp() {}

	bool operator()(std::pair<int, int> const& p1, std::pair<int, int> const& p2) const
	{
		return p1.second < p2.second;
	}
};

#endif