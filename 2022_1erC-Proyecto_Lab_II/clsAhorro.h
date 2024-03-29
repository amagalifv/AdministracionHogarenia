#ifndef CLSAHORRO_H_INCLUDED
#define CLSAHORRO_H_INCLUDED

#include "clsFecha.h"
#include "prototipos.h"

using namespace std;

class Ahorro{
    private:
        Fecha fechaAhorro;
        float montoAhorro;
    public:
        //CONSTRUCTOR POR OMISION
        Ahorro(Fecha pFecha=0, float pMonto=-1){
            fechaAhorro=pFecha;
            montoAhorro=pMonto;
        }

        //SETTERS
        void setFecha(Fecha pFecha){fechaAhorro=pFecha;}
        void setMonto(float pMonto){montoAhorro=pMonto;}

        //GETTERS
        Fecha getFecha(){return fechaAhorro;}
        float getMontoAhorro(){return montoAhorro;}

        //METODOS
        bool Cargar();
        void Mostrar();
        int leerDeDisco(int pos);
        int grabarEnDisco(int pos=-1);

        //SOBRECARGA DE OPERADORES
        // bool operator==(int anio){
        //     if(fechaAhorro.getAnio()==anio){
        //         return true;
        //     }
        //     return false;
        // }
        // bool operator==(int mes){
        //     if(fechaAhorro.getMes()==mes){
        //         return true;
        //     }
        // }
};

bool Ahorro::Cargar(){
    int auxFloat=0;
    int posDisco=0;

    cout<<"Fecha: "<<endl;
    fechaAhorro.Cargar();

    posDisco=existeRegistro(fechaAhorro.getAnio(), fechaAhorro.getMes());

    if(posDisco==-1){
        cout<<"Monto que quiere ahorrar: $";
        cin>>auxFloat;

        if(validarMontoAhorro(auxFloat, fechaAhorro.getAnio(), fechaAhorro.getMes())){
            setMonto(auxFloat);
            return true;
        }
        else{
            return false;
        }
    }
    else{
        cout<<"El registro ya existe. "<<endl;
        return false;
    }
    cout<<endl;
}
void Ahorro::Mostrar(){
    cout<<"Fecha: "<<endl;
    fechaAhorro.Mostrar();
    cout<<"Monto que quiere ahorrar: $"<<getMontoAhorro()<<endl;
}

/******************************************
 Valores que retorna leerDeDisco(int pos):
   -1: NO ENCONTRÓ EL ARCHIVO
    1: LEYO EL ARCHIVO
    2:
    NOTA: SI PARAMETRO == -8, LEE DESDE EL FINAL AL INICIO DEL ARCHIVO
******************************************/
int Ahorro::leerDeDisco(int pos){
    FILE *archivo;
    int leyo=-1;

    archivo=fopen(AR_AHORRO,"rb");

    if(archivo==NULL){
        return -1;
    }

    if( pos == -8){
        fseek(archivo, ftell(archivo)-sizeof(Ahorro), SEEK_END);
        leyo=fread(this, sizeof(Ahorro), 1, archivo);
    }
    else{
        fseek(archivo, pos*sizeof(Ahorro), 0);
        leyo=fread(this, sizeof(Ahorro), 1, archivo);
    }

    fclose(archivo);
    return leyo;
}

/******************************************
 Valores que retorna grabarEnDisco(int pos):
    -1: NO PUDO GRABAR EN EL ARCHIVO
    1: ESCRIBIÓ EL ARCHIVO
    2:
******************************************/
int Ahorro::grabarEnDisco(int pos){
    FILE *archivo;
    int escribio;

    if(pos==-1){
        archivo=fopen(AR_AHORRO, "ab");
        if(archivo==NULL){
            return -1;
        }
    }
    else{
        archivo=fopen(AR_AHORRO, "rb+");
        if(archivo==NULL){
            return -1;
        }
        fseek(archivo, sizeof(Ahorro)*pos, 0);
    }

    escribio=fwrite(this, sizeof(Ahorro), 1, archivo);
    fclose(archivo);
    return escribio;
}

#endif // CLSAHORRO_H_INCLUDED
