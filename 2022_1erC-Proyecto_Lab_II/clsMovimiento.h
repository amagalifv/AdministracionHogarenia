#ifndef CLSMOVIMIENTO_H_INCLUDED
#define CLSMOVIMIENTO_H_INCLUDED

#include "clsFecha.h"

const char *AR_MOVIMIENTOS = "movimientos.dat";
class Movimiento {
    private:
        int _id;
        int _tipo;
        Fecha _fecha;
        float _importe;
        int _categoria;
        bool _estado;

    public:
        void Mostrar();
        void Cargar();
        bool grabarEnDisco();
        int leerDeDisco(int pos);
        int leerDeDisco(int pos, const char *nombreArchivo);
        int modificarDeDisco(int pos);
    //GETTERS
        int getId(){return _id;}
        int getTipo(){return _tipo;}
        Fecha getFecha(){return _fecha;}
        float getImporte(){return _importe;}
        int getCategoria(){return _categoria;}
        bool getEstado(){return _estado;}
    //SETTERS
        void setId(int id){_id=id;}/*ID NO TIENE SETTER BORRAR*/
        void setTipo(int tipo){_tipo=tipo;}
        void setFecha(Fecha f){_fecha=f;}
        void setImporte(float imp){_importe=imp;}
        void setCategoria(int cate){_categoria=cate;}
        void setEstado(bool est){_estado=est;}

};

void Movimiento::Cargar(){
    int aux;
    float aux1;
    //bool est;

    //llamar a autogenerar id

    cout<<"INGRESE EL TIPO DE OPERACION (1-Ingreso , 0-Egreso): ";
    cin>>aux;
    setTipo(aux);

    cout<<"FECHA DE LA OPERACION: "<<endl;
    _fecha.Cargar();

    cout<<"INGRESE EL IMPORTE: ";
    cin>>aux1;
    setImporte(aux1);

    //LISTAR CATEGORIAS
    cout<<"INGRESE LA CATEGORIA DESEADA: ";
    cin>>aux;
    setCategoria(aux);

    /* PARA LA CARGA MANUAL(solo programadores)
    cout<<"Estado               :";
    cin>>est;
    setEstado(est);*/
    setEstado(true);
}

void Movimiento::Mostrar(){
    cout<<"ID                    :";
    cout<<getId()<<endl;
    cout<<"TIPO DE OPERACION     :";
    if (getTipo()) {cout<<"Ingreso"<<endl;}else{ cout<<"Egreso"<<endl;}
    cout<<"FECHA DE LA OPERACION :";
    _fecha.Mostrar();
    cout<<"IMPORTE               :";
    cout<<getImporte()<<endl;
    cout<<"CATEGORIA             :";
    cout<<getCategoria()<<endl;
    cout<<endl;
}

/*
devuelve -1 si no lo pudo abrir archivo
carga en el obj de la cls la info que leyo y devuelve 1
Si no pudo leer devuelve 0
*/
int Movimiento::leerDeDisco(int pos){
    FILE *pMov;
    int leyo;

    pMov=fopen(AR_MOVIMIENTOS,"rb");
    if (pMov==NULL){return -1;}

    fseek(pMov, sizeof(Movimiento)*pos,SEEK_SET);
    leyo=fread(this ,sizeof(Movimiento),1,pMov);
    fclose(pMov);

    return leyo;
}

/*
devuelve -1 si no lo pudo abrir archivo
carga en el obj de la cls la info que leyo y devuelve 1
Si no pudo leer devuelve 0
*/
int Movimiento::leerDeDisco(int pos, const char *nombreArchivo){
    FILE *pMov;
    int leyo;

    pMov=fopen(nombreArchivo,"rb");
    if (pMov==NULL){return -1;}

    fseek(pMov, sizeof(Movimiento)*pos,SEEK_SET);
    leyo=fread(this ,sizeof(Movimiento),1,pMov);
    fclose(pMov);

    return leyo;
}

/*
devuelve falso si NO pudo grabar
y verdadero si pudo
*/
bool Movimiento::grabarEnDisco(){
    FILE *pMov;
    bool escribio;

    pMov=fopen(AR_MOVIMIENTOS,"ab");
    if (pMov==NULL){return false;}

    escribio=fwrite(this ,sizeof(Movimiento),1,pMov);
    fclose(pMov);
    return escribio;
}

/*
-1 si no pudo abrir
0 si no pudo escribir
1 si escribió exitosamente
*/
int Movimiento::modificarDeDisco(int pos){
    FILE *pMov;
    int escribio;

    pMov=fopen(AR_MOVIMIENTOS,"rb+");
    if (pMov==NULL){return -1;}

    fseek(pMov, pos * sizeof(Movimiento),SEEK_SET);
    escribio=fwrite(this,sizeof (Movimiento),1,pMov);

    fclose(pMov);
    return escribio;
}

#endif // CLSMOVIMIENTO_H_INCLUDED
