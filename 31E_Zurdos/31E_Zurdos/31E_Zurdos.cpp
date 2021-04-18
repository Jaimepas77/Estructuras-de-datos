// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

// función que resuelve el problema
std::pair<int, bool> zurdo(bintree<char> tree) {
    if (tree.empty())
        return { 0, true };
    else if (tree.left().empty() && tree.right().empty())
        return { 1, true };
    else
    {
        std::pair <int, bool> izq = zurdo(tree.left());
        std::pair <int, bool> dcha = zurdo(tree.right());
        return { izq.first + dcha.first + 1, izq.second && dcha.second && izq.first > dcha.first };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> tree = leerArbol('.');

    std::pair<int, bool> sol = zurdo(tree);
    // escribir sol
    if (sol.second)
        std::cout << "SI\n";
    else
        std::cout << "NO\n";
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