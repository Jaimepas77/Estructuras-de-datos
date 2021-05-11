// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>

typedef long long int lli;

// función que resuelve el problema
int resolver(int datos) {
    int record = 0, tmp = 0;
    std::map<lli, int> pelis;//Clave - capítulo; valor: día

    lli clave;//Capítulo
    int valor;//Día
    for (int i = 0; i < datos; i++)
    {
        std::cin >> clave;
        valor = i;

        auto it = pelis.find(clave);
        tmp++;//Avanzamos
        if (it != pelis.end())//Si hemos visto este capítulo...
        {
            if (tmp > i - it->second)//Si se encuentra en nuestro rango de consecutivos actuales...
            {
                tmp = i - it->second;
            }
            pelis.erase(it);//Se borra el antiguo para no tener repes y poder insertar el más reciente
        }
        pelis.insert({ clave, valor });//Se inserta el dato del día actual

        if (tmp > record)
        {
            record = tmp;
        }
    }
    return record;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;

    int sol = resolver(n);
    // escribir sol
    std::cout << sol << '\n';
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