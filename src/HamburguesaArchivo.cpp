#include <iostream>
#include "HamburguesaArchivo.h"

HamburguesaArchivo::HamburguesaArchivo()
{
    //ctor
}

HamburguesaArchivo::~HamburguesaArchivo()
{
    //dtor
}


int HamburguesaArchivo::getCantidadRegistros(){
    FILE*p = fopen("Archivos/Historico/HamburguesasHistorico.dat","rb");
    if(p==NULL){fclose(p); return 0;}
    fseek(p,0,SEEK_END);
    int cantidad = ftell(p)/sizeof(Hamburguesa);
    fclose(p);
    return cantidad;
    }

Hamburguesa HamburguesaArchivo::leerRegistro(int posicion)
{
    Hamburguesa hamburguesa;
    FILE*p = fopen("Archivos/Historico/HamburguesasHistorico.dat","rb");
    if(p==NULL){fclose(p); return hamburguesa;}
    fseek(p,posicion*sizeof(Hamburguesa),SEEK_SET);
    fread(&hamburguesa,sizeof(Hamburguesa),1,p);
    fclose(p);
    return hamburguesa;
}

bool HamburguesaArchivo::guardarRegistro(Hamburguesa hamburguesa)
{
    FILE*p=fopen("Archivos/Historico/HamburguesasHistorico.dat","ab+");
    if(p==NULL){std::cout << "NO SE PUDO ABRIR EL ARCHIVO" ; return false;}
    bool escribio = fwrite(&hamburguesa,sizeof(Hamburguesa),1,p);
    fclose(p);
    return escribio;
}

bool HamburguesaArchivo::modificarRegistro(Hamburguesa hamburguesa, int posicion)
{
    FILE*p=fopen("Archivos/Historico/HamburguesasHistorico.dat","rb+");
    if(p==NULL){return false;}
    fseek(p,posicion*sizeof(Hamburguesa),SEEK_SET);
    bool escribio = fwrite(&hamburguesa,sizeof(Hamburguesa),1,p);
    fclose(p);
    return escribio;
}

int HamburguesaArchivo::buscarRegistroPorCodigo(int codigo)
{
    int cantidad = getCantidadRegistros();
    Hamburguesa aux;
    for (int i=0; i<cantidad; i++){
        aux = leerRegistro(i);
        if(aux.getCodigo()==codigo){
            return i;
        }
    }
    return -1;
}

bool HamburguesaArchivo::leerTodosLosRegistros(Hamburguesa hamburguesas[], int cantidad){
    FILE* p;
    p = fopen("Archivos/Historico/HamburguesasHistorico.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fread(hamburguesas, sizeof(Hamburguesa), cantidad, p);
    fclose(p);
    return true;
}

int HamburguesaArchivo::generarCodigo(){
    int nuevocodigo = getCantidadRegistros()+1;
    return nuevocodigo;
}
