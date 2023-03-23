#ifndef MANEJOARCHIVOS_H
#define MANEJOARCHIVOS_H


class ManejoArchivos
{
    public:
        ManejoArchivos();
        virtual ~ManejoArchivos();
        bool comprobarArchivo(char *filename);

        bool backupIngDelDia();
        bool backupBebDelDia();
        bool backupHamDelDia();
        bool backupComDelDia();
        bool backupTickets();
        bool backupPedidos();

        bool recuperarIngDelDia();
        bool recuperarBebDelDia();
        bool recuperarHamDelDia();
        bool recuperarComDelDia();
        bool recuperarTickets();
        bool recuperarPedidos();


    protected:

    private:
};

#endif // MANEJOARCHIVOS_H
