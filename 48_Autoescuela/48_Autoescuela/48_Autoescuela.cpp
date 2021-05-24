// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Autoescuela.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    std::string instruccion;
    std::cin >> instruccion;

    if (!std::cin)
        return false;

    autoescuela registro;
    while (instruccion != "FIN")
    {
        try
        {
            if (instruccion == "alta")
            {
                std::string alumno, profe;
                std::cin >> alumno >> profe;

                registro.alta(alumno, profe);
            }
            else if (instruccion == "es_alumno")
            {
                std::string alumno, profe;
                std::cin >> alumno >> profe;

                bool res = registro.es_alumno(alumno, profe);

                std::cout << alumno << " ";
                if (!res)
                    std::cout << "no ";
                std::cout << "es alumno de " << profe << '\n';
            }
            else if (instruccion == "puntuacion")
            {
                std::string alumno;
                std::cin >> alumno;

                int res = registro.puntuacion(alumno);

                std::cout << "Puntuacion de " << alumno << ": " << res << '\n';
            }
            else if (instruccion == "actualizar")
            {
                std::string alumno;
                int nota;
                std::cin >> alumno >> nota;

                registro.actualizar(alumno, nota);
            }
            else if (instruccion == "examen")
            {
                std::string profe;
                int nota;
                std::cin >> profe >> nota;

                std::vector<std::string> v = registro.examen(profe, nota);

                std::cout << "Alumnos de " << profe << " a examen: \n";
                for (std::string a : v)
                {
                    std::cout << a << '\n';
                }
            }
            else if (instruccion == "aprobar")
            {
                std::string alumno;
                std::cin >> alumno;

                registro.aprobar(alumno);
            }
        }
        catch (domain_error e)
        {
            std::cout << "ERROR\n";
        }

        std::cin >> instruccion;
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