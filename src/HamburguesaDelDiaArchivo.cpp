#include <iostream>
using namespace std;
#include "HamburguesaDelDiaArchivo.h"
#include "IngredienteDelDia.h"
#include "IngredienteDelDiaArchivo.h"
#include "IngDeHamburguesaArchivo.h"
#include "IngDeHambuguesa.h"
#include "Hamburguesa.h"
#include "HamburguesaArchivo.h"

HamburguesaDelDiaArchivo::HamburguesaDelDiaArchivo()
{
    //ctor
}

HamburguesaDelDiaArchivo::~HamburguesaDelDiaArchivo()
{
    //dtor
}


HamburguesaDelDia HamburguesaDelDiaArchivo::leer(int pos)
{
    HamburguesaDelDia HDD;
    FILE*p = fopen("Archivos/DelDia/HamburguesasDelDia.dat","rb");
    if(p==NULL){fclose(p); return HDD;}
    fseek(p,pos*sizeof(HamburguesaDelDia),SEEK_SET);
    fread(&HDD,sizeof(HamburguesaDelDia),1,p);
    fclose(p);
    return HDD;
}

bool HamburguesaDelDiaArchivo::agregar(HamburguesaDelDia hamdeldia)
{   FILE*p=fopen("Archivos/DelDia/HamburguesasDelDia.dat","ab+");
    if(p==NULL){return false;}
    bool escribio = fwrite(&hamdeldia,sizeof(HamburguesaDelDia),1,p);
    fclose(p);
    return escribio;
    }

int HamburguesaDelDiaArchivo::buscarPorCodigoyFecha(int codigo, Fecha fecha)
{
    int cantidad = getCantidadRegistros();
    HamburguesaDelDia aux;
    for (int i=0; i<cantidad; i++){
        aux = leer(i);
        if((aux.getCodigo()==codigo)&&(aux.getFecha()==fecha)){
            return i;
        }
    }
    return -1;

}


int HamburguesaDelDiaArchivo::getCantidadRegistros(){
    FILE*p = fopen("Archivos/DelDia/HamburguesasDelDia.dat","rb");
    if(p==NULL){fclose(p); return 0;}
    fseek(p,0,SEEK_END);
    int cantidad = ftell(p)/sizeof(HamburguesaDelDia);
    fclose(p);
    return cantidad;
    }

    bool HamburguesaDelDiaArchivo::leerTodosLosRegistros(HamburguesaDelDia vecham[], int cantidad){
    FILE* p;
    p = fopen("Archivos/DelDia/HamburguesasDelDia.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fread(vecham, sizeof(HamburguesaDelDia), cantidad, p);
    fclose(p);
    return true;
}

bool HamburguesaDelDiaArchivo::generarHamburguesasDelDia(){
    IngDeHamburguesaArchivo IDHA;
    int cantIDH = IDHA.getCantidadRegistros();

    IngDeHambuguesa *vecIDH = new IngDeHambuguesa[cantIDH];
    if(vecIDH==nullptr){std::cout << "ERROR AL CREAR VECTOR DINAMICO" << std::endl; return false;}
    IDHA.leerTodosLosRegistros(vecIDH, cantIDH);

    IngredienteDelDiaArchivo IDDA;
    int cantIDD = IDDA.contarIngredientesDeLaFecha();
    IngredienteDelDia *vecIDD = new IngredienteDelDia[cantIDD];
    if(vecIDD==nullptr){std::cout << "ERROR AL CREAR VECTOR DINAMICO" << std::endl; delete[]vecIDH; return false;}
    IDDA.leerTodosIngredientesDeLaFecha(vecIDD, cantIDD);

    HamburguesaArchivo HA;
    int cantHam = HA.getCantidadRegistros();

    Hamburguesa *vecHamb = new Hamburguesa[cantHam];
    if(vecHamb==nullptr){std::cout << "ERROR AL CREAR VECTOR DINAMICO" << std::endl; delete[]vecIDH; delete[]vecIDD; return false;}
    HA.leerTodosLosRegistros(vecHamb, cantHam);


    for(int i=0; i<cantHam; i++){
            int contadoring = 0;
            for(int j=0; j<cantIDH; j++){

                if(vecHamb[i].getCodigo() == vecIDH[j].getCodigoHamburguesa()){

                    for(int x=0; x<cantIDD; x++){
                        if (vecIDH[j].getCodigoIngrediente()==vecIDD[x].getCodigo()){
                            contadoring++;
                        }
                    }
                }
            }
            if (IDHA.getCantidadPorHamburguesa(vecHamb[i].getCodigo())==contadoring){
                HamburguesaDelDia aux;
                aux.setCodigo(vecHamb[i].getCodigo());
                aux.setNombre(vecHamb[i].getNombre());
                aux.setPrecio(vecHamb[i].getPrecio());
                aux.setEstado(true);
                if(buscarPorCodigoyFecha(vecHamb[i].getCodigo(),aux.getFecha())==-1){agregar(aux);}
            }
    }

     delete[]vecIDD;
     delete[]vecHamb;
     delete[]vecIDH;
    return true;
}


int HamburguesaDelDiaArchivo::contarHamburguesasDeLaFecha(){
    int cantIng = getCantidadRegistros(), contador=0;
    HamburguesaDelDia hdd;
    Fecha fecha;
    for(int i=0; i<cantIng; i++){
        hdd = leer(i);
        if(hdd.getFecha()==fecha){contador++;}
    }
    return contador;
    }

    int HamburguesaDelDiaArchivo::leerTodosHamburguesasDeLaFecha(HamburguesaDelDia hdd[], int cant)
    {
    HamburguesaDelDia aux;
        int j = 0;
        Fecha fecha;
        for(int i=0; i<getCantidadRegistros(); i++){
            aux = leer(i);
            if(aux.getFecha()==fecha){
                hdd[j]=aux;
                j++;
            }
        }
        return 1;
    }


    bool HamburguesaDelDiaArchivo::modificarRegistro(HamburguesaDelDia hdd, int pos)
    {
    FILE*p=fopen("Archivos/DelDia/HamburguesasDelDia.dat","rb+");
    if(p==NULL){return false;}
    fseek(p,pos*sizeof(HamburguesaDelDia),SEEK_SET);
    bool escribio = fwrite(&hdd, sizeof(HamburguesaDelDia),1,p);
    fclose(p);
    return escribio;
    }


int HamburguesaDelDiaArchivo::contarHamburguesasDeLaFecha(Fecha fecha){
    int cantIng = getCantidadRegistros(), contador=0;
    HamburguesaDelDia hdd;
    for(int i=0; i<cantIng; i++){
        hdd = leer(i);
        if(hdd.getFecha()==fecha){contador++;}
    }
    return contador;
    }

void HamburguesaDelDiaArchivo::leerTodosHamburguesasDeLaFecha(HamburguesaDelDia hdd[], int cant, Fecha fecha)
    {
    HamburguesaDelDia aux;
        int j = 0;
        for(int i=0; i<getCantidadRegistros(); i++){
            aux = leer(i);
            if(aux.getFecha()==fecha){
                hdd[j]=aux;
                j++;
            }
        }
    }
