#include <iostream>
#include "TicketArchivo.h"

TicketArchivo::TicketArchivo()
{
    //ctor
}

TicketArchivo::~TicketArchivo()
{
    //dtor
}

Ticket TicketArchivo::leerRegistro(int pos){
    Ticket ticket;
    FILE*p = fopen("Archivos/Caja/Tickets.dat","rb");
    if(p==NULL){fclose(p); return ticket;}
    fseek(p,pos*sizeof(Ticket),SEEK_SET);
    fread(&ticket,sizeof(Ticket),1,p);
    fclose(p);
    return ticket;
    }

    int TicketArchivo::getCantidadRegistros(){
    FILE*p = fopen("Archivos/Caja/Tickets.dat","rb");
    if(p==NULL){fclose(p); return 0;}
    fseek(p,0,SEEK_END);
    int cantidad = ftell(p)/sizeof(Ticket);
    fclose(p);
    return cantidad;
    }

int TicketArchivo::buscarTicketAbiertoPorMesayFecha(int nromesa, Fecha fecha)
{
    int cantidad = getCantidadRegistros();
    Ticket aux;
    for (int i=0; i<cantidad; i++){
        aux = leerRegistro(i);
        if((aux.getNroMesa()==nromesa)
           &&(aux.getFecha()==fecha)
            &&(aux.getEstado()==true)){
            return i;
        }
    }
    return -1;
}

int TicketArchivo::generarNroTicket(){
    int nuevocodigo = getCantidadRegistros()+1;
    return nuevocodigo;
}

bool TicketArchivo::guardarRegistro(Ticket ticket)
{
    FILE*p=fopen("Archivos/Caja/Tickets.dat","ab+");
    if(p==NULL){return false;}
    bool escribio = fwrite(&ticket,sizeof(Ticket),1,p);
    fclose(p);
    return escribio;
}

bool TicketArchivo::actualizarTicket(Ticket ticket, int posicion)
{
    FILE*p=fopen("Archivos/Caja/Tickets.dat","rb+");
    if(p==NULL){return false;}
    fseek(p,posicion*sizeof(Ticket),SEEK_SET);
    bool escribio = fwrite(&ticket, sizeof(Ticket),1,p);
    fclose(p);
    return escribio;
}

int TicketArchivo::contarTicketsAbiertos(){
        int contador = 0;
        Ticket aux;
        for(int i=0; i<getCantidadRegistros(); i++){
            aux = leerRegistro(i);
            if(aux.getEstado()==true){
                contador++;
            }
        }
    return contador;
}

void TicketArchivo::leerTodosLosTicketsAbiertos(Ticket ticket[], int cant){
        Ticket aux;
        int j=0;
        for(int i=0; i<getCantidadRegistros(); i++){
            aux = leerRegistro(i);
            if(aux.getEstado()==true){
                ticket[j] = aux;
                j++;
            }
        }
}

int TicketArchivo::buscarTickerPorCodigo(int nroticket){
    int cantidad = getCantidadRegistros();
    Ticket aux;
    for (int i=0; i<cantidad; i++){
        aux = leerRegistro(i);
        if((aux.getNroDeTicket()==nroticket)){
            return i;
        }
    }
    return -1;
}


int TicketArchivo::contarTicketsDeLaFecha(Fecha fecha){
    int cant = 0;
    Ticket aux;
    for(int i=0; i<getCantidadRegistros(); i++){
        aux = leerRegistro(i);
        if (aux.getFecha()==fecha){
            cant++;
        }
    }
    return cant;
}

void TicketArchivo::leerTodosLosTicketsDeLaFecha(Ticket tickets[], int cant, Fecha fecha){
    int j = 0;
    Ticket aux;
    for(int i=0; i<getCantidadRegistros(); i++){
        aux = leerRegistro(i);
        if (aux.getFecha()==fecha){
            tickets[j] = aux;
            j++;
        }
    }

}

void TicketArchivo::leerTodosLosRegistros(Ticket tickets[], int cant){
        for(int i=0; i<getCantidadRegistros(); i++){
            tickets[i] = leerRegistro(i);
        }
        }
