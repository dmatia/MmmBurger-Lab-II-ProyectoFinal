#include <iostream>
#include <iomanip>
#include <cstring>
#include "rlutil.h"
#include "MasterMind.h"
#include "Ingrediente.h"
#include "IngredienteArchivo.h"
#include "IngredienteDelDia.h"
#include "IngredienteDelDiaArchivo.h"
#include "Style.h"
#include "Validar.h"
#include "ManejoArchivos.h"
#include <locale.h>
#include "Fecha.h"
#include "Administrador.h"

#include "Bebida.h"
#include "BebidaArchivo.h"
#include "BebidaDelDia.h"
#include "BebidaDelDiaArchivo.h"

#include "Hamburguesa.h"
#include "HamburguesaArchivo.h"
#include "HamburguesaDelDia.h"
#include "HamburguesaDelDiaArchivo.h"
#include "IngDeHambuguesa.h"
#include "IngDeHamburguesaArchivo.h"

#include "Combo.h"
#include "ComboArchivo.h"
#include "ComboDelDia.h"
#include "ComboDelDiaArchivo.h"


#include "Ticket.h"
#include "TicketArchivo.h"

#include "Pedido.h"
#include "PedidoArchivo.h"

MasterMind::MasterMind()
{
    //ctor
}

MasterMind::~MasterMind()
{
    //dtor
}

void MasterMind::mostrarProductosDisponibles()
{
    setlocale(LC_ALL, "spanish");
    int opcmenu;
    do{
        rlutil::cls();
        ManejoArchivos MA;
        char filename1[] = "Archivos/Historico/IngredientesHistorico.dat";
        if(MA.comprobarArchivo(filename1)==true){
            IngredienteArchivo IA;
            int cant = IA.getCantidadRegistros();
            Ingrediente *vecIng = new Ingrediente[cant];
            if(vecIng==nullptr){std::cout << "ERROR AL CREAR VECTOR DINAMICO DE INGREDIENTES" << std::endl; return;}
            IA.leerTodosLosRegistros(vecIng, cant);
            Style STL;
            rlutil::setBackgroundColor(rlutil::MAGENTA);
            rlutil::locate(2, 5);
            std::cout << "     LISTADO COMPLETO DE INGREDIENTES    " << std::endl ;
            for(int i=0; i<cant; i++){
                STL.showItemIngredienteHistorico((vecIng[i].getCodigo()), (vecIng[i].getNombre()), (vecIng[i].getPrecio()), 2, 6+i);
            }
            //delete[]vecIng;
        }
        else{
            rlutil::locate(2,5);
            std::cout << "     LISTADO DE INGREDIENTES INEXISTENTE   " << std::endl ;
        }

        char filename2[] = "Archivos/Historico/BebidasHistorico.dat";
        if(MA.comprobarArchivo(filename2)==true){
        BebidaArchivo BA;
        int cantBebidas = BA.getCantidadRegistros();
        Bebida* vecBebidas = new Bebida[cantBebidas];
        if(vecBebidas==nullptr){std::cout << "ERROR AL CREAR VECTOR DINAMICO DE BEBIDAS" << std::endl; return;}
        BA.leerTodosLosRegistros(vecBebidas, cantBebidas);
        Style STL;
        rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
        rlutil::locate(45, 5);
        std::cout << "      LISTADO COMPLETO DE BEBIDAS        " << std::endl ;
        for(int i=0; i<cantBebidas; i++){
            STL.showItemIngredienteHistorico(vecBebidas[i].getCodigo(), vecBebidas[i].getNombre()+vecBebidas[i].getPresentacion(), vecBebidas[i].getPrecio(), 45, 6+i);
        }
        //delete[]vecBebidas;
        }
        else{
            rlutil::locate(45, 5);
            std::cout << "     LISTADO DE BEBIDAS INEXISTENTE      " << std::endl ;

        }

        char filename3[] = "Archivos/Historico/HamburguesasHistorico.dat";
        if(MA.comprobarArchivo(filename3)==true){
        HamburguesaArchivo HA;
        int cantHamburguesas = HA.getCantidadRegistros();
        Hamburguesa *vecHamburguesas = new Hamburguesa[cantHamburguesas];
        if(vecHamburguesas==nullptr){std::cout << "ERROR AL CREAR VECTOR DINAMICO DE HAMBURGUESAS" << std::endl; return;}
        HA.leerTodosLosRegistros(vecHamburguesas, cantHamburguesas);
        Style STL;
        rlutil::setBackgroundColor(rlutil::RED);
        rlutil::locate(88, 5);
        std::cout << "    LISTADO COMPLETO DE HAMBURGUESAS     " << std::endl ;
        for(int i=0; i<cantHamburguesas; i++){
            STL.showItemIngredienteHistorico((vecHamburguesas[i].getCodigo()), (vecHamburguesas[i].getNombre()), (vecHamburguesas[i].getPrecio()), 88, 6+i);
        }
       //delete[]vecHamburguesas;
        }
        else{
            rlutil::locate(88, 5);
            std::cout << "     LISTADO DE HAMBURGUESAS INEXISTENTE      " << std::endl ;

        }

        char filename4[] = "Archivos/Historico/CombosHistorico.dat";
        if(MA.comprobarArchivo(filename3)==true){
        ComboArchivo CA;
        int cantCombos = CA.getCantidadRegistros();
        Combo *vecCombos = new Combo[cantCombos];
        if(vecCombos==nullptr){std::cout << "ERROR AL CREAR VECTOR DINAMICO DE COMBOS" << std::endl; return;}
        CA.leerTodosLosRegistros(vecCombos, cantCombos);
        Style STL;
        rlutil::setBackgroundColor(rlutil::GREEN);
        rlutil::locate(131, 5);
        std::cout << "       LISTADO COMPLETO DE COMBOS        " << std::endl ;
        for(int i=0; i<cantCombos; i++){
            STL.showItemIngredienteHistorico((vecCombos[i].getCodigo()), (vecCombos[i].getNombre()), (vecCombos[i].getPrecio()), 131, 6+i);
        }
        //delete[]vecCombos;
        }
        else{
            rlutil::locate(131, 5);
            std::cout << "      LISTADO DE COMBOS INEXISTENTE       " << std::endl ;

        }
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::locate(1,45);

        std::cout << "1. MODIFICAR INGREDIENTE | 2. MODIFICAR BEBIDA | 3. VER/MODIFICAR HAMBURGUESA | 4. VER/MODIFICAR COMBO | 0. SALIR"<< std::endl;
        std::cout << "INGRESE OPCION DESEADA: " ; std::cin>> opcmenu;
        switch(opcmenu){
    case 1:{
            if(MA.comprobarArchivo(filename1)==true){
            Administrador adm;
            adm.modificarIngrediente();
            }
            else{std::cout << "NO EXISTE REGISTRO DE INGREDIENTES PARA MODIFICAR" << std::endl; system("pause");}

    }
        break;
    case 2:
        {
            if(MA.comprobarArchivo(filename2)==true){
            Administrador adm;
            adm.modificarBebida();
            }
            else{std::cout << "NO EXISTE REGISTRO DE BEBIDAS PARA MODIFICAR" << std::endl; Sleep(900);}
        }
        break;
    case 3:{
            if(!MA.comprobarArchivo(filename3)){std::cout << "NO EXISTE REGISTRO DE HAMBURGUESAS. NO PODRA MODIFICAR EL REGISTRO DE COMBOS" << std::endl; system("pause"); break;}
            if(MA.comprobarArchivo(filename3)==true){
            Administrador adm;
            adm.modificarHamburguesa();
            }
            else{std::cout << "NO EXISTE REGISTRO DE HAMBURGUESAS PARA MODIFICAR" << std::endl; system("pause");}
        }

        break;

    case 4:
        {

            if(!MA.comprobarArchivo(filename3)){std::cout << "NO EXISTE REGISTRO DE HAMBURGUESAS. NO PODRA MODIFICAR EL REGISTRO DE COMBOS" << std::endl; system("pause"); break;}
            if(!MA.comprobarArchivo(filename2)){std::cout << "NO EXISTE REGISTRO DE BEBIDAS. NO PODRA MODIFICAR EL REGISTRO DE COMBOS" << std::endl; system("pause"); break;}
            if(MA.comprobarArchivo(filename4)==true){
             Administrador adm;
             adm.modificarCombo();
            }
            else{std::cout << "NO EXISTE REGISTRO DE COMBOS PARA MODIFICAR" << std::endl; system("pause");}

        }
        break;
    default:
        std::cout << "OPCION INVALIDA"  << std::endl;}
        }while(opcmenu!=0);
        std::cin.ignore();
        rlutil::cls();
}

