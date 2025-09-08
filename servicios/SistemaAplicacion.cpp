#include "SistemaAplicacion.h"
#include "../dominio/Usuario.h"
#include "../dominio/Playlist.h"
#include "../dominio/Cancion.h"
#include <fstream>
#include <cctype>
#include <exception>
#include <iostream>
#include <sstream>
using namespace std;

//inicializar el contenedor de los usuarios con una cantidad maxima grande para sobredimensionar
SistemaAplicacion::SistemaAplicacion() {

    contenedorUsuario = new ContenedorUsuario(999);//inicializar contenedor de usuarios con una cantidad maxima
    contenedorCanciones = new ContenedorNexoSimple();//inicializar contenedor de canciones
    lecturaArchivo_usuario();//llamar al metodo que hace la lectura de archivos de los usuarios
    lecturaArchivo_canciones();//llamar al metodo que hace la lectura de archivos de las canciones
}
void SistemaAplicacion::lecturaArchivo_usuario() {

    ifstream archivo_usuarios("users.txt");//declara variable de tipo archivo de entrada "ifstream"

    if (!archivo_usuarios.is_open()) {//se valida si el archivose abrio correctamente
        cout<<"Error al abrir el archivo users.txt"<<endl;
        return;
    }
    string id_usuario_texto,nombre_usuario,correo_usuario,contrasenia_usuario;//declarar variables que almacenaran datos del archivo

    while (archivo_usuarios >> id_usuario_texto >> nombre_usuario >> correo_usuario >> contrasenia_usuario) {//mientras hayan datos en el archivo
        try {//se valida la entrada de la id ya que en vez de leerse como entero se lee como un string
            int id = stoi(id_usuario_texto);//stoi: convertir de string a int
            Usuario* usuario = new Usuario(id,nombre_usuario,correo_usuario,contrasenia_usuario);//se crea el objeto usuarios con los parametros de entrada
            contenedorUsuario->agregar(usuario);//el usuario es agregado al contenedor de usuarios
        }catch (invalid_argument &e) {
            cout<<"Error al leer el archivo usuarios"<<endl;
        }
    }
    archivo_usuarios.close();//se cierra la lectura del archivo
}
void SistemaAplicacion::lecturaArchivo_canciones() {

    ifstream archivo_canciones("canciones.txt");//declara variable de tipo archivo de entrada "ifstream"

    if (!archivo_canciones.is_open()) {//se valida si el archivose abrio correctamente
        cout << "Error al abrir el archivo canciones.txt" << endl;
        return;
    }
    string linea;//variable que leera cada linea del archivo
    while (getline(archivo_canciones, linea)) {//mientras hayan datos en el archivo, leera el archivo
        stringstream ss(linea);//permite leer espacios que hay en el archivo
        string nombre_cancion, album_cancion, artista_cancion, duracion_cancion;//se declaran variables que almacenaran los datos

        //se encarga de extraer los 4 campos del archivo separado por comas
        if (getline(ss,nombre_cancion,',') && getline(ss,album_cancion,',') &&
            getline(ss,artista_cancion,',') && getline(ss,duracion_cancion,',')) {
            //si se cumple la condicion entonces se procede a almacenar los datos
            Cancion* cancion = new Cancion(nombre_cancion,album_cancion,artista_cancion,duracion_cancion);//de declara la cancion con sus parametros
            this->contenedorCanciones->agregar(cancion);//la cancion se agrega al contenedor de canciones que es una lista con nexo simple

        }else {//si es que no se extraen los campos del archivo
            cout<<"Error al leer el archivo"<<endl;
            return;
        }
    }
    archivo_canciones.close();//se cierra el archivo
}

