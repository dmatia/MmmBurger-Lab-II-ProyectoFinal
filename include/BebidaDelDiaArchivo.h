#ifndef BEBIDADELDIAARCHIVO_H
#define BEBIDADELDIAARCHIVO_H
#include "BebidaDelDia.h"
#include "Fecha.h"


class BebidaDelDiaArchivo
{
    public:
        BebidaDelDiaArchivo();
        virtual ~BebidaDelDiaArchivo();

        BebidaDelDia leer(int pos);
        bool agregar(BebidaDelDia BebDelDia);
        int buscarPorCodigoyFecha(int codigo, Fecha fecha);
        bool modificarRegistro(BebidaDelDia BebDelDia, int posicion);
        int getCantidadRegistros();
        bool leerTodosLosRegistros(BebidaDelDia vecBeb[], int cantidad);

        int contarBebidasDeLaFecha();
        int leerTodosBebidasDeLaFecha(BebidaDelDia bdd[], int cant);

        int contarBebidasDeLaFecha(Fecha fecha);
        void leerTodosBebidasDeLaFecha(BebidaDelDia bdd[], int cant, Fecha fecha);

        bool descontarStock();

    protected:

    private:
};

#endif // BEBIDADELDIAARCHIVO_H
