#ifndef tecnico_h_INCLUDED
#define tecnico_h_INCLUDED

#endif

typedef struct
{
    int id_Llamada;
    char fecha[50];
    float numero_Cliente;
    int id_Problema;
    char solucionado[50];

}eLlamada;

eLlamada* _new();
eLlamada* _setters(char* var_1, char* var_2, char* var_3, char* var_4, char* var_5);

int _getters(eLlamada* this, int* var_1, char* var_2, float* var_3, char* var_4, char* var_5);

int _setId_Llamada(eLlamada* this,int id_Llamada);
int _getId_Llamada(eLlamada* this,int* id_Llamada);

int _setFecha(eLlamada* this,char* fecha);
int _getFecha(eLlamada* this,char* fecha);

int _setNumero_Cliente(eLlamada* this,float numero_Cliente);
int _getNumero_Cliente(eLlamada* this,float* numero_Cliente);

int _setId_Problema(eLlamada* this,int id_Problema);
int _getId_Problema(eLlamada* this,char* id_Problema);

int _setSolucion(eLlamada* this,char* solucionado);
int _getSolucion(eLlamada* this,char* solucionado);

int _show(eLlamada* this);
int filter_1 (void* this);
int filter_2 (void* this);
int filter_3 (void* this);
int filter_4 (void* this);
int filter_5 (void* this);
int _sortById(void* datoA, void* datoB);




