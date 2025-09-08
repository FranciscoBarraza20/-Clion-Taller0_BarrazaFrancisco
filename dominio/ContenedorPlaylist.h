//
// Created by franc on 07-09-2025.
//

#ifndef CONTENEDORPLAYLIST_H
#define CONTENEDORPLAYLIST_H
#include "Playlist.h"
#include <string>

class ContenedorPlaylist {
private:
    int cantidadMaxima;
    int cantidadActual;
    Playlist **listaPlaylist;
public:
    ContenedorPlaylist();
    ContenedorPlaylist(int cantidadMaxima);

    int getCantidadActual() const;
    //metodos de contenedor
    void agregar(Playlist* nuevo);
    int buscar(const string &nombre) const;
    void eliminar(string nombre);
    Playlist* obtener(int posicion) const;
    ~ContenedorPlaylist();

};



#endif //CONTENEDORPLAYLIST_H
