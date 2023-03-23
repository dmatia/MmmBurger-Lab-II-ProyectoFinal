#include <iostream>
using namespace std;
#include "ManejoArchivos.h"
#include "IngredienteDelDia.h"
#include "BebidaDelDia.h"
#include "HamburguesaDelDia.h"
#include "ComboDelDia.h"
#include "Ticket.h"
#include "Pedido.h"

ManejoArchivos::ManejoArchivos()
{
    //ctor
}

ManejoArchivos::~ManejoArchivos()
{
    //dtor
}

bool ManejoArchivos::comprobarArchivo(char *filename){
    FILE*p;
    p=fopen(filename, "rb");
    if(p==NULL){return false;}
    else {fclose(p); return true;}
}

bool ManejoArchivos::backupIngDelDia(){
        FILE * p1 = fopen("Archivos/DelDia/BACKUP/backupIngDelDia.dat","ab+");
        if(p1==NULL){std::cout<<"ERROR AL ABRIR BACK UP ING DEL DIA" <<std::endl; return false;}
        FILE * p2 = fopen("Archivos/DelDia/IngredientesDelDia.dat","rb");
        if(p2==NULL){std::cout<<"ERROR AL ABRIR BACK UP ING DEL DIA" <<std::endl; fclose(p1); return false;}
        IngredienteDelDia IDD;
        fseek(p1,0,SEEK_END);
        int cantidadp1 = ftell(p1)/sizeof(IngredienteDelDia);
        fseek(p2,cantidadp1*sizeof(IngredienteDelDia),SEEK_SET);
        while(fread(&IDD,sizeof(IngredienteDelDia),1,p2)){
              fwrite(&IDD,sizeof(IngredienteDelDia),1,p1);}
        fclose(p1);
        fclose(p2);
    }

bool ManejoArchivos::backupBebDelDia(){
        FILE * p1 = fopen("Archivos/DelDia/BACKUP/backupBebDelDia.dat","ab+");
        if(p1==NULL){return false;}
        FILE * p2 = fopen("Archivos/DelDia/BebidasDelDia.dat","rb");
        if(p2==NULL){fclose(p1); return false;}
        BebidaDelDia BDD;
        fseek(p1,0,SEEK_END);
        int cantidadp1 = ftell(p1)/sizeof(BebidaDelDia);
        fseek(p2,cantidadp1*sizeof(BebidaDelDia),SEEK_SET);
        while(fread(&BDD,sizeof(BebidaDelDia),1,p2)){
              fwrite(&BDD,sizeof(BebidaDelDia),1,p1);}
        fclose(p1);
        fclose(p2);
    }

bool ManejoArchivos::backupHamDelDia(){
        FILE * p1 = fopen("Archivos/DelDia/BACKUP/backupHamDelDia.dat","ab+");
        if(p1==NULL){return false;}
        FILE * p2 = fopen("Archivos/DelDia/HamburguesasDelDia.dat","rb");
        if(p2==NULL){fclose(p1); return false;}
        HamburguesaDelDia HDD;
        fseek(p1,0,SEEK_END);
        int cantidadp1 = ftell(p1)/sizeof(HamburguesaDelDia);
        fseek(p2,cantidadp1*sizeof(HamburguesaDelDia),SEEK_SET);
        while(fread(&HDD,sizeof(HamburguesaDelDia),1,p2)){
              fwrite(&HDD,sizeof(HamburguesaDelDia),1,p1);}
        fclose(p1);
        fclose(p2);
    }

bool ManejoArchivos::backupComDelDia(){
        FILE * p1 = fopen("Archivos/DelDia/BACKUP/backupComDelDia.dat","ab+");
        if(p1==NULL){return false;}
        FILE * p2 = fopen("Archivos/DelDia/CombosDelDia.dat","rb");
        if(p2==NULL){fclose(p1); return false;}
        ComboDelDia CDD;
        fseek(p1,0,SEEK_END);
        int cantidadp1 = ftell(p1)/sizeof(ComboDelDia);
        fseek(p2,cantidadp1*sizeof(ComboDelDia),SEEK_SET);
        while(fread(&CDD,sizeof(ComboDelDia),1,p2)){
              fwrite(&CDD,sizeof(ComboDelDia),1,p1);}
        fclose(p1);
        fclose(p2);
    }


bool ManejoArchivos::backupTickets(){
        FILE * p1 = fopen("Archivos/Caja/BACKUP/backupTickets.dat","ab+");
        if(p1==NULL){return false;}
        FILE * p2 = fopen("Archivos/Caja/Tickets.dat","rb");
        if(p2==NULL){fclose(p1); return false;}
        Ticket tkt;
        fseek(p1,0,SEEK_END);
        int cantidadp1 = ftell(p1)/sizeof(Ticket);
        fseek(p2,cantidadp1*sizeof(Ticket),SEEK_SET);
        while(fread(&tkt,sizeof(Ticket),1,p2)){
              fwrite(&tkt,sizeof(Ticket),1,p1);}
        fclose(p1);
        fclose(p2);
    }

