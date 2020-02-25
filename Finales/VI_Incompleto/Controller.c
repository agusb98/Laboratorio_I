#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "ingredientes.h"
#include "recetas.h"
#include "utn.h"

/** \brief Menu de opciones
 *
 * \return int La opcion elegida por el usuario
 *
 */
int controller_principalMain()
{
    system("cls");

    printf(">> Menu de Opciones\n");
    printf("\n0_ Cargar desde el archivo(CVS).");
    printf("\n1_ Alta Ingrediente");
    printf("\n2_ Modificar");
    printf("\n3_ Baja");
    printf("\n4_ Listar");
    printf("\n5_ Alta Receta");
    printf("\n6_ Informacion");
    printf("\n10_ Salir");

    fflush(stdin);
    return getInt("\n\nIngrese opcion: ");
}

/** \brief Menu de opciones
 *
 * \return int La opcion elegida por el usuario
 *
 */
int controller_editMain()
{
    system("cls");

    printf(">> Menu de Modificaciones\n");
    printf("\n1_ Nombre");
    printf("\n2_ Calorias");
    printf("\n3_ Grasas");
    printf("\n4_ Sodio");
    printf("\n5_ Carbohidratos");
    printf("\n6_ Proteinas");
    printf("\n7_ Salir");

    fflush(stdin);
    return getInt("\n\nIngrese opcion: ");
}

/** \brief Menu de opciones a filtro por escoger
 *
 * \return int La opcion elegida por el usuario
 *
 */

int controller_filterMain()
{
    system("cls");

    printf(">> Menu de Filtros\n");
    printf("\n1_ Autos");
    printf("\n2_ Motos");
    printf("\n3_ Volver al Menu Principal");

    fflush(stdin);
    return getInt("\n\nIngrese opcion: ");
}

/** \brief Carga los datos desde el archivo (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int retorna la funcion (1 - TodoOK // 0 - Error)
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayList)
{
    FILE* pArchivo = fopen(path, "r"); //Variable puntero al archivo
    system("cls");
    int flag = 0;

    printf(">> Cargar Modo Texto\n\n");
    if(pArchivo != NULL && pArrayList != NULL)   //Verifico si la lectura del archivo, si no retorna NULL accedo al parse
    {
        flag = parser_FromText(pArchivo, pArrayList);
        printf("\tDatos Cargados\n\n");
    }
    else
        printf("\nArchivo No Encontrado\n\n");
    return flag;
}

int controller_List(LinkedList* pArrayList)
{
    system("cls");
    printf(">> Datos\n\n");
    printf("  ID  |  NOMBRE  |  CALORIAS  | GRASAS | SODIO | CARBOHIDRATOS | PROTEINAS \n\n");

    for(int i=0; i<ll_len(pArrayList); i++) //Recorro el array de datos
    {
        eIngrediente* this = (eIngrediente*)ll_get(pArrayList, i); //Le asigno al puntero eIngrediente "this" lo que retorna "ll_get()"
        ingrediente_show(this); //Imprimo los datos
    }
    printf("\n\n");
    return 1;
}

int controller_saveAsText(char* path, LinkedList* pArrayList)
{
    char var_2[50];
    int var_1;
    float var_3, var_4, var_5, var_6, var_7;
    FILE* text = fopen(path, "w");

    if(text != NULL && pArrayList != NULL && confirmation())
    {
        fprintf(text,"id,nombre,calorias,grasa,sodio,carbohidratos,proteinas\n");
        for(int i=0; i<ll_len(pArrayList); i++)
        {
            eIngrediente* this = (eIngrediente*) ll_get(pArrayList, i);
            if (ingrediente_getters(this, &var_1, var_2, &var_3, &var_4, &var_5, &var_6, &var_7))
                fprintf(text, "%d,%s,%.1f,%.1f,%.1f,%.1f,%.1f\n", var_1, var_2, var_3, var_4, var_5, var_6, var_7);
        }
        return 1;
    }
    fclose(text);
    return 0;
}

/** \brief Guarda los datos en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayList)
{
    FILE* pArchivo = fopen(path, "wb");; //Puntero al archivo, abro el archivo en modo escritura binaria
    int flag = 0, datosLeidos;

    if(pArchivo != NULL && pArrayList != NULL) //Verifico que la apertura del archivo y el array de eEnvios no sea NULL, si no lo es ingreso
    {
        rewind(pArchivo); //Voy al inicio del archivo
        for(int i=0; i<ll_len(pArrayList); i++)
        {
            eIngrediente* this = (eIngrediente*)ll_get(pArrayList,i);
            datosLeidos = fwrite(this, sizeof(eIngrediente), 1, pArchivo);
            flag = 1;
            if(datosLeidos != 1)
                printf("\nError al escribir los datos en el archivo.\n\n");
        }
        printf("\nDatos Guardados Con Exito\n\n");
    }

    else  //Si no pudo acceder al archivo lo informo
        printf("\nNo se pudo acceder al archivo.\n");

    fclose(pArchivo); //Cierro el archivo
    return flag;
}

/** \brief Alta de entidades
 *
 * \param path char*
 * \param pArrayListEntity LinkedList*
 * \return int
 *
 */

