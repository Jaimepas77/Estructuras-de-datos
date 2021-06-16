// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"

// función que resuelve el problema
std::pair<int, int> resolver(const bintree<int>& rio) {

    if (rio.empty())
        return { 0, 0 };
    else if (rio.left().empty() && rio.right().empty())//Si es hoja... (CB)
        return { std::max(0, 1 - rio.root()), 0 };
    else
    {
        auto uno = resolver(rio.left());
        auto dos = resolver(rio.right());
        int caudal = std::max(uno.first + dos.first - rio.root(), 0);
        int navegables = uno.second + dos.second;
        if (uno.first >= 3)
            navegables++;
        if (dos.first >= 3)
            navegables++;
        return { caudal, navegables };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> rio;//Río de Aguaslimpias
    rio = leerArbol(-1);

    std::pair<int, int> sol = resolver(rio);//First - caudal; second - tramos navegables
    // escribir sol
    std::cout << sol.second << '\n';

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