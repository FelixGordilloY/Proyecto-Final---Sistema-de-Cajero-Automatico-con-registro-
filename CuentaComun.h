#ifndef _CUENTACOMUN_H_
#define _CUENTACOMUN_H_
#include "Cuenta.h"
#include <string>
using namespace std;

class CuentaComun : public Cuenta
{
public:
	CuentaComun(string,string,int,double);

	void depositar();
	void retirar();
	void mostrar(vector <Cuenta *> o);
    double getSld();
    string getTipo();
    int menuCuenta();
};

CuentaComun::CuentaComun(string _nom,string _dni, int clv, double sld) : Cuenta(_nom,_dni,clv,sld) {
    this->tipo = "Cuenta Comun";
}


double CuentaComun::getSld(){
    return saldo;
}

void CuentaComun::depositar(){
    double x;
    cout << "Ingresa la cantidad de dinero que deseas depositar S/:";
    cin >> x;
    saldo = saldo + x;
    cout <<""<<endl;
    cout <<" Se realizo el deposito de: S/" << x <<endl;
}


void CuentaComun::retirar(){
	double x;
    cout << "Ingresa la cantidad de dinero que deseas retirar S/:";
    cin >> x;
    if(x<=saldo){
        saldo = saldo - x;
        cout <<" Se realizo el retiro de: S/" << x <<endl;
    }else{
        cout << "No se pudo hacer el retiro, dinero insuficiente."<<endl;
    }
}

void CuentaComun::mostrar(vector <Cuenta *> o){
    cout << " ________________________________________________________________________________________________" << endl;
    cout << "" <<endl;
    cout << "TIPO: "<< getTipo() <<endl;
    cout << "" <<endl;
    cout << "NOMBRE: "<< nombre <<endl;
    cout << "" <<endl;
    cout << "DNI: " << dni << endl;
    cout << "" <<endl;
	cout << "SALDO: S/" << saldo <<endl;
    cout << "" <<endl;
	cout << "CLAVE:" << clave <<endl;   
    cout << " ________________________________________________________________________________________________" << endl;    	
}


string CuentaComun::getTipo(){
    return tipo;
}



int CuentaComun::menuCuenta(){
    int opcion;
    cout << " ________________________________________________________________________________________________" << endl;
    cout << "|                                       System Bank                                              |" << endl;
    cout << "|________________________________________________________________________________________________|" << endl;
    cout << "|ingresar una opcion:                                                                            |"<< endl;
    cout << "|      (1) Mostrar Datos                                                                         |"<< endl;
    cout << "|      (2) Retirar                                                                               |"<< endl;
    cout << "|      (3) Depositar                                                                             |"<< endl;
    cout << "|      (4) <--Regresar al Inicio                                                                 |"<< endl;    
    cout << "|                                                                                                |"<< endl;
    cout << "|________________________________________________________________________________________________|" << endl;
    cout << "           Opcion: ";
    cin >> opcion;
    return opcion; 
}

#endif