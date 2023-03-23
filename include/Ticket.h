#ifndef TICKET_H
#define TICKET_H
#include "Fecha.h"
#include "Hora.h"
//#include "Pedido.h"

class Ticket
{
    public:
        Ticket();
        virtual ~Ticket();

        void setNroTicket(int nroticket);
        void setEstado(bool estado);
        void setNroMesa(int nromesa);

        Fecha getFecha();
        Hora getHora();
        int getNroDeTicket();
        int getNroMesa();
        bool getEstado();
        float getTotal();

        bool agregarPedido(int tipo, int codigo);


    protected:

    private:
        Fecha _fecha;
        Hora _hora;
        int _nroDeTicket;
        int _nroMesa;
        float _total;
        bool _estado;
};

#endif // TICKET_H
