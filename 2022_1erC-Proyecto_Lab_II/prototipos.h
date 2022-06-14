#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

#include<iostream>
#include<cstring>
using namespace std;

const char *AR_MOVIMIENTOS = "movimientos.dat";
const char *AR_MOVIMIENTOSERVICIOS = "movimientoservicios.dat";


void cargarCadena(char *pal, int tam);

//---MOVIMIENTOS SERVICIOS---
void crearRegistroServicio(int);
void bajaLogicaServicio(int);
int buscarPorId (int);

//--------MOVIMIENTOS---------
void listarMovimientos();
int bajaLogica (int pos);
int modificarRegistro(int id);
void mostrarServicio(int id);

int menuMovimientos();

//--------CATEGORIAS---------

//----------KAKEBO-----------

//---------INFORMES----------


int menuInformes();

//-------CONFIGURACION-------


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

#endif // PROTOTIPOS_H_INCLUDED
