#ifndef _CUENTAADM_H_
#define _CUENTAADM_H_
#include "Cuenta.h"
#include <string>
#include <vector>

using namespace std;

class CuentaAdm : public Cuenta
{
public:
	CuentaAdm(string,string,int,double);

    void depositar();
	void retirar();
	void mostrar(vector <Cuenta *> o);
    double getSld();
    string getTipo();
    int menuCuenta();
};

CuentaAdm::CuentaAdm(string _nom,string _dni, int clv, double sld) : Cuenta(_nom,_dni,clv,sld) {
    this->tipo = "Cuenta Admin";
}



void CuentaAdm::mostrar(vector <Cuenta *> o){
    
    for (int i = 0; i < o.size(); i++)
    {
        cout << "CUENTA #" << i+1 << endl;
        o[i]->Impdatos();
    }
    
}

void CuentaAdm::depositar(){
}

void CuentaAdm::retirar(){
}

string CuentaAdm::getTipo(){
    return tipo;
}
double CuentaAdm::getSld(){
    return saldo;
}

int CuentaAdm::menuCuenta(){
    int opcion;
    cout << " ________________________________________________________________________________________________" << endl;
    cout << "|                                      *CUENTA ADMINISTRADOR*                                    |" << endl;
    cout << "|________________________________________________________________________________________________|" << endl;
    cout << "|ingresar una opcion:                                                                            |"<< endl;
    cout << "|      (1) Mostrar Todas las Cuenta                                                              |"<< endl;
    cout << "|                                                                                                |"<< endl;
    cout << "|      (4) <--Regresar al Inicio                                                                 |"<< endl;    
    cout << "|                                                                                                |"<< endl;
    cout << "|________________________________________________________________________________________________|" << endl;
    cout << "           Opcion: ";
    cin >> opcion;
    return opcion; 
}
#endif