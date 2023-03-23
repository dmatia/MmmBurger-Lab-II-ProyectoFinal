#ifndef COMBOARCHIVO_H
#define COMBOARCHIVO_H
#include "Combo.h"


class ComboArchivo
{
    public:
        ComboArchivo();
        virtual ~ComboArchivo();

        Combo leerRegistro(int posicion);
        bool guardarRegistro(Combo combo);
        bool modificarRegistro(Combo combo, int posicion);
        int buscarRegistroPorCodigo(int codigo);
        int getCantidadRegistros();
        bool leerTodosLosRegistros(Combo combos[], int cantidad);
        int generarCodigo();

    protected:

    private:
};

#endif // COMBOARCHIVO_H
