#ifndef FECHA_H
#define FECHA_H


class Fecha
{
    public:
        Fecha();
        virtual ~Fecha();
        int getAnio();
        int getMes();
        int getDia();

        void setAnio(int n);
        void setMes(int n);
        void setDia(int n);

        void incrementarDia();
        void incrementarMes();
        void incrementarAnio();



    bool operator==(Fecha &aux){
    if(_dia!=aux._dia)return false;
    if(_mes!=aux._mes)return false;
    if(_anio!=aux._anio)return false;
    return true;}

    bool operator >=(Fecha &aux){
    if(_anio>aux._anio){return true;}
    if((_anio>=aux._anio)&&(_mes>aux._mes)){return true;}
    if((_anio>=aux._anio)&&(_mes>=aux._mes)&&(_dia>=aux._dia)){return true;}
    return false;
    }

    bool operator <=(Fecha &aux){
    if(_anio<aux._anio){return true;}
    if((_anio<=aux._anio)&&(_mes<aux._mes)){return true;}
    if((_anio<=aux._anio)&&(_mes<=aux._mes)&&(_dia<=aux._dia)){return true;}
    return false;
    }




    protected:

    private:
        int _dia;
        int _mes;
        int _anio;
};

#endif // FECHA_H
