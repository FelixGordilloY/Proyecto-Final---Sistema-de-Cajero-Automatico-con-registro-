#ifndef _CUENTA_H_
#define _CUENTA_H_
#include <iostream>
#include <string>
#include <vector>
using namespace std;


//Clase Base
class Cuenta
{
protected:
    string nombre,dni,tipo;
    int clave;
    double saldo;
public:

    Cuenta(string,string,int,double);

    string getNom(){
        return nombre;
    }
    int getClv(){
        return clave;
    }
    string getDni(){
        return dni;
    }
    virtual double getSld(){
        return saldo;
    };
    
    virtual void mostrar(vector <Cuenta *> o) = 0;
    virtual void depositar() = 0;
    virtual void retirar() = 0;
    virtual string getTipo() = 0;
    virtual int menuCuenta()= 0;;

    void Impdatos(){
        cout << " ________________________________________________________________________________________________" << endl;
        cout << "TIPO: "<< tipo <<endl;
        cout << "NOMBRE: "<< nombre <<endl;
        cout << "DNI: " << dni << endl;
	    cout << "SALDO: S/" << saldo <<endl;   
        cout << " ________________________________________________________________________________________________" << endl;    	
    }
    
};

Cuenta::Cuenta(string _nombre,string _dni,int _clave,double _saldo) : nombre(_nombre), dni(_dni), clave(_clave) , saldo(_saldo)  {};

#endif