void MasterMind::mostrarProductosDelDia(){
    int opcvpf;
    do{
        rlutil::cls();
        Fecha fechaaux;
        std::cout << "FECHA: " << fechaaux.getDia() << "/" << fechaaux.getMes() << "/" << fechaaux.getAnio() << std::endl;
        Style STL;
        ManejoArchivos MA;
        char filename1[] = "Archivos/DelDia/IngredientesDelDia.dat";
        if(MA.comprobarArchivo(filename1)==true){
            IngredienteDelDiaArchivo IDDA;
            int cant = IDDA.getCantidadRegistros();
            IngredienteDelDia * vecIngDD = new IngredienteDelDia[cant];
            if(vecIngDD==nullptr){std::cout << "ERROR AL CREAR VECTOR DIN. ING DEL DIA" << std::endl; return;}
            IDDA.leerTodosLosRegistros(vecIngDD, cant);
            Style STL;
            rlutil::setBackgroundColor(rlutil::GREEN);
            rlutil::locate(2, 4);
            int renglon = 0;
            std::cout << "                   INGREDIENTES DISPONIBLES                  " << std::endl ;
            rlutil::locate(2,5);
            std::cout << std::left << "|" << std::setw(5) << "COD" <<
     "|" << std::setw(25) << "NOMBRE" <<
     "|" << std::setw(7)  << "PRECIO" <<
     "|" << std::setw(9) <<  "STOCK INI" <<
     "|" << std::setw(9) << "STOCK ACT " << std::endl;
            for(int i=0; i<cant; i++){
                if(vecIngDD[i].getFecha()==fechaaux){
                        STL.showItemDelDiaAdm(vecIngDD[i].getEstado(),
                                              vecIngDD[i].getCodigo(),
                                              vecIngDD[i].getNombre(),
                                              vecIngDD[i].getPrecio(),
                                              vecIngDD[i].getStockInicial(),
                                              vecIngDD[i].getStockFinal(),2,6+renglon);
                                              renglon++;
                                              }

                }
              //  delete[]vecIngDD;
            }
        else{
            rlutil::locate(2,5);
            std::cout << "     LISTADO DE INGREDIENTES INEXISTENTE   " << std::endl ;
        }

        //--------------------------------------------------------------------------------

        char filename2[] = "Archivos/DelDia/BebidasDelDia.dat";
        if(MA.comprobarArchivo(filename2)==true){
            BebidaDelDiaArchivo BDDA;
            int cant = BDDA.getCantidadRegistros();
            std::string aux;
            BebidaDelDia * vecBebDD = new BebidaDelDia[cant];
            if(vecBebDD==nullptr){std::cout << "ERROR AL CREAR VECTOR DINAMICO DE BEBIDAS DEL DIA" << std::endl; return;}
            BDDA.leerTodosLosRegistros(vecBebDD, cant);
            Style STL;
            rlutil::setBackgroundColor(rlutil::RED);
            Fecha fechaaux;
            rlutil::locate(65, 4);
            int renglon = 0;
            std::cout << "                      BEBIDAS DISPONIBLES                    " << std::endl ;
            rlutil::locate(65,5);
            std::cout << std::left << "|" << std::setw(5) << "COD" <<
     "|" << std::setw(25) << "NOMBRE" <<
     "|" << std::setw(7)  << "PRECIO" <<
     "|" << std::setw(9) <<  "STOCK INI" <<
     "|" << std::setw(9) << "STOCK ACT " << std::endl;
            for(int i=0; i<cant; i++){
                if(vecBebDD[i].getFecha()==fechaaux){

                        STL.showItemDelDiaAdm(vecBebDD[i].getEstado(),
                                              vecBebDD[i].getCodigo(),
                                              vecBebDD[i].getNombre()+vecBebDD[i].getPresentacion(),
                                              vecBebDD[i].getPrecio(),
                                              vecBebDD[i].getStockInicial(),
                                              vecBebDD[i].getStockFinal(),65,6+renglon);
                                              renglon++;
            }
            }
           // delete[]vecBebDD;
            }
        else{
            rlutil::locate(65,5);
            std::cout << "     LISTADO DE BEBIDAS INEXISTENTE   " << std::endl ;
        }

        //--------------------------------------------------------------------------------

        char filename3[] = "Archivos/DelDia/HamburguesasDelDia.dat";
        if(MA.comprobarArchivo(filename3)==true){
            HamburguesaDelDiaArchivo ADDA;
            int cant = ADDA.getCantidadRegistros();
            HamburguesaDelDia * vecADD = new HamburguesaDelDia[cant];
            if(vecADD==nullptr){std::cout << "ERROR AL CREAR VECTOR DINAMICO DE HAM DD" << std::endl; return;}
            ADDA.leerTodosLosRegistros(vecADD, cant);
            Style STL;
            rlutil::setBackgroundColor(rlutil::BLUE);
            Fecha fechaaux;
            rlutil::locate(128, 4);
            int renglon = 0;
            std::cout << "        HAMBURGUESAS DISPONIBLES        " << std::endl ;
            rlutil::locate(128,5);
            std::cout << std::left << "|" << std::setw(5) << "COD" <<
     "|" << std::setw(25) << "NOMBRE" <<
     "|" << std::setw(7)  << "PRECIO" <<
    std::endl;
            for(int i=0; i<cant; i++){
                if(vecADD[i].getFecha()==fechaaux){
                        STL.showItemDelDiaCaja2(vecADD[i].getEstado(),
                                            vecADD[i].getCodigo(),
                                              vecADD[i].getNombre(),
                                              vecADD[i].getPrecio()
                                              ,128,6+renglon);
                                              renglon++;}

                }
                // delete[]vecADD;
            }
        else{
            rlutil::locate(128,5);
            std::cout << "     LISTADO DE HAMBURGUEAS INEXISTENTE   " << std::endl ;
        }

        //--------------------------------------------------------------------------------

        char filename4[] = "Archivos/DelDia/CombosDelDia.dat";
        if(MA.comprobarArchivo(filename4)==true){
            ComboDelDiaArchivo CDDA;
            int cant = CDDA.contarCombosDeLaFecha();
            ComboDelDia *vecCDD = new ComboDelDia[cant];
            if(vecCDD==nullptr){std::cout << "ERROR AL CREAR VECTOR DINAMICO DE COMBOS DD" << std::endl; return;}
            CDDA.leerTodosCombosDeLaFecha(vecCDD,cant);
            rlutil::setBackgroundColor(rlutil::MAGENTA);
            rlutil::locate(170, 4);
            int renglon = 0;
            std::cout << "           COMBOS DISPONIBLES           " << std::endl ;
            rlutil::locate(170,5);
            std::cout << std::left << "|" << std::setw(5) << "COD" <<
     "|" << std::setw(25) << "NOMBRE" <<
     "|" << std::setw(7)  << "PRECIO" <<
    std::endl;
            for(int i=0; i<cant; i++){
                        STL.showItemDelDiaCaja2(vecCDD[i].getEstado(),
                                                vecCDD[i].getCodigo(),
                                              vecCDD[i].getNombre(),
                                              vecCDD[i].getPrecio()
                                              ,170,6+renglon);
                                              renglon++;

            }
            // delete[]vecCDD;
            }
        else{
            rlutil::locate(170,5);
            std::cout << "     LISTADO DE  COMBOS INEXISTENTE   " << std::endl ;
        }



        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::locate(1,45);

        std::cout << "1. AGREGAR STOCK A INGREDIENTE | 2. AGREGAR STOCK A BEBIDA | 3. ACTUALIZAR HAMBURGUESAS Y COMBOS DEL DIA | 0. SALIR"<< std::endl;
        std::cout << "INGRESE OPCION DESEADA: " ; std::cin>> opcvpf;
        switch(opcvpf){
        case 1:
            {
                Administrador adm;
                adm.agregarStockIngDelDia();
            }
           break;
        case 2:
            {
                Administrador adm;
                adm.agregarStockBebDelDia();
            }
           break;

           case 3:
            {
                if(actualizarHDD()==true){std::cout << "LISTADO DE HAMBURGUESAS ACTUALIZADO" << std::endl; Sleep(900);}
                else{std::cout << "NO ACTUALIZO" << std::endl; Sleep(900);}
                if(actualizarcDD()==true){std::cout << "LISTADO DE COMBOS ACTUALIZADO" << std::endl; Sleep(900); rlutil::cls();}
                else{std::cout << "NO ACTUALIZO" << std::endl; Sleep(900); rlutil::cls();}
            }
           break;


    default:
        std::cout << "OPCION INVALIDA"  << std::endl;}

    }while(opcvpf!=0);
    std::cin.ignore();
        rlutil::cls();

}

