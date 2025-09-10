//
// Created by franc on 07-09-2025.
//

#include "Nodo.h"
Nodo::Nodo() {
    //constructor vacio
    this->cancion = nullptr;
    this->siguiente = nullptr;
}
Nodo::Nodo(Cancion *cancion) {
    this->cancion = cancion;
    this->siguiente = nullptr;
}
Cancion *Nodo::getCancion() {
    return this->cancion;
}
Nodo *Nodo::getSiguiente() {
    return this->siguiente;
}
void Nodo::setSiguiente(Nodo *siguiente) {
    this->siguiente = siguiente;
}
Nodo::~Nodo() {
    
}
