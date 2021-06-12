// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

bool primeraMay(std::string word)
{
    return word[0] <= 'Z' && word[0] >= 'A';//Devuelve si la primera letra es mayúscula o no
}

bool comp(std::pair<std::string, int> i, std::pair<std::string, int> j) //Comparar deportes para ordenarlos de mayor a menor apuntados
{ 
    if (i.second > j.second)
        return true;
    else if (i.second == j.second && i.first < j.first)//Orden alfabético
        return true;
    else
        return false;
}

// función que resuelve el problema
std::vector<std::pair<std::string, int>> resolver(std::unordered_map<std::string, int> datos) {
    std::vector<std::pair<std::string, int>> ret;
    for (auto elem : datos)
        ret.push_back(elem);

    std::sort(ret.begin(), ret.end(), comp);

    return ret;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::unordered_map <std::string, int> deportes;//Deporte - clave; alumnos apuntados - valor
    std::unordered_map <std::string, std::string> alumnos;//Alumno - clave; deporte del alumno - valor

    std::string aux, deporteAct;
    std::cin >> aux;

    if (!std::cin)
        return false;

    while (aux != "_FIN_")
    {
        if (primeraMay(aux))
        {
            deporteAct = aux;
            deportes[deporteAct] = 0;//Inicializar el deporte
        }
        else
        {
            auto it = alumnos.find(aux);
            if (it == alumnos.end())//Si el alumno no está
            {
                alumnos[aux] = deporteAct;//Se registra en este deporte
                deportes[deporteAct]++;//Se contabiliza en el deporte
            }
            else if (alumnos[aux] != deporteAct && alumnos[aux] != "sindeporte")//Si el alumno se apuntó en dos deportes distintos y aún era válido...
            {
                deportes[alumnos[aux]]--;//Se borra al alumno del anterior deporte
                alumnos[aux] = "sindeporte";//Se pone una marca en minúsculas para que no coincida con ningún deporte y se sepa que el alumno ya no se contabiliza
            }
            //Si se repite en el mismo deporte o ya está invalidado por apuntarse en deportes distintos entonces no hay que cambiar nada
        }

        std::cin >> aux;
    }

    std::vector<std::pair<std::string, int>> sol = resolver(deportes);//Convertir mapa sin orden en vector ordenado por el valor del mapa

    // escribir sol
    for (auto elem : sol)
        std::cout << elem.first << " " << elem.second << '\n';

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