bool MasterMind::generarHamburguesasDelDia(){
    IngDeHamburguesaArchivo IDHA;
    int cantIDH = IDHA.getCantidadRegistros();

    IngDeHambuguesa *vecIDH = new IngDeHambuguesa[cantIDH];
    if(vecIDH==nullptr){std::cout << "ERROR AL CREAR VECTOR DINAMICO" << std::endl; return false;}
    IDHA.leerTodosLosRegistros(vecIDH, cantIDH);

    IngredienteDelDiaArchivo IDDA;
    int cantIDD = IDDA.contarIngredientesDeLaFecha();
    IngredienteDelDia *vecIDD = new IngredienteDelDia[cantIDD];
    if(vecIDD==nullptr){std::cout << "ERROR AL CREAR VECTOR DINAMICO" << std::endl; delete[]vecIDH; return false;}
    IDDA.leerTodosIngredientesDeLaFecha(vecIDD, cantIDD);

    HamburguesaArchivo HA;
    int cantHam = HA.getCantidadRegistros();

    Hamburguesa *vecHamb = new Hamburguesa[cantHam];
    if(vecHamb==nullptr){std::cout << "ERROR AL CREAR VECTOR DINAMICO" << std::endl; delete[]vecIDH; delete[]vecIDD; return false;}
    HA.leerTodosLosRegistros(vecHamb, cantHam);

    HamburguesaDelDiaArchivo HDDA;

    for(int i=0; i<cantHam; i++){
            int contadoring = 0;
            for(int j=0; j<cantIDH; j++){

                if(vecHamb[i].getCodigo() == vecIDH[j].getCodigoHamburguesa()){

                    for(int x=0; x<cantIDD; x++){
                        if (vecIDH[j].getCodigoIngrediente()==vecIDD[x].getCodigo()){
                            contadoring++;
                        }
                    }
                }
            }
            if (IDHA.getCantidadPorHamburguesa(vecHamb[i].getCodigo())==contadoring){
                HamburguesaDelDia aux;
                aux.setCodigo(vecHamb[i].getCodigo());
                aux.setNombre(vecHamb[i].getNombre());
                aux.setPrecio(vecHamb[i].getPrecio());
                aux.setEstado(true);
                if(HDDA.buscarPorCodigoyFecha(vecHamb[i].getCodigo(),aux.getFecha())==-1){HDDA.agregar(aux);}
            }
    }

    //delete[]vecIDD;
    //delete[]vecHamb;
    //delete[]vecIDH;
    return true;
}

    bool MasterMind::generarCombosDelDia(){
        HamburguesaDelDiaArchivo HDDA;
        int cantHDD = HDDA.contarHamburguesasDeLaFecha();
        HamburguesaDelDia *vecHDD = new HamburguesaDelDia[cantHDD];
        if(vecHDD==nullptr){return false;}
        HDDA.leerTodosHamburguesasDeLaFecha(vecHDD,cantHDD);

        BebidaDelDiaArchivo BDDA;
        int cantBDD = BDDA.contarBebidasDeLaFecha();
        BebidaDelDia *vecBDD = new BebidaDelDia [cantBDD];
        if(vecBDD==nullptr){delete[]vecHDD; return false;}
        BDDA.leerTodosBebidasDeLaFecha(vecBDD, cantBDD);

        ComboArchivo CA;
        int cantCmb = CA.getCantidadRegistros();
        Combo *vecCMB = new Combo [cantCmb];
        if (vecCMB==nullptr){delete[]vecHDD; delete[]vecBDD; return false;}
        CA.leerTodosLosRegistros(vecCMB, cantCmb);

        ComboDelDiaArchivo CDDA;

        Fecha fechaaux;

        for (int i=0; i<cantCmb; i++){
            for(int j=0; j<cantHDD; j++){
                if((vecCMB[i].getHamburguesa())==(vecHDD[j].getCodigo())){
                    for(int x=0; x<cantBDD; x++){
                        if(vecCMB[i].getBebida()==vecBDD[x].getCodigo()){
                            if(CDDA.buscarPorCodigoyFecha(vecCMB[i].getCodigo(),fechaaux)==-1){
                                ComboDelDia CDDaux;
                                CDDaux.setCodigo(vecCMB[i].getCodigo());
                                CDDaux.setNombre(vecCMB[i].getNombre());
                                CDDaux.setHamburguesa(vecCMB[i].getHamburguesa());
                                CDDaux.setBebida(vecCMB[i].getBebida());
                                CDDaux.setPrecio (vecCMB[i].getPrecio());
                                CDDaux.setEstado(true);
                                CDDA.agregar(CDDaux);
                            }
                        }
                    }
                }
            }

        }

        delete[]vecHDD;
        delete[]vecBDD;
        //delete[]vecCMB;
        return true;

    }

bool MasterMind::actualizarHDD(){
        HamburguesaDelDiaArchivo HDDA;
        int cant = HDDA.contarHamburguesasDeLaFecha();
        HamburguesaDelDia *vecHDD = new HamburguesaDelDia[cant];
        if(vecHDD==nullptr){return false;}
        HDDA.leerTodosHamburguesasDeLaFecha(vecHDD, cant);
        for(int i=0; i<cant; i++){
            if(vecHDD[i].verificarIngredientesDisponibles()==false){
                vecHDD[i].setEstado(false);
                HDDA.modificarRegistro(vecHDD[i],HDDA.buscarPorCodigoyFecha(vecHDD[i].getCodigo(),vecHDD[i].getFecha()));
            }
            else{
                vecHDD[i].setEstado(true);
                HDDA.modificarRegistro(vecHDD[i],HDDA.buscarPorCodigoyFecha(vecHDD[i].getCodigo(),vecHDD[i].getFecha()));
            }
        }
        delete[]vecHDD;
        return true;
}

