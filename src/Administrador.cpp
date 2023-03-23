#include <iostream>
#include "rlutil.h"
#include "Administrador.h"
#include "Style.h"
#include <cstring>
#include "Validar.h"
#include "Fecha.h"

#include "Ingrediente.h"
#include "IngredienteArchivo.h"
#include "IngredienteDelDia.h"
#include "IngredienteDelDiaArchivo.h"

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

#include "ManejoArchivos.h"
#include "MasterMind.h"

#include "TicketArchivo.h"


Administrador::Administrador()
{
    //ctor
}

Administrador::~Administrador()
{
    //dtor
}

bool Administrador::agregarNuevoIngrediente()
{
    rlutil::cls();
    Ingrediente ing;
    IngredienteArchivo IA;
    std::string nombre;
    int codigo = IA.generarCodigo(), aceptar;
    ing.setCodigo(codigo);
    float precio;
    rlutil::showcursor();
    rlutil::locate(80,15);
    std::cout << "EL CODIGO DE SU NUEVO INGRDIENTE SERÁ: #" << ing.getCodigo() << std::endl;
    rlutil::locate(80,16);
    std::cout << "INGRESE NOMBRE: " ; getline(std::cin,nombre); ing.setNombre(nombre);
    rlutil::locate(80,17);
    std::cout << "INGRESE PRECIO: $" ; validarInput(precio,0,100000); ing.setPrecio(precio);
    rlutil::locate(80,18);
    std::cout << "--------------------------------------------------------------------" << std::endl;
    rlutil::locate(80,20);
    std::cout << "SU NUEVO INGREDIENTE: " << std::endl;
    rlutil::locate(80,21);
    std::cout << "CODIGO #: " << ing.getCodigo() << std::endl;
    rlutil::locate(80,22);
    std::cout << "NOMBRE: " << ing.getNombre() << std::endl;
    rlutil::locate(80,23);
    std::cout << "PRECIO: $" << ing.getPrecio() << std::endl << std::endl;
    rlutil::locate(80,25);
    std::cout << "1. ACEPTAR | 2. CANCELAR" << std::endl;
    rlutil::locate(80,26);
    std::cout << "INGRESAR OPCION: " ; validarInput(aceptar,0,3);
    if(aceptar==1){
        if(IA.guardarRegistro(ing)==true)
            {rlutil::locate(80,27);
            std::cout <<"REGISTRO GUARDADO CORRECTAMENTE" << std::endl;
            Sleep(600); std::cin.ignore();
            rlutil::cls();
            rlutil::hidecursor();
            return true;
            }
            rlutil::locate(80,27);
            std::cout << "ERROR AL GUARDAR REGISTRO" << std::endl;
            Sleep(600);
            std::cin.ignore();
            rlutil::cls();
            rlutil::hidecursor();
            return false;
    }
    else{
            rlutil::locate(80,27);
            std::cout << "PROCESO CANCELADO" ;
            Sleep(600);
            std::cin.ignore();
            rlutil::cls();
            rlutil::hidecursor();
            return false;}


}

bool Administrador::agregarNuevaBebida()
{
    rlutil::cls();
    Bebida beb;
    BebidaArchivo BA;
    std::string nombre;
    int codigo = BA.generarCodigo(), aceptar, presentacion;
    beb.setCodigo(codigo);
    float precio;
    rlutil::showcursor();
    rlutil::locate(80,15);
    std::cout << "EL CODIGO DE SU NUEVA BEBIDA SERÁ: #" << beb.getCodigo() << std::endl;
    rlutil::locate(80,16);
    std::cout << "INGRESE NOMBRE: " ; getline(std::cin,nombre); beb.setNombre(nombre);
    rlutil::locate(80,17);
    std::cout << "INGRESE COD PRESENTACION: " ; validarInput(presentacion,0,3); beb.setPresentacion(presentacion);
    rlutil::locate(80,18);
    std::cout << "INGRESE PRECIO: $" ; validarInput(precio,0,100000); beb.setPrecio(precio);
    rlutil::locate(80,19);
    std::cout << "--------------------------------------------------------------------" << std::endl;
    rlutil::locate(80,21);
    std::cout << "SU NUEVA BEBIDA: " << std::endl;
    rlutil::locate(80,22);
    std::cout << "CODIGO #: " << beb.getCodigo() << std::endl;
    rlutil::locate(80,23);
    std::cout << "NOMBRE: " << beb.getNombre() << " " << beb.getPresentacion() << std::endl;
    rlutil::locate(80,24);
    std::cout << "PRECIO: $" << beb.getPrecio() << std::endl << std::endl;
    rlutil::locate(80,26);
    std::cout << "1. ACEPTAR | 2. CANCELAR" << std::endl;
    rlutil::locate(80,27);
    std::cout << "INGRESAR OPCION: " ; validarInput(aceptar,0,3);
    if(aceptar==1){
        if(BA.guardarRegistro(beb)==true)
            {rlutil::locate(80,29);
            std::cout <<"REGISTRO GUARDADO CORRECTAMENTE" << std::endl;
            Sleep(600); std::cin.ignore();
            rlutil::cls();
            rlutil::hidecursor();
            return true;
            }
            rlutil::locate(80,29);
            std::cout << "ERROR AL GUARDAR REGISTRO" << std::endl;
            Sleep(600);
            std::cin.ignore();
            rlutil::cls();
            rlutil::hidecursor();
            return false;
    }
    else{
            rlutil::locate(80,29);
            std::cout << "PROCESO CANCELADO" ;
            Sleep(600);
            std::cin.ignore();
            rlutil::cls();
            rlutil::hidecursor();
            return false;}
}

