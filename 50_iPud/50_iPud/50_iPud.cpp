// Nombre del alumno: JAime PAstrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include <vector>
#include "iPud.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string op;
    iPad spotify;

    std::cin >> op;
    if (!std::cin)
        return false;

    while (op != "FIN")
    {
        try {
            if (op == "addSong")
            {
                std::string c, a;
                int d;
                std::cin >> c >> a >> d;
                spotify.addSong(c, a, d);
            }
            else if (op == "addToPlaylist")
            {
                std::string c;
                std::cin >> c;
                spotify.addToPlaylist(c);
            }
            else if (op == "current")
            {
                spotify.current();
            }
            else if (op == "play")
            {
                std::string cancion = spotify.play();
                if (cancion != "")
                {
                    std::cout << "Sonando " << cancion << '\n';
                }
                else
                    std::cout << "No hay canciones en la lista\n";
            }
            else if (op == "totalTime")
            {
                int t = spotify.totalTime();
                std::cout << "Tiempo total " << t << '\n';
            }
            else if (op == "recent")
            {
                int n;
                std::cin >> n;
                std::vector <std::string> v = spotify.recent(n);
                if (v.empty())
                    std::cout << "No hay canciones recientes\n";
                else
                {
                    std::cout << "Las " << v.size() << " mas recientes\n";
                    for (auto elem : v)
                        std::cout << "    " << elem << '\n';
                }
            }
            else if (op == "deleteSong")
            {
                std::string c;
                std::cin >> c;
                spotify.deleteSong(c);
            }
        }
        catch (std::invalid_argument e) {
            std::cout << "ERROR " << e.what()<< '\n';
        }
        catch (std::domain_error e) {
            std::cout << "ERROR " << e.what() << '\n';
        }
        
        std::cin >> op;
    }

    // escribir sol
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