bool MasterMind::actualizarcDD(){
        ComboDelDiaArchivo CDDA;
        int cant = CDDA.contarCombosDeLaFecha();
        ComboDelDia *vecCDD = new ComboDelDia[cant];
        if(vecCDD==nullptr){return false;}
        CDDA.leerTodosCombosDeLaFecha(vecCDD, cant);
        for(int i=0; i<cant; i++){
            if(vecCDD[i].comprobarStock()==false){
                vecCDD[i].setEstado(false);
                CDDA.modificarRegistro(vecCDD[i],CDDA.buscarPorCodigoyFecha(vecCDD[i].getCodigo(),vecCDD[i].getFecha()));
            }
            else{
                vecCDD[i].setEstado(true);
                CDDA.modificarRegistro(vecCDD[i],CDDA.buscarPorCodigoyFecha(vecCDD[i].getCodigo(),vecCDD[i].getFecha()));
            }
        }
        delete[]vecCDD;
        return true;
}

bool MasterMind::verReportePorFecha(Fecha fecha){
        rlutil::cls();

        TicketArchivo TA;
        int cantTickets = TA.contarTicketsDeLaFecha(fecha);
        Ticket *vecTickets = new Ticket[cantTickets];
        if(vecTickets==nullptr){return false;}
        TA.leerTodosLosTicketsDeLaFecha(vecTickets,cantTickets,fecha);

        PedidoArchivo PA;
        int cantped = PA.contarPedidosDeLaFecha(fecha);
        Pedido *vecPedidos = new Pedido[cantped];
        if(vecPedidos==nullptr){delete[]vecTickets; return false;}
        PA.leerTodosLosPedidosDeLaFecha(vecPedidos,cantped,fecha);

        IngredienteDelDiaArchivo IDDA;
        int cantidd = IDDA.contarIngredientesDeLaFecha(fecha);
        IngredienteDelDia *vecIDD = new IngredienteDelDia[cantidd];
        if(vecIDD==nullptr){delete[]vecTickets; delete[]vecPedidos; return false;}
        IDDA.leerTodosIngredientesDeLaFecha(vecIDD,cantidd,fecha);

        HamburguesaDelDiaArchivo HDDA;
        int cantham = HDDA.contarHamburguesasDeLaFecha(fecha);
        HamburguesaDelDia *vecHDD = new HamburguesaDelDia[cantham];
        if(vecHDD==nullptr){delete[]vecTickets; delete[]vecIDD; delete[]vecPedidos; return false;}
        HDDA.leerTodosHamburguesasDeLaFecha(vecHDD,cantham,fecha);

        BebidaDelDiaArchivo BDDA;
        int cantbeb = BDDA.contarBebidasDeLaFecha(fecha);
        BebidaDelDia *vecBDD = new BebidaDelDia[cantbeb];
        if(vecBDD==nullptr){delete[]vecTickets; delete[]vecPedidos; delete[]vecIDD; delete[]vecHDD; return false;}
        BDDA.leerTodosBebidasDeLaFecha(vecBDD,cantbeb,fecha);

        ComboDelDiaArchivo CDDA;
        int cantcomb = CDDA.contarCombosDeLaFecha(fecha);
        ComboDelDia *vecCDD = new ComboDelDia[cantcomb];
        if(vecCDD==nullptr){delete[]vecTickets; delete[]vecPedidos; delete[]vecIDD; delete[]vecHDD; delete[]vecBDD; delete[]vecHDD; return false;}
        CDDA.leerTodosCombosDeLaFecha(vecCDD,cantcomb,fecha);

        float recaudaciontotal = 0;
        int totaltickets = cantTickets;

        for(int i=0; i<cantTickets; i++){
            recaudaciontotal += vecTickets[i].getTotal();
        }

        int contadorhamburguesamasvendida = 0;
        HamburguesaDelDia hamburguesamasvendida;
        int *veccantxham = new int[cantham];
        if(veccantxham==nullptr){delete[]vecTickets; delete[]vecPedidos; delete[]vecIDD; delete[]vecHDD; delete[]vecBDD; delete[]vecCDD; return false;}

            for(int i=0; i<cantham; i++){
                    int contaux = 0;
                for(int j=0; j<cantTickets; j++){
                    int cantPedidosTicket = PA.contarPedidosPorTicket(vecTickets[j].getNroDeTicket());
                    Pedido *vecPedidoTicket = new Pedido[cantPedidosTicket];
                    if(vecPedidoTicket==nullptr){return false;}
                    PA.leerPedidosPorTicket(vecPedidoTicket, cantPedidosTicket, vecTickets[j].getNroDeTicket());
                        for(int x=0; x<cantPedidosTicket; x++){
                            if(vecPedidoTicket[x].getCodHamburguesa()==vecHDD[i].getCodigo()){
                                contaux++;
                            }
                        }
                        delete[]vecPedidoTicket;
                }

                 if(contaux>contadorhamburguesamasvendida){
                    contadorhamburguesamasvendida = contaux;
                    hamburguesamasvendida = vecHDD[i];
                 }
                 veccantxham[i]=contaux;
            }


        int contadorbebidamasvendida = 0;
        BebidaDelDia bebidamasvendida;
        int *veccantxbeb = new int[cantbeb];
        if(veccantxbeb==nullptr){delete[]vecTickets; delete[]vecPedidos; delete[]vecIDD; delete[]vecHDD; delete[]vecBDD; delete[]vecCDD; delete[]veccantxham; return false;}

         for(int i=0; i<cantbeb; i++){
                int contaux = 0;
                for(int j=0; j<cantTickets; j++){
                    int cantPedidosTicket = PA.contarPedidosPorTicket(vecTickets[j].getNroDeTicket());
                    Pedido *vecPedidoTicket = new Pedido[cantPedidosTicket];
                    if(vecPedidoTicket==nullptr){return false;}
                    PA.leerPedidosPorTicket(vecPedidoTicket, cantPedidosTicket, vecTickets[j].getNroDeTicket());
                        for(int x=0; x<cantPedidosTicket; x++){
                            if(vecPedidoTicket[x].getCodBebida()==vecBDD[i].getCodigo()){
                                contaux++;
                            }
                        }
                        delete[]vecPedidoTicket;
                }
                 if(contaux>contadorbebidamasvendida){
                    contadorbebidamasvendida = contaux;
                    bebidamasvendida = vecBDD[i];
                 }
                 veccantxbeb[i] = contaux;
            }

        int contadorcombomasvendida = 0;
        ComboDelDia combomasvendida;
        int *veccantxcom = new int[cantcomb];
        if(veccantxcom==nullptr){delete[]vecTickets; delete[]vecPedidos; delete[]vecIDD; delete[]vecHDD; delete[]vecBDD; delete[]vecCDD; delete[]veccantxham; delete[]veccantxbeb; return false;}

         for(int i=0; i<cantcomb; i++){
                int contaux = 0;
                for(int j=0; j<cantTickets; j++){
                    int cantPedidosTicket = PA.contarPedidosPorTicket(vecTickets[j].getNroDeTicket());
                    Pedido *vecPedidoTicket = new Pedido[cantPedidosTicket];
                    if(vecPedidoTicket==nullptr){return false;}
                    PA.leerPedidosPorTicket(vecPedidoTicket, cantPedidosTicket, vecTickets[j].getNroDeTicket());
                        for(int x=0; x<cantPedidosTicket; x++){
                            if(vecPedidoTicket[x].getCodCombo()==vecCDD[i].getCodigo()){
                                contaux++;
                            }
                        }
                        delete[]vecPedidoTicket;
                }
                 if(contaux>contadorcombomasvendida){
                    contadorcombomasvendida = contaux;
                    combomasvendida = vecCDD[i];
                 }
                 veccantxcom[i] = contaux;
            }
            rlutil::cls();
            int a=15, b=15, c=60, d=15, e=110, f=15;
            rlutil::locate(15,5);
            std::cout << "FECHA REPORTE: " << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio() << std::endl;
            rlutil::locate(15,6);
            std::cout << "RECAUDACION TOTAL: $" << recaudaciontotal << std::endl;
            rlutil::locate(15,7);
            std::cout << "CANTIDAD DE TICKETS/VENTAS: " << totaltickets << std::endl;
            rlutil::locate(15,8);
            std::cout << "HAMBURGUESA MAS VENDIDA: #" << hamburguesamasvendida.getCodigo() << " " << hamburguesamasvendida.getNombre() << " - CANTIDAD: " << contadorhamburguesamasvendida << std::endl;
            rlutil::locate(15,9);
            std::cout << "BEBIDA MAS VENDIDA: #" << bebidamasvendida.getCodigo() << " " << bebidamasvendida.getNombre() << bebidamasvendida.getPresentacion() << " - CANTIDAD: " << contadorbebidamasvendida << std::endl;
            rlutil::locate(15,10);
            std::cout << "COMBO MAS VENDIDO: #" << combomasvendida.getCodigo() << " " << combomasvendida.getNombre() << "- CANTIDAD: " << contadorcombomasvendida << std::endl;

            rlutil::locate(15,12);
            std::cout << "***************************************************************************************************************************************" << std::endl;

            rlutil::locate(a, b++);
            std::cout << "HAMBURGUESAS DISPONIBLES EN LA FECHA: " << std::endl;
            b++;
            for(int i=0; i<cantham; i++){
                rlutil::locate(a,b++);
                std::cout << "#" << vecHDD[i].getCodigo() << " " << vecHDD[i].getNombre() << std::endl;
            }
            a = 43, b=17;
            for(int i=0; i<cantham; i++){
            rlutil::locate(a,b++);
            std::cout << "- " << veccantxham[i] << " UN." << std::endl;
            }

            rlutil::locate(c,d++);
            std::cout << "BEBIDAS DISPONIBLES EN LA FECHA: " << std::endl;
            d++;
            for(int i=0; i<cantbeb; i++){
                rlutil::locate(c,d++);
                std::cout << "#" << vecBDD[i].getCodigo() << " " << vecBDD[i].getNombre() << vecBDD[i].getPresentacion() << std::endl;
            }

            c = 90, d=17;
            for(int i=0; i<cantbeb; i++){
            rlutil::locate(c,d++);
            std::cout << "VENDIO " << veccantxbeb[i] << " UN." << std::endl;
            }

            rlutil::locate(e,f++);
            std::cout << "COMBOS DISPONIBLES EN LA FECHA: " << std::endl;
            f++;
            for(int i=0; i<cantcomb; i++){
                rlutil::locate(e,f++);
                std::cout << "#" << vecCDD[i].getCodigo() << " " << vecCDD[i].getNombre() << std::endl;
            }

            e = 130, f=17;
            for(int i=0; i<cantcomb; i++){
            rlutil::locate(e,f++);
            std::cout << "VENDIO " << veccantxcom[i] << " UN." << std::endl;
            }

        delete[]vecTickets;
        delete[]vecPedidos;
        delete[]vecIDD;
        delete[]vecHDD;
        delete[]vecBDD;
        delete[]vecCDD;
        delete veccantxbeb;
        delete veccantxcom;
        delete veccantxham;

        rlutil::locate(1,45);
        system("pause");
        std::cin.ignore();
        rlutil::cls();
        return true;
}

