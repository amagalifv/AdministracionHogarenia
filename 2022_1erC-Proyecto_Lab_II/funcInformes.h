#ifndef FUNCINFORMES_H_INCLUDED
#define FUNCINFORMES_H_INCLUDED
# include<iostream>
# include<cstdlib>
# include<cstdio>
# include<cstring>
using namespace std;

#include "prototipos.h"
#include "clsMovimiento.h"
#include "clsCategoria.h"

//PROTOTIPOS
void cargarArchivoCategoriasEnVector(Categoria *arrayCateg, int cant);
void mostrarArray(Categoria *arrayCateg, float *arrayAnual, int cant);
//FIN PROTOTIPOS

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
            j=0;
        }

        i++;
    }
}
*/
int calcularCantidadMovimientosAnio(int anio){
    Movimiento reg;
    int posDisco=0;

    while(reg.leerDeDisco(posDisco)==1){
        if(reg.getFecha().getAnio()==anio){
            posDisco++;
        }
    }
    return posDisco;
}

void ponerMatrizEnCero(float **matrizCategMensual, int filas, int columnas){
    for(int i=0; i<filas; i++){
        for (int j=0; j<columnas; j++){
            *(*(matrizCategMensual+i)+j)=0;
        }
    }
}

void ponerVectorEnCero(float *arrayAnual, int cant){
    for(int i=0; i<cant; i++){
        arrayAnual[i]=0;
    }
}

void cargarMatrizCategMensual(float **matrizCategMensual){
    Movimiento reg;
    int posDisco=0;
    int posMatriz=-1;

    while(reg.leerDeDisco(posDisco++)==1){
        //matrizCategMensual[reg.getIdCategoria()-1][reg.getFecha().getMes()-1]+=reg.getImporte();
        posMatriz=buscarCategoria(reg.getCategoria());
        *(*(matrizCategMensual+(posMatriz))+(reg.getFecha().getMes()-1))+=reg.getImporte();
    }
}

void mostrarMatriz(float **matrizCategMensual, int filas, int columnas){
    Categoria reg;

    mensajesListados("TOTAL GASTOS MENSUALES POR CATEGORIA");

    gotoxy(1, 4);cout<<"CATEGORIA";

    for (int i=0; i<12; i++){
        gotoxy((21+(11*i)), 4);
        cout<<"MES "<<i+1;
    }

    gotoxy(0,5);cout<<"________________________________________________________________________________________________________________________________________________________";

    for(int i=0; i<filas; i++){
        reg.leerDeDisco(i);
        gotoxy(0,7+i);
        printf("%s", reg.getNombre());

        for (int j=0; j<columnas; j++){
            gotoxy((21+(11*j)),7+i);
            printf("$%.2f", *(*(matrizCategMensual+i)+j));
        }

    }
}

void totalGastoCategMatriz(){
    int filas=calcularCantidadCategorias();
    const int columnas=12;
    float **matrizCategMensual;

    //PEDIR MEMORIA
    matrizCategMensual= new float *[filas];
    for(int i=0; i<filas; i++){
        matrizCategMensual[i]=new float [columnas];
    }

    ponerMatrizEnCero(matrizCategMensual, filas, columnas);

    cargarMatrizCategMensual(matrizCategMensual);

    mostrarMatriz(matrizCategMensual, filas, columnas);

    //LIBERAR MEMORIA
    for(int i=0; i<filas; i++){
        delete matrizCategMensual[i];
    }

    delete matrizCategMensual;
}

void cargarArchivoCategoriasEnVector(Categoria *arrayCateg, int cant){
    Categoria reg;
    int pos=0;
    for(int i=0;i<cant;i++){
        reg.leerDeDisco(i);
        pos=reg.getId()-1;
        arrayCateg[pos]=reg;
    }
}

