#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "ingredientes.h"
#include "utn.h"

eIngrediente* ingrediente_new()
{
    eIngrediente* this = malloc(sizeof(eIngrediente)); //Creo un nuevo dominios con memodia dinamica "malloc"
    if(this == NULL)
    {
        printf("Almacenamiento lleno.\n");
        exit(EXIT_FAILURE); //De ser NULL salgo
    }
    else //De lo contrario parseo a 0 y cadena vacia las variables
    {
        this->id = 0;
        strcpy(this->nombre, "");
        this->calorias = 0;
        this->grasa = 0;
        this->sodio = 0;
        this->carbohidratos = 0;
        this->proteinas = 0;

    }
    return this; //Retorno el puntero a la estructura creada
}

eIngrediente* ingrediente_setters(char* var_1, char* var_2, char* var_3, char* var_4, char* var_5, char* var_6, char* var_7)
{
    eIngrediente* this = ingrediente_new();
    if (this != NULL)
    {
        if (!ingrediente_setId(this,atoi(var_1)))
            this = NULL;

        if( !ingrediente_setNombre(this,var_2))
            this = NULL;

        if( !ingrediente_setCalorias(this,atof(var_3)) )
            this = NULL;

        if( !ingrediente_setGrasa(this,atof(var_4)) )
            this = NULL;

        if( !ingrediente_setSodio(this,atof(var_5)) )
            this = NULL;

        if( !ingrediente_setCarbohidratos(this,atof(var_6)) )
            this = NULL;

        if( !ingrediente_setProteinas(this,atof(var_7)) )
            this = NULL;

        if(this == NULL)
        {
            printf("\nError al cargar datos, revise la lista.\n");
            free(this);
        }
    }
    return this;
}

int ingrediente_getters(eIngrediente* this, int* var_1, char* var_2, float* var_3, float* var_4, float* var_5, float* var_6, float* var_7)
{
    if (this != NULL)
    {
        if (!ingrediente_getId(this, var_1))
            return 0;
        if (!ingrediente_getNombre(this, var_2))
            return 0;
        if (!ingrediente_getCalorias(this, var_3))
            return 0;
        if (!ingrediente_getGrasa(this, var_4))
            return 0;
        if (!ingrediente_getSodio(this, var_5))
            return 0;
        if (!ingrediente_getCarbohidratos(this, var_6))
            return 0;
        if (!ingrediente_getProteinas(this, var_7))
            return 0;
        return 1;
    }
    return 0;
}

int ingrediente_setId(eIngrediente* this,int id)
{
    int flag = 0;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        flag=1;
    }
    return flag;
}

int ingrediente_getId(eIngrediente* this,int* id)
{
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        return 1;
    }
    return 0;
}

int ingrediente_setNombre(eIngrediente* this,char* nombre)
{
    if(this != NULL)
    {
        strncpy(this->nombre, nombre, sizeof(this->nombre));
        return 1;
    }
    return 0;
}

int ingrediente_getNombre(eIngrediente* this,char* nombre)
{
    if (this != NULL)
    {
        strncpy(nombre, this->nombre, sizeof(this->nombre));
        return 1;
    }
    return 0;
}

int ingrediente_setCalorias (eIngrediente* this,float calorias)
{
    int flag=0;
    if(this != NULL && calorias >= 0)
    {
        this->calorias = calorias;
        flag=1;
    }
    return flag;
}

int ingrediente_getCalorias(eIngrediente* this,float* calorias)
{
    if (this != NULL && calorias != NULL)
    {
        *calorias = this->calorias;
        return 1;
    }
    return 0;
}

int ingrediente_setGrasa (eIngrediente* this,float grasa)
{
    int flag=0;
    if(this != NULL && grasa >= 0)
    {
        this->grasa = grasa;
        flag=1;
    }
    return flag;
}

