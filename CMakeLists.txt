cmake_minimum_required(VERSION 3.31)
project(Taller_nivelacion_estructura_de_datos)

set(CMAKE_CXX_STANDARD 20)

add_executable(Taller_nivelacion_estructura_de_datos main.cpp
        dominio/Playlist.cpp
        dominio/Playlist.h
        dominio/ContenedorUsuario.cpp
        dominio/usuario.cpp
        dominio/usuario.h
        dominio/ContenedorUsuario.h
        dominio/ContenedorPlaylist.cpp
        dominio/ContenedorPlaylist.h
        dominio/Cancion.cpp
        dominio/Cancion.h
        dominio/coleccion/Nodo.cpp
        dominio/coleccion/Nodo.h
        dominio/coleccion/ContenedorNexoSimple.cpp
        dominio/coleccion/ContenedorNexoSimple.h
        servicios/SistemaAplicacion.cpp
        servicios/SistemaAplicacion.h
        vista/VistaConsola.cpp
        vista/VistaConsola.h)


