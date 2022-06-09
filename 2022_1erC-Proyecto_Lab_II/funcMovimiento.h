#ifndef MOVIMIENTO_H_INCLUDED
#define MOVIMIENTO_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstdio>
# include<cstring>
using namespace std;

#include "clsMovimiento.h"

/* LISTA TODOS LOS MOVIMIENTOS */
void listarMovimientos(){
    Movimiento mov;
    int i=0;

    while(mov.leerDeDisco(i)==1){
        if (mov.getEstado()) {
            mov.Mostrar();
        }
        i++;
    }
}

/*
-1 registro no encontrado
0 si no pudo modificar
1 si cambió el archivo correctamente
*/
int bajaLogica (int pos){
    Movimiento mov;
    int modif;

    if (pos>=0) {
        mov.leerDeDisco(pos);
        mov.setEstado(false);
        modif=mov.modificarDeDisco(pos);
        return modif;
    } else {
        return -1;
    }
}

int modificarRegistro(int id){
    int opc;
    Movimiento mov;
    Fecha fecha;
    int auxI;
    float auxF;
    char resp;
    int devol;

    mov.leerDeDisco(id);

    cout<<"      ¿QUE DESEA MODIFICAR?    \n";
    cout<<"1) TIPO DE MOVIMIENTO          \n";
    cout<<"2) FECHA DE MOVIMIENTO         \n";
    cout<<"3) IMPORTE DE MOVIMIENTO       \n";
    cout<<"4) CATEGORIA DE MOVIMIENTO     \n";
    cout<<"5) SI ES GASTO FIJO            \n";
    cout<<"-------------------------------\n";

    cin>>opc;
    system("cls");

    switch(opc){

        case 1:
            cout<<"INGRESE EL TIPO DE OPERACION (1-Ingreso , 0-Egreso): ";
            cin>>auxI;
            mov.setTipo(auxI);
            break;
        case 2:
            fecha.Cargar();
            mov.setFecha(fecha);
            break;
        case 3:
            cout<<"INGRESE EL IMPORTE A MODIFICAR: ";
            cin>>auxF;
            mov.setImporte(auxF);
            break;
        case 4:
            cout<<"INGRESE LA CATEGORIA DESEADA: ";
            cin>>auxI;
            mov.setCategoria(auxI);
            break;
        case 5:
            cout<<"ES UN GASTO FIJO (S PARA SI Y N PARA NO): ";
            cin>>resp;
            if (resp=='s' || resp=='S') mov.setSiGastoFijo(true);
            else mov.setSiGastoFijo(false);
            break;
        default:
            break;
    }
    devol=mov.modificarDeDisco(id);

    return devol;
}

int menuMovimientos(){
    int opc, id, devol;
    Movimiento obj;

    while(true){
        cout<<"       MENU MOVIMIENTOS         \n";
        cout<<"--------------------------------\n";
        cout<<endl;
        cout<<"1) INGRESAR MOVIMIENTO          \n";
        cout<<"2) MODIFICAR MOVIMIENTO         \n";
        cout<<"3) BORRAR MOVIMIENTO            \n";
        cout<<"4) LISTAR MOVIMIENTOS           \n";
        cout<<"--------------------------------\n";
        cout<<"0) IR A MENU PRINCIPAL          \n";
        cin>>opc;
        system("cls");

        switch(opc){

            case 1:
                obj.Cargar();
                obj.grabarEnDisco();
                break;
            case 2:
                cout<<"INGRESE EL ID DEL MOVIMIENTO A MODIFICAR";
                cin>>id;
                modificarRegistro(id);
                break;
            case 3:
                cout<<"INGRESE EL ID DEL MOVIMIENTO A BORRAR";
                cin>>id;
                devol=bajaLogica(id);
                if (devol==1) {
                    cout<<"El registro se dió de baja exitosamente";
                }else{cout<<"Error";}
                break;
            case 4:
                listarMovimientos();
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

#endif // MOVIMIENTO_H_INCLUDED
