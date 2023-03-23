#include <iostream>
#include "IngredienteArchivo.h"

IngredienteArchivo::IngredienteArchivo(){
}

IngredienteArchivo::~IngredienteArchivo(){
}

int IngredienteArchivo::getCantidadRegistros(){
    FILE*p = fopen("Archivos/Historico/IngredientesHistorico.dat","rb");
    if(p==NULL){fclose(p); return 0;}
    fseek(p,0,SEEK_END);
    int cantidad = ftell(p)/sizeof(Ingrediente);
    fclose(p);
    return cantidad;
    }

Ingrediente IngredienteArchivo::leerRegistro(int posicion)
{
    Ingrediente ingrediente;
    FILE*p = fopen("Archivos/Historico/IngredientesHistorico.dat","rb");
    if(p==NULL){fclose(p); return ingrediente;}
    fseek(p,posicion*sizeof(Ingrediente),SEEK_SET);
    fread(&ingrediente,sizeof(Ingrediente),1,p);
    fclose(p);
    return ingrediente;
}

bool IngredienteArchivo::guardarRegistro(Ingrediente ingrediente)
{
    FILE*p=fopen("Archivos/Historico/IngredientesHistorico.dat","ab+");
    if(p==NULL){return false;}
    bool escribio = fwrite(&ingrediente,sizeof(Ingrediente),1,p);
    fclose(p);
    return escribio;
}

bool IngredienteArchivo::modificarRegistro(Ingrediente ingrediente, int posicion)
{
    FILE*p=fopen("Archivos/Historico/IngredientesHistorico.dat","rb+");
    if(p==NULL){return false;}
    fseek(p,posicion*sizeof(Ingrediente),SEEK_SET);
    bool escribio = fwrite(&ingrediente,sizeof(Ingrediente),1,p);
    fclose(p);
    return escribio;
}

int IngredienteArchivo::buscarRegistroPorCodigo(int codigo)
{
    int cantidad = getCantidadRegistros();
    Ingrediente aux;
    for (int i=0; i<cantidad; i++){
        aux = leerRegistro(i);
        if(aux.getCodigo()==codigo){
            return i;
        }
    }
    return -1;
}

bool IngredienteArchivo::leerTodosLosRegistros(Ingrediente ingrediente[], int cantidad){
    FILE* p;
    p = fopen("Archivos/Historico/IngredientesHistorico.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fread(ingrediente, sizeof(Ingrediente), cantidad, p);
    fclose(p);
    return true;
}

int IngredienteArchivo::generarCodigo(){
    int nuevocodigo = getCantidadRegistros()+1;
    return nuevocodigo;
}
