#include <iostream>
#include "PedidoArchivo.h"

PedidoArchivo::PedidoArchivo()
{
    //ctor
}

PedidoArchivo::~PedidoArchivo()
{
    //dtor
}

Pedido PedidoArchivo::leerRegistro(int posicion)
{
    Pedido pedido;
    FILE*p = fopen("Archivos/Caja/Pedidos.dat","rb");
    if(p==NULL){fclose(p); return pedido;}
    fseek(p,posicion*sizeof(Pedido),SEEK_SET);
    fread(&pedido,sizeof(Pedido),1,p);
    fclose(p);
    return pedido;
}

bool PedidoArchivo::modificarRegistro(Pedido pedido, int pos){
    FILE*p = fopen("Archivos/Caja/Pedidos.dat","rb+");
    if(p==NULL){return false;}
    fseek(p,sizeof(Pedido)*pos,SEEK_SET);
    bool modifico = fwrite(&pedido,sizeof(Pedido),1,p);
    fclose(p);
    return modifico;
}

int PedidoArchivo::getCantidadRegistros(){
    FILE*p = fopen("Archivos/Caja/Pedidos.dat", "rb");
    if(p==NULL){return 0;}
    fseek(p,0,SEEK_END);
    int cant = ftell(p)/sizeof(Pedido);
    fclose(p);
    return cant;
}

int PedidoArchivo::buscarAbiertoPorMesayFecha(int nromesa, Fecha fecha){
    int cantidad = getCantidadRegistros();
    Pedido aux;
    for (int i=0; i<cantidad; i++){
        aux = leerRegistro(i);
        if((aux.getNroMesa()==nromesa)&&(aux.getFecha()==fecha)&&(aux.getEstado()==true)) {
            return i;
        }
    }
    return -1;
}

bool PedidoArchivo::guardarRegistro(Pedido pedido)
{
    FILE*p=fopen("Archivos/Caja/Pedidos.dat","ab+");
    if(p==NULL){std::cout << "NO SE PUDO ABRIR EL ARCHIVO" ; return false;}
    bool escribio = fwrite(&pedido,sizeof(Pedido),1,p);
    fclose(p);
    return escribio;
}


bool PedidoArchivo::leerTodosLosRegistros(Pedido pedidos[], int cantidad){
    FILE* p;
    p = fopen("Archivos/Caja/Pedidos.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fread(pedidos, sizeof(Pedido), cantidad, p);
    fclose(p);
    return true;
}

int PedidoArchivo::contarPedidosPorTicket(int nroticket){
        Pedido aux;
        int cantidad = 0;
        for(int i=0; i<getCantidadRegistros(); i++){
            aux = leerRegistro(i);
            if(aux.getNroTicket()==nroticket){
                cantidad++;
            }
        }
            return cantidad;
        }

void PedidoArchivo::leerPedidosPorTicket(Pedido pedido[], int cantidad, int nroTicket){
        Pedido aux;
        int j=0;
        for(int i=0; i<getCantidadRegistros(); i++){
            aux = leerRegistro(i);
            if (aux.getNroTicket()==nroTicket){
                pedido[j] = aux;
                j++;
            }
        }/*
        std::cout << "---------------------------------" << std::endl;
        for(int i=0; i<cantidad; i++){
            std::cout << "COD PEDIDO " << pedido[i].getNroPedido() << std::endl;
            std::cout << "NRO TICKET: " << pedido[i].getNroTicket() << std::endl;
            std::cout << "COD HAMB" << pedido[i].getCodHamburguesa() << std::endl;
            std::cout << "COD BEB" << pedido[i].getCodBebida() << std::endl;
            std::cout << "COD COMB" << pedido[i].getCodCombo() << std::endl;
            std::cout << "****" << std::endl;
        }
        system("pause");*/

        }

int PedidoArchivo::generarNroPedido(){
    int nuevocodigo = getCantidadRegistros()+1;
    return nuevocodigo;
}

bool PedidoArchivo::cerrarPedidoPorTicket(int nroticket){
    Pedido aux;
    int cant = getCantidadRegistros();
    for (int i=0; i<cant; i++){
        aux = leerRegistro(i);
        if(aux.getNroTicket()==nroticket){
            aux.setEstado(false);
            modificarRegistro(aux, i);
        }
    }
    return true;
}


int PedidoArchivo::contarPedidosDeLaFecha(Fecha fecha){
    int cant = 0;
    Pedido aux;
    for(int i=0; i<getCantidadRegistros(); i++){
        aux = leerRegistro(i);
        if (aux.getFecha()==fecha){
            cant++;
        }
    }
    return cant;
}

void PedidoArchivo::leerTodosLosPedidosDeLaFecha(Pedido tickets[], int cant, Fecha fecha){
    int j = 0;
    Pedido aux;
    for(int i=0; i<getCantidadRegistros(); i++){
        aux = leerRegistro(i);
        if (aux.getFecha()==fecha){
            tickets[j] = aux;
            j++;
        }
    }

}

