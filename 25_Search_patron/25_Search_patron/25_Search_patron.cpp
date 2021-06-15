// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>

typedef long long int lli;

template <class T>
T MySearch(T const& ini1, T const& fin1, T const& ini2, T const& fin2)
{
    T act = ini1;
    while (act != fin1)//Recorrer la lista inicial
    {
        T lug1 = act, lug2 = ini2;
        while (*lug1 == *lug2)//Recorrer hasta que difieran (si no difieren y se llega al final de la segunda lista entonces hemos encontrado la secuencia)
        {
            lug1++;
            lug2++;
            if (lug2 == fin2) return act;
            if (lug1 == fin1) return fin1;
        }

        act++;
    }

    return fin1;
}

// función que resuelve el problema
void resolver(std::list <int>& original, std::list<int> &secuencia) {//Eliminar los fragmentos de la secuencia en la lista original
    std::list <std::list<int>::iterator> apariciones;

    auto it = MySearch(original.begin(), original.end(), secuencia.begin(), secuencia.end());
    while (it != original.end())
    {
        apariciones.push_back(it);//Guardamos todas las apariciones de la secuencia

        it = MySearch(++it, original.end(), secuencia.begin(), secuencia.end());
    }

    auto ap = apariciones.begin();//Para eliminar secuencias solapadas se tiene una lista de las marcas de todas las secuencias encontradas (solapadas o no)
    while (ap != apariciones.end())
    {
        auto act = ap;
        ap++;

        int i = 0;
        while ((ap == apariciones.end() || *act != *ap) && i < secuencia.size())//Si no está solapada... (si está solapada se pasa a la siguiente)
        {
            *act = original.erase(*act);
            i++;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::list <int> original, secuencia;
    lli a;
    int b, aux;
    std::cin >> a >> b;

    if (a == 0 && b == 0)
        return false;

    for (lli i = 0; i < a; i++)
    {
        std::cin >> aux;
        original.push_back(aux);
    }
    for (int i = 0; i < b; i++)
    {
        std::cin >> aux;
        secuencia.push_back(aux);
    }

    resolver(original, secuencia);

    // escribir sol
    for (int elem : original)
        std::cout << elem << " ";
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
