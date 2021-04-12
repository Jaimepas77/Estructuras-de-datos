// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

struct tDatos
{
    int nodos, hojas, altura;
};

// función que resuelve el problema
tDatos resolver(bintree<char> arbol) {

    tDatos ret;
    ret.nodos = arbol.nodes();
    ret.hojas = arbol.leafs();
    ret.altura = arbol.height();
    return ret;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> arbol;
    arbol = leerArbol('.');

    tDatos sol = resolver(arbol);
    // escribir sol
    std::cout << sol.nodos << " " << sol.hojas << " " << sol.altura << '\n';

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