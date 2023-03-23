#include <iostream>
#include <iomanip>
using namespace std;
#include "Style.h"
#include "rlutil.h"

Style::Style()
{
    //ctor
}

Style::~Style()
{
    //dtor
}

void Style::showItemMenuPrincipal(const char* text, int posx, int posy, bool selected){
        rlutil::setBackgroundColor(rlutil::DARKGREY);
    if(selected){
        rlutil::locate(posx, posy);
        std::cout << "      " << (char)16 << " " << text ;
    }
    else{

        rlutil::locate(posx, posy);
        std::cout << "      " << text << "  " ;
    }

    rlutil::setBackgroundColor(rlutil::BLACK);
}

void Style::showItemMenuAdministrador(const char* text, int posx, int posy, bool selected){
    rlutil::setBackgroundColor(rlutil::BLUE);
    if(selected){
        rlutil::locate(posx, posy);
        std::cout << "      " << (char)16 << " " << text << "       ";
    }
    else{

        rlutil::locate(posx, posy);
        std::cout << "      " << text << "         " ;
    }

    rlutil::setBackgroundColor(rlutil::BLACK);
}

void Style::showItemIngredienteHistorico(int codigo, std::string nombre, float precio, int posx, int posy){
    rlutil::setBackgroundColor(rlutil::DARKGREY);
    rlutil::locate(posx, posy);
    std::cout << left << "|" << " #" << setw(3) << codigo <<  "|" << " " <<setw(23) << nombre << " " << "| "  <<"$" << setw(5)  << precio << "|"  <<  std::endl;
    rlutil::setBackgroundColor(rlutil::BLACK);
}

void Style::showItemDelDiaAdm(bool estado, int codigo, std::string nombre, float precio, int stockincial, int stockactual, int posx, int posy)
{
    if(estado==false){
    rlutil::setBackgroundColor(rlutil::LIGHTRED);}
    else{
    rlutil::setBackgroundColor(rlutil::DARKGREY);}
    rlutil::locate(posx, posy);
    std::cout << left <<
     "|" << " #" << setw(3) << codigo <<
     "|" << " " <<setw(23) << nombre <<
     " " << "| " <<"$" << setw(5)  << precio <<
     "|"  << " " << setw(8) <<  stockincial <<
     "|" << " " << setw(9) << stockactual << std::endl;
    rlutil::setBackgroundColor(rlutil::BLACK);
}

void Style::showItemDelDiaCaja(int codigo, std::string nombre, float precio, int posx, int posy)
{
    rlutil::setBackgroundColor(rlutil::DARKGREY);
    rlutil::locate(posx, posy);
    std::cout << left <<
     "|" << " #" << setw(3) << codigo <<
     "|" << " " <<setw(23) << nombre <<
     " " << "| " <<"$" << setw(5)  << precio << std::endl;
    rlutil::setBackgroundColor(rlutil::BLACK);
}

void Style::showItemDelDiaCaja2(bool estado, int codigo, std::string nombre, float precio, int posx, int posy)
{
    if(estado==false){rlutil::setBackgroundColor(rlutil::LIGHTRED);}
    else{rlutil::setBackgroundColor(rlutil::DARKGREY);}
    rlutil::locate(posx, posy);
    std::cout << left <<
     "|" << " #" << setw(3) << codigo <<
     "|" << " " <<setw(23) << nombre <<
     " " << "| " <<"$" << setw(5)  << precio << std::endl;
    rlutil::setBackgroundColor(rlutil::BLACK);
}

void Style::showItemMenuCaja(const char* text, int posx, int posy, bool selected){
    rlutil::setBackgroundColor(rlutil::RED);
    if(selected){
        rlutil::locate(posx, posy);
        std::cout << "      " << (char)16 << " " << text << "       ";
    }
    else{

        rlutil::locate(posx, posy);
        std::cout << "      " << text << "         " ;
    }

    rlutil::setBackgroundColor(rlutil::BLACK);
}
