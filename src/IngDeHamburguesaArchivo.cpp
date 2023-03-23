#include <iostream>
#include "IngDeHamburguesaArchivo.h"

IngDeHamburguesaArchivo::IngDeHamburguesaArchivo()
{
    //ctor
}

IngDeHamburguesaArchivo::~IngDeHamburguesaArchivo()
{
    //dtor
}

bool IngDeHamburguesaArchivo::guardar(IngDeHambuguesa IDH){
    FILE*p=fopen("Archivos/Historico/IngDeHamburguesaHistorico.dat","ab+");
    if(p==NULL){std::cout << "NO SE PUDO ABRIR EL ARCHIVO" ; return false;}
    bool escribio = fwrite(&IDH,sizeof(IngDeHambuguesa),1,p);
    fclose(p);
    return escribio;
}


void IngDeHamburguesaArchivo::getIngredientesDeHamburguesa(IngDeHambuguesa IDH[], int cantidad, int codigohamburguesa)
{
    IngDeHambuguesa IDH1;
    int cantRegistros = getCantidadRegistros();
    int j=0;

    for(int i=0; i<cantRegistros; i++){
        IDH1 = leerRegistro(i);
        if (IDH1.getCodigoHamburguesa()==codigohamburguesa){
            IDH[j] = IDH1;
            j++;
        }
    }
}

IngDeHambuguesa IngDeHamburguesaArchivo::leerIngredienteEspecifico(int codigoHamburguesa, int codigoIngrediente)
{
    IngDeHambuguesa IDH;
    FILE * p = fopen ("Archivos/Historico/IngDeHamburguesaHistorico.dat", "rb");
    if(p == NULL) {return IDH;}
    while(fread(&IDH, sizeof(IngDeHambuguesa), 1, p)){
        if((IDH.getCodigoHamburguesa() == codigoHamburguesa)&&(IDH.getCodigoIngrediente()==codigoIngrediente)){
            fclose(p); return IDH;
        }
    }
}


int IngDeHamburguesaArchivo::getCantidadRegistros(){
    FILE*p = fopen("Archivos/Historico/IngDeHamburguesaHistorico.dat","rb");
    if(p==NULL){fclose(p); return 0;}
    fseek(p,0,SEEK_END);
    int cantidad = ftell(p)/sizeof(IngDeHambuguesa);
    fclose(p);
    return cantidad;}


    IngDeHambuguesa IngDeHamburguesaArchivo::leerRegistro(int posicion)
{
    IngDeHambuguesa IDH;
    FILE*p = fopen("Archivos/Historico/IngDeHamburguesaHistorico.dat","rb");
    if(p==NULL){fclose(p); return IDH;}
    fseek(p,posicion*sizeof(IngDeHambuguesa),SEEK_SET);
    fread(&IDH,sizeof(IngDeHambuguesa),1,p);
    fclose(p);
    return IDH;
}


int IngDeHamburguesaArchivo::buscarIngrediente(int codigoHamburguesa, int codigoIngrediente)
{
    int cantidad = getCantidadRegistros();
    IngDeHambuguesa IDH;
    for (int i=0; i<cantidad; i++){
        IDH = leerRegistro(i);
        if((IDH.getCodigoHamburguesa()==codigoHamburguesa)&&(IDH.getCodigoIngrediente()==codigoIngrediente)){
            return i;
        }
    }
    return -1;

}

int IngDeHamburguesaArchivo::getCantidadPorHamburguesa(int codigoHamburguesa)
{
        int cantIngredientes=0, cantidad = getCantidadRegistros();
        IngDeHambuguesa IDH;
        for (int i=0; i<cantidad; i++){
            IDH = leerRegistro(i);
            if(IDH.getCodigoHamburguesa()==codigoHamburguesa){
                cantIngredientes++;
            }
        }
        return cantIngredientes;
}

bool IngDeHamburguesaArchivo::modificarIngrediente(IngDeHambuguesa IDH)
{
    int posicion = buscarIngrediente(IDH.getCodigoHamburguesa(), IDH.getCodigoIngrediente());
    FILE*p=fopen("Archivos/Historico/IngDeHamburguesaHistorico.dat","rb+");
    if(p==NULL){return false;}
    fseek(p,posicion*sizeof(IngDeHambuguesa),SEEK_SET);
    bool escribio = fwrite(&IDH,sizeof(IngDeHambuguesa),1,p);
    fclose(p);
    return escribio;

}

bool IngDeHamburguesaArchivo::leerTodosLosRegistros(IngDeHambuguesa vecIDH[], int cantidad){
    FILE* p;
    p = fopen("Archivos/Historico/IngDeHamburguesaHistorico.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fread(vecIDH, sizeof(IngDeHambuguesa), cantidad, p);
    fclose(p);
    return true;
}

