#include <iostream>
using namespace std;
#include "HamburguesaDelDia.h"
#include "IngDeHambuguesa.h"
#include "IngDeHamburguesaArchivo.h"
#include "IngredienteDelDia.h"
#include "IngredienteDelDiaArchivo.h"

HamburguesaDelDia::HamburguesaDelDia()
{
    _estado = true;
}

HamburguesaDelDia::~HamburguesaDelDia()
{
    //dtor
}

Fecha HamburguesaDelDia::getFecha()
{
        return _fecha;
}

void HamburguesaDelDia::setEstado(bool estado){
_estado = estado;}

bool HamburguesaDelDia::descontarStock(){
    IngDeHamburguesaArchivo IDHA;
    int cant = IDHA.getCantidadPorHamburguesa(getCodigo());
    IngDeHambuguesa *vecIDH = new IngDeHambuguesa [cant];
    if(vecIDH==nullptr){return false;}
    IDHA.getIngredientesDeHamburguesa(vecIDH,cant,getCodigo());
    Fecha fecha;
    IngredienteDelDiaArchivo IDDA;
    IngredienteDelDia IDD;
    for(int i=0; i<cant; i++){
        IDD = IDDA.leer(IDDA.buscarPorCodigoyFecha(vecIDH[i].getCodigoIngrediente(),fecha));
        IDD.descontarStock(vecIDH[i].getCantidad());
        IDDA.modificarRegistro(IDD, IDDA.buscarPorCodigoyFecha(vecIDH[i].getCodigoIngrediente(),fecha));
    }
    delete[]vecIDH;
    return true;
}

bool HamburguesaDelDia::verificarIngredientesDisponibles(){
    IngDeHamburguesaArchivo IDHA;
    int cant = IDHA.getCantidadPorHamburguesa(getCodigo());
    IngDeHambuguesa *vecIDH = new IngDeHambuguesa [cant];
    if(vecIDH==nullptr){return false;}
    IDHA.getIngredientesDeHamburguesa(vecIDH,cant,getCodigo());
    Fecha fecha;
    IngredienteDelDiaArchivo IDDA;
    IngredienteDelDia IDD;
    for(int i=0; i<cant; i++){
        IDD = IDDA.leer(IDDA.buscarPorCodigoyFecha(vecIDH[i].getCodigoIngrediente(),fecha));
        if(IDD.comprobarStock()==false){
            _estado = false;
            delete[]vecIDH;
            return false;
        }
    }
    delete[]vecIDH;
    return true;
}

bool HamburguesaDelDia::getEstado(){
        return _estado;}
