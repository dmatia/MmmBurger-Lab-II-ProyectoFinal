#ifndef VALIDAR_H_INCLUDED
#define VALIDAR_H_INCLUDED

template<typename T>
T &validarInput(T &val, int val1, int val2){
    while (true) {
        if (std::cin >> val && val>val1&&val<val2) {break;}
        else {std::cout << "El valor ingresado no es valido. Intentelo de nuevo\n" << "INGRESAR NUEVO VALOR: " ; std::cin.clear(); std::cin.ignore();}}
        return val;}

#endif // VALIDAR_H_INCLUDED
