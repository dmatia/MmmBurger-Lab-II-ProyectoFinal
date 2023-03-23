#ifndef HAMBURGUESA_H
#define HAMBURGUESA_H


class Hamburguesa
{
    public:
        Hamburguesa();
        virtual ~Hamburguesa();

        void setCodigo(int codigo);
        void setNombre(std::string nombre);
        void setPrecio(float n);
        void setEstado(bool estado);
        void setIngrediente(int codigoingrediente, int cantidad);

        int getCodigo();
        std::string getNombre();
        float getPrecio();
        bool getEstado();


    protected:

    private:
        int _codigo;
        char _nombre[50];
        float _precio;


};

#endif // HAMBURGUESA_H
