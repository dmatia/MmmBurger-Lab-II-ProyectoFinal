#include <iostream>
#include <ctime>
using namespace std;
#include "Hora.h"


Hora::Hora()
{
    time_t t;
    t = time(NULL);
    struct tm *fecha;
    fecha =localtime(&t);
    _hora = fecha->tm_hour;
    _minutos = fecha->tm_min;
    _segundos = fecha->tm_sec;
}

Hora::~Hora()
{
    //dtor
}
int Hora::getHoras(){return _hora; }
int Hora::getMinutos(){return _minutos;}
int Hora::getSegundos(){return _segundos;}
