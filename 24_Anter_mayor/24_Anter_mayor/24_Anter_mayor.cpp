// IMPORTANTE:
// Nombre del alumno: Jaime Pastrana García
// Usuario del juez de clase: A56
// Usuario que se ha utilizado en esta prueba: A25


#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

// Explicación de la solución empleada



// Coste de la solución




bool resuelveCaso() {
    int nElem; std::cin >> nElem;
    if (nElem == 0) return false;


    // A completar por el alumno
    int tmp, val;
    stack<pair<int, int>> s;//first - valor; second - solucion

    for (int i = 0; i < nElem; i++)
    {
        tmp = 0;
        cin >> val;
        while (!s.empty() && s.top().first <= val)
        {
            tmp += s.top().second;
            s.pop();
            tmp++;
        }
        s.push({ val, tmp });
        cout << tmp << " ";
    }
    cout << '\n';

    return true;
}

int main() {

#ifndef DOMJUDGE
    std::ifstream in("datos.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso()) {} //Resolvemos todos los casos


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