bool Administrador::agregarNuevaHamburguesa(){
    int opcion;
    Style ST;

    HamburguesaArchivo HA;
    Hamburguesa nuevaHamburguesa;
    std::string nombre;
    float precio;
    nuevaHamburguesa.setCodigo(HA.generarCodigo());
    rlutil::cls();
    rlutil::showcursor();
    rlutil::locate(80,15);
    std::cout << "EL COD DE SU NUEVA HAMBURGUESA SERÁ: #" << nuevaHamburguesa.getCodigo() << std::endl;
    rlutil::locate(80,16);
    std::cout << "INGRESAR NOMBRE DE HAMBURGUESA: "; getline(std::cin, nombre); nuevaHamburguesa.setNombre(nombre) ; std::cout << std::endl;
    rlutil::locate(80,17);
    std::cout << "INGRESAR PRECIO HAMBURGUESA: "; validarInput(precio, 0, 100000); nuevaHamburguesa.setPrecio(precio); std::cout << std::endl;
    rlutil::cls();
    rlutil::locate(80,19);
    std::cout << "SU NUEVA HAMBURGUESA " << std::endl;
    rlutil::locate(80,20);
    std::cout << "--------------------" << std::endl << std::endl;
    rlutil::locate(80,21);
    std::cout << "CODIGO: " << nuevaHamburguesa.getCodigo() << std::endl;
    rlutil::locate(80, 22);
    std::cout << "NOMBRE: " << nuevaHamburguesa.getNombre() << std::endl;
    rlutil::locate(80, 23);
    std::cout << "PRECIO: $" << nuevaHamburguesa.getPrecio() << std::endl;

    rlutil::locate(80,24);
    std::cout << "--------------------" << std::endl << std::endl;
    rlutil::locate(80,26);
    std::cout << "1. ACEPTAR Y CONTINUAR || 2. CANCELAR" << std::endl << std::endl;
    rlutil::locate(80,27);
    validarInput(opcion,0,3);
    if(opcion==1){
    HA.guardarRegistro(nuevaHamburguesa);
    cargarIngredientesDeHamburguesa(nuevaHamburguesa);
    }
    rlutil::hidecursor(); std::cin.ignore(); rlutil::cls();
}

bool Administrador::cargarIngredientesDeHamburguesa(Hamburguesa &nuevahamburguesa){
    int opc2;
    do{
        rlutil::cls();
        std::cin.ignore();
        int codIng, cantidad, aceptar;
        IngredienteArchivo IA;
        Ingrediente ing;
        IngDeHambuguesa idh;
        IngDeHamburguesaArchivo IDHA;
        rlutil::locate(80,15);
        std::cout << "A CONTINUACION INGRESE LOS INGREDIENTES DE SU NUEVA HAMBURGUESA " ;
        rlutil::locate(80,16);
        std::cout << "--------------------------------------------------------------: " ;
        rlutil::locate(80,17);
        std::cout << "INGRESE CODIGO DE INGREDIENTE: " , validarInput(codIng,0,IA.getCantidadRegistros());
        if (IDHA.buscarIngrediente(nuevahamburguesa.getCodigo(), codIng)==-1){
        ing = IA.leerRegistro(IA.buscarRegistroPorCodigo(codIng));
        rlutil::locate(80,18);
        std::cout << "--------------------------------------------------------------: " ;
        rlutil::locate(80,19);
        std::cout << "COD #" << ing.getCodigo() << " " << ing.getNombre() ;
        rlutil::locate(80,20);
        std::cout << "INGRESE CANTIDAD/HAMBURGUESA: " ; validarInput(cantidad,0,1500);
        rlutil::locate(80,21);
        std::cout << "--------------------------------------------------------------: " ;
        rlutil::locate(80,23);
        std::cout << "1. ACEPTAR | 2. CANCELAR"<< std::endl ;
        rlutil::locate(80,24);
        validarInput(aceptar,0,3);
        if(aceptar==1){
            idh.setCodigoHamburguesa(nuevahamburguesa.getCodigo());
            idh.setCodigoIngrediente(codIng);
            idh.setCantidad(cantidad);

            if((IDHA.guardar(idh))==true){
                    rlutil::cls();
                    rlutil::locate(80,24);
                    std::cout << "REGISTRO GUARDADO" << std::endl;
                     Sleep(600);
                     std::cin.ignore();
                     rlutil::cls();
                    }
            else{
                    rlutil::cls();
                    rlutil::locate(80,24);
                    std::cout << "OPERACION CANCELADA" << std::endl;
                    Sleep(600);
                    std::cin.ignore();
                    rlutil::cls();
            }
            }
        }
        else{
            rlutil::locate(80,18);
            std::cout << "EL INGREDIENTE INGRESADO YA SE ENCUENTRA EN LA HAMBURGUESA. PARA MODIFICARLO INGRESE AL MENU DE MODIFICAR PRODUCTOS EXISTENTES." << std::endl;
        }
            rlutil::locate(80,26);
            std::cout << "1. AGREGAR OTRO INGREDIENTE | 2. TERMINAR " << std::endl;
            rlutil::locate(80,27);
            validarInput(opc2,0,3);
            if(opc2==2){
                opc2 = 0;
            }
            std::cin.ignore();
            rlutil::cls();

        }while (opc2!=0);
        std::cin.ignore();
        rlutil::cls();
    }

bool Administrador::agregarNuevoCombo(){
        int opcionC;
        Combo nuevocombo;
        ComboArchivo CA;
        HamburguesaArchivo HA;
        BebidaArchivo BA;
        Hamburguesa hamburguesaaux;
        Bebida bebidaaux;
        std::string nombre;
        int codhamburguesa, codbebida;
        float precio;

        nuevocombo.setCodigo(CA.generarCodigo());

        rlutil::cls();
        Style ST;
        rlutil::showcursor();
        rlutil::locate(80,15);
        std::cout << "EL CODIGO DE SU NUEVO COMBO SERA: " << nuevocombo.getCodigo() << std::endl;
        rlutil::locate(80,16);
        std::cout << "INGRESAR NOMBRE DEL COMBO: " ; getline(std::cin, nombre);
        rlutil::locate(80,17);
        std::cout << "INGRESAR CODIGO DE HAMBURGUESA: " ; validarInput(codhamburguesa, 0, HA.getCantidadRegistros()+1);
        rlutil::locate(80,18);
        std::cout << "INGRESAR CODIGO DE BEBIDA: " ; validarInput(codbebida, 0, BA.getCantidadRegistros()+1);
        nuevocombo.setBebida(codbebida);
        nuevocombo.setNombre(nombre);
        nuevocombo.setHamburguesa(codhamburguesa);
        nuevocombo.setPrecio(nuevocombo.generarPrecio());
        rlutil::locate(80,19);
        std::cout << "PRECIO SUGERIDO: $" << nuevocombo.getPrecio() << std::endl;
        int opcionPrecio;
        rlutil::locate(80,20);
        std::cout << "1. ACEPTAR PRECIO SUGERIDO | 2. INGRESAR NUEVO PRECIO" << std::endl;
        rlutil::locate(80,21);
        validarInput(opcionPrecio,0,3);
        if(opcionPrecio==2){
                float nuevoprecio;
                rlutil::locate(80,22);
                std::cout << "INGRESAR NUEVO PRECIO: " ;
                validarInput(nuevoprecio,0,1500000);
                nuevocombo.setPrecio(nuevoprecio);}

        rlutil::locate(80,25);
            std::cout << "SU NUEVO COMBO " << std::endl;
            rlutil::locate(80,26);
            std::cout << "--------------------" << std::endl << std::endl;
            rlutil::locate(80,27);
            std::cout << "CODIGO: #" << nuevocombo.getCodigo() << std::endl;
            rlutil::locate(80,28);
            std::cout << "NOMBRE: " << nuevocombo.getNombre() << std::endl;
            hamburguesaaux = HA.leerRegistro(codhamburguesa-1);
            bebidaaux = BA.leerRegistro(codbebida-1);
            rlutil::locate(80,29);
            std::cout << "HAMBURGUESA DEL COMBO: " << hamburguesaaux.getNombre() << std::endl;
            rlutil::locate(80,30);
            std::cout << "BEBIDA DEL COMBO: " << bebidaaux.getNombre() << std::endl;
            rlutil::locate(80, 31);
            std::cout << "PRECIO: $" << nuevocombo.getPrecio() << std::endl;
            rlutil::locate(80,32);
            std::cout << "--------------------" << std::endl << std::endl;
            rlutil::locate(80,33);
            std::cout << "1. ACEPTAR | 2. CANCELAR" << std::endl << std::endl;
            rlutil::locate(80,34);
            validarInput(opcionC,0,3);
            if(opcionC==1){
            ComboArchivo CA;
            if(CA.guardarRegistro(nuevocombo)){rlutil::locate(80,35);std::cout <<"REGISTRO GUARDADO CORRECTAMENTE"<<std::endl; std::cin.ignore(); rlutil::hidecursor(); rlutil::cls(); return true;}
            else {rlutil::locate(80,35); std::cout << "ERROR AL GUARDAR REGISTRO" << std::endl; std::cin.ignore(); rlutil::hidecursor(); rlutil::cls();
            return false;}
            }
            rlutil::locate(80,35);
            std::cout << "OPERACION CANCELADA" << std::endl;
            std::cin.ignore();
            rlutil::hidecursor();
            rlutil::cls();
}


