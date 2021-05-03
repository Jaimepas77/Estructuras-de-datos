// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;//Número de exámenes
    std::cin >> n;

    if (n <= 0)
        return false;

    std::map<std::string, int> evaluacion; //<clave, valor>
    std::string nombre;//Clave
    std::string resultado;//Correcto o incorrecto
    for (int i = 0; i < n; i++)
    {
        std::cin.ignore();
        std::getline(std::cin, nombre);//Lectura
        std::cin >> resultado;

        int correcto;
        resultado == "CORRECTO" ? correcto = 1 : correcto = -1;//Análisis del significado...

        /*
        //usando el insert
        std::pair<std::map<std::string, int>::iterator, bool> inser = evaluacion.insert({ nombre, correcto });
        if (!inser.second)
        {
            inser.first->second += correcto;
        }
        */

        //Usando el count y at, o find; e insert
            /*
            //count, at e insert
            if (evaluacion.count(nombre))//Si está...
                evaluacion.at(nombre) += correcto;
            else//Si no...
                evaluacion.insert({ nombre, correcto });
            */

            
            //find e insert
            auto it = evaluacion.find(nombre);
            if (it != evaluacion.end())//Si está...
                it->second += correcto;
            else//Si no...
                evaluacion.insert({ nombre, correcto });
            

        //Usando el operador []
        //evaluacion[nombre] += correcto;
    }

    // escribir sol
    for (std::pair <std::string, int> elem : evaluacion)
    {
        if(elem.second != 0)
            std::cout << elem.first << ", " << elem.second << '\n';
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
