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
    void agregar_cancion(Cancion* cancion);
    int buscar_cancion(string cancion);
    bool eliminar_cancion(Cancion* cancion);
    Cancion* obtener_cancion(string nombre);
    Cancion* obtener_Posicion_Cancion(int posicion);

    //destructor
    ~ContenedorNexoSimple();
};
#endif //CONTENEDORNEXOSIMPLE_H
