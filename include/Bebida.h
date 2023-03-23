#ifndef BEBIDA_H
#define BEBIDA_H


class Bebida
{
    public:
        Bebida();
        virtual ~Bebida();

        void setCodigo(int codigo);
        void setNombre(std::string);
        void setPresentacion(int presentacion);
        void setPrecio(float precio);

        int getCodigo();
        std::string getNombre();
        int getCodPresentacion();
        std::string getPresentacion();
        float getPrecio();




    protected:

    private:
        int _codigo;
        char _nombre[50];
        int _presentacion;
        float _precio;
};

#endif // BEBIDA_H