int ingrediente_getGrasa(eIngrediente* this,float* grasa)
{
    if (this != NULL && grasa != NULL)
    {
        *grasa = this->grasa;
        return 1;
    }
    return 0;
}

int ingrediente_setSodio (eIngrediente* this,float sodio)
{
    int flag=0;
    if(this != NULL && sodio >= 0)
    {
        this->sodio = sodio;
        flag=1;
    }
    return flag;
}

int ingrediente_getSodio(eIngrediente* this,float* sodio)
{
    if (this != NULL && sodio != NULL)
    {
        *sodio = this->sodio;
        return 1;
    }
    return 0;
}

int ingrediente_setCarbohidratos (eIngrediente* this,float carbohidratos)
{
    int flag=0;
    if(this != NULL && carbohidratos >= 0)
    {
        this->carbohidratos = carbohidratos;
        flag=1;
    }
    return flag;
}

int ingrediente_getCarbohidratos(eIngrediente* this,float* carbohidratos)
{
    if (this != NULL && carbohidratos != NULL)
    {
        *carbohidratos = this->carbohidratos;
        return 1;
    }
    return 0;
}

int ingrediente_setProteinas (eIngrediente* this,float proteinas)
{
    int flag=0;
    if(this != NULL && proteinas >= 0)
    {
        this->proteinas = proteinas;
        flag=1;
    }
    return flag;
}

int ingrediente_getProteinas(eIngrediente* this,float* proteinas)
{
    if (this != NULL && proteinas != NULL)
    {
        *proteinas = this->proteinas;
        return 1;
    }
    return 0;
}

int ingrediente_show(eIngrediente* this)
{
    int var_1;
    char var_2[50];
    float var_3, var_4, var_5, var_6, var_7;

    if (this != NULL && ingrediente_getters(this, &var_1, var_2, &var_3, &var_4, &var_5, &var_6, &var_7))
    {
        printf(" %3d | %8s | %.1f | %.1f | %.1f | %.1f | %.1f \n", var_1, var_2, var_3, var_4, var_5, var_6, var_7);
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

int ingredientes_sortById(void* punteroA, void* punteroB)
{

    if(punteroA != NULL && punteroB != NULL)
    {
        int id_A, id_B;

        ingrediente_getId(punteroA, &id_A);
        ingrediente_getId(punteroB, &id_B);

        if((id_A) > (id_B)) //Si id de A en menor que id de B cambio al bandera flag a 1
            return 1;
        else if((id_A) == (id_B)) //Si id de A igual que id de B dejo la bandera igual
            return 0;
        else
            return -1;
    }
    return -2;
}

/** \brief sort in list by their name
 *
 * \param void* punteroA
 * \param void* punteroB
 * \return int (1) if OK - (0) If NULL pointer
 *
 */
int ingrediente_sortByNombre(void* punteroA, void* punteroB)
{
    int flag = 0;
    if(punteroA != NULL && punteroB != NULL)
    {
        char aux_A[50];
        char aux_B[50];

        ingrediente_getNombre(punteroA, aux_A);
        ingrediente_getNombre(punteroB, aux_B);
        flag = strcmp(aux_A, aux_B);
    }
    return flag;
}

eIngrediente* ingrediente_findByID (void* this)
{
    int id, auxID;
    if(this != NULL)
    {
        for(int i=0; i<ll_len(this); i++) //Recorro el array de datos
        {
            int id;
            char nombre[50];
            eIngrediente* aux = (eIngrediente*)ll_get(this, i); //Le asigno al puntero eIngrediente "aux" lo que retorna "ll_get()"

            ingrediente_getId(aux, &id);
            ingrediente_getNombre(aux, nombre);
            printf(" %3d | %8s \n", id, nombre);
        }
        id = getInt("ID: ");
        for(int i=0; i<ll_len(this); i++)
        {
            eIngrediente* aux = ll_get(this, i);
            ingrediente_getId(aux, &auxID);
            if (id == auxID)
                return aux;
        }
    }
    return NULL;
}


