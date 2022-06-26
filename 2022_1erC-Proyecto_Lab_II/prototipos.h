#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

#include<iostream>
#include<cstring>
# include<cstdlib>
# include<cstdio>
using namespace std;

#include "clsFecha.h"

//ARCHIVOS DAT
const char *AR_MOVIMIENTOS = "Archivos/movimientos.dat";
const char *AR_MOVIMIENTOSERVICIOS = "Archivos/movimientoservicios.dat";
const char *AR_CATEGORIAS = "Archivos/categorias.dat";
const char *AR_AHORRO = "Archivos/ahorros.dat";

//ARCHIVOS BKP
const char *BKP_MOVIMIENTOS = "Archivos/movimientos.bkp";
const char *BKP_MOVIMIENTOSERVICIOS = "Archivos/movimientosServicios.bkp";
const char *BKP_CATEGORIAS = "Archivos/categorias.bkp";
const char *BKP_AHORRO = "Archivos/ahorro.bkp";

//ARCHIVOS INI
const char *INI_MOVIMIENTOS = "Archivos/movimientos.ini";
const char *INI_MOVIMIENTOSERVICIOS = "Archivos/movimientosServicios.ini";
const char *INI_CATEGORIAS = "Archivos/categorias.ini";
const char *INI_AHORRO = "Archivos/ahorro.ini";

//-------GLOBALES-------
void cargarCadena(char *pal, int tam);
void mensajeOperacion(bool resultado);
void mensajesListados(const char *mensaje);

//---MOVIMIENTOS SERVICIOS---
void crearRegistroServicio(int);
void bajaLogicaServicio(int);
int buscarPorIdServ (int);

//--------MOVIMIENTOS---------
void listarMovimientos();
int buscarPorIdMov (int &id);
int bajaLogica(int);
int modificarRegistro(int id);
void mostrarServicio(int id);
bool siCategoriaValida(int);

int menuMovimientos();

//--------FECHA---------
/*bool validarFecha(int d, int m, int a, bool siAnioFutu);
void devuelveFechaActualSistema(Fecha *f);*/

//--------CATEGORIAS---------
int proximoId();
void agregarCategoria();
bool esMovimientoValido(int);
bool esRepetido(const char *);
int listarCategorias();
int listarCategoriaPorId(int);
bool esGastoFijo(int, int, int);
int calcularCantidadCategorias();
int buscarCategoria(int);
void listarCategoriasAcotado();// PARA LISTAR EN MOVIMIENTOS
/*
void copiarArchivoCategoriasAlArray(Categoria *arrayCategorias);
int generarVectorDinamicoCategorias(Categoria *arrayCategorias);  //crea vector dinamico categ - func global
void mostrarEgresosArrayCategorias(Categoria *arrayCategorias, int cantidad);
void mostrarIngesosArrayCategorias(Categoria *arrayCategorias, int cantidad);
bool esEgreso(Categoria *arrayCategorias, int codCateg);
*/
int menuCategorias();

//----------KAKEBO-----------
float calcularIngresos(int, int);
float calcularEgresos(int, int);
float calcularGastoFijo(int, int);
bool validarMontoAhorro(float, int, int);
int existeRegistro(int anio, int mes);
void definirAhorroMes();
bool modificarAhorroMes();
float consultarAhorroDefinido();
void mostrarArchivoAhorro();
float buscarAhorroPorMesAnio(int, int);
float calcularSaldoDisponibleMesActual();
float calcularSaldoDisponibleMesPuntual(int, int);
float calcularPromedioDiarioSaldo();
void quieroAhorrarPara();
bool logroMetaAhorro(int, int);

int menuKakebo();

//---------INFORMES----------

int menuInformes();

//-------CONFIGURACION-------
int menuConfiguracion();
bool bkpMovimientos();
bool bkpMovimientosServicios();
bool bkpCategorias();
bool bkpAhorro();
bool bkpCompletoSistema();
bool restaurarBkpMovimientos();
bool restaurarBkpMovimientosServicios();
bool restaurarBkpCategorias();
bool restaurarBkpAhorross();
bool restaurarCompletoSistema();
bool datosInicioMovimientos();
bool datosInicioMovimientosServicios();
bool datosInicioCategorias();
bool datosInicioAhorros();
bool generarArchivoDatosInicio();
bool cargarDatosInicioMovimientos();
bool cargarDatosInicioMovimientosServicios();
bool cargarDatosInicioCategorias();
bool cargarDatosInicioAhorros();
bool cargarDatosDeInicio();

/*carga una cadena */
void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
    pal[i]=cin.get();
    if(pal[i]=='\n') break;
  }
  pal[i]='\0';
  fflush(stdin);
}

void mensajeOperacion(bool resultado){
  if (resultado){
      cout<<"\nOperacion exitosa!\n"<<endl;
  }
  else{
      cout<<"\nNo se pudo realizar la operacion\n"<<endl;
  }
}

void mensajesListados(const char *mensaje){
  cout<<"\n******** "<<mensaje<<" ********\n"<<endl;
}

#endif // PROTOTIPOS_H_INCLUDED
