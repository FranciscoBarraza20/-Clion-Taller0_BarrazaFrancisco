#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "coleccion/ContenedorNexoSimple.h"
using namespace std;

class Playlist {

private:
    string nombre_playlist;//contiene nombre de la playlist
    ContenedorNexoSimple* contenedorNexoSimple;//contiene el contenedor que gestiona las canciones

public:
    Playlist();
    Playlist(const string &nombre);

    //metodo get de clase playlist
    string getnombre_playlist() const;
    ContenedorNexoSimple* getlistaCanciones() const;

    //metodo set de clase playlist
    void setnombre_playlist(const string &nombre);

    //destructor de clase
    ~Playlist();

};



#endif //PLAYLIST_H