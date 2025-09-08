#ifndef CONTENEDORNEXOSIMPLE_H
#define CONTENEDORNEXOSIMPLE_H
#include "Nodo.h"

class ContenedorNexoSimple {

private:
    Nodo* cabecera;
    int tamanio;

public:
    ContenedorNexoSimple();
    //metodo get de nodo
    Nodo* getCabecera();
    int getTamanio();
    //metodo set de nodo
    void setCabecera(Nodo* cabecera);

    //metodos de nodo
    void agregar(Cancion* cancion);
    int buscar(string cancion);
    bool eliminar(Cancion* cancion);
    Cancion* obtenerCancion(string nombre);
    Cancion* obtenerPosicionCancion(int posicion);

    //destructor
    ~ContenedorNexoSimple();
};
#endif //CONTENEDORNEXOSIMPLE_H
