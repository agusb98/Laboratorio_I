#ifndef ingredientes_h_INCLUDED
#define ingredientes_h_INCLUDED

#endif

typedef struct
{
    int id;
    char nombre[50];
    float calorias, grasa, sodio, carbohidratos, proteinas;

}eIngrediente;

eIngrediente* ingrediente_new();
eIngrediente* ingrediente_setters(char* var_1, char* var_2, char* var_3, char* var_4, char* var_5, char* var_6, char* var_7);

int ingrediente_getters(eIngrediente* this, int* var_1, char* var_2, float* var_3, float* var_4, float* var_5, float* var_6, float* var_7);

int ingrediente_setId(eIngrediente* this,int id);
int ingrediente_getId(eIngrediente* this,int* id);

int ingrediente_setNombre(eIngrediente* this,char* nombre);
int ingrediente_getNombre(eIngrediente* this,char* nombre);

int ingrediente_setCalorias(eIngrediente* this,float calorias);
int ingrediente_getCalorias(eIngrediente* this,float* calorias);

int ingrediente_setGrasa(eIngrediente* this,float grasa);
int ingrediente_getGrasa(eIngrediente* this,float* grasa);

int ingrediente_setSodio(eIngrediente* this,float sodio);
int ingrediente_getSodio(eIngrediente* this,float* sodio);

int ingrediente_setCarbohidratos(eIngrediente* this,float carbohidratos);
int ingrediente_getCarbohidratos(eIngrediente* this,float* carbohidratos);

int ingrediente_setProteinas(eIngrediente* this,float proteinas);
int ingrediente_getProteinas(eIngrediente* this,float* proteinas);

int ingrediente_show(eIngrediente* this);
int ingredientes_sortById(void* punteroA, void* punteroB);
int ingrediente_sortByNombre(void* datoA, void* datoB);
eIngrediente* ingrediente_findByID (void* this);

