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
	void invertirElementos(lli p, lli l) {
		// Aqui el código del alumno
		if (l > 1)//Si hay varios elementos para invertir... (si hay sólo uno pues no se hace nada)
		{
			lli cont = 1;//Contador del elemento que lleva SIGUI
			Nodo* act = nullptr;//Nodo en análisis: se inicializa apuntando al primer nodo
			Nodo* start = this->prim;//Nodo cuyo puntero hay que cambiar para apuntar al comienzo del segmento invertido
			Nodo* end = nullptr;
			
			Nodo* sigui = this->prim;

			while (sigui != nullptr) {//¿Podemos avanzar al siguiente nodo?
				Nodo* tmp = sigui->sig;//Para mantenerlo a pesar de las manipulaciones que se puedan realizar en los if

				if (cont >= p && cont < p + l)//Si estamos en el segmento de las inversiones...
				{
					if (cont == p + l - 1)//Si es el último elem de la inversión...
					{
						if (start == nullptr)//Si el primer elemento ya formaba parte de la inversión...
							this->prim = sigui;
						else
							start->sig = sigui;

						if (sigui->sig == nullptr)//Si el último elemento forma parte de la inversión...
							this->ult = sigui;
						end->sig = sigui->sig;
					}

					if (cont == p)//Si es el primer elem de la inversión...
					{
						start = act;
						end = sigui;
					}
					else//Sólo es necesario manipular el puntero de este elem a su anterior si no es el primero (que se tiene que convertir en el último)
					{
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
		Nodo* act = this->prim;//Primer nodo

		while (act != nullptr) {//¿Podemos avanzar al siguiente nodo?
			std::cout << act->elem << " ";
			act = act->sig;
		}
		std::cout << '\n';
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
		lista.push(tmp);
	}

	lista.invertirElementos(p, l);

	// escribir sol
	lista.print();

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}