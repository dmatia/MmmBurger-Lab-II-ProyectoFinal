#include <iostream>
#include <cstring>
#include "Ingrediente.h"

Ingrediente::Ingrediente()
{
    _codigo = -100;
    _precio = 0;
}

Ingrediente::~Ingrediente()
{
    //dtor
}

void Ingrediente::setCodigo(int codigo)
{
    _codigo = codigo;
}

void Ingrediente::setNombre(std::string nombre)
{
    strcpy(_nombre,nombre.c_str());
}

void Ingrediente::setPrecio(float precio)
{
    _precio = precio;
}

int Ingrediente::getCodigo()
{
    return _codigo;
}

std::string Ingrediente::getNombre()
{
    return _nombre;
}

float Ingrediente::getPrecio()
{
    return _precio;
}
