#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cars.h"
#include "colour.h"
#include "marca.h"
#include "utn.h"

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (car_status) Empty in all
 * position of the array
 * \param eCar car[] to array of employees
 * \param len int Array length
 * \return int (1) if Ok
 *
 */
int car_init(eCar car[], int len)
{
        for(int i=0; i<len; i++)
            car[i].status = EMPTY;
    return 1;
}

/** \brief add in a existing list of cars the values received as parameters
 * in the first empty position
 * \param eCar car[]
 * \param len int
 * \param id int
 * \param patente[] char
 * \param idMarca int
 * \param idColour int
 * \param idModelo int
 * \return void
 */

void car_add(eCar car[], int len, int id, char patente[],int idMarca, int idColour,int modelo, int idClient)
{
    int index = car_findEmptyPlace(car, len);
    strcpy(car[index].patente, patente);
    car[index].idMarca = idMarca;
    car[index].idColor = idColour;
    car[index].modelo = modelo;
    car[index].status = BUSY;
    car[index].id = id;
    car[index].idClient = idClient;
}

/** \brief find a Car by Id en returns the index position in array.
 *
 * \param eCar car[]
 * \param len int
 * \param id int
 * \return Return car index position or (-1) if [car not found]
 *
 */

int findCarById(eCar car[], int len, int id)
{
    int flag = -1;
    for (int i=0; i<len; i++)
    {
        if (car[i].id  == id && car[i].status == BUSY)
        {
            flag = i;
            break;
        }
    }
    return flag;
}

/** \brief find a Car by Patente en returns the index position in array.
 *
 * \param eCar car[]
 * \param len int
 * \param id int
 * \return Return car index position or (-1) if [car not found]
 *
 */

int findCarByPatente(eCar car[], int len, char patente[])
{
    int flag = -1;
    for (int i=0; i<len; i++)
    {
        if (strcmp(car[i].patente, patente) == 0 && car[i].status == BUSY)
        {
            flag = car[i].id;
            break;
        }
    }
    return flag;
}


/** \brief find a  deleted Car by Id en returns the index position in array.
 *
 * \param eCar car[]
 * \param len int
 * \param id int
 * \return Return car index position or (-1) if [car not found]
 *
 */

int findDeletedCarById(eCar car[], int len, int id)
{
    int flag = -1;
    for (int i=0; i<len; i++)
    {
        if (car[i].id  == id && car[i].status == DELETED)
        {
            flag = i;
            break;
        }
    }
    return flag;
}

/** \brief find a Deleted Car by Patente en returns the index position in array.
 *
 * \param eCar car[]
 * \param len int
 * \param id int
 * \return Return car index position or (-1) if [car not found]
 *
 */

int findDeletedCarByPatente(eCar car[], int len, char patente[])
{
    int flag = -1;
    for (int i=0; i<len; i++)
    {
        if (strcmp(car[i].patente, patente) == 0 && car[i].status == DELETED)
        {
            flag = car[i].id;
            break;
        }
    }
    return flag;
}

/** \brief Remove a Car by Id (put isEmpty Flag in 1)
 *
 * \param eCar car[]
 * \param len int
 * \param id int
 * \return void
 *
 */

void car_delete(eCar car[], int len, int id)
{
    for (int i=0; i<len; i++)
    {
        if (car[i].id == id)
            car[i].status = DELETED;
    }
}

/** \brief print the content of cars array
 *
 * \param eCar car[]
 * \param car_len int
 * \param eMarca marca[]
 * \param marca_len int
 * \param eColour colour[]
 * \param colour_len int
 * \return void
 *
 */

void printCars(eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len)
{
    printf(">> Lista de Autos\n\n");
    printf("ID |  PATENTE  |    MARCA   |  COLOR | MODELO  |   CLIENTE  \n\n");

    for(int i=0; i<car_len; i++)
    {
        if(car[i].status == BUSY)
            printCar(car[i], marca, marca_len, colour, colour_len, client, client_len);
    }
    printf("\n");
}

/** \brief print the content of a car
 *
 * \param eCar x
 * \param eMarca y
 * \param eColour z
 * \return void
 *
 */

void printCar (eCar car, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len)
{
    int posMarca  = findMarcaById(marca, marca_len, car.idMarca);
    int posColour = findColourById(colour, colour_len, car.idColor);
    int posClient = findClientById(client, client_len, car.idClient);

    printf("%2d | %8s  | %10s | %6s |  %d   |  %s  \n", car.id, car.patente, marca[posMarca].description, colour[posColour].name, car.modelo, client[posClient].name);
}

