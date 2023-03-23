#ifndef INGREDIENTE_H
#define INGREDIENTE_H


class Ingrediente
{
    public:
        Ingrediente();
        virtual ~Ingrediente();

        void setCodigo(int codigo);
        void setNombre(std::string nombre);
        void setPrecio(float precio);

        int getCodigo();
        std::string getNombre();
        float getPrecio();

    protected:

    private:
            int _codigo;
            char _nombre[50];
            float _precio;
};

#endif // INGREDIENTE_H