bool MasterMind::verTicketsPorFecha(){
    rlutil::cls();
    int x=85, y=5;

    Fecha fecha;
    int dia, mes, anio;
    rlutil::locate(x,y++);
    std::cout << "INGRESE LA FECHA QUE DESEA BUSCAR: ";
    rlutil::locate(x,y);validarInput(dia,0,32) ;
    x++, x++;
    rlutil::locate(x,y);std::cout << "/" ; validarInput(mes,0,13);
    x++; x++; x++;
    rlutil::locate(x,y);std::cout << "/" ; validarInput(anio,2010,fecha.getAnio()+1);
    fecha.setDia(dia); fecha.setMes(mes); fecha.setAnio(anio);

    x--; x--; x--; x--; x--;
    y++;

    TicketArchivo TA;

    int cant = TA.contarTicketsDeLaFecha(fecha);
    if(cant==0){rlutil::locate(x,y++); std::cout << "NO HAY REGISTROS PARA LA FECHA INDICADA" << std::endl; Sleep(900); rlutil::cls(); return false;}

    Ticket *vecTickets = new Ticket[cant];
    if(vecTickets==nullptr){return false;}
    TA.leerTodosLosTicketsDeLaFecha(vecTickets,cant,fecha);


    y++;
    y++;

    for(int i=0; i<cant; i++){
        rlutil::locate(x,y++);
        std::cout << "FECHA: " << vecTickets[i].getFecha().getDia() << "/" << vecTickets[i].getFecha().getMes() << "/" << vecTickets[i].getFecha().getAnio() << std::endl;
        rlutil::locate(x,y++);
        std::cout << "NRO TICKET #" << vecTickets[i].getNroDeTicket() << " NRO MESA #" << vecTickets[i].getNroMesa() << std::endl;
        rlutil::locate(x,y++);
    std::cout << "DETALLE TICKET: " << std::endl;
        PedidoArchivo PA;
        int cantidadDePedidos = PA.contarPedidosPorTicket(vecTickets[i].getNroDeTicket());
        Pedido *vecped = new Pedido[cantidadDePedidos];
        if(vecped==nullptr){delete[]vecTickets; return false;}
        PA.leerPedidosPorTicket(vecped, cantidadDePedidos, vecTickets[i].getNroDeTicket());
        for(int j=0; j<cantidadDePedidos; j++){
            if(vecped[j].getCodHamburguesa()!=-1){
                HamburguesaDelDiaArchivo hdda;
                HamburguesaDelDia hdd;
                hdd = hdda.leer(hdda.buscarPorCodigoyFecha(vecped[j].getCodHamburguesa(),vecped[j].getFecha()));
                rlutil::locate(x,y++);
                std::cout << "- " << hdd.getNombre() << " $" << hdd.getPrecio() << std::endl;
            }
            if(vecped[j].getCodBebida()!=-1){
                BebidaDelDiaArchivo bdda;
                BebidaDelDia bdd;
                bdd = bdda.leer(bdda.buscarPorCodigoyFecha(vecped[j].getCodBebida(),vecped[j].getFecha()));
                rlutil::locate(x,y++);
                std::cout << "- " << bdd.getNombre() << bdd.getPresentacion() << " $" << bdd.getPrecio() << std::endl;
            }
            if(vecped[j].getCodCombo()!=-1){
                ComboDelDiaArchivo cdda;
                ComboDelDia cdd;
                cdd = cdda.leer(cdda.buscarPorCodigoyFecha(vecped[j].getCodCombo(),vecped[j].getFecha()));
                rlutil::locate(x,y++);
                std::cout << "- " << cdd.getNombre() << " $" << cdd.getPrecio() << std::endl;
            }
        }
        rlutil::locate(x,y++);
        std::cout << "TOTAL $" << vecTickets[i].getTotal() << std::endl;
        y++;
        rlutil::locate(x,y++);
        std::cout << "*****************************" << std::endl;
        y++;
        delete[]vecped;
    }

    system("pause");

    delete[]vecTickets;
    std::cin.ignore();
    rlutil::cls();
    return true;
}

