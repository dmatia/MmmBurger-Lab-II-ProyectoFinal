#include <iostream>
#include <iomanip>
using namespace std;
#include "Caja.h"
#include "rlutil.h"
#include "Pedido.h"
#include "PedidoArchivo.h"
#include "Ticket.h"
#include "TicketArchivo.h"
#include "Validar.h"

#include "Hamburguesa.h"
#include "HamburguesaArchivo.h"
#include "HamburguesaDelDia.h"
#include "HamburguesaDelDiaArchivo.h"

#include "BebidaArchivo.h"
#include "BebidaDelDia.h"
#include "BebidaDelDiaArchivo.h"

#include "Combo.h"
#include "ComboArchivo.h"
#include "ComboDelDia.h"
#include "ComboDelDiaArchivo.h"

#include "Style.h"
#include "ManejoArchivos.h"

Caja::Caja()
{
    //ctor
}

Caja::~Caja()
{
    //dtor
}


bool Caja::agregarPedido(){
    TicketArchivo TA;
    Ticket ticket;
    Fecha fecha;
    int nromesa;
    rlutil::cls();
    rlutil::locate(80,14);
    std::cout << "INGRESE NUMERO DE MESA: " ; validarInput(nromesa,0,1500);

    if(TA.buscarTicketAbiertoPorMesayFecha(nromesa, fecha)!=-1){
        rlutil::locate(80,15);
        std::cout << "SE ENCUENTRA UN PEDIDO EN CURSO PARA ESTA MESA" << std::endl;
        rlutil::locate(80,16);
        std::cout <<  "1. AGREGAR AL PEDIDO | 2. CANCELAR"  << std::endl;
        int ifuno;
        rlutil::locate(80,17);
        validarInput(ifuno,0,3);
        if(ifuno==2){cin.ignore(); rlutil::cls(); return false;}
        ticket = TA.leerRegistro(TA.buscarTicketAbiertoPorMesayFecha(nromesa, fecha));
    }
    else{
        rlutil::locate(80,15);
        std::cout << "CREANDO NUEVO TICKET" << std::endl;
        Sleep(900);
        ticket.setNroMesa(nromesa);
        ticket.setNroTicket(TA.generarNroTicket());
        TA.guardarRegistro(ticket);
    }

    menuPedido(ticket);

    TA.actualizarTicket(ticket,TA.buscarTicketAbiertoPorMesayFecha(nromesa,fecha));



}

