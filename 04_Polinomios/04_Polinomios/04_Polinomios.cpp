// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56
#include <iostream>
#include <iomanip>
#include <fstream>
#include "04_Polinomios.h"

typedef long long int lli;

// función que resuelve el problema
lli resolver(Polinomio x, int n) {
    return x.evaluar(n);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    Polinomio x;
    std::cin >> x;
    if (!std::cin)
        return false;

    int casos, num;
    std::cin >> casos;
    for (int i = 0; i < casos; i++)
    {
        std::cin >> num;
        lli sol = resolver(x, num);
        std::cout << sol << " ";
    }    // escribir sol
    std::cout << std::endl;

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