bool ManejoArchivos::backupPedidos(){
        FILE * p1 = fopen("Archivos/Caja/BACKUP/backupPedidos.dat","ab+");
        if(p1==NULL){return false;}
        FILE * p2 = fopen("Archivos/Caja/Pedidos.dat","rb");
        if(p2==NULL){fclose(p1); return false;}
        Pedido pedido;
        fseek(p1,0,SEEK_END);
        int cantidadp1 = ftell(p1)/sizeof(Pedido);
        fseek(p2,cantidadp1*sizeof(Pedido),SEEK_SET);
        while(fread(&pedido,sizeof(Pedido),1,p2)){
              fwrite(&pedido,sizeof(Pedido),1,p1);}
        fclose(p1);
        fclose(p2);
    }

bool ManejoArchivos::recuperarIngDelDia()
{
    FILE * p1 = fopen("Archivos/DelDia/BACKUP/backupIngDelDia.dat","rb");
    if(p1==NULL){return false;}

    FILE * p2 = fopen("Archivos/DelDia/IngredientesDelDia.dat", "wb+");
    if(p2==NULL){fclose(p1); return false;}

    IngredienteDelDia IDD;
    while(fread(&IDD,sizeof(IngredienteDelDia),1,p1)){
          fwrite(&IDD,sizeof(IngredienteDelDia),1,p2);}

    fclose(p1);
    fclose(p2);
    return true;
}

bool ManejoArchivos::recuperarBebDelDia()
{
    FILE * p1 = fopen("Archivos/DelDia/BACKUP/backupBebDelDia.dat","rb");
    if(p1==NULL){return false;}

    FILE * p2 = fopen("Archivos/DelDia/BebidasDelDia.dat", "wb+");
    if(p2==NULL){fclose(p1); return false;}

    BebidaDelDia BDD;
    while(fread(&BDD,sizeof(BebidaDelDia),1,p1)){
          fwrite(&BDD,sizeof(BebidaDelDia),1,p2);}

    fclose(p1);
    fclose(p2);
    return true;
}

bool ManejoArchivos::recuperarHamDelDia()
{
    FILE * p1 = fopen("Archivos/DelDia/BACKUP/backupHamDelDia.dat","rb");
    if(p1==NULL){return false;}

    FILE * p2 = fopen("Archivos/DelDia/CombosDelDia.dat", "wb+");
    if(p2==NULL){fclose(p1); return false;}

    ComboDelDia CDD;
    while(fread(&CDD,sizeof(ComboDelDia),1,p1)){
          fwrite(&CDD,sizeof(ComboDelDia),1,p2);}

    fclose(p1);
    fclose(p2);
    return true;
}

bool ManejoArchivos::recuperarComDelDia()
{
    FILE * p1 = fopen("Archivos/DelDia/BACKUP/backupComDelDia.dat","rb");
    if(p1==NULL){return false;}

    FILE * p2 = fopen("Archivos/DelDia/CombosDelDia.dat", "wb+");
    if(p2==NULL){fclose(p1); return false;}

    ComboDelDia CDD;
    while(fread(&CDD,sizeof(ComboDelDia),1,p1)){
          fwrite(&CDD,sizeof(ComboDelDia),1,p2);}

    fclose(p1);
    fclose(p2);
    return true;
}

bool ManejoArchivos::recuperarTickets()
{
    FILE * p1 = fopen("Archivos/Caja/BACKUP/backupTickets.dat","rb");
    if(p1==NULL){return false;}

    FILE * p2 = fopen("Archivos/Caja/Tickets.dat", "wb+");
    if(p2==NULL){fclose(p1); return false;}

    Ticket tkt;
    while(fread(&tkt,sizeof(Ticket),1,p1)){
          fwrite(&tkt,sizeof(Ticket),1,p2);}

    fclose(p1);
    fclose(p2);
    return true;
}

bool ManejoArchivos::recuperarPedidos()
{
    FILE * p1 = fopen("Archivos/Caja/BACKUP/backupPedidos.dat","rb");
    if(p1==NULL){return false;}

    FILE * p2 = fopen("Archivos/Caja/Pedidos.dat", "wb+");
    if(p2==NULL){fclose(p1); return false;}

    Pedido ped;
    while(fread(&ped,sizeof(Pedido),1,p1)){
          fwrite(&ped,sizeof(Pedido),1,p2);}

    fclose(p1);
    fclose(p2);
    return true;
}
