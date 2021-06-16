// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdexcept>
#include <vector>
#include "libros.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;

    if (!std::cin)
        return false;

    libreria buenavista;
    for (int i = 0; i < n; i++)
    {
        std::string op;
        std::cin >> op;
        try
        {
            if (op == "nuevoLibro")
            {
                std::string libro;
                int unidades;
                std::cin >> unidades;
                std::cin.ignore();//Tragarse el espacio
                std::getline(std::cin, libro);

                buenavista.nuevoLibro(unidades, libro);
            }
            else if (op == "comprar")
            {
                std::string libro;
                std::cin.ignore();//Tragarse el espacio
                std::getline(std::cin, libro);
                buenavista.comprar(libro);
            }
            else if (op == "estaLibro")
            {
                std::string libro;
                std::cin.ignore();//Tragarse el espacio
                std::getline(std::cin, libro);

                bool sol = buenavista.estaLibro(libro);
                if (sol)
                    std::cout << "El libro " << libro << " esta en el sistema\n";
                else
                    std::cout << "No existe el libro " << libro << " en el sistema\n";
            }
            else if (op == "elimLibro")
            {
                std::string libro;
                std::cin.ignore();//Tragarse el espacio
                std::getline(std::cin, libro);
                buenavista.elimLibro(libro);
            }
            else if (op == "numEjemplares")
            {
                std::string libro;
                std::cin.ignore();//Tragarse el espacio
                std::getline(std::cin, libro);
                try
                {
                    int ej = buenavista.numEjemplares(libro);
                    std::cout << "Existen " << ej << " ejemplares del libro " << libro << '\n';
                }
                catch (std::invalid_argument e)
                {
                    std::cout << "No existe el libro " << libro << " en el sistema\n";
                }
            }
            else if (op == "top10")
            {
                std::vector <std::string> top = buenavista.top10();
                std::cout << "TOP10\n";
                for (auto elem : top)
                    std::cout << "    " << elem << '\n';
            }
        }
        catch(std::invalid_argument e)
        {
            std::cout << e.what() << '\n';
        }
        catch (std::out_of_range e)
        {
            std::cout << e.what() << '\n';
        }
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