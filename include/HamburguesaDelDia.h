#ifndef HAMBURGUESADELDIA_H
#define HAMBURGUESADELDIA_H
#include "Fecha.h"
#include "Hamburguesa.h"


class HamburguesaDelDia : public Hamburguesa
{
    public:
        HamburguesaDelDia();
        virtual ~HamburguesaDelDia();
        void setEstado(bool estado);
        Fecha getFecha();
        bool descontarStock();
        bool verificarIngredientesDisponibles();
        bool getEstado();


    protected:

    private:
        Fecha _fecha;
        bool _estado;
};

#endif // HAMBURGUESADELDIA_H
