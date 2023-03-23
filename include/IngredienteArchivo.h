#ifndef INGREDIENTEARCHIVO_H
#define INGREDIENTEARCHIVO_H
#include "Ingrediente.h"

class IngredienteArchivo
{
    public:
        IngredienteArchivo();
        virtual ~IngredienteArchivo();

        Ingrediente leerRegistro(int posicion);
        bool guardarRegistro(Ingrediente ingrediente);
        bool modificarRegistro(Ingrediente ingrediente, int posicion);
        int buscarRegistroPorCodigo(int codigo);
        int getCantidadRegistros();
        bool leerTodosLosRegistros(Ingrediente ingrediente[], int cantidad);
        int generarCodigo();

    protected:

    private:
};

#endif // INGREDIENTEARCHIVO_H
