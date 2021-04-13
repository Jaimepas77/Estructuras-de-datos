// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"


template <class T>
// función que resuelve el problema
T resolver(bintree <T> tree) {

	if (tree.left().empty() && tree.right().empty())
		return tree.root();
	else if (tree.left().empty())
		return std::min(resolver(tree.right()), tree.root());
	else if (tree.right().empty())
		return std::min(resolver(tree.left()), tree.root());
	else
		return std::min(std::min(tree.root(), resolver(tree.left())), resolver(tree.right()));

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	char tipo;
	std::cin >> tipo;
	if (!std::cin)
		return false;

	if (tipo == 'N')
	{
		bintree<int> tree = leerArbol(-1);
		int sol = resolver(tree);
		std::cout << sol << '\n';
	}
	else
	{
		bintree<std::string> tree = leerArbol((std::string)"#");
		std::string sol = resolver(tree);
		std::cout << sol << '\n';
	}

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