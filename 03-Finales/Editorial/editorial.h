#ifndef editorial_h_INCLUDED
#define editorial_h_INCLUDED

#endif

typedef struct
{
    int var_1;
    char var_2[50];
    char var_3[50];
    float var_4;
    int var_5;

}eEditorial;

eEditorial* _new();
eEditorial* _setters(char* var_1,char* var_2, char* var_3, char* var_4, char* var_5);

void _mapPrecio(void* this);

int _show(eEditorial* this);
int _getters(eEditorial* this, int* var_1, char* var_2, char* var_3, float* var_4, char* var_5);

int _setId(eEditorial* this,int var_1);
int _getId(eEditorial* this,int* var_1);

int _setTitulo(eEditorial* this,char* var_2);
int _getTitulo(eEditorial* this,char* var_2);

int _setAutor(eEditorial* this,char* var_3);
int _getAutor(eEditorial* this,char* var_3);

int _setPrecio(eEditorial* this,float var_4);
int _getPrecio(eEditorial* this,float* var_4);

int _setIdEditorial(eEditorial* this,int var_5);
int _getIdEditorial(eEditorial* this,char* var_5);

int _sortById(void* datoA, void* datoB);
int _sortByNombre(void* punteroA, void* punteroB);

int _filter_1(void* this);
int _filter_2(void* this);

