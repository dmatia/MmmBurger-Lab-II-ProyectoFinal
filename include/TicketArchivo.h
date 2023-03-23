#ifndef TICKETARCHIVO_H
#define TICKETARCHIVO_H
#include "Fecha.h"
#include "Pedido.h"
#include "Ticket.h"

class TicketArchivo
{
    public:
        TicketArchivo();
        virtual ~TicketArchivo();

        Ticket leerRegistro(int pos);
        bool guardarRegistro(Ticket ticket);
        int getCantidadRegistros();
        int buscarTickerPorCodigo(int nroticket);
        int buscarTicketAbiertoPorMesayFecha(int nromesa, Fecha fecha);
        int generarNroTicket();
        bool actualizarTicket(Ticket ticket, int posicion);

        int contarTicketsAbiertos();
        void leerTodosLosTicketsAbiertos(Ticket ticket[], int cant);

        int contarTicketsDeLaFecha(Fecha fecha);

        void leerTodosLosTicketsDeLaFecha(Ticket tickets[], int cant, Fecha fecha);
        void leerTodosLosRegistros(Ticket tickets[], int cant);



    protected:

    private:
};

#endif // TICKETARCHIVO_H
