#include <iostream>
#include "Menu.h"
#include "Style.h"
#include "rlutil.h"
#include "Administrador.h"
#include "Validar.h"
#include "MasterMind.h"
#include "Caja.h"

Menu::Menu()
{
    //ctor
}

Menu::~Menu()
{
    //dtor
}

void Menu::menuAdministrador(){
 Style ST;
 rlutil::cls();
 int opc = -1, y=0;
    rlutil::hidecursor();
   do{
    ST.showItemMenuAdministrador("                                                ", 80, 19, 0);
    ST.showItemMenuAdministrador(" 1.INGRESAR INGREDIENTES PARA DE LA FECHA       ", 80, 20, y == 0);
    ST.showItemMenuAdministrador(" 2.VER/MODIFICAR PRODUCTOS Y STOCKS DE LA FECHA ", 80, 21, y == 1);
    ST.showItemMenuAdministrador(" 3.VER/MODIFICAR PRODUCTOS EXISTENTES           ", 80, 22, y == 2);
    ST.showItemMenuAdministrador(" 4.INGRESAR NUEVO PRODUCTO                      ", 80, 23, y == 3);
    ST.showItemMenuAdministrador(" 5.VER MENU REPORTES                            ", 80, 24, y == 4);
    ST.showItemMenuAdministrador(" 6.CREAR/RECUPERAR BACKUP                       ", 80, 25, y == 5);
    ST.showItemMenuAdministrador(" 7.CAMBIAR CONTRASEÑA                           ", 80, 26, y == 6);
    ST.showItemMenuAdministrador(" 8.VOLVER AL MENU PRINCIPAL                     ", 80, 27, y == 7);
    ST.showItemMenuAdministrador("                                                ", 80, 28, 0);
    rlutil::anykey();
    int key = rlutil::getkey();

switch(key){

    case 72:
    rlutil::locate(18, 6 + y);
    std::cout << "  " << std::endl;
    y--;
    if(y<=0){y=0;}
    break;;

    case 80:
    rlutil::locate(18, 6+y);
    std::cout << "  " << std::endl;
    y++;
    if(y>7){y=7;}
    break;

    case 1:
        switch(y){

        case 0:{
            menuCargarIngredientesDeLaFecha();
        }
            break;
        case 1:{
                MasterMind mm;
                mm.mostrarProductosDelDia();
                }
            break;
        case 2:
                {
                    MasterMind mm;
                    mm.mostrarProductosDisponibles();
                }
                break;

        case 3:
                menuNuevoProducto();
                break;
        case 4:{
                Administrador adm;
                adm.menuReportes();
                }
                break;
        case 5:{
                Administrador adm;
                adm.backupmenu();
                }
                break;
        case 6:{
                Administrador adm;
                adm.cambiarContrasenia();
                }
        case 7:{
                rlutil::cls();
                opc=0;}
                break;
        }
    }
   }while(opc!=0);

}

void Menu::menuCargarIngredientesDeLaFecha(){
    rlutil::cls();
    int opc = -1, y=0;
    rlutil::hidecursor();
    Style ST;
    do{
    ST.showItemMenuAdministrador("                                ", 85, 19, 0);
    ST.showItemMenuAdministrador(" 1. CARGAR INGREDIENTES DEL DIA ", 85, 20, y == 0);
    ST.showItemMenuAdministrador(" 2. CARGAR BEBIDAS DEL DIA      ", 85, 21, y == 1);
    ST.showItemMenuAdministrador(" 3. GENERAR HAMB/COMB DEL DIA   ", 85, 22, y == 2);
    ST.showItemMenuAdministrador(" 4. VOLVER AL MENU ANTERIOR     ", 85, 23, y == 3);
    ST.showItemMenuAdministrador("                                ", 85, 24, 0);
    rlutil::anykey();
    int key = rlutil::getkey();
    switch(key){

    case 72:
    rlutil::locate(18, 6 + y);
    std::cout << "  " << std::endl;
    y--;
    if(y<=0){y=0;}
    break;;

    case 80:
    rlutil::locate(18, 6+y);
    std::cout << "  " << std::endl;
    y++;
    if(y>3){y=3;}
    break;

    case 1:

        switch(y){
        case 0:{
            Administrador adm;
            int salir;
            do{
                adm.cargarIngredientesDelDia();
                rlutil::locate(85,25);
                std::cout << "1. CARGAR OTRO INGREDIENTE | 2. TERMINAR" << std::endl;
                rlutil::locate(85,26);
                validarInput(salir,0,3);
                if(salir==2){rlutil::cls(); std::cin.ignore(); salir=0;}
                std::cin.ignore();
                    }while(salir!=0);
        }
        break;

        case 1:{
        Administrador adm;
            int salir;
            do{
                adm.cargarBebidasDelDia();
                rlutil::locate(85,25);
                std::cout << "1. CARGAR OTRA BEBIDA | 2. TERMINAR" << std::endl;
                rlutil::locate(85,26);
                validarInput(salir,0,3);
                if(salir==2){rlutil::cls(); std::cin.ignore(); salir=0;}
                std::cin.ignore();
                    }while(salir!=0);
        }
        break;

        case 2:{
                MasterMind mm;
                if(mm.generarHamburguesasDelDia()){
                    rlutil::locate(85,26);
                    std::cout << "- HAMBURGUESAS DEL DIA GENERADO CORRECTAMENTE" << std::endl;}
                 if(mm.generarCombosDelDia()){
                    rlutil::locate(85,27);
                    std::cout << "- COMBOS DEL DIA GENERADO CORRECTAMENTE" << std::endl;}
                    Sleep(900);
                    rlutil::cls();
                }
        break;

        case 3:{
        opc=0;
        }


    }
    }
    }while(opc!=0);
    }

