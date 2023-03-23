#ifndef HAMBURGUESAARCHIVO_H
#define HAMBURGUESAARCHIVO_H
#include "Hamburguesa.h"


class HamburguesaArchivo
{
    public:
        HamburguesaArchivo();
        virtual ~HamburguesaArchivo();

        Hamburguesa leerRegistro(int posicion);
        bool guardarRegistro(Hamburguesa hamburguesa);
        bool modificarRegistro(Hamburguesa hamburguesa, int posicion);
        int buscarRegistroPorCodigo(int codigo);
        int getCantidadRegistros();
        bool leerTodosLosRegistros(Hamburguesa hamburguesa[], int cantidad);
        int generarCodigo();

    protected:

    private:
};

#endif // HAMBURGUESAARCHIVO_H