void cargarImportesEnVector(float *arrayAnual, int anio){
    Movimiento reg;
    int posDisco=0;
    int posMatriz=-1;

    while(reg.leerDeDisco(posDisco++)==1){
        if(reg.getFecha().getAnio()==anio){
            posMatriz=buscarCategoria(reg.getCategoria());
            arrayAnual[posMatriz]+=reg.getImporte();
        }
    }
}

void mostrarArray(Categoria *arrayCateg, float *arrayAnual, int cant){
    for(int i=0; i<cant; i++){
        //cout<<arrayCateg[i].getNombre()<<"\t"<<arrayAnual[i]<<"\t";
        if(strlen(arrayCateg[i].getNombre())<9){
            printf("  %s\t\t\t $%.2f\n",arrayCateg[i].getNombre(),arrayAnual[i]);
        }
        else{
            if(strlen(arrayCateg[i].getNombre())>8 && strlen(arrayCateg[i].getNombre())<14){
                printf("  %s\t\t $%.2f\n",arrayCateg[i].getNombre(),arrayAnual[i]);
            }
            else{
                printf("  %s\t $%.2f\n",arrayCateg[i].getNombre(),arrayAnual[i]);
            }
        }
        //printf("  %s\t $%.2f\n",arrayCateg[i].getNombre(),arrayAnual[i]);
    }
}

void totalGastoCategoriaAnual(int anio){
    Movimiento reg;
    int cant=0;

    cant=calcularCantidadCategorias();
    Categoria *arrayCateg;
    arrayCateg=new Categoria[cant];
    cargarArchivoCategoriasEnVector(arrayCateg, cant);

    float *arrayAnual;
    arrayAnual=new float[cant]; //es del mismo largo que categorias
    ponerVectorEnCero(arrayAnual, cant);
    cargarImportesEnVector(arrayAnual, anio);

    mensajesListados("GASTOS ANUALES POR CATEGORIA");
    mostrarArray(arrayCateg, arrayAnual,cant);

    delete arrayCateg;
    delete arrayAnual;
}

float sumarAcumuladoCategoriaPeriodo(int codCateg,int opc, Fecha fecha){
    Movimiento reg;
    MovimientoServicio regServ;
    int posDisco=0;
    int posDiscoServ=0;
    float acumulador=0;

    switch (opc)
    {
    case 1:
        /* code */
        break;

    default:
        break;
    }

    while(reg.leerDeDisco(posDisco)==1){
        if(reg.getEstado()){
            if(reg.getCategoria()==codCateg){
                if(reg.getFecha().getAnio()==fecha.getAnio() && reg.getFecha().getMes()== fecha.getMes()){
                    if(codCateg==7){
                        while(regServ.leerDeDisco(posDiscoServ)==1){
                            if(reg.getId()==regServ.getId()){
                                acumulador+=reg.getImporte();
                            }
                            posDiscoServ++;
                        }
                    }
                    else{
                        acumulador+=reg.getImporte();
                    }
                }
            }
        }
        posDisco++;
    }
    return acumulador;
}

float calcularConsumosCategorias(int codCateg, int opc, Fecha fechaActual, Fecha fecha2){
    float totalGastoActual=0;
    float totalGasto2=0;
    float porcentaje=0;

    totalGastoActual=sumarAcumuladoCategoriaPeriodo(codCateg, opc, fechaActual);
    totalGasto2=sumarAcumuladoCategoriaPeriodo(codCateg, opc, fecha2);

    if(totalGasto2==0){
        porcentaje=-2;
    }
    else{
        porcentaje=totalGastoActual*100/totalGasto2;
    }

    if(totalGastoActual==0){
        porcentaje=-1;
    }

    return porcentaje;
}

