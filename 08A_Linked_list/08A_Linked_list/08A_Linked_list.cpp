// Nombre y apellidos del alumno: Jaime Pastrana García
// usuario del juez de clase: A56

#include <iostream>
#include <fstream>

#include "queue_eda.h"

class propSerPar {
public:
    bool operator() (int n) {
        return n % 2 == 0;
    }
};

template <class T>
class ListaAmpliada : public queue<T> {
    using Nodo = typename queue<T>::Nodo;
public:
    template <class comp>
    int contarElementos(comp propiedad) const {

        // Aqui el código del alumno

        // Para comprobar que un elemento a cumple una propiedad
        // se utiliza la función recibida como parámetro
        // if (propiedad(a)) ...

        int cont = 0;
        Nodo* act = this->prim;//Primer nodo
        if (propiedad(act->elem))//¿Se cumple la propiedad en ese nodo?
            cont++;
        while (act->sig != nullptr) {//¿Podemos avanzar al siguiente nodo?
            act = act->sig;
            if (propiedad(act->elem))
                cont++;
        }

        return cont;
    }
};



bool resuelveCaso() {
    int numElem;
    std::cin >> numElem;
    if (numElem == 0) return false;

    ListaAmpliada<int> lista;
    for (size_t i = 0; i < numElem; ++i) {
        int n;
        std::cin >> n;
        lista.push(n);
    }
    int cont = lista.contarElementos(propSerPar());

    std::cout << cont << '\n';

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