bool MasterMind::verTicketsHistorico(){
    rlutil::cls();
    int x=85, y=5;
    TicketArchivo TA;

    int cant = TA.getCantidadRegistros();

    Ticket *vecTickets = new Ticket[cant];
    if(vecTickets==nullptr){return false;}
    TA.leerTodosLosRegistros(vecTickets, cant);


    for(int i=0; i<cant; i++){
        rlutil::locate(x,y++);
        std::cout << "FECHA: " << vecTickets[i].getFecha().getDia() << "/" << vecTickets[i].getFecha().getMes() << "/" << vecTickets[i].getFecha().getAnio() << std::endl;
        rlutil::locate(x,y++);
        std::cout << "NRO TICKET #" << vecTickets[i].getNroDeTicket() << " NRO MESA #" << vecTickets[i].getNroMesa() << std::endl;
        rlutil::locate(x,y++);
    std::cout << "DETALLE TICKET: " << std::endl;
        PedidoArchivo PA;
        int cantidadDePedidos = PA.contarPedidosPorTicket(vecTickets[i].getNroDeTicket());
        Pedido *vecped = new Pedido[cantidadDePedidos];
        if(vecped==nullptr){delete[]vecTickets; return false;}
        PA.leerPedidosPorTicket(vecped, cantidadDePedidos, vecTickets[i].getNroDeTicket());
        for(int j=0; j<cantidadDePedidos; j++){
            if(vecped[j].getCodHamburguesa()!=-1){
                HamburguesaDelDiaArchivo hdda;
                HamburguesaDelDia hdd;
                hdd = hdda.leer(hdda.buscarPorCodigoyFecha(vecped[j].getCodHamburguesa(),vecped[j].getFecha()));
                rlutil::locate(x,y++);
                std::cout << "- " << hdd.getNombre() << " $" << hdd.getPrecio() << std::endl;
            }
            if(vecped[j].getCodBebida()!=-1){
                BebidaDelDiaArchivo bdda;
                BebidaDelDia bdd;
                bdd = bdda.leer(bdda.buscarPorCodigoyFecha(vecped[j].getCodBebida(),vecped[j].getFecha()));
                rlutil::locate(x,y++);
                std::cout << "- " << bdd.getNombre() << bdd.getPresentacion() << " $" << bdd.getPrecio() << std::endl;
            }
            if(vecped[j].getCodCombo()!=-1){
                ComboDelDiaArchivo cdda;
                ComboDelDia cdd;
                cdd = cdda.leer(cdda.buscarPorCodigoyFecha(vecped[j].getCodCombo(),vecped[j].getFecha()));
                rlutil::locate(x,y++);
                std::cout << "- " << cdd.getNombre() << " $" << cdd.getPrecio() << std::endl;
            }
        }
        rlutil::locate(x,y++);
        std::cout << "TOTAL $" << vecTickets[i].getTotal() << std::endl;
        y++;
        rlutil::locate(x,y++);
        std::cout << "*****************************" << std::endl;
        y++;
        delete[]vecped;
    }

    system("pause");

    delete[]vecTickets;
    std::cin.ignore();
    rlutil::cls();
    return true;
}

bool MasterMind::totalPorDiaHistorico(){
    TicketArchivo TA;
    int cantTickets = TA.getCantidadRegistros();
    Ticket *vecTickets = new Ticket[cantTickets];
    TA.leerTodosLosRegistros(vecTickets, cantTickets);

    int cantFechas = 0;

    Fecha fechaaux;

    rlutil::cls();
    int x=80, y=10;
    rlutil::locate(x,y++);
    std::cout << "TOTAL RECAUDADO POR DIA HISTORICO" << std::endl;

    for(int i=0; i<cantTickets; i++){
            float totalacumulado = 0;
            int cantventas = 0;
        if(i==0){
            fechaaux = vecTickets[i].getFecha();
            for(int j=0; j<cantTickets; j++){
                if(vecTickets[j].getFecha()==fechaaux){
                    totalacumulado += vecTickets[j].getTotal();
                    cantventas++;
                }
            }
            rlutil::locate(x,y++);
            std::cout << "FECHA: " << fechaaux.getDia() << "/" << fechaaux.getMes() << "/" << fechaaux.getAnio()
            << " | TOTAL RECAUDADO: $" << totalacumulado
            << " | TOTAL OPERACIONES: " << cantventas << std::endl;
        }
        else if(!(vecTickets[i].getFecha()==fechaaux)){
            fechaaux = vecTickets[i].getFecha();
            for(int j=0; j<cantTickets; j++){
                if(vecTickets[j].getFecha()==fechaaux){
                    totalacumulado += vecTickets[j].getTotal();
                    cantventas++;
                }
            }
            rlutil::locate(x,y++);
        std::cout << "FECHA: " << fechaaux.getDia() << "/" << fechaaux.getMes() << "/" << fechaaux.getAnio()
        << " | TOTAL RECAUDADO: $" << totalacumulado
        << " | TOTAL OPERACIONES: " << cantventas << std::endl;
        }
        }

        delete[]vecTickets;
        rlutil::locate(1,40);
        system("pause");
        std::cin.ignore();
        rlutil::cls();
        return true;
    }

bool MasterMind::totalRecaudadoPorIntervalo(){
        rlutil::cls();
        int x=75, y=10;

        Fecha fecha1, fecha2;

        ingresarIntervalo(fecha1, fecha2);

        Fecha fechaconmayor;
        int MayorRecaudacion = 0;
        int cantTicketsMayor = 0;

        rlutil::locate(x,y++);
        std::cout << "RECAUDACION X DIA ENTRE " << fecha1.getDia() << "/" << fecha1.getMes() << "/" << fecha1.getAnio() <<
        " Y " << fecha2.getDia() << "/" << fecha2.getMes() << "/" << fecha2.getAnio() ;

        y++;

        while(fecha1<=fecha2){

            TicketArchivo TA;
            int cantTickets = TA.contarTicketsDeLaFecha(fecha1);
            Ticket *vecTicket = new Ticket[cantTickets];
            if(vecTicket==nullptr){return false;}
            TA.leerTodosLosTicketsDeLaFecha(vecTicket,cantTickets,fecha1);
            int acumuladorPorTicket = 0;
            for(int i=0; i<cantTickets; i++){
                acumuladorPorTicket += vecTicket[i].getTotal();
            }
            if(acumuladorPorTicket>MayorRecaudacion){
                MayorRecaudacion = acumuladorPorTicket;
                fechaconmayor = fecha1;
                cantTicketsMayor = cantTickets;
            }
            rlutil::locate(x,y++);
            std::cout << "FECHA: " << fecha1.getDia() << "/" << fecha1.getMes() << "/" << fecha1.getAnio() << " | TOTAL RECAUDADO: $" << acumuladorPorTicket << " | CANT. VENTAS: " << cantTickets << std::endl;

            delete[]vecTicket;
            fecha1.incrementarDia();
        }
        y++;
        rlutil::locate(x,y++);
        std::cout << "FECHA CON MAYOR RECAUDACION: " << fechaconmayor.getDia() << "/" << fechaconmayor.getMes() << "/" << fechaconmayor.getAnio() << " | TOTAL RECAUDADO: $" << MayorRecaudacion << " | CANT. VENTAS: " << cantTicketsMayor << std::endl;



        system("pause");
        std::cin.ignore();
        rlutil::cls();
        return true;
        }

