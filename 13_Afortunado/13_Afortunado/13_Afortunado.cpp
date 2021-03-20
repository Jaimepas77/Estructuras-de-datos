// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>//Con una cola simple basta

using namespace std;

// función que resuelve el problema
int resolver(int a, int n) {
    queue <int> v;
    for (int i = 1; i <= a; ++i)
    {
        v.push(i);
    }

    while (v.size() > 1)
    {
        for (int i = 0; i < n; i++)
        {
            v.push(v.front());
            v.pop();
        }
        v.pop();
    }

    return v.front();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int a, n;//Alumnos, intervalos
    cin >> a >> n;
    if (a == 0 && n == 0)
        return false;

    int sol = resolver(a, n);

    // escribir sol
    cout << sol << '\n';

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
