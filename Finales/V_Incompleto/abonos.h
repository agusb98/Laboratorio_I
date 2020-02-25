#ifndef abonos_h_INCLUDED
#define abonos_h_INCLUDED

#endif

typedef struct
{
    int id, tipo, idCliente;
    float importeFinal;

}eAbono;

eAbono* abono_new();
eAbono* abono_setters(char* var_1, char* var_2, char* var_3, char* var_4);
int abono_getters(eAbono* this, int* var_1, int* var_2, int* var_3, float* var_4);

int abono_setId(eAbono* this,int id);
int abono_getId(eAbono* this,int* id);
int abono_getFreeID (LinkedList* this);

int abono_setTipo(eAbono* this,int tipo);
int abono_getTipo(eAbono* this,char* tipo);

int abono_setIdCliente(eAbono* this,int idCliente);
int abono_getIdCliente(eAbono* this,int* idCliente);

int abono_setImporteFinal(eAbono* this,float importeFinal);
int abono_getImporteFinal(eAbono* this,float* importeFinal);

int abono_show(eAbono* this, LinkedList* client);
int abono_sortByImport(void* datoA, void* datoB);
int abono_sortByID(void* punteroA, void* punteroB);




