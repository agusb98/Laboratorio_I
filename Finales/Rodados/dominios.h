#ifndef dominios_h_INCLUDED
#define dominios_h_INCLUDED

#endif

typedef struct
{
    int id;
    char dominio[50];
    int anio;
    char tipo[50];

}eDominio;

eDominio* _new();
eDominio* _setters(char* var_1, char* var_2, char* var_3, char* var_4);

int _getters(eDominio* this, int* var_1, char* var_2, int* var_3, char* var_4);

int _setId(eDominio* this,int id);
int _getId(eDominio* this,int* id);

int _setDominio(eDominio* this,char* dominio);
int _getDominio(eDominio* this,char* dominio);

int _setAnio(eDominio* this,int anio);
int _getAnio(eDominio* this,int* anio);

int _setTipo(eDominio* this,char* tipo);
int _getTipo(eDominio* this,char* tipo);

int _show(eDominio* this);
int _mapTipo (void* this);
int filter_1 (void* this);
int filter_2 (void* this);
int _sortByNombre(void* datoA, void* datoB);




