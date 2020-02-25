#ifndef computer_h_INCLUDED
#define computer_h_INCLUDED

#endif

typedef struct
{
    int id;
    char descripcion[200];
    float precio;
    int idTipo;
    float oferta;

}eComputer;

eComputer* _new();
eComputer* _setters(char* id, char* descripcion, char* precio, char* idTipo, char* oferta);

int _getters(eComputer* this, int* id, char* descripcion, float* precio, char* idTipo, float* oferta);

int _setId(eComputer* this,int id);
int _getId(eComputer* this,int* id);

int _setDescripcion(eComputer* this,char* descripcion);
int _getDescripcion(eComputer* this,char* descripcion);

int _setPrecio(eComputer* this,float precio);
int _getPrecio(eComputer* this,float* precio);

int _setTipo(eComputer* this,int idTipo);
int _getTipo(eComputer* this,char* idTipo);

int _setOferta(eComputer* this,float oferta);
int _getOferta(eComputer* this,float* oferta);

int _sortById(void* datoA, void* datoB);
int _sortByNombre(void* punteroA, void* punteroB);

int _show(eComputer* this);
int _mapPrecio (void* this);
int _filterDesktop(void* this);



