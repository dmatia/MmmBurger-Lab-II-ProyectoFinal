#include <iostream>
#include "Hamburguesa.h"
#include <cstring>
#include "HamburguesaArchivo.h"
#include "IngDeHambuguesa.h"
#include "IngDeHamburguesaArchivo.h"

Hamburguesa::Hamburguesa()
{
    _codigo = -100;
    _precio = 0;
}

Hamburguesa::~Hamburguesa()
{
    //dtor
}

void Hamburguesa::setCodigo(int codigo)
{
    _codigo = codigo;
}

void Hamburguesa::setNombre(std::string nombre)
{
    strcpy(_nombre, nombre.c_str());
}

void Hamburguesa::setPrecio(float n)
{
    _precio = n;
}

void Hamburguesa::setIngrediente(int codigoingrediente, int cantidad)
{
    IngDeHambuguesa IDH;
    IDH.setCodigoHamburguesa(_codigo);
    IDH.setCodigoIngrediente(codigoingrediente);
    IDH.setCantidad(cantidad);
    IngDeHamburguesaArchivo IDHA;
    if(IDHA.guardar(IDH)){std::cout << "INGREDIENTE GUARDADO" << std::endl; system("pause"); return;}
    std::cout << "NO SE GRABO INGREDIENTE" ; system("pause");
}

int Hamburguesa::getCodigo()
{
    return _codigo;
}

std::string Hamburguesa::getNombre()
{
    return _nombre;
}

float Hamburguesa::getPrecio()
{
    return _precio;
}


