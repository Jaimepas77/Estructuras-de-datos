// Nombre y apellidos del alumno: Jaime Pastrana García
// usuario del juez de clase: A56

#include <iostream>
#include <fstream>

#include "deque_eda.h"

template <class T>
class ListaAmpliada : public deque<T> {
    using Nodo = typename deque<T>::Nodo;
public:
    void invertirElementos() {

        // Aqui el código del alumno
        if (this->nelems > 1)
        {
            Nodo* act = this->fantasma->sig;//Darle la vueta al nodo fantasma
            this->fantasma->sig = this->fantasma->ant;
            this->fantasma->ant = act;

            while (act != this->fantasma) {//¿Podemos avanzar al siguiente nodo? - ¿El siguiente nodo no es el fantasma?
                Nodo* tmp = act->ant;//Intercambiamos los punteros del nodo
                act->ant = act->sig;
                act->sig = tmp;

                act = act->ant;//Avanzamos (retrocedemos en la nueva lista)
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
    }
};

bool resuelveCaso() {
    // leer los datos de la entrada
    ListaAmpliada<int> lista;
    int n;
    std::cin >> n;

    if (!std::cin)
        return false;

    while (n != 0) {
        lista.push_back(n);
        std::cin >> n;
    }

    lista.invertirElementos();

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
