#include <iostream>

using namespace std;

#include "fecha.h"
#include "tarjeta.h"
#include "viaje.h"
#include "puntos.h"


int main(){
    int opc;
    ArchivoViaje archiV("viajes.dat");
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"*********************"<<endl;
        cout<<"1. SUBMENU TARJETAS"<<endl;
        cout<<"2. SUBMENU VIAJES"<<endl;
        cout<<"3. SUBMENU PUNTOS"<<endl;
        /*cout<<"5. MODIFICAR NRO TARJETA"<<endl;*/
        cout<<"0. SALIR"<<endl;
        cout<<"*********************"<<endl;
        cout<<"OPCION "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: subMenuTarjetas();
                break;
            case 2: subMenuViajes();
                break;
            case 3:  subMenuOpciones();
                break;
            /*case 5: if(modificarEmail()==true) cout<<"REGISTRO MODIFICADO"<<endl;
                    else cout<<"NO SE PUDO MODIFICAR EL REGISTRO"<<endl;
                break;
            case 6: cargoMasEmpleados();
                break;*/
            case 0:return 0;
                break;
        }
        cout<<endl;
        system("pause");
    }
	cout<<endl;
	system("pause");
	return 0;
}
