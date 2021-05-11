// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    std::string aux;
    std::getline(std::cin, aux);
    std::stringstream linea1(aux);//Linea en stringstream

    std::string clave;
    int valor;
    //Diccionarios inicial y secundario: en el inicial se dejarán los eliminados, en el secundario los nuevos y en el cambios los de valor cambiado
    std::map<std::string, int> ini, sec, cambios;//Clave - cadena de caracteres; valor - números enteros asociados
    while (linea1 >> clave) {//Lectura uno
        linea1 >> valor;
        ini.insert({ clave, valor });
    }

    std::getline(std::cin, aux);
    std::stringstream linea2(aux);//Linea en stringstream

    while (linea2 >> clave) {//Lectura dos
        linea2 >> valor;
        auto it = ini.find(clave);
        if (it == ini.end())//Si no está en ini...
        {
            sec.insert({ clave, valor });
        }
        else if (it->second == valor)//Si está exactamente igual...
        {
            ini.erase(it);
        }
        else//Si está pero con valor cambiado...
        {
            cambios.insert({ clave, valor });
            ini.erase(it);
        }
    }

    // escribir sol
    if (sec.size() > 0)
    {
        std::cout << "+ ";
        for (auto it : sec)
        {
            std::cout << it.first << " ";
        }
        std::cout << '\n';
    }
    if (ini.size() > 0)
    {
        std::cout << "- ";
        for (auto it : ini)
        {
            std::cout << it.first << " ";
        }
        std::cout << '\n';
    }
    if (cambios.size() > 0)
    {
        std::cout << "* ";
        for (auto it : cambios)
        {
            std::cout << it.first << " ";
        }
        std::cout << '\n';
    }
    if (sec.size() == 0 && ini.size() == 0 && cambios.size() == 0)
    {
        std::cout << "Sin cambios\n";
    }
    std::cout << "---\n";

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
    std::cin.ignore();
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}