bool Administrador::cargarIngredientesDelDia(){
    rlutil::cls();
    int codigo, stockinicial, salir;
    Fecha fechaaux;
    Ingrediente Ing;
    IngredienteArchivo IA;
    IngredienteDelDia IDD;
    IngredienteDelDiaArchivo IDDA;
    rlutil::locate(80,25);
    std::cout << "INGRESE EL CODIGO DEL INGREDIENTE A AGREGAR: " , validarInput(codigo,0,IA.getCantidadRegistros());
    rlutil::locate(80,26);
    std::cout << "--------------------------------------------------------" << std::endl;
    Ing = IA.leerRegistro(IA.buscarRegistroPorCodigo(codigo));
    if (IDDA.buscarPorCodigoyFecha(codigo, fechaaux)==-1){
            rlutil::locate(80,28);
            std::cout << "INGREDIENTE: " << Ing.getNombre();
            rlutil::locate(80,29);
            std::cout << "INGRESE STOCK INICIAL: " ; validarInput(stockinicial,0,1000000);
            IDD.setCodigo(codigo);
            IDD.setNombre(Ing.getNombre());
            IDD.setPrecio(Ing.getPrecio());
            IDD.setStockInicial(stockinicial);
            IDD.setEstado(true);

            rlutil::locate(80,31);
            std::cout << "1. ACEPTAR | 2. CANCELAR" ; rlutil::locate(80,32); validarInput(salir,0,3);
            if(salir==1){
                if((IDDA.agregar(IDD))==true){
                    rlutil::locate(80,33);
                    std::cout << "REGISTRO GUARDADO EXISTOSAMENTE" << std::endl;
                    Sleep(900); rlutil::cls(); std::cin.ignore();
                    return true;
                }
                else{
                    rlutil::locate(80,33);
                    std::cout << "ERROR AL GUARDAR EL REGISTRO" << std::endl;
                    Sleep(900); rlutil::cls(); std::cin.ignore();
                    return false;
                }
            }
            else{
                rlutil::locate(80,33);
                std::cout << "OPERACION CANCELADA" << std::endl;
                Sleep(900); rlutil::cls(); std::cin.ignore();
                return false;
            }

    }
    else{
            rlutil::locate(80,28);
            std::cout << "EL INGREDIENTE SOLICITADO YA EXISTE EN EL REGISTRO DE LA FECHA" << std::endl;
            Sleep(900);
            std::cin.ignore();
            rlutil::cls();
            return false;}
}

bool Administrador::cargarBebidasDelDia(){
    rlutil::cls();
    int codigo, stockinicial, salir;
    Fecha fechaaux;
    Bebida beb;
    BebidaArchivo BA;
    BebidaDelDia BDD;
    BebidaDelDiaArchivo BDDA;
    rlutil::locate(80,25);
    std::cout << "INGRESE EL CODIGO DE LA BEBIDA A AGREGAR: " , validarInput(codigo,0,BA.getCantidadRegistros());
    rlutil::locate(80,26);
    std::cout << "--------------------------------------------------------" << std::endl;
    beb = BA.leerRegistro(BA.buscarRegistroPorCodigo(codigo));
    if (BDDA.buscarPorCodigoyFecha(codigo, fechaaux)==-1){
            rlutil::locate(80,28);
            std::cout << "BEBIDA: " << beb.getNombre();
            rlutil::locate(80,29);
            std::cout << "INGRESE STOCK INICIAL: " ; validarInput(stockinicial,0,1000000);
            BDD.setCodigo(codigo);
            BDD.setNombre(beb.getNombre());
            BDD.setPresentacion(beb.getCodPresentacion());
            BDD.setPrecio(beb.getPrecio());
            BDD.setStockInicial(stockinicial);
            BDD.setEstado(true);

            rlutil::locate(80,31);
            std::cout << "1. ACEPTAR | 2. CANCELAR" ; rlutil::locate(80,32); validarInput(salir,0,3);
            if(salir==1){
                if((BDDA.agregar(BDD))==true){
                    rlutil::locate(80,33);
                    std::cout << "REGISTRO GUARDADO EXISTOSAMENTE" << std::endl;
                    Sleep(900); rlutil::cls(); std::cin.ignore();
                    return true;
                }
                else{
                    rlutil::locate(80,33);
                    std::cout << "ERROR AL GUARDAR EL REGISTRO" << std::endl;
                    Sleep(900); rlutil::cls(); std::cin.ignore();
                    return false;
                }
            }
            else{
                rlutil::locate(80,33);
                std::cout << "OPERACION CANCELADA" << std::endl;
                Sleep(900); rlutil::cls(); std::cin.ignore();
                return false;
            }

    }
    else{
            rlutil::locate(80,28);
            std::cout << "LA BEBIDA SOLICITADO YA EXISTE EN EL REGISTRO DE LA FECHA" << std::endl;
            Sleep(900);
            std::cin.ignore();
            rlutil::cls();
            return false;}
}


