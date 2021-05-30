// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <fstream>
#include "set_eda.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam, aux;
    std::cin >> tam;
    set<int> conjunto;

    if (tam == 0)
        return false;

    for (int i = 0; i < tam; i++)//insertar datos en el conjunto
    {
        std::cin >> aux;
        conjunto.insert(aux);
    }

    // escribir sol
    int consultas;
    std::cin >> consultas;
    for (int i = 0; i < consultas; i++)//Leer y reaccionar a cada consulta
    {
        std::cin >> aux;
        std::pair <bool, int> sol = conjunto.lower_bound(aux);//Coste logarítmico en el nº de elems del set
        if (sol.first)
            std::cout << sol.second;
        else
            std::cout << "NO HAY";
        std::cout << '\n';
    }

    std::cout << "---\n";

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
