// Nombre y apellidos del alumno: Jaime Pastrana García
// usuario del juez de clase: A56

#include <iostream>
#include <fstream>

#include "deque_eda.h"

typedef long long int lli;

template <class T>
class ListaAmpliada : public deque<T> {
    using Nodo = typename deque<T>::Nodo;
public:
	void invertirElementos(lli p, lli l) {
		// Aqui el código del alumno
		if (l > 1)//Si hay varios elementos para invertir... (si hay sólo uno pues no se hace nada)
		{
			lli cont = 1;//Contador del elemento que lleva SIGUI
			Nodo* act = this->fantasma;//Nodo en análisis: se inicializa apuntando al primer nodo
			Nodo* start = this->fantasma->sig;//Nodo cuyo puntero hay que cambiar para apuntar al comienzo del segmento invertido
			Nodo* end = nullptr;

			Nodo* sigui = this->fantasma->sig;

			while (sigui != this->fantasma) {//¿Podemos avanzar al siguiente nodo?
				Nodo* tmp = sigui->sig;//Para mantenerlo a pesar de las manipulaciones que se puedan realizar en los if

				if (cont >= p && cont < p + l)//Si estamos en el segmento de las inversiones...
				{
					if (cont == p + l - 1)//Si es el último elem de la inversión...
					{
						start->sig = sigui;
						sigui->ant = start;

						end->sig = sigui->sig;
						sigui->sig->ant = end;

						sigui->sig = act;
					}
					else if (cont == p)//Si es el primer elem de la inversión...
					{
						start = act;
						sigui->ant = sigui->sig;
						end = sigui;
					}
					else//Si no es ni el primero ni el último...
					{
						sigui->ant = sigui->sig;
						sigui->sig = act;//Invertir la dirección
					}
				}

				act = sigui;//Avanzar al siguiente nodo por la lista original
				sigui = tmp;

				++cont;
			}
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
		
		//Comprobar que funciona en ambos sentidos
		/*act = this->fantasma->ant;//Último nodo

		while (act != this->fantasma) {//¿Podemos avanzar al siguiente nodo?
			std::cout << act->elem << " ";
			act = act->ant;
		}
		std::cout << '\n';*/
	}
};

bool resuelveCaso() {
	// leer los datos de la entrada
	ListaAmpliada<lli> lista;
	lli n, p, l;//num de elems, punto de inicio, longitud de la inversión
	std::cin >> n >> p >> l;

	if (!std::cin)
		return false;

	lli tmp;
	while (n--) {
		std::cin >> tmp;
		lista.push_back(tmp);
	}

	lista.invertirElementos(p, l);

	// escribir sol
	lista.print();

	return true;

}


int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso()) {} //Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
