#ifndef entregas_h_INCLUDED
#define entregas_h_INCLUDED

#endif

typedef struct
{
    int id;
    char tipo[50];
    int cantidad;
    float precio;

}eEntregas;

eEntregas* _new();
eEntregas* _setters(char* idStr,char* tipoStr, char* cantidadStr, char* precioStr);

void _mapPrecio(void* this);

int _show(eEntregas* this);
int _getters(eEntregas* this, int* id, char* tipo, int* cantidad, float* precio);

int _setId(eEntregas* this,int id);
int _getId(eEntregas* this,int* id);

int _setTipo(eEntregas* this,char* tipo);
int _getTipo(eEntregas* this,char* tipo);

int _setCantidad(eEntregas* this,int cantidad);
int _getCantidad(eEntregas* this,int* cantidad);

int _setPrecio(eEntregas* this,float precio);
int _getPrecio(eEntregas* this,float* precio);

int _sortById(void* datoA, void* datoB);
int _sortByNombre(void* punteroA, void* punteroB);

int _filter_1(void* this);
int _filter_2(void* this);

float importe_Total(void* this);
int bultos_Total(void* this);
int tipo_1(void* this);
int tipo_2(void* this);
int tipo_3(void* this);

