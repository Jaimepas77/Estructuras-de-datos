#ifndef LIBROS
#define LIBROS

#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>
#include <list>
#include <utility>
#include <stdexcept>

class libreria {
private:
	using libro = std::string;

	struct bookInfo {
		int unidades = 0;
		int vendidos = 0;
		std::list<libro>::iterator it;//Iterador a la lista topVentas
	};

	std::unordered_map<libro, bookInfo> catalog;//Catalogo de libros y sus unidades disponibles
	//std::list<std::pair<libro, int>> topVentas;	//lista de compras ordenada (par libro-ventas)
	std::map<int, std::list<libro>> topVentas;

public:
	void nuevoLibro(int n, libro x) 
	{
		catalog[x].unidades += n;//Añadir unidades
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
			it->second.vendidos++;
			
			//Registrar compra para la lista del top 10
			if (it->second.vendidos > 1)//Si antes ya estaba en la lista de vendidos...
			{
				topVentas[it->second.vendidos - 1].erase(it->second.it);//Borrar
			}
			topVentas[it->second.vendidos].push_front(x);//Añadir
			it->second.it = topVentas[it->second.vendidos].begin();//Guardar puntero
			
			/*if (it->second.it == topVentas.end())
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
			it->second.it = ref;*/
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
			if (it->second.vendidos != 0)
				topVentas[it->second.vendidos].erase(it->second.it);

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
		if (topVentas.empty())
			return ret;

		int i = 0;
		auto it = topVentas.end();
		it--;
		while (it != topVentas.begin())
		{
			auto libs = it->second.begin();

			while (libs != it->second.end())
			{
				ret.push_back(*libs);
				i++;

				if (i >= 10)
					return ret;

				libs++;
			}
			it--;
		}

		auto libs = it->second.begin();

		while (libs != it->second.end())
		{
			ret.push_back(*libs);
			i++;

			if (i >= 10)
				return ret;

			libs++;
		}
		return ret;
	}
};

#endif
