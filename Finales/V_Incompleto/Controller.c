#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "clientes.h"
#include "abonos.h"
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
    printf("\n1_ Cargar desde el archivo(CVS).");
    printf("\n2_ Listar Clientes");
    printf("\n3_ Cargar Abonos");
    printf("\n4_ Listar Abonos");
    printf("\n5_ Guardar Archivo en Texto y Binario.");
    printf("\n10_ Salir");

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

/** \brief Carga los datos desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int retorna la funcion (1 - TodoOK // 0 - Error)
 *
 */

int controller_loadFromBinary(char* path, LinkedList* pArrayList)
{
    int flag = 0;
    FILE* pArchivo; //Variable puntero al archivo

    system("cls");

    printf(">> Cargar Modo Binario\n\n");

    if((pArchivo = fopen(path, "rb")) != NULL)
    {
        printf("\tDatos Cargados\n\n");
        parser_FromBinary(pArchivo, pArrayList); //Funcion parser modo bin
        flag = 1;
    }
    else  //Si retorna NULL no encontro el archivo, por lo tanto lo creo e informo que no se encontro y se creo uno nuevo
    {
        if((pArchivo = fopen(path, "wb")) != NULL)
            printf("\tNo se encontro el archivo. Se creo uno nuevo con el nombre %s\n\n", path);
    }
    return flag;
}

int controller_List(LinkedList* pArrayList)
{
    system("cls");
    printf(">> Datos\n\n");
    printf("  ID  |  NOMBRE  |  SEXO  | NUMERO TELEFONICO | IMPORTE \n\n");

    for(int i=0; i<ll_len(pArrayList); i++) //Recorro el array de datos
    {
        eCliente* this = (eCliente*)ll_get(pArrayList, i); //Le asigno al puntero eCliente "this" lo que retorna "ll_get()"
        cliente_show(this); //Imprimo los datos
    }
    printf("\n\n");
    return 1;
}

int controller_saveAsText(char* path, LinkedList* pArrayList)
{
    int var_1;
    char var_2[50], var_3[50];
    float var_4, var_5;

    FILE* text = fopen(path, "w");

    if(text != NULL && pArrayList != NULL && confirmation())
    {
        fprintf(text,"id,nombre,sexo,numeroTelefonico,importe\n");
        for(int i=0; i<ll_len(pArrayList); i++)
        {
            eCliente* this = (eCliente*) ll_get(pArrayList, i);
            if (cliente_getters(this, &var_1, var_2, var_3, &var_4, &var_5))
                fprintf(text, "%d,%s,%s,%.0f,%.1f\n", var_1, var_2, var_3, var_4, var_5);
        }
        return 1;
        printf("Datos Guardados con exito.\n\n");
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
            eCliente* this = (eCliente*)ll_get(pArrayList,i);
            datosLeidos = fwrite(this, sizeof(eCliente), 1, pArchivo);
            flag = 1;
            if(datosLeidos != 1)
                printf("\nError al escribir los datos en el archivo.\n\n");
        }
        printf("Datos Guardados con exito.\n\n");
    }

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

int controller_addCliente(LinkedList* pArraylist)
{
    char var_1[50] = "0", var_2[50], var_3[50], var_4[50], var_5[50];

    if(pArraylist != NULL)
    {
        eCliente* this = cliente_new();
        if (this != NULL)
        {
            getString("Ingrese nombre: ", var_2);
            getString("Ingrese sexo: ", var_3);
            getString("Ingrese numero telefonico: ", var_4);
            getString("Ingrese importe: ", var_5);

            this = cliente_setters(var_1, var_2, var_3, var_4, var_5);
            ll_add(pArraylist, this);

            cliente_setId(this, cliente_freeID(pArraylist));
            printf("\n\tDato dado de Alta\n\n");
            return 1;
        }
    }
    printf("\tError en el Ingreso de Dato\n\n");
    return 0;
}

/** \brief Alta de entidades
 *
 * \param path char*
 * \param pArrayListEntity LinkedList*
 * \return int
 *
 */

LinkedList* controller_addAbono(LinkedList* pArrayList)
{

    LinkedList* abonoList = ll_newLinkedList();
    eAbono* abono;

    LinkedList* clientesLL;
    LinkedList* conteoLL;

    eCliente* cliente;
    eCliente* clienteConteo;

    int contador = 0;
    int idAutoincremental = 0;
    int tipo;
    int idCliente = 0;
    int importeFinal;
    char idStr[20], tipoStr[20] = "0", idClienteStr[20], importeFinalStr[20];

    ll_sort(pArrayList, cliente_sortById,1);
    if(pArrayList != NULL)      //se fija que el valor pasano no sea NULL
    {
        if(abonoList != NULL) //se fija que se pudo reservar memoria
        {
            for(int i = 0; i<ll_len(pArrayList); i++)
            {
                contador = 1;
                clientesLL = ll_get(pArrayList, i);
                cliente = (eCliente*) clientesLL;
                if(cliente->id > idCliente)  //para no volver a analaizar uno que ya se analizo
                {
                    idCliente = cliente->id;
                    abono = abono_new();
                    importeFinal = cliente->importe;
                    for(int j = i+1; j<(ll_len(pArrayList)); j++)
                    {
                        conteoLL = ll_get(pArrayList, j);
                        clienteConteo = (eCliente*) conteoLL;
                        if(clienteConteo->id == idCliente)
                        {
                            contador++;
                            importeFinal = importeFinal + (clienteConteo->importe);
                        }
                    }
                    if(contador < 2)
                    {
                        tipo = 0;
                    }
                    else if(contador < 5)
                    {
                        tipo = 1;
                        importeFinal = importeFinal * 1.1;
                    }
                    else
                    {
                        tipo = 2;
                        importeFinal = importeFinal * 1.2;
                    }

                    idAutoincremental++;

                    sprintf(idStr, "%d", idAutoincremental);
                    sprintf(tipoStr, "%d", tipo);
                    sprintf(idClienteStr, "%d", idCliente);
                    sprintf(importeFinalStr, "%f", (float)importeFinal);

                    abono = abono_setters(idStr, tipoStr, idClienteStr, importeFinalStr);
                    if (abono != NULL)
                    ll_add(abonoList, abono);
                    else{
                        printf("Problema");
                        system("pause");
                    }

                }
            }
        }
        else
        {
            printf("No se ha podido reservar memoria.\n");  //aviso que no se puede reservar memoria para la nueva lista
        }
    }
    return abonoList;
}

int controller_ListComplete(LinkedList* listClientes, LinkedList* listAbonos)
{
    system("cls");
    printf(">> Datos\n\n");
    printf("  ID  |  NOMBRE  |  SEXO  | NUMERO TELEFONICO | IMPORTE F  |  ID A |  TIPO \n\n");

    if (listClientes != NULL && listAbonos != NULL)
    {
        for(int i=0; i<ll_len(listAbonos); i++) //Recorro el array de datos
        {
            eAbono* this = (eAbono*)ll_get(listAbonos, i); //Le asigno al puntero eAbono "this" lo que retorna "ll_get()"
            abono_show(this, listClientes); //Imprimo los datos
        }
        printf("\n\n");
        return 1;
    }
    return 0;
}




