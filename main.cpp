#include <iostream>
#include <cstdlib>
#include "rlutil.h"
#include <locale.h>
#include <string>
#include "Style.h"
#include "Menu.h"
#include "Administrador.h"
#include "BebidaDelDia.h"
#include "BebidaDelDiaArchivo.h"
#include "IngredienteDelDia.h"
#include "IngredienteDelDiaArchivo.h"
#include "Pedido.h"
#include "PedidoArchivo.h"
#include "ManejoArchivos.h"

int main()
{
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1800, 800, TRUE);


    setlocale(LC_ALL, "spanish");
    int opc = -1, y=0;
    rlutil::hidecursor();
    Style ST;
   do{
    ST.showItemMenuPrincipal("                         ", 85, 19, 0);
    ST.showItemMenuPrincipal(" MENU ADMINISTRADOR      ", 85, 20, y == 0);
    ST.showItemMenuPrincipal(" MENU CAJA               ", 85, 21, y == 1);
    ST.showItemMenuPrincipal(" SALIR                   ", 85, 22, y == 2);
    ST.showItemMenuPrincipal("                         ", 85, 23, 0);
    rlutil::anykey();
    int key = rlutil::getkey();

    Menu menu;
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
    if(y>2){y=2;}
    break;

    case 1:

        switch(y){
        case 0:{
            Administrador adm;
            if(adm.verificarContrasenia()){
            menu.menuAdministrador();}
            else {rlutil::cls(); rlutil::locate(80,15); std::cout << "CONTRASEÑA INCORRECTA" << std::endl; Sleep(900); std::cin.ignore(); rlutil::cls();}
        }
        break;

        case 1:{
            menu.menuCaja();
        }
        break;

        case 2:{
                int resp;
                rlutil::cls();
                ST.showItemMenuPrincipal("          ¿ESTÁ SEGURO QUE DESEA SALIR?          ", 85, 25, y == 0);
                ST.showItemMenuPrincipal("PRESIONE 1 PARA SALIR / CASO CONTRARIO PRESIONE 0", 85, 26, y == 0);
                rlutil::locate(85, 27);
                std::cout << "INGRESE OPC. DESEADA: " ; std::cin >> resp;
                rlutil::cls();
                switch(resp){
            case 1:{
                opc=0;
                }
                break;
            case 0:
                break;
                default:
                    rlutil::locate(90,20);
                    std::cout<< "OPCION INVALIDA" << std::endl;
                    std::cin.ignore();
                    Sleep(600);
                    rlutil::cls();
                break;}
                break;
        }
    }
}
   }while(opc!=0);
   ManejoArchivos MA;
   MA.backupIngDelDia();
   MA.backupBebDelDia();
   MA.backupHamDelDia();
   MA.backupComDelDia();
   MA.backupPedidos();
   MA.backupTickets();
    return 0;
}









/*
int main(){

Fecha fechaaux;

std::cout << "FECHA: " << fechaaux.getDia() << "/" << fechaaux.getMes() << "/" << fechaaux.getAnio() << std::endl << std::endl;

    for(int i=0; i<12; i++){
    for(int j= 0; j<31; j++){
        fechaaux.incrementarDia();
        std::cout << "FECHA: " << fechaaux.getDia() << "/" << fechaaux.getMes() << "/" << fechaaux.getAnio() << std::endl;
    }
    }
}

*/

/*
int main(){
PedidoArchivo PA;
Pedido ped;
for(int i=0; i<PA.getCantidadRegistros(); i++){
    ped = PA.leerRegistro(i);
    std::cout << "FECHA: " << ped.getFecha().getDia() << "/" << ped.getFecha().getMes() << "/" << ped.getFecha().getAnio() << std::endl;
    std::cout << "NRO TICKET " << ped.getNroTicket() << std::endl;
    std::cout << "NRO PEDIDO " << ped.getNroPedido() << std::endl;
    std::cout << "COD HAM " << ped.getCodHamburguesa() << std::endl;
    std::cout << "COD BEB " << ped.getCodBebida() << std::endl;
    std::cout << "COD COMBO " << ped.getCodCombo() << std::endl;
    std::cout << "ESTADO: " << ped.getEstado() << std::endl;
    std::cout << std::endl;
    std::cout << "--------------------------------" << std::endl;
}

}

int main(){
        FILE * p1 = fopen("Archivos/DelDia/IngredientesDelDia.dat","rb");
        if(p1==NULL){return  false;}
        FILE * p2 = fopen("Archivos/DelDia/BACKUP/backupIngDelDia.dat","rb");
        if(p2==NULL){fclose(p1); return  false;}
       /* FILE * p3 = fopen("Archivos/DelDia/BebidasDelDia.dat","rb");
        if(p3==NULL){fclose(p1); fclose(p2); return  false;}
        FILE * p4 = fopen("Archivos/DelDia/BACKUP/backupBebDelDia.dat","rb");
        if(p4==NULL){fclose(p1); fclose(p2); fclose(p3); return false;}

        IngredienteDelDia IDD;
        std::cout <<"INGREDIENTES DEL DIA ARCHIVO" << std::endl;
        while(fread(&IDD,sizeof(IngredienteDelDia),1,p1)){
            std::cout << IDD.getFecha().getDia() << "/" << IDD.getFecha().getMes() << "/" << IDD.getFecha().getAnio() << "  "
            << "#" << IDD.getCodigo() << " " << IDD.getNombre() << " $" << IDD.getPrecio() << " ST. INI: " << IDD.getStockInicial() << " ST. FIN: " << IDD.getStockFinal() << std::endl;
        }

        std::cout << "----------------------------------------------------------------------------------" << std::endl;

        std::cout <<"INGREDIENTES DEL DIA BACK UP" << std::endl;
        while(fread(&IDD,sizeof(IngredienteDelDia),1,p2)){
            std::cout << IDD.getFecha().getDia() << "/" << IDD.getFecha().getMes() << "/" << IDD.getFecha().getAnio() << "  "
            << "#" << IDD.getCodigo() << " " << IDD.getNombre() << " $" << IDD.getPrecio() << " ST. INI: " << IDD.getStockInicial() << " ST. FIN: " << IDD.getStockFinal() << std::endl;
        }

        fclose(p1);
        fclose(p2);



return 0;}

*/
