// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <fstream>
#include "Carnet.h"

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    string instruccion;
    cin >> instruccion;

    if (!std::cin)
        return false;

    carnet dgt;
    while (instruccion != "FIN")
    {
        try
        {
            if (instruccion == "nuevo")
            {
                string dni;
                cin >> dni;
                dgt.nuevo(dni);
            }
            else if (instruccion == "quitar")
            {
                string dni;
                int points;
                cin >> dni >> points;
                dgt.quitar(dni, points);
            }
            else if (instruccion == "recuperar")
            {
                string dni;
                int points;
                cin >> dni >> points;
                dgt.recuperar(dni, points);
            }
            else if (instruccion == "consultar")
            {
                string dni;
                cin >> dni;
                int result = dgt.consultar(dni);
                cout << "Puntos de " << dni << ": " << result << endl;
            }
            else if (instruccion == "cuantos_con_puntos")
            {
                int points;
                cin >> points;
                int result = dgt.cuantos_con_puntos(points);
                cout << "Con " << points << " puntos hay " << result << endl;
            }
            else if (instruccion == "lista_por_puntos")
            {
                int points;
                cin >> points;
                vector <string> result = dgt.lista_por_puntos(points);
                cout << "Tienen " << points << " puntos: ";
                for (string dni : result)
                    cout << dni << " ";
                cout << endl;
            }
        }
        catch (domain_error e)
        {
            cout << "ERROR: " << e.what() << endl;
        }

        cin >> instruccion;
    }

    cout << "---\n";

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