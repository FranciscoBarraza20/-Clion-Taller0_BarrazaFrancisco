#include <iostream>
#include "servicios/SistemaAplicacion.h"
#include "vista/VistaConsola.h"

using namespace std;

int main() {

    SistemaAplicacion* parteTrasera = new SistemaAplicacion();
    VistaConsola* parteFrontal = new VistaConsola(parteTrasera);
    parteFrontal->iniciar();

    return 0;

}