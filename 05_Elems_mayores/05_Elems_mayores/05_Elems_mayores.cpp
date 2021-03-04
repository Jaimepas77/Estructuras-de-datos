// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <fstream>
#include "conjunto.h"

typedef long long int lli;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    char a;
    std::cin >> a;
    if (!std::cin)
        return false;
    int tam;
    std::cin >> tam;
    if (a == 'N')
    {
        set<lli> sol = set<lli>(tam);

        lli entrada;

        std::cin >> entrada;
        while (entrada != -1)
        {
            sol.insert(entrada);
            std::cin >> entrada;
        }

        std::cout << sol << std::endl;
    }
    else
    {
        set<std::string> sol = set<std::string>(tam);

        std::string entrada;

        std::cin >> entrada;
        while (entrada != "FIN")
        {
            sol.insert(entrada);
            std::cin >> entrada;
        }

        std::cout << sol << std::endl;
    }

    // escribir sol


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