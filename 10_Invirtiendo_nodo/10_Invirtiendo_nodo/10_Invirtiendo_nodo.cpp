// Nombre y apellidos del alumno: Jaime Pastrana García
// Usuario del juez de clase: A56

#include <iostream>
#include <fstream>

#include "queue_eda.h"

template <class T>
class ListaAmpliada : public queue<T> {
    using Nodo = typename queue<T>::Nodo;
public:
    void invertirElementos() {

        // Aqui el código del alumno
        if (this->nelems > 1)
        {
            Nodo* act = this->prim;//Primer nodo
            this->prim = this->ult;
            this->ult = act;

            Nodo* sigui = act->sig;
            act->sig = nullptr;

            while (sigui != nullptr) {//¿Podemos avanzar al siguiente nodo?
                Nodo* tmp = sigui->sig;
                sigui->sig = act;
                act = sigui;
                sigui = tmp;
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
    ListaAmpliada<int> lista;
    int n;
    std::cin >> n;

    if (!std::cin)
        return false;

    while (n != 0) {
        lista.push(n);
        std::cin >> n;
    }

    lista.invertirElementos();

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