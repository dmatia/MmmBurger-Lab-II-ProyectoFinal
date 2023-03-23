#include <iostream>
#include "BebidaArchivo.h"

BebidaArchivo::BebidaArchivo()
{
    //ctor
}

BebidaArchivo::~BebidaArchivo()
{
    //dtor
}

int BebidaArchivo::getCantidadRegistros(){
    FILE*p = fopen("Archivos/Historico/BebidasHistorico.dat","rb");
    if(p==NULL){fclose(p); return 0;}
    fseek(p,0,SEEK_END);
    int cantidad = ftell(p)/sizeof(Bebida);
    fclose(p);
    return cantidad;
    }

Bebida BebidaArchivo::leerRegistro(int posicion)
{
    Bebida bebida;
    FILE*p = fopen("Archivos/Historico/BebidasHistorico.dat","rb");
    if(p==NULL){fclose(p); return bebida;}
    fseek(p,posicion*sizeof(Bebida),SEEK_SET);
    fread(&bebida,sizeof(Bebida),1,p);
    fclose(p);
    return bebida;
}

bool BebidaArchivo::guardarRegistro(Bebida bebida)
{
    FILE*p=fopen("Archivos/Historico/BebidasHistorico.dat","ab+");
    if(p==NULL){std::cout << "NO SE PUDO ABRIR EL ARCHIVO" ; return false;}
    bool escribio = fwrite(&bebida,sizeof(Bebida),1,p);
    fclose(p);
    return escribio;
}

bool BebidaArchivo::modificarRegistro(Bebida bebida, int posicion)
{
    FILE*p=fopen("Archivos/Historico/BebidasHistorico.dat","rb+");
    if(p==NULL){return false;}
    fseek(p,posicion*sizeof(Bebida),SEEK_SET);
    bool escribio = fwrite(&bebida,sizeof(Bebida),1,p);
    fclose(p);
    return escribio;
}

int BebidaArchivo::buscarRegistroPorCodigo(int codigo)
{
    int cantidad = getCantidadRegistros();
    Bebida aux;
    for (int i=0; i<cantidad; i++){
        aux = leerRegistro(i);
        if(aux.getCodigo()==codigo){
            return i;
        }
    }
    return -1;
}

bool BebidaArchivo::leerTodosLosRegistros(Bebida bebidas[], int cantidad){
    FILE* p;
    p = fopen("Archivos/Historico/BebidasHistorico.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fread(bebidas, sizeof(Bebida), cantidad, p);
    fclose(p);
    return true;
}

int BebidaArchivo::generarCodigo(){
    int nuevocodigo = getCantidadRegistros()+1;
    return nuevocodigo;
}
