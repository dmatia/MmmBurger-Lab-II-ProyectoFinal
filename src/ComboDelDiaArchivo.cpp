#include <iostream>
using namespace std;
#include "ComboDelDiaArchivo.h"
#include "Combo.h"
#include "ComboArchivo.h"
#include "HamburguesaDelDia.h"
#include "HamburguesaDelDiaArchivo.h"
#include "BebidaDelDia.h"
#include "BebidaDelDiaArchivo.h"

ComboDelDiaArchivo::ComboDelDiaArchivo()
{
    //ctor
}

ComboDelDiaArchivo::~ComboDelDiaArchivo()
{
    //dtor
}


ComboDelDia ComboDelDiaArchivo::leer(int pos)
{
    ComboDelDia CDD;
    FILE*p = fopen("Archivos/DelDia/CombosDelDia.dat","rb");
    if(p==NULL){fclose(p); return CDD;}
    fseek(p,pos*sizeof(ComboDelDia),SEEK_SET);
    fread(&CDD,sizeof(ComboDelDia),1,p);
    fclose(p);
    return CDD;
}

bool ComboDelDiaArchivo::agregar(ComboDelDia combdeldia)
{   FILE*p=fopen("Archivos/DelDia/CombosDelDia.dat","ab+");
    if(p==NULL){return false;}
    bool escribio = fwrite(&combdeldia,sizeof(ComboDelDia),1,p);
    fclose(p);
    return escribio;
    }

int ComboDelDiaArchivo::buscarPorCodigoyFecha(int codigo, Fecha fecha)
{
    int cantidad = getCantidadRegistros();
    ComboDelDia aux;
    for (int i=0; i<cantidad; i++){
        aux = leer(i);
        if((aux.getCodigo()==codigo)&&(aux.getFecha()==fecha)){
            return i;
        }
    }
    return -1;

}


int ComboDelDiaArchivo::getCantidadRegistros(){
    FILE*p = fopen("Archivos/DelDia/CombosDelDia.dat","rb");
    if(p==NULL){fclose(p); return 0;}
    fseek(p,0,SEEK_END);
    int cantidad = ftell(p)/sizeof(ComboDelDia);
    fclose(p);
    return cantidad;
    }

    bool ComboDelDiaArchivo::leerTodosLosRegistros (ComboDelDia veccombo[], int cantidad) {
    FILE* p;
    p = fopen("Archivos/DelDia/CombosDelDia.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fread(veccombo, sizeof(ComboDelDia), cantidad, p);
    fclose(p);
    return true;
}





    int ComboDelDiaArchivo::contarCombosDeLaFecha(){
    int cantIng = getCantidadRegistros(), contador=0;
    ComboDelDia cdd;
    Fecha fecha;
    for(int i=0; i<cantIng; i++){
        cdd = leer(i);
        if(cdd.getFecha()==fecha){contador++;}
    }
    return contador;
    }

    int ComboDelDiaArchivo::leerTodosCombosDeLaFecha(ComboDelDia cdd[], int cant)
    {
    ComboDelDia aux;
        int j = 0;
        Fecha fecha;
        for(int i=0; i<getCantidadRegistros(); i++){
            aux = leer(i);
            if(aux.getFecha()==fecha){
                cdd[j]=aux;
                j++;
            }
        }
        return 1;
    }


 bool ComboDelDiaArchivo::modificarRegistro(ComboDelDia cdd, int pos)
    {
    FILE*p=fopen("Archivos/DelDia/CombosDelDia.dat","rb+");
    if(p==NULL){return false;}
    fseek(p,pos*sizeof(ComboDelDia),SEEK_SET);
    bool escribio = fwrite(&cdd, sizeof(ComboDelDia),1,p);
    fclose(p);
    return escribio;
    }

int ComboDelDiaArchivo::contarCombosDeLaFecha(Fecha fecha){
    int cantIng = getCantidadRegistros(), contador=0;
    ComboDelDia cdd;
    for(int i=0; i<cantIng; i++){
        cdd = leer(i);
        if(cdd.getFecha()==fecha){contador++;}
    }
    return contador;
    }

void ComboDelDiaArchivo::leerTodosCombosDeLaFecha(ComboDelDia cdd[], int cant, Fecha fecha){
    ComboDelDia aux;
        int j = 0;
        for(int i=0; i<getCantidadRegistros(); i++){
            aux = leer(i);
            if(aux.getFecha()==fecha){
                cdd[j]=aux;
                j++;
            }
        }
    }
