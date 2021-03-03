// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
//#include <iomanip>
#include <fstream>
#include "01_Proximo_tren.h"
#include <vector>
#include <exception>
#include <algorithm>

//Breve explicación del problema: se define el tipo de dato para guardar las horas minutos y segundos que se van a tratar.
//  Con ello se definen también los operadores de lectura, escritura y comparación.
//  Finalmente se realiza una búsqueda binaria para encontrar la primera hora posterior.

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int trenes, consultas;
    std::cin >> trenes >> consultas;
    if (trenes == 0 && consultas == 0)
        return false;
    
    std::vector <Fecha> tren(trenes);

    for (Fecha& x : tren)//Lectura de trenes que pasan
        std::cin >> x;

    // escribir sol
    Fecha act;
    for (int i = 0; i < consultas; i++)
    {
        try 
        {
            std::cin >> act;//Lectura de la consulta

            //Búsqueda iterativa -> MAL -> TLE
            /*bool encontrado = false;
            int j = 0;
            while (!encontrado && j < trenes)
            {
                if (act <= tren[j])
                    encontrado = true;
                else
                    j++;
            }*/

            //Búsqueda binaria
            auto pos = std::lower_bound(tren.begin(), tren.end(), act);

            if (pos == tren.end())
                std::cout << "NO" << std::endl;// No pasarán trenes después de esa fecha
            else
                std::cout << *pos << std::endl;// Tendrá que esperar ese tiempo
        }
        catch (std::invalid_argument a)
        {
            std::cout << a.what() << std::endl;//ERROR en la fecha consultada
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
