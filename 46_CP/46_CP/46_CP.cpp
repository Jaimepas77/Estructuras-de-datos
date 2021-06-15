// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using tEquipo = std::string;
using tAciertos = int;
using tTiempo = int;
using tProblema = std::string;
using tProblemsInfo = std::unordered_map <tProblema, std::pair<bool, int>>;//Nombre del problema - clave; par <ha sido resuelto, envíos fallidos> - valor

bool comp(std::pair<tEquipo, std::pair<tAciertos, tTiempo>> a, std::pair<tEquipo, std::pair<tAciertos, tTiempo>> b)
{
    if (a.second.first > b.second.first)//Aciertos (más primero)
        return true;
    else if (a.second.first == b.second.first && a.second.second < b.second.second)//Tiempo (menos primero)
        return true;
    else if (a.second.first == b.second.first && a.second.second == b.second.second && a.first < b.first)//Nombre
        return true;
    else
        return false;
}

// función que resuelve el problema
std::vector <std::pair<tEquipo, std::pair<tAciertos, tTiempo>>> resolver(std::unordered_map <tEquipo, std::pair <std::pair<tAciertos, tTiempo>, tProblemsInfo>> teams) {
    std::vector <std::pair<tEquipo, std::pair<tAciertos, tTiempo>>> ret;
    for (auto elem : teams)//Asignar al vector los datos necesarios del map
    {
        ret.push_back({ elem.first, {elem.second.first.first, elem.second.first.second} });//Queda un poco ilegible :(
    }
    sort(ret.begin(), ret.end(), comp);//Se ordena según el orden que queremos

    return ret;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    std::unordered_map <tEquipo, std::pair <std::pair<tAciertos, tTiempo>, tProblemsInfo>> teams;//Clave - nombre del equipo; valor - par <info del equipo, info de cada problema>

    std::string equipo, problema;
    int mins;
    std::string veredicto;
    std::cin >> equipo;
    while (equipo != "FIN")
    {
        std::cin >> problema >> mins >> veredicto;

        //Encontrar equipo (si no existe crearlo) -> [], < actualizar la info del problema (si no existe crearla) y actualizar la info de acierto y tiempo >

        auto pr = teams[equipo].second.insert({ problema, {false, 0} });//Se intenta insertar el problema en el equipo con los valores iniciales
        if (!pr.first->second.first)//Si el problema no ha sido resuelto... (si ha sido resuelto ya se ignoran los envíos)
        {
            if (veredicto == "AC")//Si es AC actualizar tiempos y aciertos del equipo
            {
                teams[equipo].first.first++;//Sumar un acierto
                teams[equipo].first.second += pr.first->second.second * 20 + mins;//Sumar el tiempo
                pr.first->second.first = true;//Marcar la resolución
            }
            else//Si es incorrecto...
            {
                pr.first->second.second++;//Sumar un fallo
            }
        }

        std::cin >> equipo;
    }

    std::vector <std::pair<tEquipo, std::pair<tAciertos, tTiempo>>> sol = resolver(teams);//Ordenar los datos
    // escribir sol
    for (auto elem : sol)
        std::cout << elem.first << " " << elem.second.first << " " << elem.second.second << '\n';

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
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}