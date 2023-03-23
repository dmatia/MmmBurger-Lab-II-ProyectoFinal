#ifndef INGREDIENTEDELDIAARCHIVO_H
#define INGREDIENTEDELDIAARCHIVO_H
#include "IngredienteDelDia.h"


class IngredienteDelDiaArchivo
{
    public:
        IngredienteDelDiaArchivo();
        virtual ~IngredienteDelDiaArchivo();

        IngredienteDelDia leer(int pos);
        bool agregar(IngredienteDelDia IngDelDia);
        int buscarPorCodigoyFecha(int codigo, Fecha fecha);
        bool modificarRegistro(IngredienteDelDia IngDelDia, int posicion);
        int getCantidadRegistros();
        bool leerTodosLosRegistros(IngredienteDelDia vecIng[], int cantidad);

        int contarIngredientesDeLaFecha();
        int leerTodosIngredientesDeLaFecha(IngredienteDelDia idd[], int cant);
        int contarIngredientesDeLaFecha(Fecha fecha);
        void leerTodosIngredientesDeLaFecha(IngredienteDelDia idd[], int cant, Fecha fecha);

    protected:

    private:
};

#endif // INGREDIENTEDELDIAARCHIVO_H
