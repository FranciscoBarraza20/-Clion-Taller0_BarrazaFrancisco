#include "ContenedorNexoSimple.h"
#include <stdexcept>

//constructor vacio
ContenedorNexoSimple::ContenedorNexoSimple() {
    this->cabecera = nullptr;
    this->tamanio = 0;
}
Nodo *ContenedorNexoSimple::getCabecera() {
    return this->cabecera;
}
int ContenedorNexoSimple::getTamanio() {
    return this->tamanio;
}
void ContenedorNexoSimple::setCabecera(Nodo* cabecera) {
    this->cabecera = cabecera;
}
//METODO DE AGREGAR
void ContenedorNexoSimple::agregar_cancion(Cancion *cancion) {

    Nodo* nuevoNodo;//se declara el nuevo nodo

    try {//se valida la entrada del nodo
        nuevoNodo = new Nodo(cancion);
    }catch (invalid_argument &e) {
        throw e;
    }
    if (this->cabecera == nullptr) {//si la cabecera es nula
        this->cabecera = nuevoNodo;//la cabecera para a ser el nuevo nodo

    }else {//caso contrario
        nuevoNodo->setSiguiente(this->cabecera);//el siguiente nodo pasa ser la cabecera
        this->cabecera = nuevoNodo;//la cabecera sera el nuevo nodo
    }
    this->tamanio++;//aumenta el tamanio de la lista

}
//METODO BUSCAR
int ContenedorNexoSimple::buscar_cancion(string nombreCancion) {

    int posicion = 0;
    Nodo* actual = this->cabecera;//se crea el primer nodo de la lista

    while (actual != nullptr) {//recorre la lista minstras hayan nodos
        if (actual->getCancion()->getNombreMusica() == nombreCancion) {//se verifica si el nodo contiene el nombre de la cancion
            return posicion;//retorna la posicion en caso de haber encontrado el nodo
        }
        actual = actual->getSiguiente();//si no se cumple, pasa al siguiente nodo hasta encontrarlo
        posicion++;
    }
    return -1;//retorna -1 si el nodo no fue encontrado
}
bool ContenedorNexoSimple::eliminar_cancion(Cancion *cancion) {

    if (this->cabecera == nullptr) {
        return false;
    }
    Nodo* auxiliar = this->cabecera;
    Nodo* anterior = nullptr;

    if (auxiliar->getCancion() == cancion) {
        this->cabecera = auxiliar->getSiguiente();
        delete auxiliar;
        this->tamanio--;
        return true;
    }
    while (auxiliar != nullptr && auxiliar->getCancion() != cancion) {
        anterior = auxiliar;
        auxiliar = auxiliar->getSiguiente();
    }
    if (auxiliar == nullptr) {
        return false;
    }
    anterior->setSiguiente(auxiliar->getSiguiente());
    delete auxiliar;
    this->tamanio--;
    return true;

}
Cancion *ContenedorNexoSimple::obtener_cancion(string nombreMusica) {

    Nodo* aux = this->cabecera;//creamos el primer nodo

    while (aux != nullptr) {//recorre la lista minstras hayan nodos
        if (aux->getCancion()->getNombreMusica() == nombreMusica) {//si nodo contiene el nombre de la cancion que se busca
            return aux->getCancion();//retorna el nodo exacto que contiene la cancion
        }
        aux = aux->getSiguiente();//pasa al siguiente nodo hasta encontrarlo
    }
    return nullptr;//retorna nullptr en caso de que nose encuentre el nodo
}
ContenedorNexoSimple::~ContenedorNexoSimple() {

    Nodo* actual = this->cabecera;//se declara un auxiliar que apunta al primer nodo de la lista

    while (actual != nullptr) {//recorre la lista mientras hayan nodos
        Nodo* siguiente = actual->getSiguiente();//se guarda la referencia del nodo actual en nodo siguiente
        delete actual;
        actual = siguiente;//el nodo actual sera el siguiente nodo de la lista
    }
    actual = nullptr;
}
Cancion *ContenedorNexoSimple::obtener_Posicion_Cancion(int posicion) {

    int posicionCancion = 0;
    Nodo* aux = this->cabecera;//se crea el primer nodo de la lista

    while (aux != nullptr) {//recorre la lista mientras hayan nodos
        if (posicion == posicionCancion) {//si la posicion es iguala la posicion de la cancion
            return aux->getCancion();//retorna el nodo que contiene la cancion
        }
        aux = aux->getSiguiente();//el nodo pasa al siguiente de la lista
        posicionCancion++;//incrementa la posicion
    }
    return nullptr;//retorna nullptr sino se encuentra el nodo

}
