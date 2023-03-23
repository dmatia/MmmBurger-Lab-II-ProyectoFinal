#include <iostream>
#include "ComboDelDia.h"

#include "HamburguesaDelDia.h"
#include "HamburguesaDelDiaArchivo.h"

#include "BebidaDelDia.h"
#include "BebidaDelDiaArchivo.h"

ComboDelDia::ComboDelDia()
{
    _estado = true;
}

ComboDelDia::~ComboDelDia()
{
    //dtor
}


Fecha ComboDelDia::getFecha()
{
    return _fecha;
}

void ComboDelDia::setEstado(bool n){
    _estado = n;
}

bool ComboDelDia::getEstado(){
return _estado;}

bool ComboDelDia::comprobarStock(){
    Fecha fecha;
    HamburguesaDelDia HDD;
    HamburguesaDelDiaArchivo HDDA;
    HDD = HDDA.leer(HDDA.buscarPorCodigoyFecha(getHamburguesa(),fecha));
    if(HDD.getEstado()==false){return false;}

    BebidaDelDia BDD;
    BebidaDelDiaArchivo BDDA;
    BDD = BDDA.leer(BDDA.buscarPorCodigoyFecha(getBebida(), fecha));
    if(BDD.getEstado()==false){return false;}

    return true;
}

bool ComboDelDia::descontarStock(){
     HamburguesaDelDia hdd;
     HamburguesaDelDiaArchivo HDDA;
     hdd = HDDA.leer(HDDA.buscarPorCodigoyFecha(getHamburguesa(),_fecha));
     hdd.descontarStock();

     BebidaDelDia bdd;
     BebidaDelDiaArchivo BDDA;
     bdd = BDDA.leer(BDDA.buscarPorCodigoyFecha(getBebida(),_fecha));
     bdd.descontarStock();
     BDDA.modificarRegistro(bdd, BDDA.buscarPorCodigoyFecha(getBebida(), _fecha));

     return true;
}
