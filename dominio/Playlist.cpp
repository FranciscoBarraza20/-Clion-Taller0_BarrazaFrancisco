#include "Playlist.h"
#include <iostream>

//constructoa vacio
Playlist::Playlist() {
    this->nombre_playlist = "";
    this->contenedorNexoSimple = new ContenedorNexoSimple();
}
//constructoa con parametro de entrada como el nombre
Playlist::Playlist(const string &nombre) {
    this->nombre_playlist = nombre;//obtiene el nombre
    this->contenedorNexoSimple = new ContenedorNexoSimple();//inicializa el contenedor
}

string Playlist::getnombre_playlist() const{
    return this->nombre_playlist;
}
ContenedorNexoSimple *Playlist::getlistaCanciones() const{
    return contenedorNexoSimple;
}
void Playlist::setnombre_playlist(const string &nombre) {
    this->nombre_playlist = nombre;
}
Playlist::~Playlist() {
    delete contenedorNexoSimple;//libera memoria del contenedor de canciones
}