bool Caja::menuPedido(Ticket &ticket){
        TicketArchivo TA;
        int salir=-1;
        do{
        int renglon = 8;
        rlutil::cls();
        PedidoArchivo PA;
        int cant = PA.contarPedidosPorTicket(ticket.getNroDeTicket());
        Pedido *vecPedidos = new Pedido [cant];
        if(vecPedidos==nullptr){return false;}
        PA.leerPedidosPorTicket(vecPedidos,cant,ticket.getNroDeTicket());
        rlutil::locate(80,renglon++);
        std::cout << "DETALLE PEDIDO #" << ticket.getNroDeTicket();
        for(int i=0; i<cant; i++){
            if(vecPedidos[i].getCodHamburguesa()!=-1)
            {
                HamburguesaDelDiaArchivo HDDA;
                HamburguesaDelDia HDD;
                HDD = (HDDA.leer(HDDA.buscarPorCodigoyFecha(vecPedidos[i].getCodHamburguesa(),ticket.getFecha())));
                rlutil::locate(80,renglon++);
                std::cout << HDD.getNombre() << " $"<< HDD.getPrecio() << std::endl;
            }
            if(vecPedidos[i].getCodBebida()!=-1){
                BebidaDelDiaArchivo BDDA;
                BebidaDelDia BDD;
                BDD = (BDDA.leer(BDDA.buscarPorCodigoyFecha(vecPedidos[i].getCodBebida(),ticket.getFecha())));
                rlutil::locate(80,renglon++);
                std::cout << BDD.getNombre() << " " << BDD.getCodPresentacion() << " $"<< BDD.getPrecio() << std::endl;

            }
            if(vecPedidos[i].getCodCombo()!=-1){
                ComboDelDiaArchivo CDDA;
                ComboDelDia CDD;
                CDD = (CDDA.leer(CDDA.buscarPorCodigoyFecha(vecPedidos[i].getCodCombo(),ticket.getFecha())));
                rlutil::locate(80,renglon++);
                std::cout << CDD.getNombre()  << " $" << CDD.getPrecio();
            }
        }

        renglon++;
        renglon++;
        rlutil::locate(80,renglon++);
       std::cout << "SUBTOTAL: $" << ticket.getTotal() << std::endl;
        delete[]vecPedidos;
        rlutil::showcursor();
        renglon++;
        renglon++;
        int opcion;
        rlutil::locate(80,renglon++);
        std::cout << "1. AGREGAR HAMBURGUESA "  << std::endl;
        rlutil::locate(80,renglon++);
        std::cout << "2. AGREGAR BEBIDA " << std::endl;
        rlutil::locate(80,renglon++);
        std::cout << "3. AGREGAR COMBO " << std::endl;
        rlutil::locate(80,renglon++);
        std::cout << "4. TERMINAR " << std::endl;
        rlutil::locate(80,renglon++);
        std::cin >> opcion;

        /*if(opcion==1){
            Caja caja;
            if(caja.agregarHamburguesaAPedido(ticket)==true){ std::cout << "PEDIDO DE HAMBURGUESA GENERADO CORRECTAMENTE" << std::endl;}
            else{std::cout << "NO SE PROCESO EL PEDIDO" << std::endl;}
        }*/
        switch(opcion){
        case 1:{
            Caja caja;
            if(caja.agregarHamburguesaAPedido(ticket)==true){ rlutil::locate(80,22); std::cout << "PEDIDO DE HAMBURGUESA GENERADO CORRECTAMENTE" << std::endl; Sleep(900); rlutil::hidecursor();}
            else{rlutil::locate(80,22); std::cout << "NO SE PROCESO EL PEDIDO" << std::endl; Sleep(900); rlutil::hidecursor();
        }
        }
        break;

        case 2:{
            Caja caja;
            if(caja.agregarBebidaAPedido(ticket)==true){ rlutil::locate(80,22); std::cout << "PEDIDO DE BEBIDA GENERADO CORRECTAMENTE" << std::endl; Sleep(900); rlutil::hidecursor();}
            else{rlutil::locate(80,22); std::cout << "NO SE PROCESO EL PEDIDO" << std::endl; Sleep(900); rlutil::hidecursor();
        }
        }
        break;

        case 3:{
            Caja caja;
            if(caja.agregarComboAPedido(ticket)==true){ rlutil::locate(80,22); std::cout << "PEDIDO DE COMBO GENERADO CORRECTAMENTE" << std::endl; Sleep(900); rlutil::hidecursor();}
            else{rlutil::locate(80,22); std::cout << "NO SE PROCESO EL PEDIDO" << std::endl; Sleep(900); rlutil::hidecursor();
        }
        }
        break;

        case 4:{
                salir =0;}
            break;
        }

        }while(salir!=0);
        cin.ignore();
        rlutil::hidecursor();
        rlutil::cls();
}

