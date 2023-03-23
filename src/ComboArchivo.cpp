#include <iostream>
using namespace std;
#include "ComboArchivo.h"

ComboArchivo::ComboArchivo()
{
    //ctor
}

ComboArchivo::~ComboArchivo()
{
    //dtor
}

int ComboArchivo::getCantidadRegistros(){
    FILE*p = fopen("Archivos/Historico/CombosHistorico.dat","rb");
    if(p==NULL){fclose(p); return 0;}
    fseek(p,0,SEEK_END);
    int cantidad = ftell(p)/sizeof(Combo);
    fclose(p);
    return cantidad;
    }

Combo ComboArchivo::leerRegistro(int posicion)
{
    Combo combo;
    FILE*p = fopen("Archivos/Historico/CombosHistorico.dat","rb");
    if(p==NULL){fclose(p); return combo;}
    fseek(p,posicion*sizeof(Combo),SEEK_SET);
    fread(&combo,sizeof(Combo),1,p);
    fclose(p);
    return combo;
}

bool ComboArchivo::guardarRegistro(Combo combo)
{
    FILE*p=fopen("Archivos/Historico/CombosHistorico.dat","ab+");
    if(p==NULL){std::cout << "NO SE PUDO ABRIR EL ARCHIVO" ; return false;}
    bool escribio = fwrite(&combo,sizeof(Combo),1,p);
    fclose(p);
    return escribio;
}

bool ComboArchivo::modificarRegistro(Combo combo, int posicion)
{
    FILE*p=fopen("Archivos/Historico/CombosHistorico.dat","rb+");
    if(p==NULL){return false;}
    fseek(p,posicion*sizeof(Combo),SEEK_SET);
    bool escribio = fwrite(&combo,sizeof(Combo),1,p);
    fclose(p);
    return escribio;
}

int ComboArchivo::buscarRegistroPorCodigo(int codigo)
{
    int cantidad = getCantidadRegistros();
    Combo aux;
    for (int i=0; i<cantidad; i++){
        aux = leerRegistro(i);
        if(aux.getCodigo()==codigo){
            return i;
        }
    }
    return -1;
}

bool ComboArchivo::leerTodosLosRegistros(Combo combos[], int cantidad){
    FILE* p;
    p = fopen("Archivos/Historico/CombosHistorico.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fread(combos, sizeof(Combo), cantidad, p);
    fclose(p);
    return true;
}

int ComboArchivo::generarCodigo(){
    return getCantidadRegistros()+1;
}
