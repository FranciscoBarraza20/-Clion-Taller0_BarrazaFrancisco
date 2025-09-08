#ifndef NODO_H
#define NODO_H
#include "../Cancion.h"

class Nodo {
private:
    Nodo* siguiente;
    Cancion* cancion;

public:
    Nodo();
    Nodo(Cancion* cancion);

    Cancion* getCancion();
    Nodo* getSiguiente();
    void setSiguiente(Nodo* siguiente);
    ~Nodo();

};
#endif //NODO_H
