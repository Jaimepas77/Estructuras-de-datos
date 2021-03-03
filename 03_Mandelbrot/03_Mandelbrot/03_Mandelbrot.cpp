// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <fstream>
#include "03_Mandelbrot.h"

// función que resuelve el problema
bool resolver(Complejo<double> c, int iter) {
    Complejo<double> z = Complejo<double>(0, 0);
    while (iter > 0 && z.modulo() <= 2)
    {
        z = z * z + c;
        iter--;
    }
    return z.modulo() <= 2;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    Complejo<double> c;
    int iter;
    std::cin >> c >> iter;

    bool sol = resolver(c, iter);
    // escribir sol
    if (sol)
        std::cout << "SI" << std::endl;
    else
        std::cout << "NO" << std::endl;

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