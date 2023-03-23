#ifndef BEBIDAARCHIVO_H
#define BEBIDAARCHIVO_H
#include "Bebida.h"

class BebidaArchivo
{
    public:
        BebidaArchivo();
        virtual ~BebidaArchivo();

        Bebida leerRegistro(int posicion);
        bool guardarRegistro(Bebida bebida);
        bool modificarRegistro(Bebida bebida, int posicion);
        int buscarRegistroPorCodigo(int codigo);
        int getCantidadRegistros();
        bool leerTodosLosRegistros(Bebida bebida[], int cantidad);
        int generarCodigo();

    protected:

    private:
};

#endif // BEBIDAARCHIVO_H
