// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <exception>
#include <algorithm>
#include "02_Tarde_de_sabado.h"
#include "Pelis.h"

//Breve explicación del problema: se define el tipo de dato para guardar las horas minutos y segundos que se van a tratar.
//  Con ello se definen también los operadores de lectura, escritura y comparación.
//  Se hace igual con las películas. Finalimente se ordenan mediante la función sort y se sacan por pantalla

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int pelis;
    std::cin >> pelis;
    if (pelis == 0)
        return false;

    std::vector <Pelicula> v(pelis);

    for (Pelicula& x : v)//Lectura de las películas que hay
        std::cin >> x;
    
    // escribir sol
    //Para resolver el problema:
        //-Crear el operdor suma para fechas. -> ok
        //-Definir la clase película con hora de inicio y duración. -> ok
        //-Definir el operador menor para las películas en funcion de la hora de finalización de cada película. -> ok
        //-Definir el operador de lectura y escritura de una película. -> ok

        //-Tras ello, llamar a sort del vector de películas
        sort(v.begin(), v.end());
        //-Y sacar por pantalla las palículas ordenadas
        for (Pelicula x : v)
            std::cout << x << std::endl;
   
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