bool Administrador::agregarStockIngDelDia(){
        int coding, cant;
        IngredienteArchivo IA;
        IngredienteDelDiaArchivo IDDA;
        IngredienteDelDia IDD;
        Fecha fechaaux;
        std::cout << "INGRESE CODIGO DE INGREDIENTE A MODIFICAR: " ; validarInput(coding,0,IA.getCantidadRegistros());
        if((IDDA.buscarPorCodigoyFecha(coding, fechaaux))!=-1){
            IDD = IDDA.leer(IDDA.buscarPorCodigoyFecha(coding, fechaaux));
            std::cout << std::endl << "INGREDIENTE A MODIFICAR: #" << IDD.getCodigo() << " " << IDD.getNombre() << " Stock actual: " << IDD.getStockFinal() << std::endl;

            std::cout << "------------------------------------------------------------------" << std::endl;
            std::cout << "1. AGREGAR STOCK | 2. QUITAR STOCK: " << std::endl;
            int elegir;
            std::cin>>elegir;
            switch(elegir){
        case 1:{
                std::cout << "INGRESE CANTIDAD A AGREGAR " ; validarInput(cant,0,1500000); IDD.agregarStock(cant);
                if(IDD.comprobarStock()==true){IDD.setEstado(true);}
                else{IDD.setEstado(false);}}
                break;
        case 2:{
                std::cout << "INGRESE CANTIDAD A QUITAR " ; validarInput(cant,0,1500000); IDD.descontarStockAdm(cant);
                if(IDD.comprobarStock()==true){IDD.setEstado(true);}
                else{IDD.setEstado(false);}}
                break;
        default: {
                std::cout << "OPCION INVALIDA. OPERACION CANCELADA" << std::endl;}
            }


            IDDA.modificarRegistro(IDD, IDDA.buscarPorCodigoyFecha(coding, fechaaux));
            std::cout << "STOCK MODIFICADO" << std::endl;
            Sleep(900);
            std::cin.ignore();
            rlutil::cls();
            return true;
        }
        else{std::cout << "EL INGREDIENTE SOLICITADO NO SE ENCUENTRA DISPONIBLE EN LA FECHA" << std::endl;
        Sleep(900);
            std::cin.ignore();
            rlutil::cls();
            ; return false;}
}

bool Administrador::agregarStockBebDelDia(){
        int coding, cant;
        BebidaArchivo BA;
        BebidaDelDiaArchivo BDDA;
        BebidaDelDia BDD;
        Fecha fechaaux;
        std::cout << "INGRESE CODIGO DE LA BEBIDA A MODIFICAR: " ; validarInput(coding,0,BA.getCantidadRegistros());
        if((BDDA.buscarPorCodigoyFecha(coding, fechaaux))!=-1){
            BDD = BDDA.leer(BDDA.buscarPorCodigoyFecha(coding, fechaaux));
            std::cout << std::endl << "BEBIDA A MODIFICAR: #" << BDD.getCodigo() << " " << BDD.getNombre() << BDD.getPresentacion() << " Stock actual: " << BDD.getStockFinal() << std::endl;

            std::cout << "------------------------------------------------------------------" << std::endl;
            std::cout << "1. AGREGAR STOCK | 2. QUITAR STOCK: " << std::endl;
            int elegir;
            std::cin>>elegir;
            switch(elegir){
        case 1:{
                std::cout << "INGRESE CANTIDAD A AGREGAR " ; validarInput(cant,0,1500000); BDD.agregarStock(cant);
                if(BDD.comprobarStock()==true){BDD.setEstado(true);}
                else(BDD.setEstado(false));
                break;
        case 2:{
                std::cout << "INGRESE CANTIDAD A QUITAR " ; validarInput(cant,0,1500000); BDD.descontarStockAdm(cant);
                if(BDD.comprobarStock()==true){BDD.setEstado(true);}
                else{BDD.setEstado(false);}}
                break;
        default: {
                std::cout << "OPCION INVALIDA. OPERACION CANCELADA" << std::endl;}
            }
            }

            BDDA.modificarRegistro(BDD, BDDA.buscarPorCodigoyFecha(coding, fechaaux));
            std::cout << "STOCK MODIFICADO" << std::endl;
            Sleep(900);
            std::cin.ignore();
            rlutil::cls();
            return true;
        }
        else{std::cout << "LA BEBIDA SOLICITADO NO SE ENCUENTRA DISPONIBLE EN LA FECHA" << std::endl;
        Sleep(900);
            std::cin.ignore();
            rlutil::cls();
            ; return false;}
}



bool Administrador::modificarIngrediente(){
        std::string nombre;
        int coding, cant, precio, aceptar;
        IngredienteArchivo IA;
        Ingrediente ing;
        std::cout << "INGRESE CODIGO DEL INGREDIENTE A MODIFICAR: " ; validarInput(coding,0,IA.getCantidadRegistros());
        if((IA.buscarRegistroPorCodigo(coding))!=-1){
            std::cin.ignore();
            ing = IA.leerRegistro(IA.buscarRegistroPorCodigo(coding));
            std::cout << std::endl << "INGREDIENTE A MODIFICAR: #" << ing.getCodigo() << " " << ing.getNombre() << " $" << ing.getPrecio() << std::endl;
            std::cout << "------------------------------------------------------------------" << std::endl;
            std::cout << "INGRESE NUEVO NOMBRE: " ; getline(std::cin,nombre); ing.setNombre(nombre);
            std::cout << "INGRESE NUEVO PRECIO: $" ; validarInput(precio,0,100000); ing.setPrecio(precio);
            std::cout << "--------------------------------------------------------------------" << std::endl;
            std::cout << "INGREDIETE MODIFICADO: " << std::endl;
            std::cout << "CODIGO #: " << ing.getCodigo() << std::endl;
            std::cout << "NOMBRE: " << ing.getNombre() << std::endl;
            std::cout << "PRECIO: $" << ing.getPrecio() << std::endl << std::endl;
            std::cout << "1. ACEPTAR | 2. CANCELAR" << std::endl;
            std::cout << "INGRESAR OPCION: " ; validarInput(aceptar,0,3);
            if(aceptar==1){
                    if(IA.modificarRegistro(ing, IA.buscarRegistroPorCodigo(ing.getCodigo()))==true){
                    std::cout <<"REGISTRO GUARDADO CORRECTAMENTE" << std::endl;
                    Sleep(600); std::cin.ignore();
                    rlutil::cls();
                    rlutil::hidecursor();
                    return true;
                    }
                    std::cout << "ERROR AL GUARDAR REGISTRO" << std::endl;
                    Sleep(600);
                    std::cin.ignore();
                    rlutil::cls();
                    rlutil::hidecursor();
                    return false;
            }
    else{
            std::cout << "PROCESO CANCELADO" ;
            Sleep(600);
            std::cin.ignore();
            rlutil::cls();
            rlutil::hidecursor();
            return false;}
}
}

