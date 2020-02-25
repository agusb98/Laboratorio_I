#ifndef dominio_h_INCLUDED
#define dominio_h_INCLUDED

#endif

typedef struct
{
    int id;
    char dominio[50];
    int anio;
    char tipo;

}eDominio;

eDominio* dominio_new();
eDominio* dominio_setters(char* idStr,char* dominioStr,char* anioStr, char* tipoStr);
void  dominio_mapTipo(void* this);

int dominio_show(eDominio* this);

int dominio_setId(eDominio* this,int id);
int dominio_getId(eDominio* this,int* id);

int dominio_setDominio(eDominio* this,char* dominio);
int dominio_getDominio(eDominio* this,char* dominio);

int dominio_setAnio(eDominio* this,int anio);
int dominio_getAnio(eDominio* this,int* anio);

int dominio_setTipo(eDominio* this,char tipo);
int dominio_getTipo(eDominio* this,char* tipo);

int dominio_sortByPatente(void* envioA, void* envioB);

int dominio_filterMotos(void* this);
int dominio_filterAutos(void* this);

int dominio_getters(eDominio* this, int* id, char* dominio, int* anio, char* tipo);
