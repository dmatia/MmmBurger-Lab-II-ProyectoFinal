#ifndef CAJA_H
#define CAJA_H
#include "Ticket.h"


class Caja
{
    public:
        Caja();
        virtual ~Caja();

        bool agregarPedido();
        bool menuPedido(Ticket &ticket);
        bool agregarHamburguesaAPedido(Ticket &ticket);
        bool agregarBebidaAPedido(Ticket &ticket);
        bool agregarComboAPedido(Ticket &ticket);

        bool cerrarTicket(int &renglon);

        void verTicketsAbiertos();

        void verProductosDisponibles();

    protected:

    private:
};

#endif // CAJA_H