bool Administrador::modificarBebida(){
        std::string nombre;
        int codbeb, cant, presentacion, precio, aceptar;
        BebidaArchivo BA;
        Bebida beb;
        std::cout << "INGRESE CODIGO DE LA BEBIDA A MODIFICAR: " ; validarInput(codbeb,0,BA.getCantidadRegistros());
        if((BA.buscarRegistroPorCodigo(codbeb))!=-1){
            std::cin.ignore();
            beb = BA.leerRegistro(BA.buscarRegistroPorCodigo(codbeb));
            std::cout << std::endl << "BEBIDA A MODIFICAR: #" << beb.getCodigo() << " " << beb.getNombre() << beb.getPresentacion() << " $" << beb.getPrecio() << std::endl;
            std::cout << "------------------------------------------------------------------" << std::endl;
            //rlutil::locate(80,16);
            std::cout << "INGRESE NUEVO NOMBRE: " ; getline(std::cin,nombre); beb.setNombre(nombre);
            //rlutil::locate(80,17);
            std::cout << "INGRESE NUEVO COD PRESENTACION: " ; validarInput(presentacion,0,3); beb.setPresentacion(presentacion);
            //rlutil::locate(80,18);
            std::cout << "INGRESE NUEVO PRECIO: $" ; validarInput(precio,0,100000); beb.setPrecio(precio);
            //rlutil::locate(80,19);
            std::cout << "--------------------------------------------------------------------" << std::endl;
            //rlutil::locate(80,21);
            std::cout << "SU NUEVA BEBIDA: " << std::endl;
            //rlutil::locate(80,22);
            std::cout << "CODIGO #: " << beb.getCodigo() << std::endl;
            //rlutil::locate(80,23);
            std::cout << "NOMBRE: " << beb.getNombre() << " " << beb.getPresentacion() << std::endl;
            //rlutil::locate(80,24);
            std::cout << "PRECIO: $" << beb.getPrecio() << std::endl << std::endl;
            //rlutil::locate(80,26);
            std::cout << "1. ACEPTAR | 2. CANCELAR" << std::endl;
            //rlutil::locate(80,27);
            std::cout << "INGRESAR OPCION: " ; validarInput(aceptar,0,3);
            if(aceptar==1){
                    if(BA.modificarRegistro(beb, BA.buscarRegistroPorCodigo(beb.getCodigo()))==true){
                    //rlutil::locate(80,29);
                    std::cout <<"REGISTRO GUARDADO CORRECTAMENTE" << std::endl;
                    Sleep(600); std::cin.ignore();
                    rlutil::cls();
                    rlutil::hidecursor();
                    return true;
                    }
                    //rlutil::locate(80,29);
                    std::cout << "ERROR AL GUARDAR REGISTRO" << std::endl;
                    Sleep(600);
                    std::cin.ignore();
                    rlutil::cls();
                    rlutil::hidecursor();
                    return false;
            }
    else{
           // rlutil::locate(80,29);
            std::cout << "PROCESO CANCELADO" ;
            Sleep(600);
            std::cin.ignore();
            rlutil::cls();
            rlutil::hidecursor();
            return false;}
}
}

bool Administrador::modificarHamburguesa()
{
    int codigo;
    HamburguesaArchivo HA;
    Hamburguesa ham;
    IngDeHambuguesa *IDA;
    IngDeHamburguesaArchivo IDAH;
    IngredienteArchivo IA;
    Ingrediente ingaux;
    std::string nombre;
    float precio;

    std::cout << "INGRESAR CODIGO DE LA HAMBURGUESA: " << std::endl;
    validarInput(codigo,0,HA.getCantidadRegistros()+1);
    std::cout << "-------------------------------------------- " << std::endl;
    std::cout << "HAMBURGUESA: " << std::endl;
    ham = HA.leerRegistro(HA.buscarRegistroPorCodigo(codigo));
    std::cout << "CODIGO #" <<  ham.getCodigo() << std::endl;
    std::cout << "NOMBRE: " <<  ham.getNombre() << std::endl;
    std::cout << "PRECIO: $" << ham.getPrecio() << std::endl;
    std::cout << "INGREDIENTES: " << std::endl;
    int cantIng = IDAH.getCantidadPorHamburguesa(codigo);
    IDA = new IngDeHambuguesa[cantIng];
    if(IDA==nullptr){std::cout << "ERROR DE MEMORIA" << std::endl; return false;}
    IDAH.getIngredientesDeHamburguesa(IDA,cantIng,codigo);
    for(int i=0; i<cantIng; i++){
            ingaux = IA.leerRegistro(IA.buscarRegistroPorCodigo(IDA[i].getCodigoIngrediente()));
            std::cout << "cod ing #" << IDA[i].getCodigoIngrediente() <<
            " | " << ingaux.getNombre() <<
            " | " << "cant x hamb: " << IDA[i].getCantidad() << std::endl;
    }

    std::cout << "-------------------------------------------- " << std::endl;
    std::cin.ignore();
    std::cout << "1. MODIFICAR HAMBURGUESA | 2. TERMINAR" << std::endl;
    int modificar;
    validarInput(modificar,0,3);
    if(modificar==1){
    std::cin.ignore();
    std::cout << std::endl<< "INGRESAR NUEVO NOMBRE:  " ; getline(std::cin, nombre); ham.setNombre(nombre) ; std::cout << std::endl;
    std::cout << "INGRESAR NUEVO PRECIO: $" ; validarInput(precio, 0, 100000); ham.setPrecio(precio); std::cout << std::endl;

    modificarIngredienteHamburguesa(codigo);

    if(HA.modificarRegistro(ham,HA.buscarRegistroPorCodigo(ham.getCodigo()))){std::cout << "MODIFICO CORRECTAMENTE" << std::endl;}
    else{std::cout << "NO MODIFICO" << std::endl;}

    std::cout << "-------------------------------------------- " << std::endl;
    std:: cout << "HAMBURGUESA MODIFICADA: " << std::endl;
    ham = HA.leerRegistro(HA.buscarRegistroPorCodigo(codigo));
    std::cout << "CODIGO #" <<  ham.getCodigo() << std::endl;
    std::cout << "NOMBRE: " <<  ham.getNombre() << std::endl;
    std::cout << "PRECIO: $" << ham.getPrecio() << std::endl;
    std::cout << "INGREDIENTES: " << std::endl;
    cantIng = IDAH.getCantidadPorHamburguesa(codigo);
    delete[]IDA;
    IDA = new IngDeHambuguesa[cantIng];
    if(IDA==nullptr){std::cout << "ERROR DE MEMORIA" << std::endl; return false;}
    IDAH.getIngredientesDeHamburguesa(IDA,cantIng,codigo);
    for(int i=0; i<cantIng; i++){
            ingaux = IA.leerRegistro(IA.buscarRegistroPorCodigo(IDA[i].getCodigoIngrediente()));
            std::cout << "cod ing #" << IDA[i].getCodigoIngrediente() <<
            " | " << ingaux.getNombre() <<
            " | " << "cant x hamb: " << IDA[i].getCantidad() << std::endl;
    }
    if(HA.modificarRegistro(ham,HA.buscarRegistroPorCodigo(ham.getCodigo()))){delete[]IDA; std::cin.ignore(); std::cout << "REGISTRO MODIFICADO CORRECTAMENTE" << std::endl; return true;}
    std::cin.ignore();
    std::cout<<"NO SE MODIFICO EL REGISTRO" << std::endl; delete[]IDA; return false;}
    else {
        delete[]IDA; std::cin.ignore(); rlutil::cls(); return false;
    }
}

