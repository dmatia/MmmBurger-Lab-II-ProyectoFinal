#ifndef COMBO_H
#define COMBO_H


class Combo
{
    public:
        Combo();
        virtual ~Combo();

        void setCodigo(int n);
        void setNombre(std::string n);
        void setHamburguesa(int n);
        void setBebida(int n);
        void setPrecio(float n);

        int getCodigo();
        std::string getNombre();
        int getHamburguesa();
        int getBebida();
        float getPrecio();

        float generarPrecio();

    protected:

    private:
        int _codigo;
        char _nombre[50];
        int _codigohamburguesa;
        int _codigobebida;
        float _precio;
};

#endif // COMBO_H
