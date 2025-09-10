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

    int getCantidadActual();
    //metodos de contenedor
    void agregar_playlist(Playlist* nuevo);
    int buscar_playlist(string nombre);

    void eliminar_playlist(string nombre);
    Playlist* obtener_playlist(int posicion);
    ~ContenedorPlaylist();

};

#endif //CONTENEDORPLAYLIST_H