bool Administrador::modificarIngredienteHamburguesa(int codham){

    int salir, codingrediente, cantidad;
    Ingrediente ingaux;
    IngredienteArchivo IA;
    IngDeHambuguesa IDH;
    IngDeHamburguesaArchivo IDHA;
    do{
            std::cout << " - PARA MODIFICAR UN INGREDIENTE DE LA HAMBURGUESA, INGRESE EL CODIGO Y LA CANTIDAD" << std::endl;
            std::cout << " - PARA ELIMINAR UN INGREDIENTE DE LA HAMBURGUESA, INGRESE EL CODIGO Y 0 (CERO) COMO CANTIDAD" << std::endl;
            std::cout << " - PARA AGREGAR UN INGREDIENTE NUEVO INGRESE CODIGO Y CANTIDAD" << std::endl << std::endl << std::endl;
            IDH.setCodigoHamburguesa(codham);
            std::cout << "INGRESE CODIGO INGREDIENTE: " ; validarInput(codingrediente,0,IA.getCantidadRegistros()+1); IDH.setCodigoIngrediente(codingrediente);
            ingaux = IA.leerRegistro(IA.buscarRegistroPorCodigo(codingrediente));
            std::cout <<"INGREDIENTE: " << ingaux.getNombre() << std::endl;
            std::cout << "INGRESE CANT/HAMBURGUESA: " ; validarInput(cantidad,-1,10000); IDH.setCantidad(cantidad);
            if(IDHA.buscarIngrediente(codham,codingrediente)==-1){
                if(IDHA.guardar(IDH)){std::cout << std::endl<< "INGREDIENTE AGREGADO CORRECTAMENTE" << std::endl;}
                else{std::cout<< std::endl<<"NO SE PUDO AGREGAR EL REGISTRO" << std::endl;}
            }
            else{
                if(IDHA.modificarIngrediente(IDH)==true){std::cout<< std::endl << "INGREDIENTE MODIFICADO CORRECTAMENTE" << std::endl;}
                else{std::cout << std::endl<< "NO SE PUDO MODIFICAR EL REGISTRO" << std::endl;}
            }
            std::cout << std::endl << "1. AGREGAR/MODIFICAR OTRO INGREDIENTE | 2.TERMINAR" << std::endl;
            validarInput(salir,0,3);
            if(salir==2){salir=0;}
            std::cout << std::endl << std::endl;
    }while(salir!=0);
    std::cin.ignore();
}

bool Administrador::modificarCombo()
{
    int codigo;
    ComboArchivo CA;
    Combo combo;
    HamburguesaArchivo HA;
    BebidaArchivo BA;
    Hamburguesa hamaux;
    Bebida bebidaaux;
    std::string nombre;
    float precio;
    int codhamburguesa, codbebida;
    std::cout << "INGRESAR CODIGO DE COMBO: " ; validarInput(codigo,0,CA.getCantidadRegistros()+1);
    std::cout << "-------------------------------------------- " << std::endl;
    std::cout << "COMBO: " << std::endl;
    combo = CA.leerRegistro(CA.buscarRegistroPorCodigo(codigo));
    std::cout << "CODIGO #" << combo.getCodigo() << " | NOMBRE: " << combo.getNombre() << " | PRECIO: $" << combo.getPrecio() << std::endl;
    hamaux = HA.leerRegistro(HA.buscarRegistroPorCodigo(combo.getHamburguesa()));
    bebidaaux = BA.leerRegistro(BA.buscarRegistroPorCodigo(combo.getBebida()));
    std::cout << "HAMBURGUESA DEL COMBO: #" << combo.getHamburguesa() << " | " << hamaux.getNombre() << std::endl;
    std::cout << "BEBIDA DEL COMBO: #" << combo.getBebida() << " | " << bebidaaux.getNombre() << std::endl;
    std::cout << "-------------------------------------------- " << std::endl;
     std::cin.ignore();
    std::cout << "1. MODIFICAR COMBO | 2. TERMINAR" << std::endl;
    int modificar;
    validarInput(modificar,0,3);
    if(modificar==1){
    std::cin.ignore();
    std::cout << "INGRESAR NUEVO NOMBRE DE COMBO:  " ; getline(std::cin, nombre); combo.setNombre(nombre) ;
    std::cout << "AGREGAR NUEVA HAMBURGUESA DE COMBO: " ; validarInput(codhamburguesa,0,HA.getCantidadRegistros()+1); combo.setHamburguesa(codhamburguesa);
    std::cout << "AGREGAR NUEVA BEBIDA DE COMBO: " ; validarInput(codbebida,0,BA.getCantidadRegistros()+1); combo.setBebida(codbebida);
    combo.setPrecio(combo.generarPrecio());
    std::cout << "EL PRECIO SUGERIDO PARA SU COMBO ES: $" << combo.getPrecio() << std::endl;
    int aceptar;
    std::cout << "1. ACEPTAR | 2. INGRESAR PRECIO MANUALMENTE " << std::endl;
    std::cout << "INGRESE RESPUESTA: " ; validarInput(aceptar,0,3);
    if(aceptar==2){
        std::cout << "INGRESE NUEVO PRECIO: $" ; validarInput(precio,0,1500000);
        combo.setPrecio(precio);
    }
     std::cout << "-------------------------------------------- " << std::endl;
     std::cout << "SU COMBO MODIFICADO: " << std::endl;
     std::cout << "CODIGO #" << combo.getCodigo() << " | NOMBRE: " << combo.getNombre() << " | PRECIO: $" << combo.getPrecio() << std::endl;
     hamaux = HA.leerRegistro(HA.buscarRegistroPorCodigo(combo.getHamburguesa()));
     bebidaaux = BA.leerRegistro(BA.buscarRegistroPorCodigo(combo.getBebida()));
     std::cout << "HAMBURGUESA DEL COMBO: #" << combo.getHamburguesa() << " | " << hamaux.getNombre() << std::endl;
     std::cout << "BEBIDA DEL COMBO: #" << combo.getBebida() << " | " << bebidaaux.getNombre() << std::endl;
     std::cout << "-------------------------------------------- " << std::endl;
     std::cin.ignore();
     std::cout << "1. ACEPTAR | 2.CANCELAR" << std::endl;
     int aceptar1;
     validarInput(aceptar1,0,3);
    if(aceptar1==1){
            if(CA.modificarRegistro(combo,CA.buscarRegistroPorCodigo(codigo))){std::cout << "REGISTRO MODIFICADO CORRECTAMENTE" << std::endl; Sleep(900); std::cin.ignore(); rlutil::cls(); return true;}
            else{
                    std::cout<<"NO SE MODIFICO EL REGISTRO" << std::endl; Sleep(900); std::cin.ignore(); rlutil::cls(); return false;
            }
    }
    }
    else{std::cin.ignore(); rlutil::cls(); return false;}
}


