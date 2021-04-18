// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"

// función que resuelve el problema
template <typename T>
std::pair<int, int> resolver(bintree<T> tree) {
    if (tree.empty())
        return{ 0, 0 };
    else
    {
        std::pair<int, int> izq = resolver(tree.left());
        std::pair<int, int> dcha = resolver(tree.right());
        return { std::max(izq.second + dcha.second + 1, std::max(izq.first, dcha.first)), std::max(izq.second, dcha.second) + 1 };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> tree = leerArbol('.');

    std::pair<int, int> sol = resolver(tree);//first - solución; second - niveles del árbol
    // escribir sol
    std::cout << sol.first << '\n';

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