//metodo para iniciar sesion
bool SistemaAplicacion::iniciarSesion(string nombre, string contrasenia) {

    int posicion = contenedorUsuario->buscar(nombre);//accede a la posicion del usuario segun su nombre

    if (posicion == -1) {//si el usuario nose encuentra en el sistema
        cout<<"Usuario "<<nombre<<" No ha sido encontrado. Debe registrarse"<<endl;
        return false;
    }
    Usuario* usuario = contenedorUsuario->obtener(posicion);//accede al usuario por su posicion

    //si el nombre o la contrasenia ingresadas por el usuario son distintas a las que registro
    if (usuario->getNombre() != nombre || usuario->getContrasenia() != contrasenia) {
        cout<<"Datos del usuario registrados no son correctos"<<endl;
        return false;
    }
    usuarioActual = usuario;//el usuario actual sera el usuario que se haya registrado
    cout<<"Inicio de sesion exitoso"<<endl;//mensaje indicando el resultado
    return true;//retorna true porque se cumple la condicion
}
//metodo para que el usuario pueda registrarse en el programa
void SistemaAplicacion::registrarse(string nombre, string correo, string contrasenia) {

    //validar ingreso de correo por el usuario
    string correosDisponibles[] = {"@gmail.com","@outlook.com","@gmail.cl","@hotmail.com"};
    bool correoValido = false;

    for (string formatoAceptado : correosDisponibles) {
        if (correo.ends_with(formatoAceptado)) {
            correoValido = true;
            break;
        }
    }
    if (!correoValido) {
        cout<<"El correo debe terminar en @gmail.com, @outlook.com, @gmail.cl o @hotmail.com"<<endl;
        return;
    }
    //validar formato de contrasenia
    bool tieneMayuscula = false;
    bool tieneSigno = false;

    for (char caracter : contrasenia) {
        if (isupper(caracter)) {
            tieneMayuscula = true;
        }
        if (ispunct(caracter)) {
            tieneSigno = true;
        }
    }
    if (!tieneMayuscula || !tieneSigno) {
        cout<<"Su contrasenia por lo menos debe tener uan mayuscula y un signo"<<endl;
        return;
    }
    int posicion = contenedorUsuario->buscar(nombre);//accede a la posicion del usuario por su nombre

    if (posicion != -1) {//si el usuario intenta registrar a un usuario ya existente
        cout<<"El usuario "<<nombre<< " ya existe. Intente con otro nombre"<<endl;
        return;
    }
    int ultimaId = this->contenedorUsuario->getCantidadActual()+1;//generador de id automatico
    Usuario* usuario_nuevo = new Usuario(ultimaId,nombre,correo,contrasenia);//se crea el usuario

    try {//se valida el usuario que se vaya a agregar
        contenedorUsuario->agregar(usuario_nuevo);//el nuevo usuario es agregado al contenedor
        cout<<"Usuario fue registrado con exito y su id es "<<ultimaId<<endl;

    }catch (exception &e) {//salta mensaje con la excepcion
        cout<<"Error al registrar al usuario. Intente nuevamente"<<endl;
    }
}
//metodos de Playlist
void SistemaAplicacion::crearPlaylist(string nombre) {

    Playlist* playlistExistente = buscarPlaylist(nombre);

    if (playlistExistente != nullptr) {
        cout<<"La playlist "<<nombre<<" ya existe"<<endl;
        return;
    }
    //condicion para limitar la creacion de playlist
    if (usuarioActual->getContenedorPLaylist_usuario()->getCantidadActual() >= 3) {
        cout<<"Has superado el limite para crear playlist"<<endl;
        return;
    }
    Playlist* nuevaPlaylist = new Playlist(nombre);//se crea la playlist por su nombre
    usuarioActual->getContenedorPLaylist_usuario()->agregar(nuevaPlaylist);//usuario crea la playlist
    cout<<"Playlist creada con exito"<<endl;
}
void SistemaAplicacion::agregarCancion(string nombrePlaylist, string nombreCancion) {


    Playlist* playlistExistente = buscarPlaylist(nombrePlaylist);//obtenemos la playlist especifica

    if (playlistExistente == nullptr) {//se valida si la playlist existe
        cout<<"La playlist "<<nombrePlaylist<<" no ha sido encontrada"<<endl;
        return;
    }
    //verificamos si la cancion que se quiere agregar no sea nula
    Cancion* cancion = contenedorCanciones->obtenerCancion(nombreCancion);//obtenemos la cancion especifica en base a su nombre

    if (cancion == nullptr) {//si la cancion que queremos acceder no existe
        cout<<"La cancion "<<nombreCancion<< " no existe en el catalogo"<<endl;
        return;
    }

    playlistExistente->getlistaCanciones()->agregar(cancion);//la cancion se agrega a la playlist
    cout<<"cancion agregada con exito"<<endl;

}
void SistemaAplicacion::eliminarCancion(string nombrePlaylist, string nombreCancion,int indice) {

    //obtenemos la playlist especifica
    Playlist* playlistEncontrada = buscarPlaylist(nombrePlaylist);//se inicializa la playlist

    if (playlistEncontrada == nullptr) {//verificamos que la playlist creada no sea nula
        cout<<"La playlist: "<<nombrePlaylist<<" no ha sido encontrada"<<endl;
        return;
    }
    //se valida si hay canciones en la playlist
    if (playlistEncontrada->getlistaCanciones()->getTamanio() == 0) {//si la tamanio de la lista es cero
        cout<<"La playlist "<<nombrePlaylist<<" esta vacia"<<endl;//la lista esta vacia
        return;
    }
    if (indice < 0 || indice >= playlistEncontrada->getlistaCanciones()->getTamanio()){
        cout<<"indice seleccionado no valido"<<endl;
        return;
    }
    Cancion* cancionEliminar = playlistEncontrada->getlistaCanciones()->obtenerPosicionCancion(indice);//accede a la posicion de la cancion segun el indice que tiene la cancion
    if (cancionEliminar == nullptr) {
        cout<<"nose encontro la cancion en el indide"<<indice<<endl;
        return;
    }
    playlistEncontrada->getlistaCanciones()->eliminar(cancionEliminar);//se elimina la cancion de la playlist
    cout<<"La cancion "<<cancionEliminar->getNombreMusica()<<" ha sido eliminada con exito de la playlist "<<nombrePlaylist<<endl;
}
void SistemaAplicacion::renombrarPlaylist(string nombreAntiguo,string nombreNuevo) {

    //obtenemos la playlist especifica
    Playlist* playlist = buscarPlaylist(nombreAntiguo);

    if (playlist == nullptr) {
        cout<<"Error al renombrar la playlist. La playlist "<<nombreAntiguo<<" no fue encontrada"<<endl;

    }else {
        playlist->setnombre_playlist(nombreNuevo);
        cout<<"Playlist renombrada con exito"<<endl;
    }
}