bool Administrador::backupmenu(){
    int salir = -1;
        do{
        rlutil::cls();
        int x = 80;
        int y = 15;
        rlutil::locate(x, y++);
        std::cout << "1. GENERAR BACKUP INMEDIATO" << std::endl;
        rlutil::locate(x, y++);
        std::cout << "2. RECUPERAR BACKUP" << std::endl;
        rlutil::locate(x, y++);
        std::cout << "3. SALIR" << std::endl;
        rlutil::locate(x, y++);
        int opcion;
        rlutil::locate(x, y++);
        std::cout << "RESPUESTA: " ; std::cin >> opcion;
        switch(opcion){
            case 1:{
                ManejoArchivos MA;
                if(MA.backupIngDelDia()){rlutil::locate(x, y++); std::cout << "BACK UP INGREDIENTES DEL DIA EXITOSO" << std::endl;}
                else{rlutil::locate(x, y++); std::cout << "NO SE PUDO REALIZAR BACK UP DE INGREDIENTES DEL DIA" << std::endl;}

                if(MA.backupBebDelDia()){rlutil::locate(x, y++); std::cout << "BACK UP BEBIDAS DEL DIA EXITOSO" << std::endl;}
                else{rlutil::locate(x, y++); std::cout << "NO SE PUDO REALIZAR BACK UP DE BEBIDAS DEL DIA" << std::endl;}

                if(MA.backupHamDelDia()){rlutil::locate(x, y++); std::cout << "BACK UP HAMBURGUESAS DEL DIA EXITOSO" << std::endl;}
                else{rlutil::locate(x, y++); std::cout << "NO SE PUDO REALIZAR BACK UP DE HAMBURGUESAS DEL DIA" << std::endl;}

                if(MA.backupComDelDia()){rlutil::locate(x, y++); std::cout << "BACK UP COMBOS DEL DIA EXITOSO" << std::endl;}
                else{rlutil::locate(x, y++); std::cout << "NO SE PUDO REALIZAR BACK UP DE COMBOS DEL DIA" << std::endl;}

                if(MA.backupTickets()){rlutil::locate(x, y++); std::cout << "BACK UP TICKETS EXITOSO" << std::endl;}
                else{rlutil::locate(x, y++); std::cout << "NO SE PUDO REALIZAR BACK UP DE TICKETS" << std::endl;}

                if(MA.backupPedidos()) {rlutil::locate(x, y++); std::cout << "BACK UP PEDIDOS EXITOSO" << std::endl;}
                else{rlutil::locate(x, y++); std::cout << "NO SE PUDO REALIZAR BACK UP DE PEDIDOS" << std::endl;}
                system("pause");
                }
                break;
            case 2:
                {   y++;
                    rlutil::locate(x, y++);
                    std::cout << "LEA ATENTAMENTE ANTES DE CONTINUAR: " << std::endl;
                    rlutil::locate(x, y++);
                    std::cout << "SI RECUPERA DESDE EL ARCHIVO BACK UP, EL SISTEMA LIMPIARÁ CUALQUIER REGISTRO QUE NO ESTÉ GUARDADO EN EL BACK UP " << std::endl;
                    rlutil::locate(x, y++);
                    std::cout << "Y SUS ARCHIVOS ACTUALES SERAN REEMPLAZADOS POR LOS ARCHIVOS BACKUP. SI DESEA RECUPERAR SUS ULTIMOS MOVIMIENTOS" << std::endl;
                    rlutil::locate(x, y++);
                    std::cout << "PUEDE GUARDAR SUS REGISTROS MAS RECIENTES DESDE LA OPCION BACK UP INMEDIATO O BIEN CERRANDO EL PROGRAMA" << std::endl;
                    y++;
                    rlutil::locate(x, y++);
                    std::cout << "1. CONTINUAR | 2. CANCELAR" << std::endl;
                    std::cin.ignore();
                    int continuar;
                    rlutil::locate(x++, y++);
                    validarInput(continuar,0,3);
                    if(continuar==1){
                            ManejoArchivos MA;
                        if(MA.recuperarIngDelDia()){rlutil::locate(x, y++);
                        std::cout << "ARCHIVO ING DEL DIA RECUPERADO EXITOSAMENTE" << std::endl;}
                        else{rlutil::locate(x, y++); std::cout << "NO SE PUDO RECUPERAR ARCHIVO INGREDIENTES DEL DIA" << std::endl;}

                        if(MA.recuperarBebDelDia()){rlutil::locate(x, y++); std::cout << "ARCHIVO BEBIDAS DEL DIA RECUPERADO EXITOSAMENTE" << std::endl;}
                        else{rlutil::locate(x, y++); std::cout << "NO SE PUDO RECUPERAR ARCHIVO BEBIDAS DEL DIA" << std::endl;}

                        if(MA.recuperarHamDelDia()){rlutil::locate(x, y++); std::cout << "ARCHIVO HAMBURGUESAS DEL DIA RECUPERADO EXITOSAMENTE" << std::endl;}
                        else{rlutil::locate(x, y++); std::cout << "NO SE PUDO RECUPERAR ARCHIVO HAMBURGUESAS DEL DIA" << std::endl;}

                        if(MA.recuperarComDelDia()){rlutil::locate(x, y++); std::cout << "ARCHIVO COMBOS DEL DIA RECUPERADO EXITOSAMENTE" << std::endl;}
                        else{rlutil::locate(x, y++); std::cout << "NO SE PUDO RECUPERAR ARCHIVO COMBOS DEL DIA" << std::endl;}

                        if(MA.recuperarTickets()){rlutil::locate(x, y++); std::cout << "ARCHIVO TICKETS DEL DIA RECUPERADO EXITOSAMENTE" << std::endl;}
                        else{rlutil::locate(x, y++); std::cout << "NO SE PUDO RECUPERAR ARCHIVO TICKETS DEL DIA" << std::endl;}

                        if(MA.recuperarPedidos()){rlutil::locate(x, y++); std::cout << "ARCHIVO PEDIDOS RECUPERADO EXITOSAMENTE" << std::endl;}
                        else{rlutil::locate(x, y++); std::cout << "NO SE PUDO RECUPERAR ARCHIVO PEDIDOS" << std::endl;}

                        system("pause");
                    }
                }
                break;
            case 3:
                {
                    salir=0;
                }
                break;
            default:
                {   rlutil::locate(x, y++);
                    std::cout << "OPCION INVALIDA" << std::endl; Sleep(900);
                }
                break;
        }

        }while(salir!=0);
        std::cin.ignore();
        rlutil::cls();
        return true;
}


