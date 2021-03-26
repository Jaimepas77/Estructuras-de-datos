// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
using namespace std;//Para ahorrar un poco de tiempo que gasta poner std:: en todos lados

// función que resuelve el problema
void resolver(list <int> &lista) {
    for (auto it = lista.begin(); it != lista.end(); ++it)
        lista.insert(it, *it);//Inserta el elemento justo en la posición anterior a la actual.
}

void impresionar(list <int>& lista) {
    auto it = lista.end();//Iterador para realizar el recorrido en orden inverso
    while (it != lista.begin())
        cout << *(--it) << ' ';//Probando maneras distintas de hacerlo
    cout << '\n';
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tmp;
    list <int> lista;
    cin >> tmp;//Primera lectura para ver si hay elems

    if (!std::cin)
        return false;

    if (tmp != 0)//Seguimos leyendo si el elemento primero es distinto de 0
    {
        lista.push_front(tmp);
        cin >> tmp;
    }
    while (tmp != 0)//Lectura hasta que se encuentra un 0
    {
        lista.push_front(tmp);
        cin >> tmp;
    }

    resolver(lista);//Duplicamos los elementos...

    // escribir sol
    impresionar(lista);

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

//#Practicando