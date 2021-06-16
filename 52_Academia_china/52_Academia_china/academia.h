#ifndef ACADEMY
#define ACADEMY
#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <vector>
#include <set>
#include <list>

class academia_chino {
private:
	using dni = std::string;
	std::unordered_map<dni, std::pair<int, std::list<dni>::iterator>> alumnos;//Registro de alumnos y <su grado correspondiente (7 equivale a graduado) y su iterador al grupo>
	std::vector<std::list<dni>> recientes;//Última persona graduada en cada curso
	std::set<dni> grads;//Alumnos que ya se han graduado
public:
	academia_chino() 
	{
		std::vector<std::list<dni>> n(6);
		recientes = n;//Inicializar el vector para que tenga 6 grados
	}

	void nuevo_estudiante(dni d, int c)//Coste cte (O(1))
	{
		auto it = alumnos.find(d);
		if (it != alumnos.end())
			throw std::domain_error("Estudiante existente");
		else if(c < 1 || c > 6)
			throw std::domain_error("Grupo incorrecto");
		else
		{
			recientes[c-1].push_front(d);
			alumnos.insert({ d, {c, recientes[c-1].begin()} });
		}
	}

	void promocionar(dni alumno)//Coste logarítmico (O(log n) siendo n el número de graduados) en el peor de los casos
	{
		auto it = alumnos.find(alumno);
		if (it == alumnos.end())
			throw std::domain_error("Estudiante no existente");
		else if (it->second.first == 7)//Si está graduado...
			throw std::domain_error("Estudiante ya graduado");
		else//Avanzar estudiante de curso
		{
			recientes[it->second.first-1].erase(it->second.second);//Borrar del curso anterior
			it->second.first++;

			if (it->second.first < 7)
			{
				recientes[it->second.first-1].push_front(alumno);//Añadir al nuevo curso
				it->second.second = recientes[it->second.first-1].begin();
			}
			else//Se gradua!!!!!
			{
				grads.insert(alumno);
				it->second.second = recientes[0].end();//Valor de vacío (no es necesario)
			}
		}
	}

	int grupo_estudiante(dni alumno)//Coste cte (O(1))
	{
		auto it = alumnos.find(alumno);
		if (it == alumnos.end())
			throw std::domain_error("Estudiante no existente");
		else if (it->second.first == 7)//Si está graduado...
			throw std::domain_error("Estudiante ya graduado");
		else
			return it->second.first;
	}

	std::vector<dni> graduados()//Coste lineal (O(n) siendo n el nº de graduados)
	{
		std::vector <dni> ret;
		for (dni a : grads)
			ret.push_back(a);
		return ret;
	}

	dni novato(int g)//Coste cte (O(1))
	{
		if (g < 1 || g > 6)
			throw std::domain_error("Grupo incorrecto");
		else if (recientes[g-1].empty())
			throw std::domain_error("Grupo vacio");
		else
			return recientes[g-1].front();
	}
};

#endif