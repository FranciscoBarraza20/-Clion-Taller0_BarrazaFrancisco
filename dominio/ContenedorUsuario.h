//
// Created by franc on 07-09-2025.
//

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
    void agregar(Usuario* nuevo);
    int buscar(const string nombre);
    Usuario* obtener(int posicion);
    ~ContenedorUsuario();

};



#endif //CONTENEDORUSUARIO_H
