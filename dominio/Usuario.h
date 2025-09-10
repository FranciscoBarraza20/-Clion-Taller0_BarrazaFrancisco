//
// Created by franc on 07-09-2025.
//

#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <vector>

#include "ContenedorPlaylist.h"
#include "Playlist.h"
using namespace std;

class Usuario {

private:
    int id;
    string nombre;
    string correo;
    string contrasenia;
    ContenedorPlaylist* contenedorPlaylist;

public:
    Usuario();
    Usuario(int id,string nombre,string correo,string contrasenia);

    //metodos get de clase
    int getId();
    string getNombre();
    string getCorreo();
    string getContrasenia();
    ContenedorPlaylist *getContenedorPLaylist_usuario();

    //metodos set de clase
    void setId(int id);
    void setNombre(string nombre);
    void setCorreo(string correo);
    void setContrasenia(string contrasenia);

    //destructor
    ~Usuario();

};



#endif //USUARIO_H
