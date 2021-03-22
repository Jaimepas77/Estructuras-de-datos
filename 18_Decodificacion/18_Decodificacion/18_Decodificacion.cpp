// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <queue>
#include <string>//Para poder leer la línea completa

//Explicación: el primer descifrado se realiza utilizando una cola y una pila para recuperar el orden anterior.
// El segundo descifrado se hace utilizando una pila auxiliar en la que se dan la vuelta a las consonantes.

bool vocal(const char &n)//Comprobar si un carácter es o no una vocal
{
	if (n == 'a' || n == 'A' || n == 'e' || n == 'E' || n == 'i' || n == 'I' || n == 'o' || n == 'O' || n == 'u' || n == 'U')
		return true;
	else
		return false;
}

std::string getCola(std::stack<char> &q)//Vacía la pila en el string
{
	std::string ret = "";
	while (!q.empty())
	{
		ret += q.top();
		q.pop();
	}
	return ret;
}

// función que resuelve el problema
std::string resolver(std::string word) {
	std::queue <char> first;
	std::stack <char> second, aux;
	//X''
	for (int i = 0; i < word.length(); i++)
	{
		if (i % 2 == 0)//Elementos en posición par a la cola
			first.push(word[i]);
		else//En impar a la pila
			second.push(word[i]);

	}
	//X'
	std::string sol = "";
	while (!first.empty())//Cola
	{
		if (!vocal(first.front()))//Invertir consonantes poniendolas en la pila auxiliar
			aux.push(first.front());
		else//Vocal
		{
			sol += getCola(aux);//Asegurarse de que no hay consonantes que invertir
			sol += first.front();
		}
		first.pop();
	}
	while (!second.empty())//Pila
	{
		if (!vocal(second.top()))//Invertir consonantes poniendolas en la pila auxiliar
			aux.push(second.top());
		else//Vocal
		{
			sol += getCola(aux);
			sol += second.top();
		}
		second.pop();
	}
	sol += getCola(aux);//Asegurar que se han puesto todas las constonantes
	//X
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	std::string word;
	std::getline(std::cin, word);
	if (!std::cin)
		return false;

	std::string sol = resolver(word);

	// escribir sol
	std::cout << sol << '\n';

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