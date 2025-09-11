#include "ContenedorUsuario.h"
#include <stdexcept>
#include <string>
using namespace std;
class Usuario;

//constructor vacio
ContenedorUsuario::ContenedorUsuario() {
    this->cantidadMaxima = 0;
    this->cantidadActual = 0;
    this->listaUsuarios = nullptr;
}

//constructor con la cantidad maxima
ContenedorUsuario::ContenedorUsuario(const int cantidadMaxima) {

    if (cantidadMaxima < 0) {
        throw invalid_argument("Cantidad maxima no puede ser negativo");
    }
    this->cantidadMaxima = cantidadMaxima;
    this->cantidadActual = 0;
    this->listaUsuarios = new Usuario*[cantidadMaxima];

}
int ContenedorUsuario::getCantidadActual(){
    return this->cantidadActual;
}

void ContenedorUsuario::agregar_usuario(Usuario* nuevo) {

    if (cantidadActual >= cantidadMaxima) {
        throw invalid_argument("Error al agregar usuario, contenedor lleno");
    }
    this->listaUsuarios[cantidadActual] = nuevo;
    this->cantidadActual++;

}
int ContenedorUsuario::buscar_usuario(string nombre)  {

    for (int i = 0; i < this->cantidadActual; i++) {
        if (listaUsuarios[i]->getNombre() == nombre) {
            return i;
        }
    }
    return -1;
}

Usuario* ContenedorUsuario::obtener_usuario(int posicion){

    if (posicion < 0 || posicion >= this->cantidadActual) {
        throw invalid_argument("Posicion no valida");
    }
    return this->listaUsuarios[posicion];
}
ContenedorUsuario::~ContenedorUsuario() {

    for (int i = 0; i < this->cantidadActual; ++i) {
        delete listaUsuarios[i];
    }
    delete listaUsuarios;
}
