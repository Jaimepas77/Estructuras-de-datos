#ifndef LIBROS
#define LIBROS

#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <utility>
#include <stdexcept>

class libreria {
private:
	using libro = std::string;

	struct bookInfo {
		int unidades = 0;
		std::list<std::pair<libro, int>>::iterator it;//Iterador a la lista topVentas
	};

	std::unordered_map<libro, bookInfo> catalog;//Catalogo de libros y sus unidades disponibles
	std::list<std::pair<libro, int>> topVentas;	//lista de compras ordenada (par libro-ventas) //ERROR: SÓLO HACE FALTA MANTENER LOS 10 MEJORES!!!

public:
	void nuevoLibro(int n, libro x) 
	{
		catalog[x].unidades += n;//Añadir unidades

		catalog[x].it = topVentas.end();
	}

	void comprar(libro x)
	{
		auto it = catalog.find(x);
		if (it == catalog.end())
			throw std::invalid_argument("Libro no existente");
		else if (it->second.unidades == 0)
			throw std::out_of_range("No hay ejemplares");
		else
		{
			it->second.unidades--;

			//Registrar compra para la lista del top 10
			if (it->second.it == topVentas.end())
			{
				topVentas.push_back({ x, 1 });//Añadir a la lista de ventas (top 10)
				it->second.it = --topVentas.end();
			}
			else
				it->second.it->second++;//Sumar ejemplar
			auto ref = it->second.it;
			while (ref != topVentas.begin() && it->second.it->second >= ref->second)
			{
				ref--;
			}

			if(ref != topVentas.begin())
				ref++;
			
			ref = topVentas.insert(ref, *it->second.it);
			topVentas.erase(it->second.it);
			it->second.it = ref;
		}
	}

	bool estaLibro(libro x)
	{
		return catalog.count(x);
	}

	void elimLibro(libro x)
	{
		auto it = catalog.find(x);

		if (it != catalog.end())
		{
			//Eliminar del top 10...
			if (it->second.it != topVentas.end())
			{
				topVentas.erase(it->second.it);
				it->second.it = topVentas.end();
			}

			catalog.erase(it);
		}
	}

	int numEjemplares(libro x)
	{
		auto it = catalog.find(x);
		if (it == catalog.end())
			throw std::invalid_argument("Libro no existente");
		else
			return it->second.unidades;
	}

	std::vector <libro> top10()
	{
		//Recorrer los diez primeros libros del top y meterlos en un vector
		std::vector<libro> ret;
		int i = 0;
		for (auto elem : topVentas)
		{
			if (i >= 10 || elem.second == 0) break;
			ret.push_back(elem.first);
			i++;
		}
		return ret;
	}
};

#endif
