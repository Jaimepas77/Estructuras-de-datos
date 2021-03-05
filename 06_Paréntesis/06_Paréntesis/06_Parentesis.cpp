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
	char tmp;
	std::cin.get(tmp);

	if (!std::cin)
		return false;
	
	std::stack<char> pila;
	bool funciona = true;

	while (funciona && tmp != '\n')
	{
		//Evaluar
		if (tmp == '(' || tmp == '[' || tmp == '{')
			pila.push(tmp);
		else if (pila.size() > 0 && ( (tmp == ')' && pila.top() == '(') || (tmp == '}' && pila.top() == '{') || (tmp == ']' && pila.top() == '[') ) )
			pila.pop();
		else if (tmp == ')' || tmp == ']' || tmp == '}')
			funciona = false;

		std::cin.get(tmp);
	}

	while (tmp != '\n')
		std::cin.get(tmp);
	
	// escribir sol
	if (funciona && pila.size() == 0)
		std::cout << "SI\n";
	else
		std::cout << "NO\n";

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