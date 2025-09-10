#include "Playlist.h"
#include <iostream>

//constructoa vacio
Playlist::Playlist() {
    this->nombre_playlist = "";
    this->contenedorNexoSimple = new ContenedorNexoSimple();
}
//constructoa con parametro de entrada como el nombre
Playlist::Playlist(string &nombre) {
    this->nombre_playlist = nombre;//obtiene el nombre
    this->contenedorNexoSimple = new ContenedorNexoSimple();//inicializa el contenedor
}

string Playlist::getnombre_playlist(){
    return this->nombre_playlist;
}
ContenedorNexoSimple *Playlist::getlistaCanciones(){
    return contenedorNexoSimple;
}
void Playlist::setnombre_playlist(string &nombre) {
    this->nombre_playlist = nombre;
}
Playlist::~Playlist() {
    delete contenedorNexoSimple;//libera memoria del contenedor de canciones
}
