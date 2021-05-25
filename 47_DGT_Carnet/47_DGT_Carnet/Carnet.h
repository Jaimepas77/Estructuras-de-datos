//Jaime Pastrana García
//A56

#ifndef CARNET
#define CARNET

#include <unordered_map>
#include <stdexcept>
#include <list>
#include <vector>

using namespace std;

class carnet {
private:
	const int PUNTOS_MAX = 15;
	unordered_map<string, int> conductores;//Clave - dni; valor - puntos
	vector<int> conPuntos;//Lleva la cuenta de cuantas personas tienen ese nº de puntos.

public:
	carnet()
	{
		//Inicializar el tamaño del vector que llevará la cuenta de los puntos.
		conPuntos.resize(PUNTOS_MAX + 1);//El valor por defecto del int es 0, con lo que se inicializa a 0
	}

	void nuevo(string DNI)//Añadir un conductor: coste constante (O(1))
	{
		if (!conductores.insert({ DNI, PUNTOS_MAX }).second)//Se intenta insertar y si no se puede porque ya estaba...
		{
			throw domain_error("Conductor duplicado");
		}
		else
		{
			conPuntos[PUNTOS_MAX]++;//Contabilizamos a este conductor dentro de los conductores con 15 points
		}
	}

	void quitar(string DNI, int points)//Retirar puntos a un conductor: coste constante (O(1))
	{
		auto it = conductores.find(DNI);
		if (it == conductores.end())
		{
			throw domain_error("Conductor inexistente");
		}
		else
		{
			conPuntos[it->second]--;

			it->second -= points;
			if (it->second < 0)
				it->second = 0;

			conPuntos[it->second]++;
		}
	}

	int consultar(string DNI) const //Consultar puntos del conductor: coste cte (O(1))
	{
		auto it = conductores.find(DNI);
		if (it == conductores.end())
		{
			throw domain_error("Conductor inexistente");
		}
		else
		{
			return it->second;
		}
	}

	int cuantos_con_puntos(int points) const //Consultar cuantos tienen un determinado nº de puntos: coste cte (O(1))
	{
		if (points < 0 || points >= conPuntos.size())
		{
			throw domain_error("Puntos no validos");
		}
		else
		{
			return conPuntos[points];
		}
	}
};

#endif

