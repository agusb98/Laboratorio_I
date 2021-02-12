#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cars.h"
#include "servis.h"
#include "job.h"

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (status) Empty in all
 * position of the array
 * \param eJob job[]
 * \param len int Array length
 * \return int (1) if Ok - (0) if not
 *
 */

int job_init(eJob job[], int len)
{
    int flag= 0;
    for(int i=0; i<len; i++)
    {
        job[i].status = EMPTY;
        flag= 1;
    }
    return flag;
}

/** \brief add in a existing list of jobs the values received as parameters
 * in the first empty position
 * \param eJob[] job
 * \param job_len int
 * \param id_job int
 * \param id_car int
 * \param id_servis int
 * \param day int
 * \param month int
 * \param year int
 * \return void
 */

void job_add(eJob job[], int job_len, int id_job, int id_car, int id_servis, int day, int month, int year, int id_client)
{
    int index = job_findEmptyPlace(job, job_len);
    job[index].id_job = id_job;
    job[index].id_servis = id_servis;
    job[index].id_car = id_car;
    job[index].fecha.day = day;
    job[index].fecha.month = month;
    job[index].fecha.year = year;
    job[index].id_client = id_client;
    job[index].status = BUSY;
}

/** \brief search for an empty position
 *
 * \param eJob job[]
 * \param len int
 * \return Return job index position or (-1) if [job not found]
 *
 */

int job_findEmptyPlace(eJob job[], int len)
{
    int flag = -1;
    for(int i=0; i<len; i++)
    {
        if(job[i].status == EMPTY)
        {
            flag = i;
            break;
        }
    }
    return flag;
}

/** \brief search an empty id
 *
 * \param eJob job[]
 * \param len int
 * \return Return job index position or (-1) if [job not found]
 *
 */

int job_findNextId(eJob job[], int len)
{
    int flag = -1;
    for(int i=0; i<len; i++)
    {
        if(job[i].status == EMPTY)
        {
            flag = i+1;
            break;
        }
    }
    return flag;
}

/** \brief find a Job by Id en returns the index position in array.
 *
 * \param eJob[] job
 * \param len int
 * \param id int
 * \return Return job index position or (-1) if [job not found]
 *
 */

int findJobById(eJob job[], int len,int id)
{
    int flag = -1;
    if(job != NULL && len > 0)
    {
        for (int i=0; i<len; i++)
        {
            if (job[i].id_job == id && job[i].status == BUSY)
            {
                flag = i;
                break;
            }
        }
    }
    return flag;
}

/** \brief find a Job by Id Car en returns the index position in array.
 *
 * \param eJob[] job
 * \param len int
 * \param id int
 * \return Return job index position or (-1) if [job not found]
 *
 */

int findJobByIdCar(eJob job[], int len,int id)
{
    int flag = -1;
    if(job != NULL && len > 0)
    {
        for (int i=0; i<len; i++)
        {
            if (job[i].id_car == id && job[i].status == BUSY)
            {
                flag = i;
                break;
            }
        }
    }
    return flag;
}

/** \brief print the content of jobs array
 *
 * \param eJob[] job
 * \param job_len int
 * \param eCar[] car
 * \param car_len int
 * \param eMarca[] marca
 * \param marca_len int
 * \param eColour[] colour
 * \param colour_len int
 * \param eServis[] servis
 * \param servis_len int
 * \return void
 *
 */

void printJobs(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eServis servis[], int servis_len, eClient client[], int client_len)
{
    printf(">>Lista de Trabajos\n\n");
    printf("ID |  PATENTE  |   SERVICIO |   FECHA    |    CLIENTE \n\n");

    for (int i=0; i<job_len; i++)
    {
        if (job[i].status == BUSY)
            printJob(job[i], car, car_len, servis, servis_len, client, client_len);
    }
    printf("\n\n");
}

/** \brief search a determinate job by id in the list of rents
 *
 * \param eJob[] job
 * \param job_len int
 * \param eCar[] car
 * \param car_len int
 * \param eMarca[] marca
 * \param marca_len int
 * \param eColour[] colour
 * \param colour_len int
 * \param eServis[] servis
 * \param servis_len int
 * \return Return job index position or (-1) if [job not found]
 *
 */