void compararAhorroCategoriaPeriodos(){
    Fecha fechaActual;
    Fecha fecha2;
    int opc=0;
    int mes=0;
    int anio=0;
    int codCateg;
    int posCateg=-1;
    float porcentaje=0;

    devuelveFechaActualSistema(&fechaActual);

    mensajesListados("PORCENTAJE DE AHORRO CON RELACION A GASTO ANTERIOR");

    cout<<"Ingrese el codigo de la categoria a comparar (0 para salir): \n";
    listarCategoriasAcotado();
    cout<<"\nCategoria elegida: ";
    cin>>codCateg;

    if(codCateg==0){
        cout<<"Proceso cancelado!"<<endl;
        return;
    }

    if(codCateg==7){
        cout<<"Ingrese el numero del servicio (1-EDENOR, 2-GAS NATURAL, 3-TELEFONO, 4-AYSA. 5-PATENTE, 6-ARBA, 7-INTERNET): ";
        cin>>opc;
        while(opc<=0 && opc>7){
            cout<<"Opcion ingresada inválida, escríbala nuevamente: ";
            cin>>opc;
        }
    }

    posCateg=buscarCategoria(codCateg);

    while(posCateg==-1){
        cout<<"El codigo elegido no corresponde a una categoria del listado, escriba nuevamente: ";
        cin>>codCateg;
        posCateg=buscarCategoria(codCateg);
    }

    cout<<"Ingrese el periodo a comparar (se comparará el periodo actual con otro mes/año a elección): "<<endl;
    cout<<"Mes: ";
    cin>>mes;
    cout<<"Año: ";
    cin>>anio;
    fecha2.setMes(mes);
    fecha2.setAnio(anio);

    porcentaje=calcularConsumosCategorias(codCateg, opc, fechaActual, fecha2);

    //**********************
    //Agregar que debe comparar movServ si es categ 7!!!

    if(porcentaje==-1){
        cout<<"No tuviste gastos de esa categoria en ninguno de los periodos!"<<endl;
        return;
    }
    if(porcentaje==-2){
        cout<<"No tuviste gastos de esa categoria en el periodo anterior"<<endl;
        return;
    }
    if(porcentaje==0){
            cout<<"Comparando ambos periodos gastaste lo mismo."<<endl;
    }
    else{
        if(porcentaje>=1 && porcentaje<=100){
            printf("Comparando ambos periodos tuviste un ahorro del %.2f%\n",porcentaje);
        }
        else{
            if(porcentaje>100){
                cout<<"Comparando ambos periodos gastaste un "<<porcentaje-100<<"% más que el periodo anterior."<<endl;
            }
        }
    }
}

void totalAhorroMensual(){
    int anio=0;
    float montoAhorro;

    mensajesListados("TOTAL DE AHORROS POR MES");
    cout<<"\nIndique el año a informar: ";
    cin>>anio;

    for(int i=0; i<12; i++){
        montoAhorro=buscarAhorroPorMesAnio(anio, i+1);
        cout<<"Mes "<<i+1<<"\t$"<<montoAhorro+calcularSaldoDisponibleMesPuntual(anio, i+1)<<endl;
    }
}

void totalAhorroAnual(){
    float acumulador;
    int anio=0;
    float montoAhorro;

    mensajesListados("TOTAL DE AHORROS POR AÑO");
    cout<<"\nIndique el año a informar: ";
    cin>>anio;
    for(int i=0; i<12; i++){
        montoAhorro=buscarAhorroPorMesAnio(anio, i+1);
        acumulador=montoAhorro+calcularSaldoDisponibleMesPuntual(anio, i+1);
    }

    cout<<"El total de dinero ahorrado durante el año "<<anio<<" fue de $"<<acumulador<<endl;
}

int menuInformes(){
    int opc, anio, auxInt;

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
                totalGastoCategMatriz();
                break;
            case 6:
                cout<<"Escriba el año a consultar: ";
                cin>>auxInt;
                cout<<endl;
                totalGastoCategoriaAnual(auxInt);
                break;
            case 7:
                compararAhorroCategoriaPeriodos();
                break;
            case 8:
                totalAhorroMensual();
                break;
            case 9:
                totalAhorroAnual();
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