void SistemaAplicacion::eliminarPlaylist(string nombrePlaylist) {

    //obtenemos la playlist especifica
    Playlist* playlistEliminar = buscarPlaylist(nombrePlaylist);

    if (playlistEliminar != nullptr) {
        usuarioActual->getContenedorPLaylist_usuario()->eliminar(nombrePlaylist);
        cout<<"playlist eliminada con exito"<<endl;
    }else {
        cout<<"La playlist "<<nombrePlaylist<<" no ha sido eliminada"<<endl;
    }
}
void SistemaAplicacion::verPlaylist(string nombrePlaylist) {

    //obtenemos la playlist especifica
    Playlist* playlist = buscarPlaylist(nombrePlaylist);

    if (playlist == nullptr) {
        cout<<"La playlist "<<nombrePlaylist<<" no ha sido encontrada"<<endl;
        return;
    }
    if (playlist->getlistaCanciones()->getTamanio() == 0) {
        cout<<"No hay canciones para ver. Intente agregar canciones"<<endl;
        return;
    }
    Nodo* aux = playlist->getlistaCanciones()->getCabecera();//se obtiene el primer elemento de la lista contenido en la playlist
    int indice = 0;//variable que simboliza la posicion de la cancion

    cout<<"playlist "<<nombrePlaylist<<endl;
    while (aux != nullptr) {//mientras hayan elementos en la lista
        cout<<"["<<indice<<"] "<<"Cancion: "<<aux->getCancion()->getNombreMusica()<<endl;//se imprime el indice y el nombre de la cancion
        aux = aux->getSiguiente();//el nodo pasa a ser el siguiente de la lista
        indice++;//incrementa el indice para enumerar la lista
    }
    cout<<endl;//salto de linea
}
//metodo para obtener la playlist en base al nombre
Playlist* SistemaAplicacion::buscarPlaylist(string nombre) {

    //se recorre la lista de playlist
    for (int i = 0; i < usuarioActual->getContenedorPLaylist_usuario()->getCantidadActual(); ++i) {
        Playlist* playlist = usuarioActual->getContenedorPLaylist_usuario()->obtener(i);
        if (playlist->getnombre_playlist() == nombre) {//si el nombre de la playlist es igual al nombre que le dio el usuario a su playlist
            return playlist;//retorna la playlist del usuario
        }
    }
    return nullptr;//retorna nullptr si es que nose encontro la playlist
}

