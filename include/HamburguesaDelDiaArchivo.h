#ifndef HAMBURGUESADELDIAARCHIVO_H
#define HAMBURGUESADELDIAARCHIVO_H
#include "HamburguesaDelDia.h"
#include "Fecha.h"

class HamburguesaDelDiaArchivo
{
    public:
        HamburguesaDelDiaArchivo();
        virtual ~HamburguesaDelDiaArchivo();

        HamburguesaDelDia leer(int pos);
        bool agregar(HamburguesaDelDia hamdeldia);
        int buscarPorCodigoyFecha(int codigo, Fecha fecha);
        int getCantidadRegistros();
        bool leerTodosLosRegistros(HamburguesaDelDia vecham[], int cantidad);
        bool generarHamburguesasDelDia();

        bool modificarRegistro(HamburguesaDelDia hdd, int pos);

        int contarHamburguesasDeLaFecha();
        int leerTodosHamburguesasDeLaFecha(HamburguesaDelDia hdd[], int cant);

        int contarHamburguesasDeLaFecha(Fecha fecha);
        void leerTodosHamburguesasDeLaFecha(HamburguesaDelDia hdd[], int cant, Fecha fecha);


    protected:

    private:
};

#endif // HAMBURGUESADELDIAARCHIVO_H