bool Caja::agregarHamburguesaAPedido(Ticket &ticket){
        rlutil::cls();
        int codham;
        HamburguesaArchivo HA;
        HamburguesaDelDiaArchivo HDDA;
        HamburguesaDelDia HDD;
        rlutil::locate(80,15);
        std::cout << "INGRESE CODIGO DE HAMBURGUESA: " ; validarInput(codham, 0, HA.getCantidadRegistros());
        if(HDDA.buscarPorCodigoyFecha(codham,ticket.getFecha())!=-1){
            HDD = HDDA.leer(HDDA.buscarPorCodigoyFecha(codham,ticket.getFecha()));
            rlutil::locate(80,17);
            std::cout << "DETALLE PRODUCTO: " << HDD.getNombre() << "  $" << HDD.getPrecio() << std::endl ;

            int aceptar;
            rlutil::locate(80,19);
            std::cout << "1. SUMAR A PEDIDO | 2. CANCELAR" << std::endl;
            rlutil::locate(80,20);
            validarInput(aceptar, 0,3);
            if(aceptar==2){return false;}
            else{
            if(HDD.verificarIngredientesDisponibles()==false){
                    HDDA.modificarRegistro(HDD, HDDA.buscarPorCodigoyFecha(HDD.getCodigo(), HDD.getFecha()));
                    rlutil::locate(80,22);
                    std::cout << "1 O MAS COMPONENTES DE ESTA HAMBURGUESA SE ENCUENTRAN SIN STOCK" << std::endl;
                    rlutil::locate(80,23);
                    std::cout << "1. CONTINUAR | 2.CANCELAR" << std::endl;
                    int opc2;
                    rlutil::locate(80,24);
                    validarInput(opc2, 0, 3);
                    if(opc2==2){
                        std::cin.ignore();
                        rlutil::cls();
                        return false;
                    }
                }
                    if(ticket.agregarPedido(1,codham)==true){
                            rlutil::cls();
                            std::cin.ignore();
                            return true;
                }
                else{
                   // std::cout << "ERROR AL GENERAR PEDIDO" << std::endl;
                    Sleep(900);
                    std::cin.ignore();
                    return false;
                }
            }
        }
        else{
            rlutil::locate(80,19);
            std::cout << "LA HAMBURGUESA SOLICITADA NO SE ENCUENTRA DISPONIBLE EN LA FECHA" << std::endl;
            system("pause");
            Sleep(900);
            std::cin.ignore();
            return false;
        }
}

bool Caja::agregarBebidaAPedido(Ticket &ticket){
        rlutil::cls();
        int codbeb;
        BebidaArchivo BA;
        BebidaDelDiaArchivo BDDA;
        BebidaDelDia BDD;
        rlutil::locate(80,15);
        std::cout << "INGRESE CODIGO DE BEBIDA: " ; validarInput(codbeb, 0, BA.getCantidadRegistros());
        if(BDDA.buscarPorCodigoyFecha(codbeb,ticket.getFecha())!=-1){
            BDD = BDDA.leer(BDDA.buscarPorCodigoyFecha(codbeb,ticket.getFecha()));
            rlutil::locate(80,17);
            std::cout << "DETALLE PRODUCTO: " << BDD.getNombre() << BDD.getPresentacion() << "  $" << BDD.getPrecio() << std::endl ;

            int aceptar;
            rlutil::locate(80,19);
            std::cout << "1. SUMAR A PEDIDO | 2. CANCELAR" << std::endl;
            rlutil::locate(80,20);
            validarInput(aceptar, 0,3);
            if(aceptar==2){return false;}
            else{
            if(BDD.comprobarStock()==false){
                    BDDA.modificarRegistro(BDD, BDDA.buscarPorCodigoyFecha(BDD.getCodigo(), BDD.getFecha()));
                    rlutil::locate(80,22);
                    std::cout << "LA BEBIDA SOLICITADA SE ENCUENTRA SIN STOCK" << std::endl;
                    rlutil::locate(80,23);
                    std::cout << "1. CONTINUAR | 2.CANCELAR" << std::endl;
                    int opc2;
                    rlutil::locate(80,24);
                    validarInput(opc2, 0, 3);
                    if(opc2==2){
                        std::cin.ignore();
                        rlutil::cls();
                        return false;
                    }
                }
                    if(ticket.agregarPedido(2,codbeb)==true){
                            rlutil::cls();
                            std::cin.ignore();
                            return true;
                }
                else{
                   // std::cout << "ERROR AL GENERAR PEDIDO" << std::endl;
                    Sleep(900);
                    std::cin.ignore();
                    return false;
                }
            }
        }
        else{
            rlutil::locate(80,19);
            std::cout << "LA BEBIDA SOLICITADA NO SE ENCUENTRA DISPONIBLE EN LA FECHA" << std::endl;
            system("pause");
            Sleep(900);
            std::cin.ignore();
            return false;
        }
}