int controller_addIngrediente(LinkedList* pArraylist)
{
    char var_1[50] = "0", var_2[50], var_3[50], var_4[50], var_5[50], var_6[50], var_7[50];
    system("cls");
    printf(">> Nueva Receta\n\n");

    if(pArraylist != NULL)
    {
        eIngrediente* this = ingrediente_new();
        if (this != NULL)
        {
            getString("Ingrese nombre: ", var_2);
            getString("Ingrese calorias: ", var_3);
            getString("Ingrese grasas: ", var_4);
            getString("Ingrese sodio: ", var_5);
            getString("Ingrese carbohidratos: ", var_6);
            getString("Ingrese proteinas: ", var_7);

            this = ingrediente_setters(var_1, var_2, var_3, var_4, var_5, var_6, var_7);
            ll_add(pArraylist, this);
            ingrediente_setId(this, ll_indexOf(pArraylist, this) + 1);
            printf("\n\tDato dado de Alta\n\n");
            return 1;
        }
    }
    printf("\tError en el Ingreso de Dato\n\n");
    return 0;
}

/** \brief Modificacion de entidades
 *
 * \param path char*
 * \param pArrayListEntity LinkedList*
 * \return int
 *
 */

int controller_editIngrediente(LinkedList* pArraylist)
{
    char var[50];
    if(pArraylist != NULL)
    {
        eIngrediente* this = ingrediente_findByID(pArraylist);
        if (this != NULL)
        {
            switch(controller_editMain())
            {
            case 1:
            {
                getString("Ingrese Dato : ", var);
                if (confirmation())
                    ingrediente_setNombre(this, var);
            }
            break;
            case 2:
            {
                getString("Ingrese Dato : ", var);
                if (confirmation())
                    ingrediente_setCalorias(this, atof (var));
            }
            break;
            case 3:
            {
                getString("Ingrese Dato : ", var);
                if (confirmation())
                    ingrediente_setGrasa(this, atof (var));
            }
            break;
            case 4:
            {
                getString("Ingrese Dato : ", var);
                if (confirmation())
                    ingrediente_setSodio(this, atof (var));
            }
            break;
            case 5:
            {
                getString("Ingrese Dato : ", var);
                if (confirmation())
                    ingrediente_setCarbohidratos(this, atof (var));
            }
            break;
            case 6:
            {
                getString("Ingrese Dato : ", var);
                if (confirmation())
                    ingrediente_setProteinas(this, atof (var));
            }
            break;
            default:
                break;
            }
            return 1;
        }
        else
            printf("\nID no encontrado\n");
    }
    return 0;
}

/** \brief eliminacion de entidades
 *
 * \param path char*
 * \param pArrayListEntity LinkedList*
 * \return int
 *
 */

int controller_removeIngrediente(LinkedList* pArraylist)
{
    if(pArraylist != NULL)
    {
        eIngrediente* this = ingrediente_findByID(pArraylist);
        if (this != NULL && confirmation())
        {
            if (ll_remove(pArraylist, ll_indexOf(pArraylist, this)) != -1)
                printf("\tEliminado con Exito\n");
            else
                printf("\tError al Modificar Dato\n");
        }
        return 1;
    }
    return 0;
}

/** \brief Alta de entidades
 *
 * \param path char*
 * \param pArrayListEntity LinkedList*
 * \return int
 *
 */

int controller_addReceta(LinkedList* pArrayList, LinkedList* pArrayList_1)
{
    char var_1[50] = "0", var_2[50], var_3[50], var_4[50], var_5[50], var_6[50], var_7[50], var_8[50];
    system("cls");
    printf(">> Nueva Receta\n\n");

    if(pArrayList != NULL && pArrayList_1 != NULL)
    {
        eReceta* this = receta_new();
        if (this != NULL)
        {
            getString("Ingrese nombre: ", var_2);
            for (int i=0; i<ll_len(pArrayList); i++)
            {
                eIngrediente* aux = ingrediente_findByID(pArrayList_1);
                if (aux != NULL)
                {
                    ingrediente_getNombre(aux, var_3);
                    getString("Ingrese calorias: ", var_4);
                    getString("Ingrese grasas: ", var_5);
                    getString("Ingrese sodio: ", var_6);
                    getString("Ingrese carbohidratos: ", var_7);
                    getString("Ingrese proteinas: ", var_8);
                }
                    this = receta_setters(var_1, var_2, var_3, var_4, var_5, var_6, var_7, var_8);
            }
            ll_add(pArrayList, this);
            receta_setId(this, ll_indexOf(pArrayList, this) + 1);
            printf("\n\tDato dado de Alta\n\n");
            return 1;
        }
    }
    printf("\tError en el Ingreso de Dato\n\n");
    return 0;
}

int controller_loadFromText_Recetas(char* path, LinkedList* pArrayList)
{
    FILE* pArchivo = fopen(path, "r"); //Variable puntero al archivo
    system("cls");
    int flag = 0;

    printf(">> Cargar Modo Texto\n\n");
    if(pArchivo != NULL && pArrayList != NULL)   //Verifico si la lectura del archivo, si no retorna NULL accedo al parse
        flag = parser_FromText_Recetas(pArchivo, pArrayList);
        if (!flag)
            printf("\n\tError en el Ingreso de Recetas\n\n");

    return flag;
}


int controller_ListReceta(LinkedList* pArrayList)
{
    system("cls");
    printf(">> Datos\n\n");
    printf("  ID  |  NOMBRE  |  INGREDIENTES  |  CALORIAS  | GRASAS | SODIO | CARBOHIDRATOS | PROTEINAS \n\n");

    for(int i=0; i<ll_len(pArrayList); i++) //Recorro el array de datos
    {
        eReceta* this = (eReceta*)ll_get(pArrayList, i); //Le asigno al puntero eReceta "this" lo que retorna "ll_get()"
        receta_show(this); //Imprimo los datos
    }
    printf("\n\n");
    return 1;
}




