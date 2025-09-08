#include "VistaConsola.h"
#include "../servicios/SistemaAplicacion.h"
#include <iostream>
using namespace std;

VistaConsola::VistaConsola(SistemaAplicacion *sistema) {
    this->sistema = sistema;
}
void VistaConsola::iniciar() {
    menu();//metodo que muestra al inicio de la ejecucion del programa
}
void VistaConsola::menu() {
    string opcion_letra;

    while (true) {

        cout<<"::: BIBLIOTECA MUSICAL DJ DORO ::: "<<endl;
        cout<<"1. Iniciar sesion "<<endl;
        cout<<"2. Registrarse "<<endl;
        cout<<"3. Finalizar "<<endl;
        cout<<"Ingrese una opcion: "<<endl;
        cin>>opcion_letra;

        try {
            int opcion = stoi(opcion_letra);

            if (opcion == 1) {
                iniciarSesion();
                continue;
            }
            if (opcion == 2) {
                registrar();
                continue;
            }
            if (opcion == 3) {
                cout<<"Cerrrando programa..."<<endl;
                //metodos para la persistencia de datos
                sistema->escribirArchivo_canciones();
                sistema->escribirArchivo_usuarios();
                break;
            }
            cout<<"opcion no valida"<<endl;

        }catch (invalid_argument &e) {
            cout<<"Ingrese un numero"<<endl;
        }
    }
}
void VistaConsola::iniciarSesion() {

    string nombre,contrasenia;

    cout<<"::: INICIAR SESION :::"<<endl;
    cout<<"Ingrese nombre: "<<endl;
    cin>>nombre;
    cout<<"Ingrese contrasenia: "<<endl;
    cin>>contrasenia;

    try {
        //si el inicio de sesion fue exitoso
        if (this->sistema->iniciarSesion(nombre,contrasenia)) {
            menu_playlist();//el usuario accede a un segundo menu
        }else {
            return;
        }
    }catch (invalid_argument &e) {
        cerr<<e.what()<<endl;
    }
}
void VistaConsola::registrar() {

    string nombre,correo,contrasenia;

    cout<<"::: REGISTRARSE ::: "<<endl;
    cout<<"Ingrese su nombre: "<<endl;
    cin>>nombre;
    cout<<"Ingrese correo: "<<endl;
    cin>>correo;
    cout<<"Ingrese su contrasenia: "<<endl;
    cin>>contrasenia;

    sistema->registrarse(nombre,correo,contrasenia);
}

