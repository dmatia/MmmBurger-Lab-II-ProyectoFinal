#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include "Hamburguesa.h"


class Administrador
{
    public:
        Administrador();
        virtual ~Administrador();

        bool agregarNuevoIngrediente();
        bool agregarNuevaBebida();
        bool agregarNuevaHamburguesa();
        bool cargarIngredientesDeHamburguesa(Hamburguesa &nuevahamburguesa);
        bool agregarNuevoCombo();

        bool verificarIngrediente(int codigohamburguesa, int codigoingrediente);

        bool cargarIngredientesDelDia();
        bool cargarBebidasDelDia();

       // bool agregarStockAIngredienteDeLaFecha();

        bool modificarIngrediente();
        bool modificarBebida();
        bool modificarHamburguesa();
        bool modificarIngredienteHamburguesa(int codham);
        bool modificarCombo();

        bool agregarStockIngDelDia();
        bool agregarStockBebDelDia();

        bool backupmenu();

        bool menuReportes();

        bool cambiarContrasenia();
        bool verificarContrasenia();

    protected:

    private:
};

#endif // ADMINISTRADOR_H
