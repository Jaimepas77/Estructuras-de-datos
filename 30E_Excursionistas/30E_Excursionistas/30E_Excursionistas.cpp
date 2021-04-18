// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"


// función que resuelve el problema
std::pair<int, int> resolver(bintree<int> tree) {
    if (tree.empty())
        return { 0, 0 };
    else
    {
        std::pair <int, int> izq = resolver(tree.left());
        std::pair <int, int> dcha = resolver(tree.right());

        int equipos = 0;
        int rescatados = std::max(izq.second, dcha.second) + tree.root();//El número máximo de rescatados por equipo es siempre el nº de rescatados máximo de entre las dos ramas más el nodo actual

        equipos = izq.first + dcha.first;
        if (tree.root() > 0)//Si se rescata en este nodo...
            equipos = std::max(equipos, 1);//Tiene que haber mínimo un equio de rescate (si no lo hay se pone)

        return { equipos, rescatados };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree <int> tree = leerArbol(-1);

    std::pair<int, int> sol = resolver(tree);
    // escribir sol
    std::cout << sol.first << " " << sol.second << '\n';//first - equipos necesarios; second - equipo con más rescatados
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