void MasterMind::ingresarIntervalo(Fecha &fecha1, Fecha &fecha2){
        do{
        int dia, mes, anio;
        int x=80, y=15;
        Fecha fechaaux;
        rlutil::cls();
        rlutil::locate(x,y++);
        std::cout << "INGRESE EL INTERVALO DE FECHAS A BUSCAR, ASEGURESE QUE LA SEGUNDA FECHA SEA POSTERIOR A LA PRIMERA " ;
        rlutil::locate(x,y++);
        std::cout << "DESDE: ";
        rlutil::locate(x,y);validarInput(dia,0,32) ;
        x++, x++;
        rlutil::locate(x,y);std::cout << "/" ; validarInput(mes,0,13);
        x++; x++; x++;
        rlutil::locate(x,y);std::cout << "/" ; validarInput(anio,2010,fechaaux.getAnio()+1);
        fecha1.setDia(dia); fecha1.setMes(mes); fecha1.setAnio(anio);

        x--; x--; x--; x--; x--;
        y++;

        rlutil::locate(x,y++);
        std::cout << "HASTA: ";
        rlutil::locate(x,y);validarInput(dia,0,32) ;
        x++, x++;
        rlutil::locate(x,y);std::cout << "/" ; validarInput(mes,0,13);
        x++; x++; x++;
        rlutil::locate(x,y);std::cout << "/" ; validarInput(anio,fecha1.getAnio()-1,fechaaux.getAnio()+1);
        fecha2.setDia(dia); fecha2.setMes(mes); fecha2.setAnio(anio);

        x--; x--; x--; x--; x--;
        y++;

        }while(
              !(fecha2>=fecha1));
              std::cin.ignore();
              rlutil::cls();
}

bool MasterMind::PodioProductosHistorico(){
    rlutil::cls();
    PodioHamburguesasHistorico();
    PodioBebidasHistorico();
    PodioCombosHistorico();
    rlutil::locate(1,50);
    system("pause");
    std::cin.ignore();
    rlutil::cls();
}

bool MasterMind::PodioHamburguesasHistorico()
{
            int x=5, y=5;
            HamburguesaArchivo HA;
            int cantHam = HA.getCantidadRegistros();
            Hamburguesa *vecHam = new Hamburguesa[cantHam];
            if(vecHam==nullptr){return false;}
            HA.leerTodosLosRegistros(vecHam,cantHam);

            HamburguesaDelDiaArchivo HDDA;
            int cantHDD = HDDA.getCantidadRegistros();
            HamburguesaDelDia *vecHDDaux = new HamburguesaDelDia[cantHDD];
            if(vecHDDaux==nullptr){delete[]vecHam; return false;}
            HDDA.leerTodosLosRegistros(vecHDDaux,cantHDD);

            int hamdistintas = cantHam;


            for(int i=0; i<cantHam; i++){
                for(int j=0; j<cantHDD; j++){
                    if(vecHDDaux[j].getCodigo()==vecHam[i].getCodigo()){
                        if(strcmp((vecHDDaux[j].getNombre().c_str()), (vecHam[i].getNombre().c_str()))!=0){
                            hamdistintas ++;
                        }
                    }
                }
            }


            //delete[]vecHam;

            HamburguesaDelDia *vecHDD = new HamburguesaDelDia [hamdistintas];
            if(vecHDD==nullptr){delete[]vecHam; delete[]vecHDDaux; return false;}

            int j=0;


            for(int i=0; i<cantHDD; i++){
                if(i==0){
                    vecHDD[j] = vecHDDaux[i];
                    j++;
                }
                else{
                    for(int x=0; x<hamdistintas; x++){
                        if(vecHDDaux[i].getCodigo()==vecHDD[x].getCodigo()){
                           if(strcmp(vecHDDaux[i].getNombre().c_str(),vecHDD[i].getNombre().c_str())==0){
                            x=hamdistintas;
                           }
                    }
                    else if(strcmp(vecHDDaux[i].getNombre().c_str(),vecHDD[i].getNombre().c_str())!=0){
                        vecHDD[j] = vecHDDaux[i];
                        j++;
                    }
                    }
                }
            }


             PedidoArchivo PA;
             int canPed = PA.getCantidadRegistros();
             Pedido *vecPeds = new Pedido[canPed];
             if(vecPeds==nullptr){delete[]vecHam; delete[]vecHDDaux; delete[]vecHDD; return false;}
             PA.leerTodosLosRegistros(vecPeds, canPed);

             float *vecVentaxHam= new float[hamdistintas];
             if(vecVentaxHam==nullptr){delete[]vecHam; delete[]vecHDDaux; delete[]vecHDD; delete[]vecPeds; return false;}

            for(int j=0; j<hamdistintas; j++){
                        float floataux = 0;
                        vecVentaxHam[j] = floataux;
                        for(int i=0; i<canPed; i++){
                                if(vecPeds[i].getCodHamburguesa()==vecHDD[j].getCodigo()){
                                    floataux = vecHDDaux[j].getPrecio();
                                    vecVentaxHam[j] += floataux;
                                }
                }
             }


             int aux;
                HamburguesaDelDia hddaux;
                for(int i=0; i<hamdistintas; i++){
                    for(int j=i+1; j<hamdistintas; j++){
                        if(vecVentaxHam[j]>vecVentaxHam[i]){
                            aux = vecVentaxHam[j];
                            vecVentaxHam[j] = vecVentaxHam[i];
                            vecVentaxHam[i] = aux;

                            hddaux = vecHDD[j];
                            vecHDD[j] = vecHDD[i];
                            vecHDD[i] = hddaux;

                        }
                    }
                }
                rlutil::locate(x,y++);
                std::cout << "PODIO HAMBURGUESAS HISTORICO: " << std::endl;
                y++;
                for(int i=0; i<hamdistintas; i++){
                    rlutil::locate(x,y++);
                     std::cout << "#" << i+1 << " HAMBURGUESA: " << vecHDD[i].getNombre() ; rlutil::locate(x+40,y-1); std::cout << " TOTAL RECAUDADO: $" << vecVentaxHam[i] << std::endl;
                     x-40;
                }

//delete[]vecHam; delete[]vecHDDaux; delete[]vecHDD; delete[]vecPeds;
return true;

}

