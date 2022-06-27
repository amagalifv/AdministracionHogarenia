# include<iostream>
# include<cstdlib>
# include<cstdio>
# include<cstring>
// Añade paquete de idiomas
#include <locale.h>
# include<windows.h>
using namespace std;

#include "prototipos.h"
#include "clsFecha.h"
#include "clsMovimiento.h"
#include "clsMovimientoServicio.h"
#include "funcMovimiento.h"
#include "funcMovimientoServicio.h"
#include "clsCategoria.h"
#include "funcCategoria.h"
#include "clsAhorro.h"
#include "funcAhorro.h"
#include "funcConfiguracion.h"
#include "funcInformes.h"



int main(){
    system ("color 57");
    //system ("mode con cols=152 lines=32");

    /**********************************
     maneja tamaño de la ventana sin
     limitar el buffer de la consola
     tb permite que se pueda mover
    **********************************/
    HWND hWnd=GetConsoleWindowNT();
    MoveWindow(hWnd,0,0,1250,500,TRUE);

    int opc;
    setlocale(LC_ALL, "spanish");

    while(true){
        cout<<"************************************\n";
        cout<<"           MENU PRINCIPAL           \n";
        cout<<"************************************\n";
        cout<<"      1) MENU MOVIMIENTOS           \n";
        cout<<"      2) MENU CATEGORIAS            \n";
        cout<<"      3) MENU KAKEBO                \n";
        cout<<"      4) MENU INFORMES              \n";
        cout<<"      5) MENU CONFIGURACION         \n";
        cout<<"************************************\n";
        cout<<"      0) FIN DEL PROGRAMA           \n";
        cout<<"************************************\n";
        cout<<endl;
        cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
        cin>>opc;
        system("cls");

        switch(opc){

            case 1:
                menuMovimientos();
                break;
            case 2:
                menuCategorias();
                break;
            case 3:
                menuKakebo();
                break;
            case 4:
                menuInformes();
                break;
            case 5:
                menuConfiguracion();
                break;
            default:
                return 0;
                break;
        }
        cout<<endl;
        system("pause");
        system("cls");
    }

    system("pause");
    return 0;
}
