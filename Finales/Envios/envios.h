#ifndef envios_h_INCLUDED
#define envios_h_INCLUDED

#endif

typedef struct
{
    int var_1;
    char var_2[50];
    float var_3;
    int var_4;
    float var_5;

}eEnvio;

eEnvio* _new();
eEnvio* _setters(char* var_1, char* var_2, char* var_3, char* var_4, char* var_5);

int _getters(eEnvio* this, int* var_1, char* var_2, float* var_3, char* var_4, float* var_5);

int _setId(eEnvio* this,int var_1);
int _getId(eEnvio* this,int* var_1);

int _setNombre(eEnvio* this,char* var_2);
int _getNombre(eEnvio* this,char* var_2);

int _setKilometros(eEnvio* this,float var_3);
int _getKilometros(eEnvio* this,float* var_3);

int _setTipo(eEnvio* this,int var_4);
int _getTipo(eEnvio* this,char* var_4);

int _setPrecio(eEnvio* this,float var_5);
int _getPrecio(eEnvio* this,float* var_5);

int _sortById(void* datoA, void* datoB);
int _sortByNombre(void* punteroA, void* punteroB);

int _show(eEnvio* this);
int _mapPrecio (void* this);



