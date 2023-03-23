#include <iostream>
using namespace std;
#include "BebidaDelDiaArchivo.h"

BebidaDelDiaArchivo::BebidaDelDiaArchivo()
{
    //ctor
}

BebidaDelDiaArchivo::~BebidaDelDiaArchivo()
{
    //dtor
}


BebidaDelDia BebidaDelDiaArchivo::leer(int pos)
{
    BebidaDelDia BDD;
    FILE*p = fopen("Archivos/DelDia/BebidasDelDia.dat","rb");
    if(p==NULL){fclose(p); return BDD;}
    fseek(p,pos*sizeof(BebidaDelDia),SEEK_SET);
    fread(&BDD,sizeof(BebidaDelDia),1,p);
    fclose(p);
    return BDD;
}

bool BebidaDelDiaArchivo::agregar(BebidaDelDia BebDelDia)
{   FILE*p=fopen("Archivos/DelDia/BebidasDelDia.dat","ab+");
    if(p==NULL){std::cout << "NO SE PUDO ABRIR EL ARCHIVO" ; return false;}
    bool escribio = fwrite(&BebDelDia,sizeof(BebidaDelDia),1,p);
    fclose(p);
    return escribio;
    }

int BebidaDelDiaArchivo::buscarPorCodigoyFecha(int codigo, Fecha fecha)
{
    int cantidad = getCantidadRegistros();
    BebidaDelDia aux;
    for (int i=0; i<cantidad; i++){
        aux = leer(i);
        if((aux.getCodigo()==codigo)&&(aux.getFecha()==fecha)){
            return i;
        }
    }
    return -1;

}

bool BebidaDelDiaArchivo::modificarRegistro(BebidaDelDia BebDelDia, int posicion)
{
    FILE*p=fopen("Archivos/DelDia/BebidasDelDia.dat","rb+");
    if(p==NULL){return false;}
    fseek(p,posicion*sizeof(BebidaDelDia),SEEK_SET);
    bool escribio = fwrite(&BebDelDia,sizeof(BebidaDelDia),1,p);
    fclose(p);
    return escribio;
}

int BebidaDelDiaArchivo::getCantidadRegistros(){
    FILE*p = fopen("Archivos/DelDia/BebidasDelDia.dat","rb");
    if(p==NULL){fclose(p); return 0;}
    fseek(p,0,SEEK_END);
    int cantidad = ftell(p)/sizeof(BebidaDelDia);
    fclose(p);
    return cantidad;
    }

    bool BebidaDelDiaArchivo::leerTodosLosRegistros(BebidaDelDia vecBeb[], int cantidad){
    FILE* p;
    p = fopen("Archivos/DelDia/BebidasDelDia.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fread(vecBeb, sizeof(BebidaDelDia), cantidad, p);
    fclose(p);
    return true;
}

int BebidaDelDiaArchivo::contarBebidasDeLaFecha(){
    int cantIng = getCantidadRegistros(), contador=0;
    BebidaDelDia bdd;
    Fecha fecha;
    for(int i=0; i<cantIng; i++){
        bdd = leer(i);
        if(bdd.getFecha()==fecha){contador++;}
    }
    return contador;
    }

    int BebidaDelDiaArchivo::leerTodosBebidasDeLaFecha(BebidaDelDia bdd[], int cant)
    {
    BebidaDelDia aux;
        int j = 0;
        Fecha fecha;
        for(int i=0; i<getCantidadRegistros(); i++){
            aux = leer(i);
            if(aux.getFecha()==fecha){
                bdd[j]=aux;
                j++;
            }
        }
        return 1;
    }


int BebidaDelDiaArchivo::contarBebidasDeLaFecha(Fecha fecha){
    int cantIng = getCantidadRegistros(), contador=0;
    BebidaDelDia bdd;
    for(int i=0; i<cantIng; i++){
        bdd = leer(i);
        if(bdd.getFecha()==fecha){contador++;}
    }
    return contador;
    }

void BebidaDelDiaArchivo::leerTodosBebidasDeLaFecha(BebidaDelDia bdd[], int cant, Fecha fecha)
    {
    BebidaDelDia aux;
        int j = 0;
        for(int i=0; i<getCantidadRegistros(); i++){
            aux = leer(i);
            if(aux.getFecha()==fecha){
                bdd[j]=aux;
                j++;
            }
        }
    }
