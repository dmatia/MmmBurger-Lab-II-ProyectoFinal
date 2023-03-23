#include <iostream>
#include <cstring>
#include "Bebida.h"
#include "BebidaArchivo.h"

Bebida::Bebida()
{
    _codigo = -100;
    _precio = 0;
}

Bebida::~Bebida()
{
    //dtor
}


void Bebida::setCodigo(int codigo)
{
    _codigo = codigo;
}

void Bebida::setNombre(std::string nombre)
{
    strcpy(_nombre,nombre.c_str());
}

void Bebida::setPresentacion(int presentacion){
    _presentacion = presentacion;}


void Bebida::setPrecio(float precio)
{
    _precio=precio;
}

int Bebida::getCodigo()
{
    return _codigo;
}

std::string Bebida::getNombre()
{
    return _nombre;
}

std::string Bebida::getPresentacion(){
    if(_presentacion==1){return " de 500ml";}
    if(_presentacion==2){return " de 1000ml";}
}

int Bebida::getCodPresentacion(){
    return _presentacion;
    }

float Bebida::getPrecio()
{
    return _precio;
}

