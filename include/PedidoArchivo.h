#ifndef PEDIDOARCHIVO_H
#define PEDIDOARCHIVO_H
#include "Pedido.h"
#include "Fecha.h"

class PedidoArchivo
{
    public:
        PedidoArchivo();
        virtual ~PedidoArchivo();

        Pedido leerRegistro(int pos);
        int getCantidadRegistros();

        int buscarAbiertoPorMesayFecha(int mesa, Fecha fecha);

        bool leerTodosLosRegistros(Pedido pedidos[], int cantidad);
        bool guardarRegistro(Pedido pedido);

        int contarPedidosPorTicket(int nroticket);
        void leerPedidosPorTicket(Pedido pedido[], int cantidad, int nroTicket);

        int generarNroPedido();

        bool modificarRegistro(Pedido pedido, int pos);
        bool cerrarPedidoPorTicket(int nroticket);

        int contarPedidosDeLaFecha(Fecha fecha);
        void leerTodosLosPedidosDeLaFecha(Pedido pedidos[], int cant, Fecha fecha);




    protected:

    private:
};

#endif // PEDIDOARCHIVO_H
