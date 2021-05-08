// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <vector>
#include <string>

#include <sstream>//string stream

//Coste: O(log n) siendo n el número de palabras que se analizan

/*char minus(char a)//
{
    if (a <= 'Z')
        return a - ('A' - 'a');
    else
        return a;
}*/

std::string toLower(std::string word)
{
    std::string ret = "";
    for (char elem : word)
    {
        ret += std::tolower(elem);
    }
    return ret;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;

    if (n == 0)
        return false;

    std::map<std::string, std::vector<int>> dic;//Clave: palabra; valor: líneas con apariciones

    std::cin.ignore();
    for (int i = 1; i <= n; i++)
    {
        std::string str;
        std::getline(std::cin, str);//Lees toda la línea

        std::stringstream ss(str);//La conviertes en un stream

        std::string aux;//Lees el stream de la línea
        ss >> aux;
        while (ss)
        {
            aux = toLower(aux);//Convertir a minúsculas
            if (aux.length() > 2)//Sólo palabras de más de dos de longitud
            {
                auto it = dic.find(aux);
                if (it != dic.end())//Si está
                {
                    if (it->second.back() != i)//Si no se ha localizado aún esta línea
                        it->second.push_back(i);
                }
                else
                {
                    dic.insert({ aux, {i} });
                }
            }

            ss >> aux;
        }

        /*char aux = ' ';
        while (aux != '\n')
        {
            std::string word = "";
            std::cin.get(aux);
            while (aux != ' ' && aux != '\n')
            {
                //Convertir aux a mayúscula
                aux = minus(aux);

                word += aux;
                std::cin.get(aux);
            }

            if (word.length() > 2)//Sólo palabras de más de dos de longitud
            {
                auto it = dic.find(word);
                if (it != dic.end())//Si está
                {
                    if (it->second.back() != i)//Si no se ha localizado aún esta línea
                        it->second.push_back(i);
                }
                else
                {
                    dic.insert({ word, {i} });
                }
            }
        }*/
    }

    // escribir sol
    for (auto elem : dic)
    {
        std::cout << elem.first << " ";
        for (int x : elem.second)
        {
            std::cout << x << " ";
        }
        std::cout << '\n';
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
