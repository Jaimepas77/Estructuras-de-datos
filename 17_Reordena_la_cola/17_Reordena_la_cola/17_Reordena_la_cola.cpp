// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56


#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <stack>

//Explicación de la resolución: dado que todos los nºs negativos van antes que los positivos se guardan en una estructura distinta.
// Dado que los nºs negativos van en orden inverso al que deben llevar, se utiliza una pila para darles la vuelta rápidamente.
// Dado que los elementos positivos van en el orden correcto, se guardan en una cola y se imprimen posteriormente (después de haber puesto los negativos).

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;
    if (n == 0)//Caso centinela
        return false;

    std::queue <int> q;//Para los nºs positivos
    std::stack <int> s;//Para los nºs negativos (que van en orden inverso al dado)
    for (int i = 0; i < n; i++)
    {
        int tmp;
        std::cin >> tmp;
        if (tmp < 0)//Dependiendo de si el nº es positivo...
            s.push(tmp);
        else
            q.push(tmp);
    }

    // escribir sol
    while (s.size() > 0)//Nºs negativos
    {
        std::cout << s.top() << " ";
        s.pop();
    }

    while (q.size() > 0)//Nºs positivos
    {
        std::cout << q.front() << " ";
        q.pop();
    }

    std::cout << '\n';

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
