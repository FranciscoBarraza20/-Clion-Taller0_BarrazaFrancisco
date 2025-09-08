#include "ContenedorPlaylist.h"
#include <stdexcept>
#include <string>
using namespace std;

//constructor vacio
ContenedorPlaylist::ContenedorPlaylist() {
    this->cantidadMaxima = 0;
    this->cantidadActual = 0;
    this->listaPlaylist = nullptr;
}

//constructor con la cantidad maxima
ContenedorPlaylist::ContenedorPlaylist(const int cantidadMaxima) {

    if (cantidadMaxima < 0) {
        throw invalid_argument("Cantidad maxima no puede ser negativo");
    }
    this->cantidadMaxima = cantidadMaxima;
    this->cantidadActual = 0;
    this->listaPlaylist = new Playlist*[cantidadMaxima];

}
int ContenedorPlaylist::getCantidadActual() const{
    return this->cantidadActual;
}

void ContenedorPlaylist::agregar(Playlist* nuevo) {

    if (cantidadActual >= cantidadMaxima) {
        throw invalid_argument("Error al agregar playlist, contenedor lleno");
    }
    this->listaPlaylist[cantidadActual] = nuevo;
    this->cantidadActual++;

}
int ContenedorPlaylist::buscar(const string &nombre) const {

    for (int i = 0; i < this->cantidadActual; i++) {
        if (listaPlaylist[i]->getnombre_playlist() == nombre) {
            return i;
        }
    }
    return -1;
}

Playlist* ContenedorPlaylist::obtener(int posicion) const{

    if (posicion < 0 || posicion >= this->cantidadActual) {
        throw invalid_argument("Posicion no valida");
    }
    return this->listaPlaylist[posicion];
}

void ContenedorPlaylist::eliminar(string nombre) {

    int posicion = buscar(nombre);

    if (posicion == -1) {
        throw invalid_argument("Playlist no existe");
    }

    for (int i = posicion; i < this->getCantidadActual()-1; ++i) {
        listaPlaylist[i] = listaPlaylist[i+1];
    }
    this->cantidadActual--;

}
ContenedorPlaylist::~ContenedorPlaylist() {

    for (int i = 0; i < this->cantidadActual; ++i) {
        delete listaPlaylist[i];
    }
    delete[] listaPlaylist;
}