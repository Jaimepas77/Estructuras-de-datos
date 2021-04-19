// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

bool isPrimo(int num)
{
    bool primo = true;
    if (num % 2 == 0)//Si dos es divisor
        primo = false;
    for (int i = 3;primo && i <= num/2; i += 2)//Revisar los impares
    {
        if (num % i == 0)//Si encontramos un divisor...
            primo = false;
    }
    return primo;
}

// función que resuelve el problema
std::pair <int, int> resolver(bintree <int> tree) {
    if (tree.empty() || isPrimo(tree.root()))//Si se cumple es que por aquí no se puede pasar
        return { -1, -1 };
    else if (tree.root() % 7 == 0)
        return{ tree.root(), 1 };//Número y profundidad actual
    else
    {
        std::pair<int, int> izq = resolver(tree.left());
        std::pair<int, int> dcha = resolver(tree.right());

        std::pair<int, int> ret;
        if (izq.first !=-1 && (dcha.first == -1|| izq.second <= dcha.second))
            ret = izq;
        else
            ret = dcha;

        ret.second++;//Añadimos la profundidad actual
        return ret;
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> tree = leerArbol(-1);

    std::pair <int, int> sol = resolver(tree);//Devuelve: first - nodo; second - profundidad
    // escribir sol
    if (sol.first != -1)//Si se ha encontrado...
        std::cout << sol.first << " " << sol.second << '\n';
    else
        std::cout << "NO HAY\n";

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