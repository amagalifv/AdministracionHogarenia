#ifndef FUNCMOVIMIENTOSERVICIO_H_INCLUDED
#define FUNCMOVIMIENTOSERVICIO_H_INCLUDED

#include "prototipos.h"
#include "clsMovimientoServicio.h"

void crearRegistroServicio(int id){
    MovimientoServicio serv;

    serv.Cargar(id);
    serv.grabarEnDisco();
}

void bajaLogicaServicio(int id){
    int pos;
    MovimientoServicio serv;

    pos=buscarPorId(id);
    if (serv.leerDeDisco(pos)!=-1) {
        serv.setEstado(false);
    }

}

/************************************
retorna pos de servicio en arch mov_Servicios
-1 si no lo encuentra
*************************************/
int buscarPorId (int id) {
    int i=0;
    MovimientoServicio serv;

    while (serv.leerDeDisco(i)==1) {
        if (serv.getId()==id) {
            return i;
        }
    }
    return -1;
}

#endif // FUNCMOVIMIENTOSERVICIO_H_INCLUDED
