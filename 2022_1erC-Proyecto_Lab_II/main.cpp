# include<iostream>
# include<cstdlib>
# include<cstdio>
# include<cstring>
using namespace std;

# include "prototipos.h"
# include "clsMovimiento.h"
# include "funcMovimiento.h"

int main(){
    int opc;

    while(true){
        cout<<"        MENU PRINCIPAL          \n";
        cout<<"--------------------------------\n";
        cout<<endl;
        cout<<"1) MENU MOVIMIENTOS             \n";
        cout<<"2) MENU CATEGORIAS              \n";
        cout<<"3) MENU KAKEBO                  \n";
        cout<<"4) MENU INFORMES                \n";
        cout<<"5) MENU CONFIGURACION           \n";
        cout<<"--------------------------------\n";
        cout<<"0) FIN DEL PROGRAMA             \n";
        cin>>opc;
        system("cls");

        switch(opc){

            case 1:
                menuMovimientos();
                break;
            case 2:
                cout<<"En construccion...";
                //menuCategorias();
                break;
            case 3:
                cout<<"En construccion...";
                //menuKakebo();
                break;
            case 4:
                //menuInformes();
                cout<<"En construccion...";
                break;
            case 5:
                //menuConfiguracion();
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