bool Caja::agregarComboAPedido(Ticket &ticket){
        rlutil::cls();
        int codcomb;
        ComboArchivo CA;
        ComboDelDiaArchivo CDDA;
        ComboDelDia CDD;
        rlutil::locate(80,15);
        std::cout << "INGRESE CODIGO DE COMBO: " ; validarInput(codcomb, 0, CA.getCantidadRegistros());
        if(CDDA.buscarPorCodigoyFecha(codcomb,ticket.getFecha())!=-1){
            CDD = CDDA.leer(CDDA.buscarPorCodigoyFecha(codcomb,ticket.getFecha()));
            rlutil::locate(80,17);
            std::cout << "DETALLE PRODUCTO: " << CDD.getNombre() << "  $" << CDD.getPrecio() << std::endl ;

            int aceptar;
            rlutil::locate(80,19);
            std::cout << "1. SUMAR A PEDIDO | 2. CANCELAR" << std::endl;
            rlutil::locate(80,20);
            validarInput(aceptar, 0,3);
            if(aceptar==2){return false;}
            else{
            if(CDD.comprobarStock()==false){
                   // CDDA.modificarRegistro(CDD, CDDA.buscarPorCodigoyFecha(CDD.getCodigo(), CDD.getFecha()));
                    rlutil::locate(80,22);
                    std::cout << "1 O MAS COMPONENTES DEL COMBO SOLICITADO SE ENCUENTRA SIN STOCK" << std::endl;
                    rlutil::locate(80,23);
                    std::cout << "1. CONTINUAR | 2.CANCELAR" << std::endl;
                    int opc2;
                    rlutil::locate(80,24);
                    validarInput(opc2, 0, 3);
                    if(opc2==2){
                        std::cin.ignore();
                        rlutil::cls();
                        return false;
                    }
                }
                    if(ticket.agregarPedido(3,codcomb)==true){
                            rlutil::cls();
                            std::cin.ignore();
                            return true;
                }
                else{
                   // std::cout << "ERROR AL GENERAR PEDIDO" << std::endl;
                    Sleep(900);
                    std::cin.ignore();
                    return false;
                }
            }
        }
        else{
            rlutil::locate(80,19);
            std::cout << "EL COMBO SOLICITADO NO SE ENCUENTRA DISPONIBLE EN LA FECHA" << std::endl;
            system("pause");
            Sleep(900);
            std::cin.ignore();
            return false;
        }
}








