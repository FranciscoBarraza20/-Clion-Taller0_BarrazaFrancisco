//
// Created by franc on 07-09-2025.
//

#ifndef SISTEMAAPLICACION_H
#define SISTEMAAPLICACION_H

#include <string>
#include "../dominio/Cancion.h"
#include "../dominio/ContenedorUsuario.h"
#include "../dominio/Playlist.h"
#include "../dominio/Usuario.h"
#include "../dominio/coleccion/ContenedorNexoSimple.h"

class SistemaAplicacion {

private:
    Usuario* usuarioActual;
    Cancion* cancion_actual;
    ContenedorUsuario* contenedorUsuario;
    ContenedorNexoSimple* contenedorCanciones;

public:
    SistemaAplicacion();

    //metodos para lectura de datos
    void lecturaArchivo_usuario();//metodo para leer archivo "users.txt"
    void lecturaArchivo_canciones();//metodo para leer archivo "canciones.txt"

    //metodos para persistencia de datos
    void escribirArchivo_usuarios();//metodo para escribir los resultados del archivo "users.txt"
    void escribirArchivo_canciones();//metodo para escribir los resultados del archivo "canciones.txt"

    //metodos del sistema que gestiona los usuarios
    bool iniciarSesion(string nombre,string contrasenia);
    void registrarse(string nombre,string correo,string contrasenia);

    //metodos del sistema que gestiona las playlist y las canciones
    void crearPlaylist(string nombre);
    void agregarCancion(string nombre, string nombreCancion);
    void eliminarCancion(string nombre,string nombreCancion,int indice);
    void renombrarPlaylist(string nombreActual, string nombreNuevo);
    void eliminarPlaylist(string nombre);
    void verPlaylist(string nombre);

    //metodo auxiliar que me ayudara a buscar las playlist en base su nombre
    Playlist* buscarPlaylist(string nombre);



};



#endif //SISTEMAAPLICACION_H