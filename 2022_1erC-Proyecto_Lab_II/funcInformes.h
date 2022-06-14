#ifndef FUNCINFORMES_H_INCLUDED
#define FUNCINFORMES_H_INCLUDED
# include<iostream>
# include<cstdlib>
# include<cstdio>
# include<cstring>
using namespace std;


int menuInformes(){
    int opc;

    while(true){
        cout<<"               MENU INFORMES                \n";
        cout<<"--------------------------------------------\n";
        cout<<endl;
        cout<<" 1) TOTAL INGRESOS  MENSUALES               \n";
        cout<<" 2) TOTAL EGRESOS  MENSUALES                \n";
        cout<<" 3) TOTAL INGRESOS  ANUALES                 \n";
        cout<<" 4) TOTAL EGRESOS  ANUALES                  \n";
        cout<<" 5) TOTAL GASTO POR CATEGORIA MENSUAL       \n";
        cout<<" 6) TOTAL GASTO FIJO EN MENSUAL DETERMINADO \n";
        cout<<" 7) TOTAL GASTO POR CATEGORIA ANUAL         \n";
        cout<<" 8) ESTABLECER PORCENTAJE DE AHORRO POR     \n";
        cout<<" CATEGORIA EN RELACION AL GASTO             \n";
        cout<<" 9) TOTAL AHORRO  MENSUAL                   \n";
        cout<<"10) TOTAL AHORRO ANUAL                      \n";
        cout<<"--------------------------------------------\n";
        cout<<"0) FIN DEL PROGRAMA                         \n";
        cin>>opc;
        system("cls");

        switch(opc){

            case 1:
                cout<<"En construccion...";
                break;
            case 2:
                cout<<"En construccion...";
                break;
            case 3:
                cout<<"En construccion...";
                break;
            case 4:
                cout<<"En construccion...";
                break;
            case 5:
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
