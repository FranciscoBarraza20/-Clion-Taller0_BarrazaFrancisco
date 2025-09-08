
#include "Usuario.h"

//constructor vacio
Usuario::Usuario() {
    this->id = 0;
    this->nombre = "";
    this->correo = "";
    this->contrasenia = "";
    contenedorPlaylist = new ContenedorPlaylist(999);
}
//constructor con parametros de entrada
Usuario::Usuario(int id,string nombre, string correo,  string contrasenia) {
    this->id = id;
    this->nombre = nombre;
    this->correo = correo;
    this->contrasenia = contrasenia;
    contenedorPlaylist = new ContenedorPlaylist(999);
}
//metodos get de clase
int Usuario::getId() const {
    return this->id;
}
string Usuario::getNombre() const{
    return this->nombre;
}
string Usuario::getCorreo() const{
    return this->correo;
}
string Usuario::getContrasenia() const{
    return this->contrasenia;
}
ContenedorPlaylist *Usuario::getContenedorPLaylist_usuario() {
    return contenedorPlaylist;
}

//metodos set de clase
void Usuario::setNombre(string nombre) {
    this->nombre = nombre;
}
void Usuario::setCorreo(string correo) {
    this->correo = correo;
}
void Usuario::setContrasenia(string contrasenia) {
    this->contrasenia = contrasenia;
}

//destructor de clase
Usuario::~Usuario() {
    delete contenedorPlaylist;

}