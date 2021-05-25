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
	unordered_map<string, pair<int, list<string>::iterator>> conductores;//Clave - dni; valor - puntos e iterador a la lista de esos puntos
	vector<list<string>> conPuntos;//Lleva la cuenta de los dnis de las personas que tienen ese nº de puntos.

public:
	carnet() : conPuntos(PUNTOS_MAX+1) {}

	void nuevo(string DNI)//Añadir un conductor: coste constante (O(1))
	{
		auto c = conductores.find(DNI);
		if (c != conductores.end())//si no se puede porque ya estaba...
		{
			throw domain_error("Conductor duplicado");
		}
		else
		{
			conPuntos[PUNTOS_MAX].push_front(DNI);//Contabilizamos a este conductor dentro de los conductores con 15 points
			auto it = conPuntos[PUNTOS_MAX].begin();
			conductores.insert({ DNI, { PUNTOS_MAX, it } });
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
			if (it->second.first > 0)
			{
				conPuntos[it->second.first].erase(it->second.second);//Eliminar de la lista en tiempo cte (O(1))

				it->second.first -= points;
				if (it->second.first < 0)
					it->second.first = 0;

				conPuntos[it->second.first].push_front(it->first);//Añadir a la lista y actualizar el iterador
				auto p = conPuntos[it->second.first].begin();
				it->second.second = p;
			}
		}
	}

	void recuperar(string DNI, int points)//Recuperar puntos en un conductor: coste cte (O(1))
	{
		auto it = conductores.find(DNI);
		if (it == conductores.end())
		{
			throw domain_error("Conductor inexistente");
		}
		else
		{
			if (it->second.first < 15)//Si no cambian los puntos, no se borra y se añade porque altera el orden de la lista
			{
				conPuntos[it->second.first].erase(it->second.second);//Eliminar de la lista en tiempo cte (O(1))

				it->second.first += points;
				if (it->second.first > 15)
					it->second.first = 15;

				conPuntos[it->second.first].push_front(it->first);//Añadir a la lista y actualizar el iterador
				auto p = conPuntos[it->second.first].begin();
				it->second.second = p;
			}
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
			return it->second.first;
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
			return conPuntos[points].size();
		}
	}

	vector <string> lista_por_puntos(int points) const//Coste lineal en el nº de conductores con points puntos (O(n) siendo n el nº de conductores con esos puntos)
	{
		if (points < 0 || points >= conPuntos.size())
		{
			throw domain_error("Puntos no validos");
		}
		else
		{
			vector <string> ret;
			for (string elem : conPuntos[points])
				ret.push_back(elem);
			return ret;
		}
	}
};

#endif

