#ifndef HORA_H
#define HORA_H


class Hora
{
    public:
        Hora();
        virtual ~Hora();
        int getHoras();
        int getMinutos();
        int getSegundos();

    protected:

    private:
        int _hora;
        int _minutos;
        int _segundos;
};

#endif // HORA_H