/** \brief search a determinate car by id in the list of games
 *
 * \param eCar car[]
 * \param car_len int
 * \param eMarca marca[]
 * \param marca_len int
 * \param eColour colour[]
 * \param colour_len int
 * \return position of array Cars or (-1) if could not find
 *
 */

int car_getIdInList(eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len)
{
    char patente[8];

    printCars(car, car_len, marca, marca_len, colour, colour_len, client, client_len);
    getString("Patente: ", patente);
    int flag = findCarByPatente(car, car_len, patente);

    return flag;
}

/** \brief search for an empty position
 *
 * \param eCar car[]
 * \param len int
 * \return int (position of array) or (-1) if there is no place
 *
 */

int car_findEmptyPlace(eCar car[], int len)
{
    int flag = -1;
    for(int i=0; i<len; i++)
    {
        if(car[i].status == EMPTY)
        {
            flag = i;
            break;
        }
    }
    return flag;
}

/** \brief search an empty id
 *
 * \param eCar car[]
 * \param len int
 * \return (pos of array cars) or (-1) if there is no next id
 *
 */

int car_findNextId(eCar car[], int len)
{
    int flag = -1;
    for(int i=0; i<len; i++)
    {
        if(car[i].status == EMPTY)
        {
            flag = i+1;
            break;
        }
    }
    return flag;
}

/** \brief add in a existing list of games the values received as parameters
 * in the first empty position
 * \param eCar car[]
 * \param car_len int
 * \param eMarca marca[]
 * \param marca_len int
 * \param eColour colour[]
 * \param colour_len int
 * \return int (1) if Ok - (0) invalid option
 */

int car_modificate(eCar car[], int car_len, int id, eColour colour[], int colour_len, eMarca marca[], int marca_len)
{
    int flag, status=0, index;
    int modelo;
    int idColour;

    index = findCarById(car, car_len, id);
    switch (editCarMain())
    {
    case 1:
        printColours(colour, colour_len);
        flag = getValidInt("Color: ", "Color invalido, Reintente: ", &idColour,5000,5000+colour_len,3);
        if (!flag && confirmation())
        {
            car[index].idColor = idColour;
            status=1;
        }
        break;
    case 2:
        flag = getValidInt("Modelo: ", "Modelo invalido, Reintente: ", &modelo, 1950, 2019, 3);
        if (!flag && confirmation())
        {
            car[index].modelo = modelo;
            status=1;
        }
        break;
    default:
        printf("Opcion Ingresada Invalida");
        break;
    }
    return status;
}

/** \brief create cars to see if program run OK
 *
 * \param eCar y[]
 * \return void
 *
 */

void car_hardcore(eCar y[])
{
    eCar x[]=
    {
        {1,  "AAA201", 1000, 5001, 1995, 1, 1},
        {2,  "DFR234", 1003, 5000, 2002, 1, 2},
        {3,  "GFT564", 1002, 5003, 2007, 1, 3},
        {4,  "ACD321", 1002, 5003, 1995, 1, 4},
        {5,  "HTD656", 1004, 5002, 2008, 1, 5},
        {6,  "QSZ435", 1003, 5001, 1994, 1, 6},
        {7,  "LGX201", 1001, 5000, 2012, 1, 7},
        {8,  "SUZ324", 1001, 5002, 1991, 1, 8},
        {9,  "HCU762", 1000, 5003, 2008, 1, 9},
        {10, "DYC735", 1003, 5001, 2002, 1,10},
        {11, "JJK879", 1003, 5001, 2010, 1,11},
        {12, "FED322", 1004, 5002, 2006, 1,12},
        {13, "GHV332", 1001, 5003, 2007, 1,13},
        {14, "BDE221", 1000, 5004, 1996, 1,14},
        {15, "OPD332", 1000, 5001, 2014, 1,15},
        {16, "PPD121", 1002, 5001, 2015, 1,16},
        {17, "IIT230", 1001, 5000, 2009, 1,17},
        {18, "KOD220", 1004, 5002, 2011, 1,18},
        {19, "QSZ305", 1004, 5002, 1993, 1,19},
        {20, "SSD128", 1002, 5003, 1992, 1,20},
        {21, "SSD240", 1003, 5004, 1992, 1,21},
        {22, "EDF213", 1001, 5000, 2001, 1,22},
    };

    for(int i=0; i<22; i++)
        y[i] = x[i];
}

/** \brief print all option of Modification able to choose
 *
 * \param  void
 * \return int option choosed
 */

int editCarMain()
{
    printf("\n");
    printf(">> Menu de Modificaciones\n");
    printf("\n1_ COLOR");
    printf("\n2_ MODELO");
    printf("\n3_ Salir");

    fflush(stdin);
    int opt = getInt("\n\nIngrese opcion: ");
    return opt;
}


