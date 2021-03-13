// Nombre y apellidos del alumno: Jaime Pastrana García
// Usuario del juez de clase: A56

#include <iostream>
#include <fstream>

#include "queue_eda.h"

typedef long long int lli;

template <class T>
class ListaAmpliada : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	void mezclarElementos(ListaAmpliada<T> &lista2) {
		// Aqui el código del alumno
		if (lista2.nelems > 0 && this->nelems > 0)
		{
			//Hay que incluir en this los elems de lista2 con una mezcla ordenada.
			Nodo* tmp, * act1 = this->prim, * ant1 = nullptr, * act2 = lista2.prim;

			//El primer caso se trata por separado al ser especial por tener que tratar con el puntero a prim
			if (act1->elem > act2->elem)
			{
				//Insertar elem de la lista 2 en el principio
				this->prim = act2;
				tmp = act2->sig;
				act2->sig = act1;

				ant1 = act2;//Guardar el elem anterior
				act2 = tmp;//Avanzar al siguiente en la segunda lista
			}
			else
			{
				ant1 = act1;//Avanzamos
				act1 = act1->sig;
			}

			while (act1 != nullptr && act2 != nullptr)//Recorrer las listas hasta que una de las dos se termine
			{
				if (act1->elem > act2->elem)//Colocar el act2 y avanzar la segunda lista
				{
					//insertar
					ant1->sig = act2;
					tmp = act2->sig;
					act2->sig = act1;

					//avanzar lista2
					ant1 = act2;
					act2 = tmp;
				}
				else
				{
					ant1 = act1;//avanza lista1
					act1 = act1->sig;
				}
			}
			//Luego asegurar que se termina de recorrer cada lista
			if (act2 != nullptr)
			{
				this->ult = lista2.ult;//Actualizar el último elemento (que ahora es de la lista 2)
				ant1->sig = act2;//Conectar los últimos elems que queden de la lista 2
			}

			//Actualizar el contador de lista1
			this->nelems += lista2.nelems;
			lista2.nelems = 0;
			lista2.prim = nullptr;
			lista2.ult = nullptr;
		}
		else if (this->nelems == 0)//si la lista original es vacía entonces la solución es la lista 2
		{
			*this = lista2;
		}
	}

	void print() const
	{
		Nodo* act = this->prim;//Primer nodo

		while (act != nullptr) {//¿Podemos avanzar al siguiente nodo?
			std::cout << act->elem << " ";
			act = act->sig;
		}
		std::cout << '\n';
	}
};

void resuelveCaso() {
	// leer los datos de la entrada
	ListaAmpliada<lli> lista1, lista2;

	lli tmp;
	std::cin >> tmp;
	while (tmp != 0) {//Leer lista 1
		lista1.push(tmp);
		std::cin >> tmp;
	}
	std::cin >> tmp;
	while (tmp != 0) {//Leer lista2
		lista2.push(tmp);
		std::cin >> tmp;
	}

	lista1.mezclarElementos(lista2);

	// escribir sol
	lista1.print();
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}