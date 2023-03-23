#ifndef COMBODELDIA_H
#define COMBODELDIA_H
#include "Combo.h"
#include "Fecha.h"

class ComboDelDia : public Combo
{
    public:
        ComboDelDia();
        virtual ~ComboDelDia();

        Fecha getFecha();
        void setEstado(bool n);

        bool descontarStock();
        bool comprobarStock();
        bool getEstado();

    protected:

    private:
        Fecha _fecha;
        bool _estado;
};

#endif // COMBODELDIA_H