void Caja::verTicketsAbiertos(){
        int salir = -1;
        do{
        rlutil::cls();
        TicketArchivo TA;
        int cant = TA.contarTicketsAbiertos();
        if(cant==0){rlutil::locate(90,20); std::cout << "NO HAY TICKETS ABIERTOS" << std::endl; Sleep(900); rlutil::cls(); salir=0;}
        else{
        Ticket *vecTA = new Ticket[cant];
        TA.leerTodosLosTicketsAbiertos(vecTA, cant);
        int renglon = 5;
        rlutil::locate(40,renglon++);
        for(int i=0; i<cant; i++){
            rlutil::locate(40,renglon++);
            std::cout << "--------------------------------" << std::endl << std::endl;
            rlutil::locate(40,renglon++);
            std::cout << "TICKET #" << vecTA[i].getNroDeTicket() << "   " << "MESA #" << vecTA[i].getNroMesa() << std::endl;
            rlutil::locate(40,renglon++);
            std::cout << "FECHA: " << vecTA[i].getFecha().getDia() << "/" << vecTA[i].getFecha().getMes() << "/" << vecTA[i].getFecha().getAnio() << std::endl;
            PedidoArchivo PA;
            int cantPed = PA.contarPedidosPorTicket(vecTA[i].getNroDeTicket());
            Pedido *vecPedidos = new Pedido[cantPed];
            if(vecPedidos==nullptr){return;}
            PA.leerPedidosPorTicket(vecPedidos,cantPed,vecTA[i].getNroDeTicket());
            rlutil::locate(40,renglon++);
            std::cout << "DETALLE:" << std::endl;
            for(int j=0; j<cantPed; j++){
                if(vecPedidos[j].getCodHamburguesa()!=-1){
                    HamburguesaDelDia HDD;
                    HamburguesaDelDiaArchivo HDDA;
                    HDD = HDDA.leer(HDDA.buscarPorCodigoyFecha(vecPedidos[j].getCodHamburguesa(),vecPedidos[j].getFecha()));
                    rlutil::locate(40,renglon++);
                    std::cout << j+1 <<" - " << HDD.getNombre() << " $" << HDD.getPrecio() << std::endl;}

                if(vecPedidos[j].getCodBebida()!=-1){
                    BebidaDelDia BDD;
                    BebidaDelDiaArchivo BDDA;
                    BDD = BDDA.leer(BDDA.buscarPorCodigoyFecha(vecPedidos[j].getCodBebida(),vecPedidos[j].getFecha()));
                    rlutil::locate(40,renglon++);
                    std::cout << j+1 <<" - " << BDD.getNombre() << BDD.getPresentacion() << " $" << BDD.getPrecio() << std::endl;}

                if(vecPedidos[j].getCodCombo()!=-1){
                    ComboDelDia CDD;
                    ComboDelDiaArchivo CDDA;
                    CDD = CDDA.leer(CDDA.buscarPorCodigoyFecha(vecPedidos[j].getCodCombo(),vecPedidos[j].getFecha()));
                    rlutil::locate(40,renglon++);
                    std::cout << j+1 <<" - " << CDD.getNombre() << " $" << CDD.getPrecio() << std::endl;}
            }

            rlutil::locate(40,renglon++);
            std::cout << "TOTAL: $" << vecTA[i].getTotal() << std::endl << std::endl;

        }

        rlutil::locate(40,renglon++);
        std::cout << "--------------------------------" << std::endl << std::endl;

        int renglon1 = 10;
        rlutil::locate(90, renglon1++);
        std::cout << "      MENU      " << std::endl;
        rlutil::locate(90, renglon1++);
        std::cout << "----------------" << std::endl;
        rlutil::locate(90, renglon1++);
        std::cout << "1. CERRAR TICKET" << std::endl;
        rlutil::locate(90, renglon1++);
        std::cout << "2. SALIR" << std::endl;
        rlutil::locate(90, renglon1++);
        int opcion;
        std::cout << "INGRESE RESPUESTA: " ; validarInput(opcion,0,3);
        if(opcion==1){
            if(cerrarTicket(renglon1)==true){
                rlutil::locate(90, renglon1++);
                std::cout << "TICKET CERRADO" << std::endl;
                Sleep(900);

            }
            else{
                rlutil::locate(90, renglon1++);
                std::cout << "OPERACION CANCELADA" << std::endl;
                Sleep(900);
            }
        }
        else{
            salir=0;
        }
        }
        }while(salir!=0);


        std::cin.ignore();
        rlutil::cls();
}

bool Caja::cerrarTicket(int &renglon){

        rlutil::locate(90, renglon++);
        int nroticket;
        TicketArchivo TA;
        Ticket ticket;
        std::cout << "INGRESE NRO DE TICKET: " ; validarInput(nroticket,0,TA.getCantidadRegistros()+1);
        ticket = TA.leerRegistro(TA.buscarTickerPorCodigo(nroticket));
        if (ticket.getEstado()==true){
                ticket.setEstado(false);
                PedidoArchivo PA;
                PA.cerrarPedidoPorTicket(nroticket);
                TA.actualizarTicket(ticket,TA.buscarTickerPorCodigo(nroticket));
                return true;
        }
        else{
            rlutil::locate(90, renglon++);
            std::cout << "EL TICKET INGRESADO YA HA SIDO CERRADO" << std::endl;
            Sleep(900);
            cin.ignore();
            return false;
        }
}

