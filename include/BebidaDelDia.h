#ifndef BEBIDADELDIA_H
#define BEBIDADELDIA_H
#include <Bebida.h>
#include "Fecha.h"


class BebidaDelDia : public Bebida
{
    public:
        BebidaDelDia();
        virtual ~BebidaDelDia();

        void setStockInicial(int stockinicial);
        void setEstado(bool n);

        void agregarStock(int stockaagregar);
        int getStockInicial();
        int getStockFinal();
        Fecha getFecha();
        bool getEstado();
        bool descontarStock();
        bool descontarStock(int cant);
        bool descontarStockAdm(int cant);
        bool comprobarStock();

    protected:

    private:
        Fecha _fecha;
        bool _estado;
        int _stockInicial;
        int _stockFinal;
};

#endif // BEBIDADELDIA_H
