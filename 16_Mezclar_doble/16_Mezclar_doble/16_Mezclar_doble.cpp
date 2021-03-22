// Nombre y apellidos del alumno: Jaime Pastrana García
// Usuario del juez de clase: A56

#include <iostream>
#include <fstream>

#include "deque_eda.h"

typedef long long int lli;

template <class T>
class ListaAmpliada : public deque<T> {
	using Nodo = typename deque<T>::Nodo;
public:
	void mezclarElementos(ListaAmpliada<T>& lista2) {
		// Aqui el código del alumno
		if (lista2.nelems > 0 && this->nelems > 0)
		{
			//Hay que incluir en this los elems de lista2 con una mezcla ordenada.
			Nodo* tmp, * act1 = this->fantasma->sig, * ant1 = this->fantasma, * act2 = lista2.fantasma->sig;

			//El primer caso se trata por separado al ser especial por tener que tratar con el puntero a prim
			if (act1->elem > act2->elem)
			{
				//Insertar elem de la lista 2 en el principio
				this->fantasma->sig = act2;
				act2->ant = this->fantasma;
				tmp = act2->sig;
				act2->sig = act1;
				act1->ant = act2;

				ant1 = act2;//Guardar el elem anterior
				act2 = tmp;//Avanzar al siguiente en la segunda lista
			}
			else
			{
				ant1 = act1;//Avanzamos
				act1 = act1->sig;
			}

			while (act1 != this->fantasma && act2 != lista2.fantasma)//Recorrer las listas hasta que una de las dos se termine
			{
				if (act1->elem > act2->elem)//Colocar el act2 y avanzar la segunda lista
				{
					//insertar
					ant1->sig = act2;
					act2->ant = ant1;
					tmp = act2->sig;
					act2->sig = act1;
					act1->ant = act2;

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
			if (act2 != lista2.fantasma)
			{
				this->fantasma->ant = lista2.fantasma->ant;//Actualizar el último elemento (que ahora es de la lista 2)
				this->fantasma->ant->sig = this->fantasma;
				ant1->sig = act2;//Conectar los últimos elems que queden de la lista 2
				act2->ant = ant1;
			}

			//Actualizar el contador de lista1
			this->nelems += lista2.nelems;
			lista2.nelems = 0;
			lista2.fantasma->sig = lista2.fantasma->ant = lista2.fantasma;
		}
		else if (this->nelems == 0)//si la lista original es vacía entonces la solución es la lista 2
		{
			*this = lista2;
		}
	}

	void print() const
	{
		Nodo* act = this->fantasma->sig;//Primer nodo

		while (act != this->fantasma) {//¿Podemos avanzar al siguiente nodo?
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
		lista1.push_back(tmp);
		std::cin >> tmp;
	}
	std::cin >> tmp;
	while (tmp != 0) {//Leer lista2
		lista2.push_back(tmp);
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