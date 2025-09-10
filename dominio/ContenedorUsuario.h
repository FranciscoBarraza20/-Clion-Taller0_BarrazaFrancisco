#ifndef CONTENEDORUSUARIO_H
#define CONTENEDORUSUARIO_H
#include "Usuario.h"
#include <string>
using namespace std;

class ContenedorUsuario {

private:
    int cantidadMaxima;
    int cantidadActual;
    Usuario **listaUsuarios;
public:
    ContenedorUsuario();
    ContenedorUsuario(int cantidadMaxima);

    int getCantidadActual();
    //metodos de contenedor
    void agregar_usuario(Usuario* nuevo);
    int buscar_usuario(string nombre);
    Usuario* obtener_usuario(int posicion);
    ~ContenedorUsuario();

};

#endif //CONTENEDORUSUARIO_H
