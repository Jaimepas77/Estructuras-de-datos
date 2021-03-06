// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;

    if (!std::cin)
        return false;

    std::stack<std::pair<std::string, int>>pila;//stack con pares fecha - pasajeros
    // escribir sol
    for (int i = 0; i < n; ++i)//En cada accidente...
    {
        std::pair<std::string, int> tmp;
        std::cin >> tmp.first >> tmp.second;

        bool encontrado = false;
        while (!encontrado && pila.size() > 0)//Sacar elementos hasta que no queden o el que toque tenga estrictamente más pasajeros.
        {
            if (pila.top().second > tmp.second)
                encontrado = true;
            else
                pila.pop();
        }

        if (encontrado)
            std::cout << pila.top().first << std::endl;
        else
            std::cout << "NO HAY\n";

        pila.push(tmp);//El accidente actual se tiene en cuenta
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