void SistemaAplicacion::escribirArchivo_usuarios() {


    ofstream archivoSalida_usuarios("resultados_users.txt");//creamos el archivo de salida para los usuarios

    if (!archivoSalida_usuarios.is_open()) {//verificamos si el archivo esta abierto
        cout<<"Error al abrir el archivo"<<endl;
        return;
    }
    //recorremos la lista de los usuarios en base a la cantidad actual de usuarios que fueron registrados
    for (int i = 0; i < contenedorUsuario->getCantidadActual(); ++i) {
        Usuario* usuario = contenedorUsuario->obtener(i);//accedemos a todas las posiciones de los usuarios registrados
        //la variable archivo lee los datos obtenidos en el registro y los imprime en el archivo de salida
        archivoSalida_usuarios<<usuario->getId()<<",";
        archivoSalida_usuarios<<usuario->getNombre()<<",";
        archivoSalida_usuarios<<usuario->getCorreo()<<",";
        archivoSalida_usuarios<<usuario->getContrasenia()<<endl;
    }
    archivoSalida_usuarios.close();//cierra el archivo
}

void SistemaAplicacion::escribirArchivo_canciones() {


    ofstream archivoSalida_canciones("resultados_canciones.txt");//declaramos el nombre que tendra el archivo de salida

    if (!archivoSalida_canciones.is_open()) {//verificar si el archivo esta abierto
        cout<<"Error al abrir el archivo de salida"<<endl;
        return;
    }
    //recorremos la lista de playlist de los usuarios
    for (int i = 0; i < usuarioActual->getContenedorPLaylist_usuario()->getCantidadActual(); ++i) {
        Playlist* playlist = usuarioActual->getContenedorPLaylist_usuario()->obtener(i);
        //el archivo de salida lee el nombre del usuario y el nombre de la playlist que le dio el usuario

        //se recorre la lista de canciones segun el numero de canciones en la playlist
        for (int i = 0; i < playlist->getlistaCanciones()->getTamanio(); ++i) {
            Cancion* cancion = playlist->getlistaCanciones()->obtenerPosicionCancion(i);//se accede a todas las posiciones de las canciones de la lista
            archivoSalida_canciones << usuarioActual->getNombre() <<",";
            archivoSalida_canciones << playlist->getnombre_playlist() <<",";
            archivoSalida_canciones << cancion->getNombreMusica() <<",";
            archivoSalida_canciones<< cancion->getAlbum() <<",";
            archivoSalida_canciones<<cancion->getArtista() <<",";
            archivoSalida_canciones<<cancion->getDuracion()<<endl;
        }
        archivoSalida_canciones <<endl;//salto de linea
    }
    archivoSalida_canciones.close();//se cierra el archivo
}
