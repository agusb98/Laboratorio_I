#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "recetas.h"
#include "utn.h"

eReceta* receta_new()
{
    eReceta* this = malloc(sizeof(eReceta)); //Creo un nuevo dominios con memodia dinamica "malloc"
    if(this == NULL)
    {
        printf("Almacenamiento lleno.\n");
        exit(EXIT_FAILURE); //De ser NULL salgo
    }
    else //De lo contrario parseo a 0 y cadena vacia las variables
    {
        this->id = 0;
        strcpy(this->nombre, "");
        strcpy(this->ingredientes, "");
        this->calorias = 0;
        this->grasa = 0;
        this->sodio = 0;
        this->carbohidratos = 0;
        this->proteinas = 0;

    }
    return this; //Retorno el puntero a la estructura creada
}

eReceta* receta_setters(char* var_1, char* var_2, char* var_3, char* var_4, char* var_5, char* var_6, char* var_7, char* var_8)
{
    eReceta* this = receta_new();
    if (this != NULL)
    {
        if (!receta_setId(this,atoi(var_1)))
            this = NULL;

        if( !receta_setNombre(this,var_2))
            this = NULL;

        if( !receta_setIngredientes(this,var_3))
            this = NULL;

        if( !receta_setCalorias(this,atof(var_4)) )
            this = NULL;

        if( !receta_setGrasa(this,atof(var_5)) )
            this = NULL;

        if( !receta_setSodio(this,atof(var_6)) )
            this = NULL;

        if( !receta_setCarbohidratos(this,atof(var_7)) )
            this = NULL;

        if( !receta_setProteinas(this,atof(var_8)) )
            this = NULL;

        if(this == NULL)
        {
            printf("\nError al cargar datos, revise la lista.\n");
            free(this);
        }
    }
    return this;
}

int receta_getters(eReceta* this, int* var_1, char* var_2, char* var_3, float* var_4, float* var_5, float* var_6, float* var_7, float* var_8)
{
    if (this != NULL)
    {
        if (!receta_getId(this, var_1))
            return 0;
        if (!receta_getNombre(this, var_2))
            return 0;
            if (!receta_getIngredientes(this, var_3))
            return 0;
        if (!receta_getCalorias(this, var_4))
            return 0;
        if (!receta_getGrasa(this, var_5))
            return 0;
        if (!receta_getSodio(this, var_6))
            return 0;
        if (!receta_getCarbohidratos(this, var_7))
            return 0;
        if (!receta_getProteinas(this, var_8))
            return 0;
        return 1;
    }
    return 0;
}

int receta_setId(eReceta* this,int id)
{
    int flag = 0;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        flag=1;
    }
    return flag;
}

int receta_getId(eReceta* this,int* id)
{
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        return 1;
    }
    return 0;
}

int receta_setNombre(eReceta* this,char* nombre)
{
    if(this != NULL)
    {
        strncpy(this->nombre, nombre, sizeof(this->nombre));
        return 1;
    }
    return 0;
}

int receta_getNombre(eReceta* this,char* nombre)
{
    if (this != NULL)
    {
        strncpy(nombre, this->nombre, sizeof(this->nombre));
        return 1;
    }
    return 0;
}

int receta_setIngredientes(eReceta* this,char* ingredientes)
{
    if(this != NULL)
    {
        strncpy(this->ingredientes, ingredientes, sizeof(this->ingredientes));
        return 1;
    }
    return 0;
}

int receta_getIngredientes(eReceta* this,char* ingredientes)
{
    if (this != NULL)
    {
        strncpy(ingredientes, this->ingredientes, sizeof(this->ingredientes));
        return 1;
    }
    return 0;
}

int receta_setCalorias (eReceta* this,float calorias)
{
    int flag=0;
    if(this != NULL && calorias >= 0)
    {
        this->calorias = calorias;
        flag=1;
    }
    return flag;
}

int receta_getCalorias(eReceta* this,float* calorias)
{
    if (this != NULL && calorias != NULL)
    {
        *calorias = this->calorias;
        return 1;
    }
    return 0;
}

int receta_setGrasa (eReceta* this,float grasa)
{
    int flag=0;
    if(this != NULL && grasa >= 0)
    {
        this->grasa = grasa;
        flag=1;
    }
    return flag;
}

int receta_getGrasa(eReceta* this,float* grasa)
{
    if (this != NULL && grasa != NULL)
    {
        *grasa = this->grasa;
        return 1;
    }
    return 0;
}

int receta_setSodio (eReceta* this,float sodio)
{
    int flag=0;
    if(this != NULL && sodio >= 0)
    {
        this->sodio = sodio;
        flag=1;
    }
    return flag;
}

int receta_getSodio(eReceta* this,float* sodio)
{
    if (this != NULL && sodio != NULL)
    {
        *sodio = this->sodio;
        return 1;
    }
    return 0;
}

int receta_setCarbohidratos (eReceta* this,float carbohidratos)
{
    int flag=0;
    if(this != NULL && carbohidratos >= 0)
    {
        this->carbohidratos = carbohidratos;
        flag=1;
    }
    return flag;
}

int receta_getCarbohidratos(eReceta* this,float* carbohidratos)
{
    if (this != NULL && carbohidratos != NULL)
    {
        *carbohidratos = this->carbohidratos;
        return 1;
    }
    return 0;
}

int receta_setProteinas (eReceta* this,float proteinas)
{
    int flag=0;
    if(this != NULL && proteinas >= 0)
    {
        this->proteinas = proteinas;
        flag=1;
    }
    return flag;
}

int receta_getProteinas(eReceta* this,float* proteinas)
{
    if (this != NULL && proteinas != NULL)
    {
        *proteinas = this->proteinas;
        return 1;
    }
    return 0;
}

int receta_show(eReceta* this)
{
    int var_1;
    char var_2[50], var_3[50];
    float var_4, var_5, var_6, var_7, var_8;

    if (this != NULL && receta_getters(this, &var_1, var_2, var_3, &var_4, &var_5, &var_6, &var_7, &var_8))
    {
        printf(" %3d | %8s | %8s | %.1f | %.1f | %.1f | %.1f | %.1f \n", var_1, var_2, var_3, var_4, var_5, var_6, var_7, var_8);
        return 1;
    }
    return 0;
}

/** \brief sort envios in list by their id
 *
 * \param void* punteroA
 * \param void* punteroB
 * \return int (-1) si punteroA menor a punteroB
               (0) si punteroA igual a punteroB
               (1) si punteroA manor a punteroB
               (-2) If NULL pointer
 *
 */

int receta_sortById(void* punteroA, void* punteroB)
{

    if(punteroA != NULL && punteroB != NULL)
    {
        int id_A, id_B;

        receta_getId(punteroA, &id_A);
        receta_getId(punteroB, &id_B);

        if((id_A) > (id_B)) //Si id de A en menor que id de B cambio al bandera flag a 1
            return 1;
        else if((id_A) == (id_B)) //Si id de A igual que id de B dejo la bandera igual
            return 0;
        else
            return -1;
    }
    return -2;
}
