#include <iostream>
using namespace std;
#include <cstring>
#include "Combo.h"
#include "Hamburguesa.h"
#include "HamburguesaArchivo.h"
#include "Bebida.h"
#include "BebidaArchivo.h"
#include "ComboArchivo.h"

Combo::Combo()
{
    _codigo= -100; _precio=0;
}

Combo::~Combo()
{
    //dtor
}

void Combo::setCodigo(int n){_codigo = n;}
void Combo::setNombre(std::string n){strcpy(_nombre, n.c_str());}
void Combo::setHamburguesa(int n){_codigohamburguesa = n;}
void Combo::setBebida(int n){_codigobebida = n;}
void Combo::setPrecio(float n){_precio = n;}

int Combo::getCodigo(){return _codigo;}
string Combo::getNombre(){return _nombre;}
int Combo::getHamburguesa(){return _codigohamburguesa;}
int Combo::getBebida(){return _codigobebida;}
float Combo::getPrecio(){return _precio;}


float Combo::generarPrecio(){
    HamburguesaArchivo HA;
    BebidaArchivo BA;
    Hamburguesa ham = HA.leerRegistro(_codigohamburguesa-1);
    Bebida beb = BA.leerRegistro(_codigobebida-1);
    int precio = (ham.getPrecio()+beb.getPrecio())-(((ham.getPrecio()+beb.getPrecio())*10)/100);
    return precio;
}
