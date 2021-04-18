// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"

template <class T>
class bintree_ext : public bintree <T> {
	using Link = typename bintree <T>::Link;
public:
	bintree_ext() : bintree <T>() {}
	bintree_ext(bintree_ext <T> const& l, T const& e, bintree_ext <T > const& r) : bintree <T>(l, e, r) {}
	T minimoNodos()
	{
		return minimoNodos(this->raiz);
	}
private:
	T minimoNodos(Link tree) {
		if (tree->left == nullptr && tree->right == nullptr)
			return tree->elem;
		else if (tree->left == nullptr)
			return std::min(minimoNodos(tree->right), tree->elem);
		else if (tree->right == nullptr)
			return std::min(minimoNodos(tree->left), tree->elem);
		else
			return std::min(std::min(tree->elem, minimoNodos(tree->left)), minimoNodos(tree->right));
	}
};
template <typename T>
inline bintree_ext <T> leerArbol_ext(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un arbol vacio
		return {};
	}
	else { // leer recursivamente los hijos
		bintree_ext <T> iz = leerArbol_ext(vacio);
		bintree_ext <T> dr = leerArbol_ext(vacio);
		return { iz , raiz , dr };
	}
}


template <class T>
T resolver(bintree_ext <T> tree) {//Elemento mínimo
	return tree.minimoNodos();
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
		bintree_ext<int> tree = leerArbol_ext(-1);
		int sol = resolver(tree);
		std::cout << sol << '\n';
	}
	else
	{
		bintree_ext<std::string> tree = leerArbol_ext((std::string)"#");
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