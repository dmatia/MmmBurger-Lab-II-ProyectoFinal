#ifndef COMBODELDIAARCHIVO_H
#define COMBODELDIAARCHIVO_H
#include "ComboDelDia.h"
#include "Fecha.h"


class ComboDelDiaArchivo
{
    public:
        ComboDelDiaArchivo();
        virtual ~ComboDelDiaArchivo();

        ComboDelDia leer(int pos);
        bool agregar(ComboDelDia combdeldia);
        int buscarPorCodigoyFecha(int codigo, Fecha fecha);
        int getCantidadRegistros();
        bool leerTodosLosRegistros(ComboDelDia veccombo[], int cantidad);
        bool generarCombosDelDia();

        int contarCombosDeLaFecha();
        int leerTodosCombosDeLaFecha(ComboDelDia cdd[], int cant);

        int contarCombosDeLaFecha(Fecha fecha);
        void leerTodosCombosDeLaFecha(ComboDelDia cdd[], int cant, Fecha fecha);

        bool modificarRegistro(ComboDelDia cdd, int pos);

    protected:

    private:
};

#endif // COMBODELDIAARCHIVO_H
