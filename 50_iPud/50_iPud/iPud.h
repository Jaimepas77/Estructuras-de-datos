//Jaime Pastrana Garc�a
//A56

#ifndef IPUD
#define IPUD

#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <list>
#include <vector>

class iPad {
private:
	using cancion = std::string;//Nombre de la canci�n 

	struct tSongInfo {
		int duracion = 0;
		std::list<cancion>::iterator cola;
		bool isCola = false;//Si est� en cola
		std::list<cancion>::iterator past;//Iterador a la lista de reproducidas en el pasado
		bool isPast = false;//Si est� en la lista de reproducidos en el pasado
	};

	std::unordered_map<cancion, tSongInfo> canciones;
	std::list<cancion> colaRepr;//Cola de reproducci�n
	int duracion = 0; //Duraci�n de las canciones en cola
	std::list<cancion> reproducidas;//Canciones reproducidas en el pasado

public:
	void addSong(cancion s, std::string a, int d) {
		tSongInfo info;
		info.duracion = d;
		if (!canciones.insert({ s, info }).second)
			throw std::invalid_argument("addSong");
	}

	void addToPlaylist(cancion s) {
		//No puede repetirse
		auto it = canciones.find(s);
		if (it == canciones.end())
			throw std::invalid_argument("addToPlaylist");
		else
		{
			if (!it->second.isCola)
			{
				it->second.isCola = true;
				colaRepr.push_back(s);//Ponerla
				it->second.cola = --colaRepr.end();//Marcarla
				duracion += it->second.duracion;
			}
		}
	}

	cancion current() const {
		if (colaRepr.size() > 0)
			return colaRepr.front();
		else
			throw std::domain_error("current");
	}

	cancion play() {
		if (!colaRepr.empty())//Si es vac�a no hace nada
		{
			reproducidas.push_front(colaRepr.front());//Se a�ade a la lista de reproducidas

			canciones[reproducidas.front()].isCola = false;//Se retira como canci�n en cola
			colaRepr.pop_front();

			if (canciones[reproducidas.front()].isPast) {//Si estaba en la lista se elimina su anterior referencia
				reproducidas.erase(canciones[reproducidas.front()].past);
			}

			canciones[reproducidas.front()].isPast = true;//Se marca como canci�n reproducida
			canciones[reproducidas.front()].past = reproducidas.begin();

			duracion -= canciones[reproducidas.front()].duracion;
			return reproducidas.front();
		}
		return "";
	}

	int totalTime() const {
		return duracion;
	}

	std::vector<cancion> recent(int n) const {
		std::vector <cancion> ret;
		for (cancion elem : reproducidas)
			if (n-- > 0)
				ret.push_back(elem);
			else
				break;
		return ret;
	}

	void deleteSong(cancion s) {
		auto it = canciones.find(s);
		if (it != canciones.end())
		{
			if (it->second.isCola)
			{
				colaRepr.erase(it->second.cola);
				duracion -= it->second.duracion;
			}
			if (it->second.isPast)
			{
				reproducidas.erase(it->second.past);
			}

			canciones.erase(it);
		}
	}
};

#endif IPUD