bool MasterMind::PodioBebidasHistorico()
{
            int x=80, y=5;
            BebidaArchivo BA;
            int cantBeb = BA.getCantidadRegistros();
            Bebida *vecBeb = new Bebida[cantBeb];
            if(vecBeb==nullptr){return false;}
            BA.leerTodosLosRegistros(vecBeb,cantBeb);

            BebidaDelDiaArchivo BDDA;
            int cantBDD = BDDA.getCantidadRegistros();
            BebidaDelDia *vecBDDaux = new BebidaDelDia[cantBDD];
            if(vecBDDaux==nullptr){delete[]vecBeb; return false;}
            BDDA.leerTodosLosRegistros(vecBDDaux,cantBDD);

            int bebdistintas = cantBeb;


            for(int i=0; i<cantBeb; i++){
                for(int j=0; j<cantBDD; j++){
                    if(vecBDDaux[j].getCodigo()==vecBeb[i].getCodigo()){
                        if(strcmp((vecBDDaux[j].getNombre().c_str()), (vecBeb[i].getNombre().c_str()))!=0){
                            bebdistintas ++;
                        }
                    }
                }
            }


            //delete[]vecHam;

            BebidaDelDia *vecBDD = new BebidaDelDia [bebdistintas];
            if(vecBDD==nullptr){delete[]vecBeb; delete[]vecBDDaux; return false;}

            int j=0;


            for(int i=0; i<cantBDD; i++){
                if(i==0){
                    vecBDD[j] = vecBDDaux[i];
                    j++;
                }
                else{
                    for(int x=0; x<bebdistintas; x++){
                        if(vecBDDaux[i].getCodigo()==vecBDD[x].getCodigo()){
                           if(strcmp(vecBDDaux[i].getNombre().c_str(),vecBDD[i].getNombre().c_str())==0){
                            x=bebdistintas;
                           }
                    }
                    else if(strcmp(vecBDDaux[i].getNombre().c_str(),vecBDD[i].getNombre().c_str())!=0){
                        vecBDD[j] = vecBDDaux[i];
                        j++;
                    }
                    }
                }
            }


             PedidoArchivo PA;
             int canPed = PA.getCantidadRegistros();
             Pedido *vecPeds = new Pedido[canPed];
             if(vecPeds==nullptr){delete[]vecBeb; delete[]vecBDDaux; delete[]vecBDD; return false;}
             PA.leerTodosLosRegistros(vecPeds, canPed);

             float *vecVentaxBeb= new float[bebdistintas];
             if(vecVentaxBeb==nullptr){delete[]vecBeb; delete[]vecBDDaux; delete[]vecBDD; delete[]vecPeds; return false;}

            for(int j=0; j<bebdistintas; j++){
                        float floataux = 0;
                        vecVentaxBeb[j] = floataux;
                        for(int i=0; i<canPed; i++){
                                if(vecPeds[i].getCodBebida()==vecBDD[j].getCodigo()){
                                    floataux = vecBDDaux[j].getPrecio();
                                    vecVentaxBeb[j] += floataux;
                                }
                }
             }


             int aux;
                BebidaDelDia bddaux;
                for(int i=0; i<bebdistintas; i++){
                    for(int j=i+1; j<bebdistintas; j++){
                        if(vecVentaxBeb[j]>vecVentaxBeb[i]){
                            aux = vecVentaxBeb[j];
                            vecVentaxBeb[j] = vecVentaxBeb[i];
                            vecVentaxBeb[i] = aux;

                            bddaux = vecBDD[j];
                            vecBDD[j] = vecBDD[i];
                            vecBDD[i] = bddaux;

                        }
                    }
                }
                rlutil::locate(x,y++);
                std::cout << "PODIO BEBIDAS HISTORICO: " << std::endl;
                y++;
                for(int i=0; i<bebdistintas; i++){
                    rlutil::locate(x,y++);
                     std::cout << "#" << i+1 << " BEBIDA: " << vecBDD[i].getNombre() << vecBDD[i].getPresentacion(); rlutil::locate(x+40,y-1); std::cout << " TOTAL RECAUDADO: $" << vecVentaxBeb[i] << std::endl;
                     x-40;
                }



//delete[]vecHam; delete[]vecHDDaux; delete[]vecHDD; delete[]vecPeds;
return true;

}



bool MasterMind::PodioCombosHistorico()
{
            int x=150, y=5;
            ComboArchivo CA;
            int cantCom = CA.getCantidadRegistros();
            Combo *vecCom = new Combo[cantCom];
            if(vecCom==nullptr){return false;}
            CA.leerTodosLosRegistros(vecCom,cantCom);

            ComboDelDiaArchivo CDDA;
            int cantCDD = CDDA.getCantidadRegistros();
            ComboDelDia *vecCDDaux = new ComboDelDia[cantCDD];
            if(vecCDDaux==nullptr){delete[]vecCom; return false;}
            CDDA.leerTodosLosRegistros(vecCDDaux,cantCDD);

            int comdistintas = cantCom;


            for(int i=0; i<cantCom; i++){
                for(int j=0; j<cantCDD; j++){
                    if(vecCDDaux[j].getCodigo()==vecCom[i].getCodigo()){
                        if(strcmp((vecCDDaux[j].getNombre().c_str()), (vecCom[i].getNombre().c_str()))!=0){
                            comdistintas ++;
                        }
                    }
                }
            }


            //delete[]vecHam;

            ComboDelDia *vecCDD = new ComboDelDia [comdistintas];
            if(vecCDD==nullptr){delete[]vecCom; delete[]vecCDDaux; return false;}

            int j=0;


            for(int i=0; i<cantCDD; i++){
                if(i==0){
                    vecCDD[j] = vecCDDaux[i];
                    j++;
                }
                else{
                    for(int x=0; x<comdistintas; x++){
                        if(vecCDDaux[i].getCodigo()==vecCDD[x].getCodigo()){
                           if(strcmp(vecCDDaux[i].getNombre().c_str(),vecCDD[i].getNombre().c_str())==0){
                            x=comdistintas;
                           }
                    }
                    else if(strcmp(vecCDDaux[i].getNombre().c_str(),vecCDD[i].getNombre().c_str())!=0){
                        vecCDD[j] = vecCDDaux[i];
                        j++;
                    }
                    }
                }
            }


             PedidoArchivo PA;
             int canPed = PA.getCantidadRegistros();
             Pedido *vecPeds = new Pedido[canPed];
             if(vecPeds==nullptr){delete[]vecCom; delete[]vecCDDaux; delete[]vecCDD; return false;}
             PA.leerTodosLosRegistros(vecPeds, canPed);

             float *vecVentaxCom= new float[comdistintas];
             if(vecVentaxCom==nullptr){delete[]vecCom; delete[]vecCDDaux; delete[]vecCDD; delete[]vecPeds; return false;}

            for(int j=0; j<comdistintas; j++){
                        float floataux = 0;
                        vecVentaxCom[j] = floataux;
                        for(int i=0; i<canPed; i++){
                                if(vecPeds[i].getCodCombo()==vecCDD[j].getCodigo()){
                                    floataux = vecCDDaux[j].getPrecio();
                                    vecVentaxCom[j] += floataux;
                                }
                }
             }


             int aux;
                ComboDelDia cddaux;
                for(int i=0; i<comdistintas; i++){
                    for(int j=i+1; j<comdistintas; j++){
                        if(vecVentaxCom[j]>vecVentaxCom[i]){
                            aux = vecVentaxCom[j];
                            vecVentaxCom[j] = vecVentaxCom[i];
                            vecVentaxCom[i] = aux;

                            cddaux = vecCDD[j];
                            vecCDD[j] = vecCDD[i];
                            vecCDD[i] = cddaux;

                        }
                    }
                }
                rlutil::locate(x,y++);
                std::cout << "PODIO COMBOS HISTORICO: " << std::endl;
                y++;
                for(int i=0; i<comdistintas; i++){
                    rlutil::locate(x,y++);
                     std::cout << "#" << i+1 << " COMBO: " << vecCDD[i].getNombre(); rlutil::locate(x+30,y-1); std::cout << " TOTAL RECAUDADO: $" << vecVentaxCom[i] << std::endl;
                     x-30;
                }



//delete[]vecHam; delete[]vecHDDaux; delete[]vecHDD; delete[]vecPeds;
return true;

}