bool Administrador::menuReportes(){
    rlutil::cls();
    int opc = -1, y=0;
    rlutil::hidecursor();
    Style ST;
    do{
    ST.showItemMenuAdministrador("                                    ", 85, 17, 0);
    ST.showItemMenuAdministrador(" 1. VER REPORTE DEL DIA             ", 85, 18, y == 0);
    ST.showItemMenuAdministrador(" 2. VER REPORTE POR FECHA           ", 85, 19, y == 1);
    ST.showItemMenuAdministrador(" 3. TOTAL X DIA HISTORICO           ", 85, 20, y == 2);
    ST.showItemMenuAdministrador(" 4. TOTAL RECAUDADO POR INTERVALO   ", 85, 21, y == 3);
    ST.showItemMenuAdministrador(" 5. RANKING PRODUCTOS HISTORICO     ", 85, 22, y == 4);
    ST.showItemMenuAdministrador(" 6. VER TICKETS POR FECHA           ", 85, 23, y == 5);
    ST.showItemMenuAdministrador(" 7. VER TICKETS HISTORICO           ", 85, 24, y == 6);
    ST.showItemMenuAdministrador(" 8. SALIR                           ", 85, 25, y == 7);
    ST.showItemMenuAdministrador("                                    ", 85, 26, 0);
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
            MasterMind mm;
            Fecha fecha;
            TicketArchivo TA;
            int cant = TA.contarTicketsDeLaFecha(fecha);
            if(cant==0){rlutil::cls(); rlutil::locate(80,25); std::cout << "NO HAY REGISTROS PARA LA FECHA" << std::endl; Sleep(900); std::cin.ignore(); rlutil::cls();}
            else{
            mm.verReportePorFecha(fecha);
            }
        }
        break;

        case 1:{
                    int x=85, y=30;
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
                    TicketArchivo TA;
                    int cant = TA.contarTicketsDeLaFecha(fecha);
                    if(cant==0){y++; rlutil::locate(x,y++); std::cout << "NO HAY REGISTROS PARA LA FECHA INDICADA" << std::endl; Sleep(1500); std::cin.ignore(); rlutil::cls();}

                    else{MasterMind mm;
                    mm.verReportePorFecha(fecha);
                    }
                }
        break;

        case 2:{
                MasterMind mm;
                mm.totalPorDiaHistorico();
        }
        break;

        case 3:{
                MasterMind mm;
                mm.totalRecaudadoPorIntervalo();
        }
        break;

        case 4:{
                MasterMind mm;
                mm.PodioProductosHistorico();
        }
        break;

        case 5:{
                MasterMind mm;
                mm.verTicketsPorFecha();
        }
        break;

        case 6:{
                MasterMind mm;
                mm.verTicketsHistorico();
        }
        break;

        case 7:{
        opc=0;
        std::cin.ignore();
        rlutil::cls();
        }


    }
    }
    }while(opc!=0);

}


bool Administrador::cambiarContrasenia(){
        rlutil::cls();
        char nuevacontrasenia[20];
        rlutil::locate(80,15);
        std::cout << "INGRESE NUEVA CONTRASENIA: " << std::endl;
        rlutil::locate(80,16);
        std::cin >> nuevacontrasenia;

        FILE*p = fopen("Archivos/Admin/Contrasenia.dat","wb");
        if(p==NULL){return false;}
        bool cambio = fwrite(&nuevacontrasenia,sizeof(nuevacontrasenia),1,p);
        fclose(p);
        std::cin.ignore();
        rlutil::cls();
        return cambio;
        }

bool Administrador::verificarContrasenia(){
        rlutil::cls();
        rlutil::locate(80,15);
        char contrasenia[20];
        std::cout << "INGRESE CONTRASENIA DE ADMINISTRADOR: " << std::endl;
        rlutil::locate(80,16);
        rlutil::setColor(rlutil::BLACK);
        std::cin >> contrasenia;

        char contraseniaactual[40];
        rlutil::setColor(rlutil::WHITE);
        FILE*p = fopen("Archivos/Admin/Contrasenia.dat","rb");
        if(p==NULL){return false;}
        fread(&contraseniaactual,sizeof(contraseniaactual),1,p);
        if(strcmp(contrasenia,contraseniaactual)==0){
            fclose(p);
            std::cin.ignore();
            rlutil::cls();
            return true;
        }
        fclose(p);
        std::cin.ignore();
        rlutil::cls();
        return false;
        }
