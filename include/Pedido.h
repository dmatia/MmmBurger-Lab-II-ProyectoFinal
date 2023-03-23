#ifndef PEDIDO_H
#define PEDIDO_H
#include "Hora.h"
#include "Fecha.h"


class Pedido
{
    public:
        Pedido();
        virtual ~Pedido();

        void setCodHamburguesa(int codham);
        void setCodBebida(int codbeb);
        void setCodCombo(int codcomb);
        void setNroTicket(int nroticket);
        void setNroMesa(int nromesa);
        void setEstado(bool estado);
        void setNroPedido(int nropedido);

        Fecha getFecha();
        int getNroPedido();
        int getCodHamburguesa();
        int getCodBebida();
        int getCodCombo();
        int getNroMesa();
        int getNroTicket();
        bool getEstado();




    protected:

    private:
        Fecha _fecha;
        int _codHamburguesa;
        int _codBebida;
        int _codCombo;
        int _nroticket;
        int _nroPedido;
        int _nroMesa;
        bool _estado;
};

#endif // PEDIDO_H
