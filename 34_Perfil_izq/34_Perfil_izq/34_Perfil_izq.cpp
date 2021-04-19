// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"

// función que resuelve el problema
void resolver(const bintree<int> &tree, std::vector <int> &sol, int prof) {
    prof++;
    if (tree.empty())
        return;
    else
    {
        if (prof > sol.size())
            sol.push_back(tree.root());

        //Primero la izquierda, para sacar el perfil izquierdo. Si quisieramos el derecho entonces habría que buscar primero en la derecha.
        resolver(tree.left(), sol, prof);
        resolver(tree.right(), sol, prof);
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> tree = leerArbol(-1);

    std::vector <int> v;
    resolver(tree, v, 0);
    // escribir sol
    for (int a : v)
        std::cout << a << " ";
    std::cout << '\n';

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