void Menu::menuNuevoProducto(){
    rlutil::cls();
    int opc = -1, y=0;
    rlutil::hidecursor();

    Style ST;
    do{
    ST.showItemMenuAdministrador("                             ", 85, 19, 0);
    ST.showItemMenuAdministrador(" 1. NUEVO INGREDIENTE        ", 85, 20, y == 0);
    ST.showItemMenuAdministrador(" 2. NUEVA BEBIDA             ", 85, 21, y == 1);
    ST.showItemMenuAdministrador(" 3. NUEVA HAMBURGUESA        ", 85, 22, y == 2);
    ST.showItemMenuAdministrador(" 4. NUEVO COMBO              ", 85, 23, y == 3);
    ST.showItemMenuAdministrador(" 5. VOLVER AL MENU ANTERIOR  ", 85, 24, y == 4);
    ST.showItemMenuAdministrador("                             ", 85, 25, 0);
    rlutil::anykey();
    int key = rlutil::getkey();
    switch(key){

    case 72:
    rlutil::locate(18, 6 + y);
    std::cout << "  " << std::endl;
    y--;
    if(y<=0){y=0;}
    break;;

    case 80:
    rlutil::locate(18, 6+y);
    std::cout << "  " << std::endl;
    y++;
    if(y>4){y=4;}
    break;

    case 1:

        switch(y){
        case 0:{
            Administrador adm;
            int salir;
            do{
            adm.agregarNuevoIngrediente();
            rlutil::locate(85,25);
            std::cout << "1. AGREGAR OTRO INGREDIENTE | 2. TERMINAR" << std::endl;
            rlutil::locate(85,26);
            validarInput(salir,0,3);
            if(salir==2){rlutil::cls(); salir=0; std::cin.ignore();}
            std::cin.ignore();
                }while(salir!=0);
        }
        break;

        case 1:{
            Administrador adm;
            int salir;
            do{
            adm.agregarNuevaBebida();
            rlutil::locate(85,25);
            std::cout << "1. AGREGAR OTRA BEBIDA | 2. TERMINAR" << std::endl;
            rlutil::locate(85,26);
            validarInput(salir,0,3);
            if(salir==2){rlutil::cls(); salir=0; std::cin.ignore(); }
            std::cin.ignore();
                }while(salir!=0);
        }
        break;


        case 2:{
            Administrador adm;
            int salir;
            do{
            adm.agregarNuevaHamburguesa();
            rlutil::locate(85,25);
            std::cout << "1. AGREGAR OTRA HAMBURGUESA | 2. TERMINAR" << std::endl;
            rlutil::locate(85,26);
            validarInput(salir,0,3);
            if(salir==2){rlutil::cls(); salir=0; std::cin.ignore(); }
            std::cin.ignore();
                }while(salir!=0);
        }
        break;

        case 3:{
            Administrador adm;
            int salir;
            do{
            adm.agregarNuevoCombo();
            rlutil::locate(85,25);
            std::cout << "1. AGREGAR OTRO COMBO | 2. TERMINAR" << std::endl;
            rlutil::locate(85,26);
            validarInput(salir,0,3);
            if(salir==2){rlutil::cls(); salir=0; std::cin.ignore(); }
            std::cin.ignore();
                }while(salir!=0);
        }
        break;

        case 4:{
        opc=0;
        }


    }
    }
    }while(opc!=0);
    }


void::Menu::menuCaja(){
Style ST;
 rlutil::cls();
 int opc = -1, y=0;
    rlutil::hidecursor();
   do{
    ST.showItemMenuCaja("                                         ", 80, 19, 0);
    ST.showItemMenuCaja(" 1. AGREGAR PEDIDO                       ", 80, 20, y == 0);
    ST.showItemMenuCaja(" 2. VER PEDIDOS ABIERTOS / CERRAR TICKET ", 80, 21, y == 1);
    ST.showItemMenuCaja(" 3. VER PRODUCTOS DISPONIBLES            ", 80, 22, y == 2);
    ST.showItemMenuCaja(" 4. VOLVER                               ", 80, 23, y == 3);
    ST.showItemMenuCaja("                                         ", 80, 24, 0);
    rlutil::anykey();
    int key = rlutil::getkey();

switch(key){

    case 72:
    rlutil::locate(18, 6 + y);
    std::cout << "  " << std::endl;
    y--;
    if(y<=0){y=0;}
    break;;

    case 80:
    rlutil::locate(18, 6+y);
    std::cout << "  " << std::endl;
    y++;
    if(y>3){y=3;}
    break;

    case 1:
        switch(y){

        case 0:{
                    Caja caja;
                    caja.agregarPedido();
                }
            break;
        case 1:{
                    Caja caja;
                    caja.verTicketsAbiertos();
                }
            break;
        case 2:
                {
                    Caja caja;
                    caja.verProductosDisponibles();
                }
                break;

        case 3:{
                rlutil::cls();
                opc=0;}
                break;
        }
    }
   }while(opc!=0);

}
