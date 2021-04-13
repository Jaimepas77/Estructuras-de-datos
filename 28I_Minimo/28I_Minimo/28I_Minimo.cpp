// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"


/*template <class T>
class bintree_ext : public bintree <T> {
	using Link = typename bintree <T>::Link;
public:
	bintree_ext() : bintree <T>() {}
	bintree_ext(bintree_ext <T> const& l, T const& e, bintree_ext <T > const& r) :
		bintree <T>(l, e, r) {}
	int min()
	{
		return equilibrado(this -> raiz).eq;
	}// función que resuelve el problema
private:
	struct tSol {
		bool eq;
		int altura;
	};
	tSol minimo(Link r) {
		if (r == nullptr) { return { true, 0 }; }
		else {
			tSol Izda = equilibrado(r->left);
			tSol Drch = equilibrado(r->right);
			return { Izda.eq && Drch.eq &&
			std::abs(Izda.altura - Drch.altura) <= 1 ,
			std::max(Izda.altura , Drch.altura) + 1 };
		}
	}
};

template <typename T >
inline bintree_ext <T> leerArbol_ext(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un arbol vacio
		return {};
	}
	else { // leer recursivamente los hijos
		bintree_ext <T > iz = leerArbol_ext(vacio);
		bintree_ext <T > dr = leerArbol_ext(vacio);
		return { iz, raiz, dr };
	}
}*/

template <class T>
T resolver(bintree <T> tree) {
	return tree.root();
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