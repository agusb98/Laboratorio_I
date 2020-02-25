#ifndef recetas_h_INCLUDED
#define recetas_h_INCLUDED

#endif


typedef struct
{
    int id;
    char nombre[50];
    char ingredientes[200];
    float calorias, grasa, sodio, carbohidratos, proteinas;

}eReceta;

eReceta* receta_new();
eReceta* receta_setters(char* var_1, char* var_2, char* var_3, char* var_4, char* var_5, char* var_6, char* var_7, char* var_8);

int receta_getters(eReceta* this, int* var_1, char* var_2, char* var_3, float* var_4, float* var_5, float* var_6, float* var_7, float* var_8);

int receta_setId(eReceta* this,int id);
int receta_getId(eReceta* this,int* id);

int receta_setNombre(eReceta* this,char* nombre);
int receta_getNombre(eReceta* this,char* nombre);

int receta_setIngredientes(eReceta* this,char* ingredientes);
int receta_getIngredientes(eReceta* this,char* ingredientes);

int receta_setCalorias(eReceta* this,float calorias);
int receta_getCalorias(eReceta* this,float* calorias);

int receta_setGrasa(eReceta* this,float grasa);
int receta_getGrasa(eReceta* this,float* grasa);

int receta_setSodio(eReceta* this,float sodio);
int receta_getSodio(eReceta* this,float* sodio);

int receta_setCarbohidratos(eReceta* this,float carbohidratos);
int receta_getCarbohidratos(eReceta* this,float* carbohidratos);

int receta_setProteinas(eReceta* this,float proteinas);
int receta_getProteinas(eReceta* this,float* proteinas);

int receta_show(eReceta* this);
int receta_sortById(void* punteroA, void* punteroB);


