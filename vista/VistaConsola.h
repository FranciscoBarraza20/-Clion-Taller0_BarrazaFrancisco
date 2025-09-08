//
// Created by franc on 07-09-2025.
//

#ifndef VISTACONSOLA_H
#define VISTACONSOLA_H
#include "../servicios/SistemaAplicacion.h"

class VistaConsola {
private:
    SistemaAplicacion* sistema;

    void iniciarSesion() ;
    void registrar() ;

    //metodos de playlist
    void menu_playlist();
    void crear_Playlist();
    void gestionar_Playlist();

    //metodos para la gestion de la playlist
    void agregar_Cancion();
    void eliminar_Cancion();
    void renombrar_Playlist();
    void eliminar_Playlist();
    void ver_Playlist();

public:
    VistaConsola(SistemaAplicacion* sistema);
    void iniciar();
    void menu();


};



#endif //VISTACONSOLA_H