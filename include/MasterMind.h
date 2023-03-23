#ifndef MASTERMIND_H
#define MASTERMIND_H
#include "Fecha.h"


class MasterMind
{
    public:
        MasterMind();
        virtual ~MasterMind();

        void mostrarProductosDisponibles();

        void mostrarProductosDelDia();

        bool generarHamburguesasDelDia();
        bool generarCombosDelDia();

        bool actualizarHDD();
        bool actualizarcDD();

        bool verReportePorFecha(Fecha fecha);
        bool verTicketsHistorico();
        bool verTicketsPorFecha();
        bool totalPorDiaHistorico();
        bool totalRecaudadoPorIntervalo();

        void ingresarIntervalo(Fecha &fecha1, Fecha &fecha2);

        bool PodioProductosHistorico();
        bool PodioHamburguesasHistorico();
        bool PodioBebidasHistorico();
        bool PodioCombosHistorico();


    protected:

    private:
};

#endif // MASTERMIND_H
