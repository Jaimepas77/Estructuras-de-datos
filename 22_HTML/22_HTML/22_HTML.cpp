// Nombre del alumno Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stack>

// función que resuelve el problema
bool resolver(std::string frase, int& p, int& b, int& i, int& q) {
    std::stack<char> s;

    for (int j = 6; j < frase.size() - 7; j++)
    {
        std::string open = frase.substr(j, 3), close = open + frase[j+3];
        
        if (open == "<p>" || open == "<b>" || open == "<i>" || open == "<q>")
        {
            s.push(open[1]);
            j += 2;
        }
        
        if (close == "</p>" || close == "</b>" || close == "</i>" || close == "</q>")
        {
            if (!s.empty() && s.top() == open[2])
            {
                s.pop();
                switch (open[2])
                {
                case 'p': p++;
                    break;
                case 'b': b++;
                    break;
                case 'i': i++;
                    break;
                case 'q': q++;
                }
            }
            else
                return false;

            j += 3;
        }
    }

    if (s.empty())
        return true;
    else
        return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string frase;
    std::getline(std::cin, frase);

    if (!std::cin)
        return false;

    int p = 0, b = 0, i = 0, q = 0;
    // escribir sol tras resolver
    if (resolver(frase, p, b, i, q))
        std::cout << "SI " << p << " " << b << " " << i << " " << q << '\n';
    else
        std::cout << "NO\n";
    
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