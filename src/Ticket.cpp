#include <iostream>
using namespace std;
#include "Ticket.h"
#include "Pedido.h"
#include "PedidoArchivo.h"

#include "HamburguesaDelDia.h"
#include "HamburguesaDelDiaArchivo.h"

#include "BebidaDelDia.h"
#include "BebidaDelDiaArchivo.h"

#include "ComboDelDia.h"
#include "ComboDelDiaArchivo.h"

Ticket::Ticket()
{
    _estado = true;
    _nroDeTicket = -1;
    _total = 0;
}

Ticket::~Ticket()
{
    //dtor
}

Fecha Ticket::getFecha(){
    return _fecha;
    }


int Ticket::getNroDeTicket(){
    return _nroDeTicket;
    }

int Ticket::getNroMesa(){
    return _nroMesa;
    }

void Ticket::setNroTicket(int nroticket)
{
        _nroDeTicket = nroticket;
}

void Ticket::setNroMesa(int nromesa){
    _nroMesa = nromesa;}

Hora Ticket::getHora()
{
    return _hora;
}

bool Ticket::getEstado(){
    return _estado;}

    void Ticket::setEstado(bool estado)
    {
        _estado = estado;
    }

    float Ticket::getTotal()
    {
        return _total;
    }

bool Ticket::agregarPedido(int tipo, int codigo){
    PedidoArchivo PA;
    Pedido aux;
    aux.setEstado(true);
    aux.setNroTicket(_nroDeTicket);
    aux.setNroMesa(_nroMesa);
    aux.setNroPedido(PA.generarNroPedido());

    if(tipo==1){
            aux.setCodHamburguesa(codigo);
            HamburguesaDelDia hdd;
            HamburguesaDelDiaArchivo HDDA;
            hdd = HDDA.leer(HDDA.buscarPorCodigoyFecha(codigo,aux.getFecha()));
            hdd.descontarStock();
            _total+= hdd.getPrecio();
    }
    if(tipo==2){
            aux.setCodBebida(codigo);
            BebidaDelDia bdd;
            BebidaDelDiaArchivo BDDA;
            bdd = BDDA.leer(BDDA.buscarPorCodigoyFecha(codigo,aux.getFecha()));
            bdd.descontarStock();
            BDDA.modificarRegistro(bdd,BDDA.buscarPorCodigoyFecha(codigo, aux.getFecha()));
            _total+= bdd.getPrecio();
    }
    if(tipo==3){
            aux.setCodCombo(codigo);
            ComboDelDia cdd;
            ComboDelDiaArchivo CDDA;
            cdd = CDDA.leer(CDDA.buscarPorCodigoyFecha(codigo,aux.getFecha()));
            cdd.descontarStock();
            _total+= cdd.getPrecio();
    }
    PA.guardarRegistro(aux);
    return true;
}


