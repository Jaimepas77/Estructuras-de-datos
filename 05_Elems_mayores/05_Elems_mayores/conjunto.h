//
//  conjunto.h
//
// Nombre del alumno: Jaime Pastrana García
// Usuario del Juez: A56


//bool binary_search(v.begin(), v.end(), elem, greater<tipo>()) devuelve si el elemnto se encuentra en un vector ordenado descendentemente
//bool binary_search(v, v+contador, elem, greater<tio>())

#ifndef conjunto_h
#define conjunto_h

#include <cstddef>    // size_t
#include <stdexcept>  // std::domain_error
#include <utility>    // std::move
#include <vector>
#include <algorithm>

template <class T>
class set {
public:
    set(size_t tam = TAM_INICIAL); // constructor
    set(set<T> const& other); // constructor por copia
    set<T>& operator=(set<T> const& other); // operador de asignación
    ~set(); // destructor
    void insert(T e);
    bool contains(T e) const;
    void erase(T e);
    bool empty() const;
    size_t size() const;

    //Añadidas (si no hay min se lanza excepción)
    T min() const
    {
        if (contador == 0)
            throw std::domain_error("Sin elementos");
        else
            return datos[contador - 1];
    }

    void erase_min()
    {
       if (contador == 0)
            throw std::domain_error("Sin elementos");
        else
            contador--;
    }

    T getElem(int pos)const
    {
        return datos[pos];
    }

private:
    const static size_t TAM_INICIAL = 8;
    size_t contador;
    size_t capacidad;
    T* datos;
    void amplia();
    void libera();
    void copia(set<T> const& other);

};

template <class T>
set<T>::set(size_t tam) : contador(0), capacidad(tam), datos(new T[capacidad]) {}

template <class T>
set<T>::~set() {
    libera();
}

template <class T>
void set<T>::libera() {
    delete[] datos;
}

/** Constructor por copia */
template <class T>
set<T>::set(set<T> const& other) {
    copia(other);
}

/** Operador de asignación */
template <class T>
set<T>& set<T>::operator=(set<T> const& other) {
    if (this != &other) {
        libera();
        copia(other);
    }
    return *this;
}

template <class T>
void set<T>::copia(set<T> const& other) {
    capacidad = other.capacidad;
    contador = other.contador;
    datos = new T[capacidad];
    for (size_t i = 0; i < contador; ++i)
        datos[i] = other.datos[i];
}

template <class T>
void set<T>::insert(T e) {
    if (!contains(e) && (contador < capacidad || e > min())) {
        if (contador == capacidad)
            erase_min();
        auto lugar = std::lower_bound(datos, datos + contador, e, std::greater<T>());
        int i = contador-1;
        while(i >= lugar - datos)
        {
            datos[i+1] = datos[i];
            i--;
        }
        *lugar = e;
        ++contador;
    }
}

template <class T>
bool set<T>::contains(T e) const {
    bool encontrado = std::binary_search(datos, datos + contador, e, std::greater<T>());
    
    return encontrado;
}

template <class T>
void set<T>::amplia() {
    T* nuevos = new T[2 * capacidad];
    for (size_t i = 0; i < capacidad; ++i)
        nuevos[i] = std::move(datos[i]);
    delete[] datos;
    datos = nuevos;
    capacidad *= 2;
}

template <class T>
void set<T>::erase(T e) {//No se toca pq no se necesita, pero se necesitaría modificar para usarse
    size_t i = 0;
    while (i < contador && datos[i] != e)
        ++i;
    if (i < contador) {
        datos[i] = datos[contador - 1];
        --contador;
    }
    else
        throw std::domain_error("El elemento no esta");
}

template <class T>
bool set<T>::empty() const {
    return contador == 0;
}

template <class T>
size_t set<T>::size() const {
    return contador;
}

template <typename T>
inline std::ostream& operator <<(std::ostream& out, const set<T>& conj)
{
    for(int i = conj.size()-1; i >= 0; --i)
        out << conj.getElem(i) << " ";

    return out;
}

#endif // conjunto_h