#include <iostream>
#include "Pedido.h"
#include "PedidoArchivo.h"

Pedido::Pedido()
{
    _codBebida = -1;
    _codCombo = -1;
    _codHamburguesa = -1;
    _nroMesa = -1;
    _nroticket = -1;
    _estado = true;
}

Pedido::~Pedido()
{
    //dtor
}

void Pedido::setCodHamburguesa(int codham)
{
    _codHamburguesa = codham;
}

void Pedido::setCodBebida(int codbeb)
{
    _codBebida = codbeb;
}

void Pedido::setCodCombo(int codcomb)
{
    _codCombo = codcomb;
}

void Pedido::setNroTicket(int nroticket)
{
    _nroticket = nroticket;
}

void Pedido::setNroMesa(int nromesa)
{
    _nroMesa = nromesa;
}

void Pedido::setEstado(bool estado)
{
    _estado = estado;
}

Fecha Pedido::getFecha()
{
        return _fecha;
}

int Pedido::getCodHamburguesa()
{
    return _codHamburguesa;
}

int Pedido::getCodBebida()
{
    return _codBebida;
}

int Pedido::getCodCombo()
{
    return _codCombo;
}

int Pedido::getNroMesa()
{
    return _nroMesa;
}

int Pedido::getNroTicket()
{
    return _nroticket;
}

bool Pedido::getEstado()
{
    return _estado;
}

void Pedido::setNroPedido(int nropedido)
{
    _nroPedido = nropedido;
}

int Pedido::getNroPedido()
{
    return _nroPedido;
}
