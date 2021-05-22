// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Empleo.h"

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    if (!std::cin)
        return false;

    oficinaEmpleo oficina;
    string instruccion;
    cin >> instruccion;

    while (instruccion != "FIN")
    {
        try
        {
            if (instruccion == "altaOficina")
            {
                string persona, empleo;
                cin >> persona >> empleo;
                oficina.altaOficina(persona, empleo);
            }
            else if (instruccion == "ofertaEmpleo")
            {
                string empleo;
                cin >> empleo;
                cout << empleo << ": " << oficina.ofertaEmpleo(empleo) << endl;
            }
            else if (instruccion == "listadoEmpleos")
            {
                string persona;
                cin >> persona;
                vector <string> empleos = oficina.listadoEmpleos(persona);
                cout << persona << ": ";
                for (string emp : empleos)
                {
                    cout << emp << " ";
                }
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

    cin.ignore();

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