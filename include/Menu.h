#ifndef MENU_H
#define MENU_H


class Menu
{
    public:
        Menu();
        virtual ~Menu();

        void menuAdministrador();
        void menuCargarIngredientesDeLaFecha();
        void menuNuevoProducto();

        void menuCaja();

    protected:

    private:
};

#endif // MENU_H
