// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdexcept>
#include "academia.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string op;
    academia_chino cambridge;
    std::cin >> op;

    if (!std::cin)
        return false;

    while (op != "FIN")
    {
        try {
            if (op == "nuevo_estudiante")
            {
                std::string dni;
                int grupo;
                std::cin >> dni >> grupo;
                cambridge.nuevo_estudiante(dni, grupo);
            }
            else if (op == "promocionar")
            {
                std::string dni;
                std::cin >> dni;
                cambridge.promocionar(dni);
            }
            else if (op == "grupo_estudiante")
            {
                std::string dni;
                std::cin >> dni;
                int num = cambridge.grupo_estudiante(dni);
                std::cout << dni << " esta en el grupo " << num << '\n';
            }
            else if (op == "graduados")
            {
                std::vector<std::string> v;
                v = cambridge.graduados();
                std::cout << "Lista de graduados: ";
                for (auto d : v)
                    std::cout << d << " ";
                std::cout << '\n';
            }
            else if (op == "novato")
            {
                int c;
                std::cin >> c;
                std::string dni = cambridge.novato(c);
                std::cout << "Novato de " << c << ": ";
                std::cout << dni << '\n';
            }
        }
        catch (std::domain_error e)
        {
            std::cout << "ERROR: " << e.what() << '\n';
        }
        catch (std::invalid_argument e)
        {
            std::cout << "ERROR: " << e.what() << '\n';
        }

        std::cin >> op;
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