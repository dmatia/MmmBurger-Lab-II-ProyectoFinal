#include <iostream>
#include <ctime>
using namespace std;
#include "Fecha.h"

Fecha::Fecha()
{
    time_t t;
    t = time(NULL);
    struct tm *fecha;
    fecha =localtime(&t);
    _dia = fecha->tm_mday;
    _mes = fecha->tm_mon+1;
    _anio = fecha->tm_year+1900;
}

Fecha::~Fecha()
{
    //dtor
}

int Fecha::getDia () {return _dia;}
int Fecha::getMes () {return _mes;}
int Fecha::getAnio () {return _anio;}

void Fecha::setDia (int n) {_dia = n;}
void Fecha::setMes (int n) {_mes = n;}
void Fecha::setAnio (int n) {_anio = n;}

void Fecha::incrementarDia(){
    _dia+=1;
    if(_dia==32){
        incrementarMes();
        _dia=1;
    }
}

void Fecha::incrementarMes(){
    _mes+=1;
    if(_mes==13){
        incrementarAnio();
        _mes = 1;
    }
}

void Fecha::incrementarAnio(){
    _anio+=1;}
