#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

const char *AR_MOVIMIENTOS = "movimientos.dat";

//--------MOVIMIENTOS---------
int autogenerarId();
void listarMovimientos();
int bajaLogica (int pos);
int modificarRegistro(int id);

/* MENU -->*/int menuMovimientos();

//--------CATEGORIAS---------

//----------KAKEBO-----------

//---------INFORMES----------

//-------CONFIGURACION-------

#endif // PROTOTIPOS_H_INCLUDED
