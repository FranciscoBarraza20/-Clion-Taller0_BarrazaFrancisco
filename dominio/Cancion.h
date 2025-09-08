#ifndef CANCION_H
#define CANCION_H
#include <string>
using namespace std;

class Cancion {
private:
    string nombreMusica;
    string album;
    string artista;
    string duracion;

public:
    Cancion();
    Cancion(string nombreMusica,string album,string artista,string duracion);
    //metodos get de clase
    string getNombreMusica();
    string getAlbum();
    string getArtista();
    string getDuracion();
    //metodos set de clase
    void setNombreMusica(string nombreMusica);
    void setAlbum(string album);
    void setArtista(string artista);
    void setDuracion(string duracion);

    ~Cancion();

};



#endif //CANCION_H