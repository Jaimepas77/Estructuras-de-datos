// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"

struct tSol
{
    bool binario;
    int min, max;
};

//Coste lineal en el nº de nodos del árbol binario

//  Solucionado mediante una función recursiva que comprueba que el mayor de los elementos de la izquierda 
// sea siempre menor que la raíz para cada uno de los subárboles obtenibles.
// Además comprueba lo propio con el subárbol diestro (que su menor elemento sea mayor que la raíz).

// función que resuelve el problema
tSol resolver(bintree <int> tree) {
    if (tree.empty())
    {
        return { true, -1, -1 };//-1 es un valor que indica que no hay aún nºs analizados
    }
    else
    {
        tSol izq = resolver(tree.left());
        tSol dcha = resolver(tree.right());

        tSol ret;
        if (izq.binario && (izq.max < tree.root() || izq.max == -1) && dcha.binario && (dcha.min > tree.root() || dcha.min == -1))//Si cumple las condiciones...
        {
            ret.binario = true;
            if (izq.min == -1)
                ret.min = tree.root();
            else
                ret.min = izq.min;

            if (dcha.max == -1)
                ret.max = tree.root();
            else
                ret.max = dcha.max;
        }
        else
        {
            ret = { false, -1, -1 };
        }

        return ret;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> tree;
    tree = leerArbol(-1);

    tSol sol = resolver(tree);
    // escribir sol
    if (sol.binario)
        std::cout << "SI\n";
    else
        std::cout << "NO\n";

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