void VistaConsola::menu_playlist() {

    string opcionLetra;
    int opcion;

    while (true) {
        cout<<"::: SISTEMA DE GESTION DE PLAYLIST ::: "<<endl;
        cout<<"1. Crear playlist"<<endl;
        cout<<"2. Gestionar playlist"<<endl;
        cout<<"3. Volver "<<endl;
        cout<<"Ingrese una opcion: "<<endl;
        cin>>opcionLetra;

        try {
            opcion = stoi(opcionLetra);

            if (opcion == 1) {
                crear_Playlist();
                continue;
            }
            if(opcion == 2) {
                gestionar_Playlist();
                continue;
            }
            if (opcion == 3) {
                cout<<"Saliendo...."<<endl;
                break;
            }
            cout<<"opcion no valida"<<endl;
        }catch (invalid_argument &e) {
            cout<<"Ingrese un numero"<<endl;
        }
    }
}
//metodos para creacon y gestion de playlist
void VistaConsola::crear_Playlist(){

    string nombre_playlist;

    cout<<"::: CREAR PLAYLIST ::: "<<endl;
    cout<<"Ingrese nombre de la playlist: "<<endl;
    cin.ignore();//limpia el buffer
    getline(cin,nombre_playlist);//para leer la linea completa incluso los espacios
    sistema->crearPlaylist(nombre_playlist);

}
void VistaConsola::gestionar_Playlist() {

    string opcionLetra;

    while (true) {
        cout<<"::: SISTEMA DE GESTION DE PLAYLIST ::: "<<endl;
        cout<<"[1] Agregar canciones a la playlist"<<endl;
        cout<<"[2] Eliminar canciones previamente agregadas"<<endl;
        cout<<"[3] Renombrar playlists existentes"<<endl;
        cout<<"[4] Eliminar playlists completas"<<endl;
        cout<<"[5] Visualizar playlists junto con las canciones que contienen"<<endl;
        cout<<"[6] Salir"<<endl;
        cout<<"Ingrese una opcion:"<<endl;
        cin>>opcionLetra;

        try {
            int opcion = stoi(opcionLetra);

            if (opcion == 1) {
                agregar_Cancion();
                continue;
            }
            if (opcion == 2) {
                eliminar_Cancion();
                continue;
            }
            if (opcion == 3) {
                renombrar_Playlist();
                continue;
            }
            if (opcion == 4) {
                eliminar_Playlist();
                continue;
            }
            if (opcion == 5) {
                ver_Playlist();
                continue;
            }
            if (opcion == 6) {
                cout<<"Saliendo..."<<endl;
                break;
            }
            cout<<"opcion no valida"<<endl;

        }catch (invalid_argument e) {
            cout<<"ingrese un numero"<<endl;
        }
    }
}
void VistaConsola::agregar_Cancion(){

    string nombre_playlist,nombre_cancion,album,artista,duracion;

    cout<<"::: AGREGAR CANCIONES :::"<<endl;
    cout<<"Ingrese nombre de la playlist a la que desea agregar canciones:"<<endl;
    cin.ignore();//limpia el buffer
    getline(cin,nombre_playlist);//para leer la linea completa incluso los espacios

    cout<<"Ingrese nombre de la cancion"<<endl;
    getline(cin,nombre_cancion);//para leer la linea completa incluso los espacios
    sistema->agregarCancion(nombre_playlist,nombre_cancion);

}
void VistaConsola::eliminar_Cancion() {

    string nombre_playlist,nombreCancion;
    int indice = 0;

    cout<<"::: ELIMINAR CANCION :::"<<endl;
    cout<<"Ingrese nombre de la playlist: "<<endl;
    cin>>nombre_playlist;

    //se llama al metodo encargado de buscar playlist por su nombre
    Playlist* playlist = sistema->buscarPlaylist(nombre_playlist);

    if (playlist == nullptr) {
        cout<<"La playlist no ha sido encontrada"<<endl;
        return;
    }
    if (playlist->getlistaCanciones()->getTamanio() == 0) {//si en la playlist no hay canciones
        cout<<"No hay mas canciones en la playlist "<<nombre_playlist<<endl;
        return;
    }
    //se recorre la lista de canciones
    for (int i = 0; i <playlist->getlistaCanciones()->getTamanio() ; ++i) {
        Cancion* cancion = playlist->getlistaCanciones()->obtenerPosicionCancion(i);//se accede a todas las posiciones de la cancion contenida en la lista
        cout<<"["<<i<<"] "<<cancion->getNombreMusica()<<endl;//imprime la posicion como el nombre de la cancion
    }
    cout<<"Ingrese el indice que tiene la cancion:"<<endl;
    cin>>indice;
    //se valida si el indice ingresado es mayor o menor a la cantidad de canciones que hay en la playlist
    if (indice < 0 || indice >= playlist->getlistaCanciones()->getTamanio()) {
        cout<<"Indice seleccionado no valido"<<endl;
        return;
    }
    Cancion* cancion = playlist->getlistaCanciones()->obtenerPosicionCancion(indice);
    nombreCancion = cancion->getNombreMusica();

    sistema->eliminarCancion(nombre_playlist,nombreCancion,indice);
}
void VistaConsola::eliminar_Playlist() {

    string nombrePlaylist;

    cout<<"::: ELIMINAR PLAYLIST :::"<<endl;
    cout<<"Ingrese el nombre de la playlist que desea eliminar:"<<endl;
    cin>>nombrePlaylist;

    //se llama al metodo encargado de buscar playlist por su nombre
    Playlist* playlist = sistema->buscarPlaylist(nombrePlaylist);

    if (playlist == nullptr) {
        cout<<"Playlist no ha sido encontrada"<<endl;
        return;
    }

    //si el nombre de la playlist es igual al nombre de la playlist que creo el usuario
    //se procede a confirmar si se desea eliminar la playlist
    int opcion;
    cout<<"Esta seguro de eliminar la playlist "<<nombrePlaylist<<" ?"<<endl;
    cout<<"[1] Si"<<endl;
    cout<<"[2] No"<<endl;
    cin>>opcion;

    if (opcion == 1) {//si usuario ingresa la primera opcion se elimina la playlist
        sistema->eliminarPlaylist(nombrePlaylist);
    }else {//caso contrario se indica que la operacion se cancela
        cout<<"Ha cancelado eliminar la playlist"<<endl;
        return;
    }
}
void VistaConsola::renombrar_Playlist() {

    string nombrePlaylist,nuevoNombre;
    string opcionLetra;
    int opcion;

    cout<<"::: RENOMBRAR PLAYLIST :::"<<endl;
    cout<<"Ingrese nombre de la playlist: "<<endl;
    cin>>nombrePlaylist;

    Playlist* playlistUsuario = sistema->buscarPlaylist(nombrePlaylist);

    if (playlistUsuario == nullptr) {
        cout<<"Playlist no encontrada"<<endl;
        return;
    }
    cout<<"Esta seguro de renombrar la playlist?"<<nombrePlaylist<<endl;
    cout<<"[1] Si"<<endl;
    cout<<"[2] No"<<endl;
    cout<<"Ingrese una opcion: "<<endl;
    cin>>opcionLetra;
    try {
        opcion = stoi(opcionLetra);

        if (opcion == 1) {
            cout<<"Ingrese nuevo nombre para playlist"<<endl;
            cin>>nuevoNombre;
            sistema->renombrarPlaylist(nombrePlaylist,nuevoNombre);
        }else {
            cout<<"Ha cancelado renombrar la playlist"<<endl;
        }
    }catch (invalid_argument &e) {
        cout<<"Ingrese un numero"<<endl;
    }
}
void VistaConsola::ver_Playlist() {

    string nombrePlaylist;

    cout<<"::: VER PLAYLIST :::"<<endl;
    cout<<"Ingrese el nombre de la playlist que desea ver"<<endl;
    cin>>nombrePlaylist;

    Playlist* playlist = sistema->buscarPlaylist(nombrePlaylist);

    if (playlist == nullptr) {
        cout<<"Playlist no ha sido encontrada"<<endl;
        return;
    }
    sistema->verPlaylist(nombrePlaylist);
}