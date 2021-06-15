// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <fstream>
#include <list>

template <class T>
T Mysearch(T const& ini1, T const& fin1, T const& ini2, T const& fin2) {


    // Aqui el código del alumno
    T act = ini1;
    while (act != fin1)//Recorrer la lista inicial
    {
        T lug1 = act, lug2 = ini2;
        while (*lug1 == *lug2)//Recorrer hasta que difieran (si no difieren y se llega al final de la segunda lista entonces hemos encontrado la secuencia)
        {
            lug1++;
            lug2++;
            if (lug2 == fin2) return act;
            if (lug1 == fin1) return fin1;
        }

        act++;
    }

    return fin1;
}

bool resuelveCaso() {
    int nElem1, nElem2; std::cin >> nElem1 >> nElem2;
    if (nElem1 == 0 && nElem2 == 0) return false;
    // Lectura delos datos
    std::list<int> lista1;
    for (int i = 0; i < nElem1; ++i) {
        int aux;
        std::cin >> aux;
        lista1.push_back(aux);
    }
    std::list<int> lista2;
    for (int i = 0; i < nElem2; ++i) {
        int aux;
        std::cin >> aux;
        lista2.push_back(aux);
    }
    // Elimina todas las apariciones de la lista2 en la lista 1
    // Utilizando la función Mysearch
    auto it1 = lista1.begin();
    while (it1 != lista1.end()) {
        it1 = Mysearch(it1, lista1.end(), lista2.begin(), lista2.end());
        if (it1 != lista1.end()) {
            for (int i = 0; i < lista2.size(); ++i) {
                it1 = lista1.erase(it1);
            }
        }
    }
    // Escribe la lista
    auto it = lista1.begin();
    if (it != lista1.end()) {
        std::cout << *it;
        ++it;
    }
    for (; it != lista1.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';


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
