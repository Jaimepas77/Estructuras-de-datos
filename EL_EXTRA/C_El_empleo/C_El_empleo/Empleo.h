#ifndef EMPLEO
#define EMPLEO

#include <map>
#include <unordered_map>
#include <list>
#include <vector>//Para el retorno de la funcion listadoEmpleos

using namespace std;

class oficinaEmpleo {
private:
	using nombreEmpleo = string;
	using nombrePersona = string;
	unordered_map <nombreEmpleo, list<nombrePersona>> empleos;//Tabla de empleos que contiene una lista de personas apuntadas
	unordered_map <nombrePersona, map<nombreEmpleo, list<nombrePersona>::iterator>> personas;//Tabla de personas apuntadas que contiene una tabla ordenada de sus empleos con su posici�n en la lista.

public:
	void altaOficina(nombrePersona pers, nombreEmpleo emp) //A�ade a una persona en un empleo
		// Coste -> O(log n) siendo n el n�mero de empleos que tiene la persona
	{
		auto it = personas.find(pers);//O(1) (coste cte)
		if (it == personas.end())//Si no est� registrado...
		{
			empleos[emp].push_back(pers);//A�adimos a la persona en el empleo (O(1) (coste cte))
			auto persLug = empleos[emp].end();//Buscamos el iterador a la persona reci�n guardada
			personas[pers].insert({emp, --persLug});//Insertamos la persona con su empleo y su referencia en la lista de espera (O(1) (coste cte))
		}
		else//Si el individuo est� registrado...
		{
			bool esta = personas[pers].count(emp);//Buscamos si la persona ya est� en ese empleo (O(log n) siendo n el n� de empleos de la persona (coste logar�tmico))
			if (!esta)//El individuo no est� apuntado a este empleo
			{
				empleos[emp].push_back(pers);//Persona a�adida a la lista (O(1) (coste cte))
				auto persLug = empleos[emp].end();//Buscamos el iterador a la persona reci�n guardada
				personas[pers].insert({ emp, --persLug });//Insertamos en la persona su empleo con su referencia en la lista de espera (O(1) (coste cte))
			}
		}
	}

	nombrePersona ofertaEmpleo(nombreEmpleo emp) //Mostrar y eliminar a la persona que est� la siguiente en la lista de ese empleo
		// Coste -> O(n) siendo n el n� de empleos que tiene la persona elminada
	{
		auto it = empleos.find(emp);//Buscamos el empleo (O(1) (coste cte))
		if (it == empleos.end())//Si el empleo no existe...
		{
			throw domain_error("No existen personas apuntadas a este empleo");
		}
		else//Si el empleo existe...
		{
			auto elegido = it->second.begin();//Iterador a la persona elegida para el empleo (O(1) (coste cte))
			string ret = *elegido;//Nombre que se va a retornar
			
			//Borrar persona de sus empleos
			for (auto refEmp : personas[ret])//Por cada empleo que tuviera la persona (O(n) siendo n el n� de empleos (coste lineal))
			{
				empleos[refEmp.first].erase(refEmp.second);//Borrar a la persona de la lista del empleo (O(1) (coste cte))

				if (empleos[refEmp.first].empty())//Si la lista del empleo se ha quedado vac�a...
					empleos.erase(refEmp.first);
			}
			//Borrar persona de la lista de personas
			personas.erase(ret);//(O(1) (coste cte))

			return ret;
		}
	}

	vector<nombreEmpleo> listadoEmpleos(nombrePersona pers)//Devuelve un listado con todos los empleos a los que opta un candidato espec�fico
		// Coste -> (O(n) siendo n el n� de empleos de la persona (coste lineal)
	{
		try
		{
			auto listaEmp = personas.at(pers);
			vector<nombreEmpleo> ret;
			for (auto elem : listaEmp) //(O(n) siendo n el n� de empleos de la persona (coste lineal)
			{
				ret.push_back(elem.first);
			}
			return ret;
		}
		catch (exception e)
		{
			throw domain_error("Persona inexistente");
		}

	}
};

#endif
