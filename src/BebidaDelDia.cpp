#include <iostream>
using namespace std;
#include "BebidaDelDia.h"

BebidaDelDia::BebidaDelDia()
{
    _estado = true;
    _stockInicial = 0;
    _stockFinal = 0;
}

BebidaDelDia::~BebidaDelDia()
{
    //dtor
}

void BebidaDelDia::setStockInicial(int stockinicial)
{
    _stockInicial = stockinicial;
    _stockFinal = stockinicial;
}

void BebidaDelDia::agregarStock(int stockaagregar)
{
    _stockInicial += stockaagregar;
    _stockFinal += stockaagregar;
}

int BebidaDelDia::getStockInicial()
{
    return _stockInicial;
}

int BebidaDelDia::getStockFinal()
{
        return _stockFinal;
}

Fecha BebidaDelDia::getFecha()
{
        return _fecha;
}

bool BebidaDelDia::comprobarStock(){
        if (_stockFinal>0){return true;}
        return false;
            }

bool BebidaDelDia::descontarStock(int cant){
            _stockFinal-=cant;
            if(comprobarStock()==true){_estado = true; return true;}
            else{_estado = false; return false;}

    }

bool BebidaDelDia::descontarStock(){
            _stockFinal-=1;
            if(comprobarStock()==true){_estado = true; return true;}
            else{_estado = false; return false;}

    }

bool BebidaDelDia::descontarStockAdm(int cant){
            _stockFinal-=cant;
            _stockInicial-=cant;
            if(comprobarStock()==true){_estado = true; return true;}
            else{_estado = false; return false;}

    }

void BebidaDelDia::setEstado(bool n){
    _estado = n;}

bool BebidaDelDia::getEstado(){
        return _estado;
        }
