#include <iostream>
#include <string>
#include "Cuenta.h"
#include "CuentaComun.h"
#include "CuentaAdm.h"
#include "Menu.h"
#include "Registro.h"

using namespace std;

int main(){

    vector <Cuenta *> Cuentas;

    Registro <CuentaComun> RegCta("regCuentas.txt");
    Registro <CuentaAdm> RegCtaAdm("regCuentasAdm.txt");
    RegCta.DescargarCuentas(Cuentas);
    RegCtaAdm.DescargarCuentas(Cuentas);
    int opcion;
    //Bucle
    do
    {
        opcion = 0;
        system("cls");
        switch (menuInicio())
        {
        case 1:
            system("cls");
            int ingclave;
            cout << "Ingrese su clave;" <<endl;
            cin >> ingclave;
            if(buscarCuenta(ingclave,Cuentas))
            {
                //APUNTAR A LA CUENTA ENCONTRADA
                Cuenta * ptrCuenta = devolverCuenta(ingclave,Cuentas);
                do
                {
                    opcion = 0;
                    system("cls");
                    switch (ptrCuenta->menuCuenta())
                    {
                    case 1:
                        ptrCuenta->mostrar(Cuentas);
                        system("pause");
                        break;
                    case 2:
                        ptrCuenta->retirar();
                        system("pause");
                        break;
                    case 3:
                        ptrCuenta->depositar();
                        system("pause");
                        break;
                    case 4:
                        opcion = 4;
                        break;
                    default:
                        break;
                    }
                } while (opcion !=4);
            }
            opcion = 0;
            break;
        case 2:
            RegCta.agregar(Cuentas);
            system("pause");
            break;
        case 3:
            opcion = 3;
            break;
        default:
            cout << "Numero invalido" << endl;
            break;
        }
    } while (opcion !=3);



    RegCta.CargarCuentas(Cuentas);


    //Liberar Memoria
    for (const Cuenta *cuentaPtr : Cuentas )
	{
        delete cuentaPtr;
	}
}
