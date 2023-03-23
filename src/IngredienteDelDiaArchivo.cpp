#include <iostream>
using namespace std;
#include "IngredienteDelDiaArchivo.h"

IngredienteDelDiaArchivo::IngredienteDelDiaArchivo()
{
    //ctor
}

IngredienteDelDiaArchivo::~IngredienteDelDiaArchivo()
{
    //dtor
}

IngredienteDelDia IngredienteDelDiaArchivo::leer(int pos)
{
    IngredienteDelDia IDD;
    FILE*p = fopen("Archivos/DelDia/IngredientesDelDia.dat","rb");
    if(p==NULL){fclose(p); return IDD;}
    fseek(p,pos*sizeof(IngredienteDelDia),SEEK_SET);
    fread(&IDD,sizeof(IngredienteDelDia),1,p);
    fclose(p);
    return IDD;
}

bool IngredienteDelDiaArchivo::agregar(IngredienteDelDia IngDelDia)
{   FILE*p=fopen("Archivos/DelDia/IngredientesDelDia.dat","ab+");
    if(p==NULL){std::cout << "NO SE PUDO ABRIR EL ARCHIVO" ; return false;}
    bool escribio = fwrite(&IngDelDia,sizeof(IngredienteDelDia),1,p);
    fclose(p);
    return escribio;
    }

int IngredienteDelDiaArchivo::buscarPorCodigoyFecha(int codigo, Fecha fecha)
{
    int cantidad = getCantidadRegistros();
    IngredienteDelDia aux;
    for (int i=0; i<cantidad; i++){
        aux = leer(i);
        if((aux.getCodigo()==codigo)&&(aux.getFecha()==fecha)){
            return i;
        }
    }
    return -1;

}

bool IngredienteDelDiaArchivo::modificarRegistro(IngredienteDelDia IngDelDia, int posicion)
{
    FILE*p=fopen("Archivos/DelDia/IngredientesDelDia.dat","rb+");
    if(p==NULL){return false;}
    fseek(p,posicion*sizeof(IngredienteDelDia),SEEK_SET);
    bool escribio = fwrite(&IngDelDia,sizeof(IngredienteDelDia),1,p);
    fclose(p);
    return escribio;
}

int IngredienteDelDiaArchivo::getCantidadRegistros(){
    FILE*p = fopen("Archivos/DelDia/IngredientesDelDia.dat","rb");
    if(p==NULL){fclose(p); return 0;}
    fseek(p,0,SEEK_END);
    int cantidad = ftell(p)/sizeof(IngredienteDelDia);
    fclose(p);
    return cantidad;
    }

    bool IngredienteDelDiaArchivo::leerTodosLosRegistros(IngredienteDelDia vecIng[], int cantidad){
    FILE* p;
    p = fopen("Archivos/DelDia/IngredientesDelDia.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fread(vecIng, sizeof(IngredienteDelDia), cantidad, p);
    fclose(p);
    return true;
}

int IngredienteDelDiaArchivo::contarIngredientesDeLaFecha(){
    int cantIng = getCantidadRegistros(), contador=0;
    IngredienteDelDia idd;
    Fecha fecha;
    for(int i=0; i<cantIng; i++){
        idd = leer(i);
        if(idd.getFecha()==fecha){contador++;}
    }
    return contador;
    }

int IngredienteDelDiaArchivo::contarIngredientesDeLaFecha(Fecha fecha){
    int cantIng = getCantidadRegistros(), contador=0;
    IngredienteDelDia idd;
    for(int i=0; i<cantIng; i++){
        idd = leer(i);
        if(idd.getFecha()==fecha){contador++;}
    }
    return contador;
    }

    int IngredienteDelDiaArchivo::leerTodosIngredientesDeLaFecha(IngredienteDelDia idd[], int cant)
    {
        IngredienteDelDia aux;
        int j = 0;
        Fecha fecha;
        for(int i=0; i<getCantidadRegistros(); i++){
            aux = leer(i);
            if(aux.getFecha()==fecha){
                idd[j]=aux;
                j++;
            }
        }
        return 1;
    }

 void IngredienteDelDiaArchivo::leerTodosIngredientesDeLaFecha(IngredienteDelDia idd[], int cant, Fecha fecha)
    {
        IngredienteDelDia aux;
        int j = 0;
        for(int i=0; i<getCantidadRegistros(); i++){
            aux = leer(i);
            if(aux.getFecha()==fecha){
                idd[j]=aux;
                j++;
            }
        }
    }
