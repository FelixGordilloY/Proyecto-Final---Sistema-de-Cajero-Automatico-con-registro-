#ifndef _REGISTRO_H_
#define _REGISTRO_H_
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Cuenta.h"
using namespace std;

template<typename T>
class Registro
{
private:
	//Nombre del archivo de texto para registrar
	string nomArchivo;
public:
	Registro(string _nomArchivo): nomArchivo(_nomArchivo) {};

    void agregar(vector<Cuenta *> &o);

	void DescargarCuentas(vector<Cuenta *> &o);
	void CargarCuentas(vector<Cuenta *> &o);
};

//Agregar un Cuenta Nueva al vector
template<typename T>
void Registro<T>::agregar(vector<Cuenta *> &o){
    ofstream Archivo;
	string Nombre,Codigo;
    int Clave;
	double Saldo = 0;
	Archivo.open(nomArchivo, ios::out | ios::app);
	cout << "Ingrese su:\nNombre: ";
	cin >> Nombre;
	cout << "DNI: ";
	cin >> Codigo;
	cout << "Clave: ";
	cin >> Clave;
	Archivo << Nombre << " " << Codigo << " " << Saldo << " " << Clave << endl;
	o.push_back(new T(Nombre,Codigo,Clave,Saldo));
    Archivo.close();
}


template<typename T>
void Registro<T>::DescargarCuentas(vector<Cuenta *> &o){
	ifstream Archivo;
	Archivo.open(nomArchivo,ios::in);
	//Variables Aux.
	string nom;
	string dni;
	int clv;
	int sld;
	
	//apuntamos al Nombre
    Archivo>>nom;
	//Recibimos los datos mientras que haiga algo que leer
	while (!Archivo.eof())	
    {
		Archivo>>dni;
		Archivo>>sld;
		Archivo>>clv;
		//Lo añadimos al vector 
		o.push_back(new T(nom,dni,clv,sld));
        Archivo>>nom;	
	}
	Archivo.close();
}


template<typename T>
void Registro<T>::CargarCuentas(vector<Cuenta *> &o){
	ofstream Archivo;
	Archivo.open(nomArchivo, ios::out);
    T("","",0,0);
	
	for (int i = 0; i < o.size(); i++)
	{   
		//Evitar Guardar Cuentas que son de otro tipo
        if (o[i]->getTipo() == T("","",0,0).getTipo())
        {
            Archivo << o[i]->getNom() << " " << o[i]->getDni() << " " << o[i]->getSld() << " " << o[i]->getClv()<< "\n";
        }  
	}
	Archivo.close();
}


//FUNCIONES CLAVES
//Verificar si existe la clave ingresada
bool buscarCuenta(int ingclv,vector<Cuenta *> o){
	for (int i = 0; i < o.size() ; i++)
	{
		if(o[i]->getClv() == ingclv){
			return true;
		}
	}
	return false;
}
//Retornar la clave ingresada
Cuenta* devolverCuenta(int ingclv,vector<Cuenta *> o){
	for (int i = 0; i < o.size() ; i++)
	{
		if(o[i]->getClv() == ingclv){
			return o[i];
		}
	}
}
#endif