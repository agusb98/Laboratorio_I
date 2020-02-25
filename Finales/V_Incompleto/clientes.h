#ifndef clientes_h_INCLUDED
#define clientes_h_INCLUDED

#endif

typedef struct
{
    int id;
    char nombre[50];
    char sexo[50];
    float numeroTelefonico;
    float importe;

}eCliente;

eCliente* cliente_new();
eCliente* cliente_setters(char* var_1, char* var_2, char* var_3, char* var_4, char* var_5);

int cliente_getters(eCliente* this, int* var_1, char* var_2, char* var_3, float* var_4, float* var_5);

int cliente_setId(eCliente* this,int id);
int cliente_getId(eCliente* this,int* id);
int cliente_freeID (LinkedList* this);

int cliente_setNombre(eCliente* this,char* nombre);
int cliente_getNombre(eCliente* this,char* nombre);

int cliente_setSexo(eCliente* this,char* sexo);
int cliente_getSexo(eCliente* this,char* sexo);

int cliente_setNumeroTelefonico(eCliente* this,float numeroTelefonico);
int cliente_getNumeroTelefonico(eCliente* this,float* numeroTelefonico);

int cliente_setImporte(eCliente* this,float importe);
int cliente_getImporte(eCliente* this,float* importe);

int cliente_show(eCliente* this);
int cliente_sortByNombre(void* datoA, void* datoB);
int cliente_sortById(void* datoA, void* datoB);




