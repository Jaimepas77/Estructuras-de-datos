// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"

struct tDatos
{
    bool nada;//Si es nada
    int min, max;//Nodo hoja de profundidad mínima y nodo hoja de profundidad máxima
};

// función que resuelve el problema
tDatos resolver(bintree <char> tree) {
    if (tree.empty())
        return { false, 0, 0 };
    else
    {
        tDatos izq = resolver(tree.left());
        tDatos dcha = resolver(tree.right());

        if (izq.nada || dcha.nada || (izq.max - 2 >= dcha.min) || (izq.min < dcha.max))
            return { true, 0, 0 };
        else
            return { false, dcha.min + 1, izq.max + 1 };
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree <char> tree = leerArbol('.');

    tDatos sol = resolver(tree);//First - profundidad "máxima"; second - "profundidad mínima"
    // escribir sol
    if (sol.nada)
        std::cout << "NADA\n";
    else if (sol.max == sol.min)
        std::cout << "COMPLETO\n";
    else
        std::cout << "SEMICOMPLETO\n";

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