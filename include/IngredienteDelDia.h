#ifndef INGREDIENTEDELDIA_H
#define INGREDIENTEDELDIA_H
#include "Fecha.h"
#include <Ingrediente.h>


class IngredienteDelDia : public Ingrediente
{
    public:
        IngredienteDelDia();
        virtual ~IngredienteDelDia();

        void setStockInicial(int stockinicial);
        void agregarStock(int stockaagregar);
        void setEstado(bool n);

        int getStockInicial();
        int getStockFinal();
        Fecha getFecha();
        bool getEstado();

        bool descontarStock(int cant);
        bool descontarStockAdm(int cant);

        bool comprobarStock();



    protected:

    private:
        Fecha _fecha;
        int _stockInicial;
        int _stockFinal;
        bool _estado;
};

#endif // INGREDIENTEDELDIA_H
