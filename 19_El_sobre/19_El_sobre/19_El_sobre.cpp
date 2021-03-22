// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <fstream>
#include <deque>
#include <queue>

typedef long long int lli;

//El problema se resuelve según se leen los elementos

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    lli n, k;//Nº total de sobres, nº de sobres seleccionados
    std::cin >> n >> k;
    if (n == 0 && k == 0)
        return false;

    lli tmp;
    std::deque<lli> q;
    std::queue <lli> salida, sol;
    //El máximo va a ser simpre q.front()
    for (lli i = 0; i < k; i++)//Inicializar
    {
        std::cin >> tmp;
        while (!q.empty() && tmp > q.back())
            q.pop_back();
        q.push_back(tmp);
        salida.push(tmp);
    }

    sol.push(q.front());
    for (lli i = k; i < n; i++)//Recorrer
    {
        std::cin >> tmp;
       
        while (!q.empty() && tmp > q.back())//Los elementos menores que el que acabamos de colocar resultan completamente innecesarios para nuestro propósito, al no poder nunca más ser el máximo de entre los sobres que se tienen.
            q.pop_back();
        q.push_back(tmp);
        salida.push(tmp);

        if (salida.front() == q.front())//Si el elemento máximo actual se sale en este momento del grupo de sobres...
            q.pop_front();
        salida.pop();//La cola con los elementos actuales se mantiene según debe.

        //En el frente de la pila se encuentra siempre el sobre que no ha podido ser superado por sus posteriores, puesto que si no se habría eliminado.
        sol.push(q.front());//Se va guardando el máximo de cada grupo de sobres en el vector o cola de la solución.
    }

    // escribir sol
    while (!sol.empty())
    {
        std::cout << sol.front() << " ";
        sol.pop();
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
