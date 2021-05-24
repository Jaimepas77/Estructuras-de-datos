//Jaime Pastrana García
//A56

#ifndef AUTOESCUELA
#define AUTOESCUELA

#include <stdexcept>
#include <unordered_map>
#include <set>
#include <vector>

using namespace std;

class autoescuela {
private:
	using nombreAlumno = string;
	using nombreProfe = string;
	unordered_map<nombreProfe, set<nombreAlumno>> profes;//Clave - profe; valor - alumnos ordenados
	unordered_map<nombreAlumno, pair<nombreProfe, int>> alumnos; //Clave - alumno; valor - profesor y nota correspondiente

public:
	void alta(nombreAlumno const& a, nombreProfe const& p)//Coste logarítmico (O(log n) siendo n el nº de alumnos del profesor p) dado que hay que ordenar a los alumnos
	{
		auto it = alumnos.find(a);//Cte
		if (it == alumnos.end())//Si el alumno no está dado de alta...
		{
			alumnos.insert({ a, {p, 0} });
			profes[p].insert(a);//(O(log n))
		}
		else
		{//Hay que borrar antes de insertar para que, si se da de alta con el mismo profesor, no borremos los datos que no hemos insertado por estar repetidos.
			profes[it->second.first].erase(a);//Borrar del antiguo profe ((Coste logarítmico (O(log n)))
			it->second.first = p;//Actualizar el profe del alumno (Coste cte amortizado (O(1)))
			profes[p].insert(a);//Asignar en el nuevo profe (Coste logarítmico (O(log n)))
		}
	}

	bool es_alumno(nombreAlumno const& a, nombreProfe const& p) const //Coste cte (O(1))
	{
		auto it = alumnos.find(a);//Se busca el alumno
		return it != alumnos.end() && it->second.first == p;//Si el alumno existe y tiene el profe por el que se pregunta se devuelve true.
	}

	int puntuacion(nombreAlumno const& a) const //Coste: O(1)
	{
		auto it = alumnos.find(a);//Se busca el alumno
		if (it == alumnos.end())
		{
			throw domain_error("El alumno " + a + " no esta matriculado");
		}
		else
		{
			return it->second.second;
		}
	}

	void actualizar(nombreAlumno const& a, int n)//Coste: O(1)
	{
		auto it = alumnos.find(a);//Se busca el alumno
		if (it == alumnos.end())
		{
			throw domain_error("El alumno " + a + " no esta matriculado");
		}
		else
		{
			it->second.second += n;
		}
	}

	vector<nombreAlumno> examen(nombreProfe const& p, int n) const//Coste: O(n) siendo n el nº de alumnos correspondientes al profesor
	{
		vector<nombreAlumno> ret;
		auto it = profes.find(p);
		if (it != profes.end())
		{
			for (nombreAlumno alumn : it->second)
			{
				if (alumnos.at(alumn).second >= n)//Si el alumno supera la nota mínima
					ret.push_back(alumn);
			}
		}
		return ret;
	}

	void aprobar(nombreAlumno const& a)//Coste: O(log n) siendo n el nº de alumnos del profesor del alumno
	{
		auto it = alumnos.find(a);
		if (it == alumnos.end())
		{
			throw domain_error("El alumno " + a + " no esta matriculado");
		}
		else
		{
			profes[it->second.first].erase(a);//Coste logarítmico
			alumnos.erase(a);
		}
	}
};

#endif