void Caja::verProductosDisponibles(){
    int salir = -1;
    do{
        cin.ignore();
        rlutil::cls();
        Fecha fechaaux;
        std::cout << "FECHA: " << fechaaux.getDia() << "/" << fechaaux.getMes() << "/" << fechaaux.getAnio() << std::endl;
        Style STL;
        ManejoArchivos MA;
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
            rlutil::locate(80, 4);
            int renglon = 0;
            std::cout << "            BEBIDAS DISPONIBLES         " << std::endl ;
            rlutil::locate(80,5);
            std::cout << std::left << "|" << std::setw(5) << "COD" <<
     "|" << std::setw(25) << "NOMBRE" <<
     "|" << std::setw(7)  << "PRECIO" <<  std::endl;
            for(int i=0; i<cant; i++){
                if(vecBebDD[i].getFecha()==fechaaux){

                        STL.showItemDelDiaCaja2(vecBebDD[i].getEstado(), vecBebDD[i].getCodigo(),
                                              vecBebDD[i].getNombre()+vecBebDD[i].getPresentacion(),
                                              vecBebDD[i].getPrecio(),
                                              80,6+renglon);
                                              renglon++;
            }
            }
           // delete[]vecBebDD;
            }
        else{
            rlutil::locate(80,5);
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
            rlutil::locate(35, 4);
            int renglon = 0;
            std::cout << "        HAMBURGUESAS DISPONIBLES        " << std::endl ;
            rlutil::locate(35,5);
            std::cout << std::left << "|" << std::setw(5) << "COD" <<
     "|" << std::setw(25) << "NOMBRE" <<
     "|" << std::setw(7)  << "PRECIO" <<
    std::endl;
            for(int i=0; i<cant; i++){
                if(vecADD[i].getFecha()==fechaaux){
                        STL.showItemDelDiaCaja2(vecADD[i].getEstado(),vecADD[i].getCodigo(),
                                              vecADD[i].getNombre(),
                                              vecADD[i].getPrecio()
                                              ,35,6+renglon);
                                              renglon++;}

                }
                // delete[]vecADD;
            }
        else{
            rlutil::locate(35,5);
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
            rlutil::locate(125, 4);
            int renglon = 0;
            std::cout << "           COMBOS DISPONIBLES           " << std::endl ;
            rlutil::locate(125,5);
            std::cout << std::left << "|" << std::setw(5) << "COD" <<
     "|" << std::setw(25) << "NOMBRE" <<
     "|" << std::setw(7)  << "PRECIO" <<
    std::endl;
            for(int i=0; i<cant; i++){
                        STL.showItemDelDiaCaja2(vecCDD[i].getEstado(),
                                             vecCDD[i].getCodigo(),
                                              vecCDD[i].getNombre(),
                                              vecCDD[i].getPrecio()
                                              ,125,6+renglon);
                                              renglon++;

            }
            // delete[]vecCDD;
            }
        else{
            rlutil::locate(125,5);
            std::cout << "     LISTADO DE  COMBOS INEXISTENTE   " << std::endl ;
        }



        rlutil::setBackgroundColor(rlutil::BLACK);

        rlutil::locate(1,30);
        std::cout << "1. AGREGAR PEDIDO | 2. SALIR" << std::endl;
        int opc;
        std::cout << "OPCION: " ; std::cin >> opc;
        switch(opc){
            case 1:{
                agregarPedido();
                }
                break;
            case 2: {
                salir = 0;
                }
                break;
            default:{
                std::cout << "OPCION INVALIDA" << std::endl;
                }
                break;
                }
        }while(salir!=0);
        rlutil::cls();

    }
