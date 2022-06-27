#ifndef FUNCINFORMES_H_INCLUDED
#define FUNCINFORMES_H_INCLUDED
# include<iostream>
# include<cstdlib>
# include<cstdio>
# include<cstring>
using namespace std;

#include "clsMovimiento.h"
#include "clsCategoria.h"

/***************************************************
BUSCA LA CATEGORIA EN AR_CATEGORIAS
Y DEVUELVE EL TIPO DE CATEGORIA (2 EGRESO 1 INGRESO)
0 SI NO LA ENCUENTRA
***************************************************/

// VA EN FUNC-CATEGORIA !!!!!!!!!!!!!!

int buscarTipoCategoria(int categoria){
    Categoria cate;
    int i=0;

    while(cate.leerDeDisco(i)==1) {
        if (cate.getId()==categoria) {
            return cate.getTipoMov();
        }
        i++;
    }
    return 0;
}

void totalIngresosPorMes(int anio){
    Movimiento mov;
    float v[12]={0};
    string  meses[12]={"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Sepiembre","Octubre","Noviembre","Diciembre"};
    int j=0, tipoCategoria;

    while(mov.leerDeDisco(j)==1) {

        tipoCategoria=buscarTipoCategoria(mov.getCategoria());

        if (mov.getFecha().getAnio()==anio && tipoCategoria==1) {
            v[mov.getFecha().getMes()-1]+=mov.getImporte();
        }
        j++;
    }

    cout<<"\n*********LISTA DE INGRESOS POR MES*********\n";
    for (int k=0; k<12; k++) {
        cout<<meses[k]<<" - Total $ "<<v[k]<<endl;
    }
}

void totalEgresosPorMes(int anio){
    Movimiento mov;
    float v[12]={0};
    string  meses[12]={"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Sepiembre","Octubre","Noviembre","Diciembre"};
    int j=0, tipoCategoria;

    while(mov.leerDeDisco(j)==1) {
        tipoCategoria=buscarTipoCategoria(mov.getCategoria());
        if (mov.getFecha().getAnio()==anio && tipoCategoria==2) {
            v[mov.getFecha().getMes()-1]+=mov.getImporte();
        }
        j++;
    }

    cout<<"\n*********LISTA DE EGRESOS POR MES*********\n";
    for (int k=0; k<12; k++) {
        cout<<meses[k]<<" - Total $ "<<v[k]<<endl;
    }
}

void totalIngresosPorAnio(int anio){
    Categoria cate;
    Movimiento mov;
    float acu=0;
    int i=0, j=0;

    while (cate.leerDeDisco(i)==1) {

        if (cate.getTipoMov()==1) { // si es igual a ingreso
            cout<<"CATEGORIA: "<<cate.getId()<<" - "<<cate.getNombre();

            while(mov.leerDeDisco(j)==1) {
                if (mov.getFecha().getAnio()==anio && mov.getCategoria()==cate.getId()) {
                    acu+=mov.getImporte();
                }
                j++;
            }

            cout<<": $"<<acu<<endl;
            acu=0;
            j=0;
        }

        i++;
    }
}

void totalEgresosPorAnio(int anio){
    Categoria cate;
    Movimiento mov;
    float acu=0;
    int i=0, j=0;

    while (cate.leerDeDisco(i)==1) {

        if (cate.getTipoMov()==2) { // si es igual a egreso
            cout<<"CATEGORIA: "<<cate.getId()<<" - "<<cate.getNombre();

            while(mov.leerDeDisco(j)==1) {
                if (mov.getFecha().getAnio()==anio && mov.getCategoria()==cate.getId()) {
                    acu+=mov.getImporte();
                }
                j++;
            }

            cout<<": $"<<acu<<endl;
            acu=0;
            j=0;
        }

        i++;
    }
}

/*
void totalGastoPorCategoriaMensual(int anio){
    Categoria cate;
    Movimiento mov;
    float v[12]={0};
    string  meses[12]={"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Sepiembre","Octubre","Noviembre","Diciembre"};
    int i=0, j=0;

    while (cate.leerDeDisco(i)==1) {

        if (cate.getTipoMov()==2) { // si es igual a egreso
            cout<<"CATEGORIA: "<<cate.getId()<<" - "<<cate.getNombre()<<endl;

            while(mov.leerDeDisco(j)==1) {
                if (mov.getFecha().getAnio()==anio && mov.getCategoria()==cate.getId()) {
                    v[mov.getFecha().getMes()-1]+=mov.getImporte();
                }
                j++;
            }

            for (int k=0; k<12; k++) {
                cout<<meses[k]<<" - Total $ "<<v[k]<<endl;
                v[k]=0;//aca voy poniendo el vecto en 0 para la próxima categoria
            }
        }

        i++;
    }
}
*/

int menuInformes(){
    int opc, anio;

    while(true){
        cout<<"               MENU INFORMES                \n";
        cout<<"--------------------------------------------\n";
        cout<<endl;
        cout<<" 1) TOTAL INGRESOS  MENSUALES               \n";
        cout<<" 2) TOTAL EGRESOS  MENSUALES                \n";
        cout<<" 3) TOTAL INGRESOS  ANUALES                 \n";
        cout<<" 4) TOTAL EGRESOS  ANUALES                  \n";
        cout<<" 5) TOTAL GASTO POR CATEGORIA MENSUAL       \n";
        cout<<" 6) TOTAL GASTO POR CATEGORIA ANUAL         \n";
        cout<<" 7) ESTABLECER PORCENTAJE DE AHORRO POR     \n";
        cout<<" CATEGORIA EN RELACION AL GASTO             \n";
        cout<<" 8) TOTAL AHORRO  MENSUAL                   \n";
        cout<<" 9) TOTAL AHORRO ANUAL                      \n";
        cout<<"--------------------------------------------\n";
        cout<<"0) FIN DEL PROGRAMA                         \n";
        cin>>opc;
        system("cls");

        switch(opc){

            case 1:
                cout<<"INGRESE EL AÑO A LISTAR: ";
                cin>>anio;
                totalIngresosPorMes(anio);
                break;
            case 2:
                cout<<"INGRESE EL AÑO A LISTAR: ";
                cin>>anio;
                totalEgresosPorMes(anio);
                break;
            case 3:
                cout<<"INGRESE EL AÑO A LISTAR: ";
                cin>>anio;
                totalIngresosPorAnio(anio);
                break;
            case 4:
                cout<<"INGRESE EL AÑO A LISTAR: ";
                cin>>anio;
                totalEgresosPorAnio(anio);
                break;
            case 5:
                //cout<<"INGRESE EL AÑO A LISTAR: ";
                //cin>>anio;
                //totalGastoPorCategoriaMensual(anio);
                cout<<"En construccion...";
                break;
            case 6:
                cout<<"En construccion...";
                break;
            case 7:
                cout<<"En construccion...";
                break;
            case 8:
                cout<<"En construccion...";
                break;
            case 9:
                cout<<"En construccion...";
                break;
            case 10:
                cout<<"En construccion...";
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

#endif // FUNCINFORMES_H_INCLUDED
