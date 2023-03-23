#ifndef INGDEHAMBUGUESA_H
#define INGDEHAMBUGUESA_H


class IngDeHambuguesa
{
    public:
        IngDeHambuguesa();
        virtual ~IngDeHambuguesa();

            void setCodigoHamburguesa (int codigoHamburguesa);
            void setCodigoIngrediente (int codigoIngrediente);
            void setCantidad (int cantidad);

            int getCodigoHamburguesa();
            int getCodigoIngrediente();
            int getCantidad();

    protected:

    private:
            int _codigoHamburguesa;
            int _codigoIngrediente;
            int _cantidad;
};

#endif // INGDEHAMBUGUESA_H
