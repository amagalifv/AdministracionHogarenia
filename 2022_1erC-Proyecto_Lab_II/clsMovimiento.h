#ifndef CLSMOVIMIENTO_H_INCLUDED
#define CLSMOVIMIENTO_H_INCLUDED

#include "clsFecha.h"

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
        bool leerDeDisco();
    //GETTERS
        int getId(){return _id;}
        int getTipo(){return _tipo;}
        Fecha getFecha(){return _fecha;}
        float getImporte(){return _importe;}
        int getCategoria(){return _categoria;}
        bool getEstado(){return _estado;}
    //SETTERS
        void setId(int id){/*No deberia tener setter*/}
        void setTipo(int tipo){_tipo=tipo;}
        void setFecha(Fecha f){_fecha=f;}
        void setImporte(float imp){_importe=imp;}
        void setCategoria(int cate){_categoria=cate;}
        void setEstado(bool est){_estado=est;}

};

#endif // CLSMOVIMIENTO_H_INCLUDED
