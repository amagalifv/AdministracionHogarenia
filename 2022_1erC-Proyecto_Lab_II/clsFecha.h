#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED
# include<iostream>
using namespace std;

/*AUN NO MEJORÉ ESTA CLASE HAY QUE EDITARLA*/
class Fecha {
    private:
        int _dia, _mes, _anio;
    public:
        Fecha(int dia=0, int mes=0, int anio=0){
            _dia=dia;
            _mes=mes;
            _anio=anio;
        }
        void Mostrar();
        void Cargar();
        void CargarParaCli();
        int ConsolidadarFecha(){return ((_anio*10000)+(_mes*100)+(_dia));}
        ///gets()
        int getDia(){return _dia;}
        int getMes(){return _mes;}
        int getAnio(){return _anio;}
        ///sets()
        void setDia(int d){if(d>=1 && d<=31){ _dia=d;}else{_dia=0;_mes=0;_anio=0;}}
        void setMes(int m){if(m>=1 && m<=12){ _mes=m;}else{_dia=0;_mes=0;_anio=0;}}
        void setAnio(int a){if(a>=1920 && a<=2022){_anio=a;}else{_dia=0;_mes=0;_anio=0;}}
};

void Fecha::Mostrar(){
    if (getDia()<10){
        cout<<"0"<<getDia();
    }else{
        cout<<getDia();
    }
    cout<<"/";
    if (getMes()<10){
        cout<<"0"<<getMes();
    }else{
        cout<<getMes();
    }
    cout<<"/"<<getAnio()<<endl;
}

void Fecha::Cargar(){
    int aux;

    cout<<"INGRESE EL DIA:             ";
    cin>>aux;
    setDia(aux);

    cout<<"INGRESE EL MES:             ";
    cin>>aux;
    setMes(aux);

    cout<<"INGRESE EL AÑO (4 digitos): ";
    cin>>aux;
    setAnio(aux);
}

#endif // CLSFECHA_H_INCLUDED
