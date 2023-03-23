#include <iostream>
#include "IngredienteDelDia.h"


IngredienteDelDia::IngredienteDelDia()
{
    _estado = true;
    _stockFinal = 0;
    _stockInicial = 0;
}

IngredienteDelDia::~IngredienteDelDia()
{
    //dtor
}

void IngredienteDelDia::setStockInicial(int stockinicial)
{
    _stockInicial = stockinicial;
    _stockFinal = stockinicial;
}

void IngredienteDelDia::agregarStock(int stockaagregar)
{
    _stockInicial += stockaagregar;
    _stockFinal += stockaagregar;
}

int IngredienteDelDia::getStockInicial()
{
    return _stockInicial;
}

int IngredienteDelDia::getStockFinal()
{
        return _stockFinal;
}

Fecha IngredienteDelDia::getFecha()
{
        return _fecha;
}

bool IngredienteDelDia::comprobarStock(){
        if (_stockFinal>0){return true;}
        return false;
            }

bool IngredienteDelDia::descontarStock(int cant){
            _stockFinal-=cant;
            if(comprobarStock()==true){_estado = true; return true;}
            else{_estado = false; return false;}
    }

bool IngredienteDelDia::descontarStockAdm(int cant){
            _stockInicial-=cant;
            _stockFinal-=cant;
            if(comprobarStock()==true){_estado = true; return true;}
            else{_estado = false; return false;}
    }

void IngredienteDelDia::setEstado(bool n){
    _estado = n;}

bool IngredienteDelDia::getEstado(){
        return _estado;
        }

