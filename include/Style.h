#ifndef STYLE_H
#define STYLE_H


class Style
{
    public:
        Style();
        virtual ~Style();
        void showItemMenuPrincipal(const char* text, int posx, int posy, bool selected);
        void showItemMenuAdministrador(const char*text, int posx, int posy, bool selected);
        void showItemIngredienteHistorico(int codigo, std::string nombre, float precio, int posx, int posy);
        void showItemDelDiaAdm(bool estado, int codigo, std::string nombre,  float precio, int stockincial, int stockactual, int posx, int posy);
        void showItemDelDiaCaja(int codigo, std::string nombre, float precio, int posx, int posy);
        void showItemDelDiaCaja2(bool estado, int codigo, std::string nombre, float precio, int posx, int posy);

        void showItemMenuCaja(const char*text, int posx, int posy, bool selected);

    protected:

    private:
};

#endif // STYLE_H
