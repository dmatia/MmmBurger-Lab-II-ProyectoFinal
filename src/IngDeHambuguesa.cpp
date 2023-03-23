#include <iostream>
#include "IngDeHambuguesa.h"

IngDeHambuguesa::IngDeHambuguesa()
{
    //ctor
}

IngDeHambuguesa::~IngDeHambuguesa()
{
    //dtor
}

void IngDeHambuguesa::setCodigoHamburguesa(int codigoHamburguesa)
{
    _codigoHamburguesa = codigoHamburguesa;
}

void IngDeHambuguesa::setCodigoIngrediente(int codigoIngrediente)
{
    _codigoIngrediente = codigoIngrediente;
}

void IngDeHambuguesa::setCantidad(int cantidad)
{
    _cantidad = cantidad;
}

int IngDeHambuguesa::getCodigoHamburguesa()
{
    return _codigoHamburguesa;
}

int IngDeHambuguesa::getCodigoIngrediente()
{
    return _codigoIngrediente;
}

int IngDeHambuguesa::getCantidad()
{
    return _cantidad;
}
