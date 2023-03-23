#ifndef INGDEHAMBURGUESAARCHIVO_H
#define INGDEHAMBURGUESAARCHIVO_H
#include "IngDeHambuguesa.h"

class IngDeHamburguesaArchivo
{
    public:
        IngDeHamburguesaArchivo();
        virtual ~IngDeHamburguesaArchivo();

        void getIngredientesDeHamburguesa(IngDeHambuguesa IDH[], int cantidad, int codigohamburguesa);
        IngDeHambuguesa leerIngredienteEspecifico(int codigoHamburguesa, int codigoIngrediente);
        IngDeHambuguesa leerRegistro(int posicion);

        bool guardar(IngDeHambuguesa ingdehamburguesa);

        int buscarIngrediente(int codigoHamburguesa, int codigoIngrediente);
        int getCantidadPorHamburguesa(int codigoHamburguesa);
        bool modificarIngrediente(IngDeHambuguesa IDH);

        int getCantidadRegistros();

        bool leerTodosLosRegistros(IngDeHambuguesa vecIDH[], int cantidad);

    protected:

    private:
};

#endif // INGDEHAMBURGUESAARCHIVO_H
