#include "Cancion.h"
#include <string>
#include "Cancion.h"
using namespace std;

//constructor vacio
Cancion::Cancion() {
    this->nombreMusica = "";
    this->album = "";
    this->artista = "";
    this->duracion = "";
}
//constructor con parametros de entrada
Cancion::Cancion(string nombreMusica, string album, string artista, string duracion) {
    this->nombreMusica = nombreMusica;
    this->album = album;
    this->artista = artista;
    this->duracion = duracion;
}
//metodos get de clase
string Cancion::getNombreMusica() {
    return this->nombreMusica;
}
string Cancion::getAlbum() {
    return this->album;
}
string Cancion::getArtista() {
    return this->artista;
}
string Cancion::getDuracion() {
    return this->duracion;
}
//metodos set de clase
void Cancion::setNombreMusica(string nombreMusica) {
    this->nombreMusica = nombreMusica;
}
void Cancion::setAlbum(string album) {
    this->album = album;
}
void Cancion::setArtista(string artista) {
    this->artista = artista;
}
void Cancion::setDuracion(string duracion) {
    this->duracion = duracion;
}
//destructor de clase
Cancion::~Cancion() {

}