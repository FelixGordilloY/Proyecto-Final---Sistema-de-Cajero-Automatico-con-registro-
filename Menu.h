#ifndef _MENU_H_
#define _MENU_H_
#include <iostream>
#include <string>
using namespace std;


int menuInicio(){
    int opcion;
    cout << " ________________________________________________________________________________________________" << endl;
    cout << "|                                       System Bank                                              |" << endl;
    cout << "|________________________________________________________________________________________________|" << endl;
    cout << "|ingresar a:                                                                                     |"<< endl;
    cout << "|      (1) Ingresar                                                                              |"<< endl;
    cout << "|      (2) Crear Cuenta                                                                          |"<< endl;
    cout << "|      (3) Salir                                                                                 |"<< endl;
    cout << "|________________________________________________________________________________________________|" << endl;
    cout << "           Opcion: ";
    cin >> opcion;
    return opcion;    
}

#endif