int job_getIdInList(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eServis servis[], int servis_len, eClient client[], int client_len)
{
    int id, valid, flag= -1;

    printJobs(job, job_len, car, car_len, marca, marca_len, colour, colour_len, servis, servis_len, client, client_len);
    valid = getValidInt("ID: ","Fuera de Rango\n", &id, 0, job_len+1, 3);

    if (!valid && findJobById(job, job_len, id) != -1)
        flag= id;

    else
        printf("\nAlquiler no encontrado\n\n");

    return flag;
}



/** \brief add in a existing list of rents the values valided
 * \param eJob x
 * \param eCar y
 * \param eColour z
 * \return void
 */

void printJob(eJob job, eCar car[], int car_len, eServis servis[], int servis_len, eClient client[], int client_len)
{
    int posCar = findCarById(car, car_len, job.id_car);
    if (posCar == -1)
        posCar = findDeletedCarById(car, car_len, job.id_car);

    int posServis = findServisById(servis, servis_len, job.id_servis);
    int posClient = findClientById(client, client_len, job.id_client);

    printf("%2d | %8s  | %10s | %2d-%2d-%d | %13s \n", job.id_job, car[posCar].patente, servis[posServis].description, job.fecha.day, job.fecha.month, job.fecha.year, client[posClient].name);
}


/** \brief create jobs to see if program run OK
 *
 * \param eJob y[]
 * \return void
 *
 */

void job_hardcore(eJob y[])
{
    eJob x[]=
    {

        {1, 1, 20000, {12,3,2019}, 1, 1},
        {2, 2, 20000, {2,4,2019}, 1, 2},
        {3, 3, 20001, {7,1,2019}, 1, 3},
        {4, 4, 20002, {9,11,2019}, 1, 4},
        {5, 5, 20003, {12,12,2019}, 1, 5},
        {6, 6, 20001, {21,7,2019}, 1, 6},
        {7, 7, 20001, {29,8,2019}, 1, 7},
        {8, 8, 20004, {31,5,2019}, 1, 8},
        {9, 9, 20004, {2,2,2019}, 1, 9},
        {10, 10, 20000, {18,2,2019}, 1, 10},
        {11, 11, 20001, {17,3,2019}, 1, 11},
        {12, 1, 20000, {17,4,2019}, 1, 1},
        {13, 2, 20000, {2,6,2019}, 1, 2},
        {14, 3, 20001, {7,3,2019}, 1, 3},
        {15, 4, 20002, {21,7,2019}, 1, 4},
        {16, 5, 20003, {11,9,2019}, 1, 5},
        {17, 6, 20001, {3,7,2019}, 1, 6},
        {18, 7, 20001, {21,8,2019}, 1, 7},
        {19, 8, 20004, {28,5,2019}, 1, 8},
        {20, 9, 20004, {2,8,2019}, 1, 9},
        {21, 10, 20000, {8,2,2019}, 1, 10},
        {22, 11, 20001, {17,3,2019}, 1, 11},
        {23, 18, 20003, {17,4,2019}, 1, 18},
        {24, 19, 20000, {21,3,2019}, 1, 19},
        {25, 20, 20002, {16,4,2019}, 1, 20},
        {26, 21, 20000, {17,4,2019}, 1, 21},
        {27, 22, 20001, {23,3,2019}, 1, 22},
        {28, 1, 20000, {12,2,2019}, 1, 1},
        {29, 2, 20000, {2,3,2019}, 1, 2},
        {30, 3, 20001, {7,2,2019}, 1, 3},
        {31, 4, 20002, {9,12,2019}, 1, 4},
        {32, 5, 20003, {12,9,2019}, 1, 5},
        {33, 6, 20001, {21,5,2019}, 1, 6},
        {34, 5, 20002, {12,2,2019}, 1, 5},
        {35, 6, 20000, {21,1,2019}, 1, 6},
    };

    for(int i=0; i<35; i++)
    {
        y[i] = x[i];
    }
}
