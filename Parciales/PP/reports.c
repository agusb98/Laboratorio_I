#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "fecha.h"
#include "marca.h"
#include "colour.h"
#include "cars.h"
#include "servis.h"
#include "job.h"
#include "cliente.h"


/** \brief print all option able to choose
 *
 * \param  void
 * \return int option choosed
 */

int reportsMain()
{
    system("cls");

    printf(">>Informes de Trabajos\n\n");
    printf("\n1_ Autos por Color");
    printf("\n2_ Autos por Det Marca");
    printf("\n3_ Trabajos por Det Auto");
    printf("\n4_ Autos sin Trabajo");
    printf("\n5_ Importe Total de trabajos por un Det Auto");
    printf("\n6_ Servicio mas Popular");
    printf("\n7_ Recaudacion en Det Fecha");
    printf("\n8_ Autos que realizaron un Encerado y la fecha");
    printf("\n9_ Trabajos realizados a Autos blancos");
    printf("\n10_ Facturacion total por Pulidos");
    printf("\n11_ Marca de autos que efectuaron mas lavados completos");
    printf("\n12_ Autos que recibieron Trabajos en una Determinada Fecha");

    printf("\n\n\n13_ Autos por color en un det Marca");
    printf("\n14_ Paten de los autos grises");
    printf("\n15_ Autos con una misma marca de patente ingresada");
    printf("\n16_ listar los autos de hombre");
    printf("\n17_ listar el nombre de los clientes con marca renault");
    printf("\n18_ cantidad de pulidos realizados a autos mujeres");
    printf("\n19_ marca de autos mas elegidos por mujeres");
    printf("\n20_ nombres de las personas que efectuaros lavados");
    printf("\n21_ Salir");

    fflush(stdin);
    int opt = getInt("\n\nIngrese opcion: ");
    return opt;
}

/** \brief cont all active jobs (status 1)
 *
 * \param job[] eJob
 * \param len int
 * \return int cont
 *
 */

int report_contBusyJobs(eJob job[], int len)
{
    int cont=0;
    for(int i=0; i< len; i++)
    {
        if(job[i].status == BUSY)
            cont ++;
    }
    return cont;
}

/** \brief cont all active jobs (status 1)
 *
 * \param job[] eJob
 * \param len int
 * \return int cont
 *
 */

int report_contBusyCars(eCar car[], int len)
{
    int cont=0;
    for(int i=0; i<len; i++)
    {
        if(car[i].status == BUSY)
            cont ++;
    }
    return cont;
}

/** \brief acum salary of all active jobs (status 1)
 *
 * \param job[] eJob
 * \param job_len int
 * \param servis[] eServis
 * \param servis_len int
 * \return float acum of prices
 *
 */

float report_acumBusyPrices(eJob job[], int job_len, eServis servis[], int servis_len)
{
    float acum=0;
    for(int i=0; i<job_len; i++)
    {
        if(job[i].status == BUSY);
        {
            int posServis = findServisById(servis, servis_len, job[i].id_servis);
            acum += servis[posServis].price;
        }
    }
    return acum;
}

/** \brief prom of prices of all services
 *
 * \param job[] eJob
 * \param job_len int
 * \param servis[] eServis
 * \param servis_len int
 * \return float prom of Prices
 *
 */

float report_promPrices(eJob job[], int job_len, eServis servis[], int servis_len)
{
    int cont = report_contBusyJobs(job, job_len);
    float acum = report_acumBusyPrices(job, job_len, servis, servis_len);
    float prom = (float) acum/cont;

    return prom;
}

/** \brief cont jobs that prices are less of prom
 *
 * \param job[] eJob
 * \param job_len int
 * \param servis[] eServis
 * \param servis_len int
 * \return int cont with less of prom
 *
 */

int report_contLessProm(eJob job[], int job_len, eServis servis[], int servis_len)
{
    int cont=0;
    float prom = report_promPrices(job, job_len, servis, servis_len);

    for (int i=0; i<job_len; i++)
    {
        if (job[i].status == BUSY)
        {
            int posServis = findServisById(servis, servis_len, job[i].id_servis);
            if (servis[posServis].price < prom)
                cont++;
        }
    }
    return cont;
}

/** \brief cont jobs that price are up of prom
 *
 * \param job[] eJob
 * \param job_len int
 * \param servis[] eServis
 * \param servis_len int
 * \return int cont jobs
 */

int report_contUpProm(eJob job[], int job_len, eServis servis[], int servis_len)
{
    int cont = report_contBusyJobs(job, job_len);
    int less = report_contLessProm(job, job_len, servis, servis_len);
    return (cont - less);
}

/** \brief print all cars into a Service
 *
 * \param job[] eJob
 * \param job_len int
 * \param car[] eCar
 * \param car_len int
 * \param marca[] eMarca
 * \param marca_len int
 * \param colour[] eColour
 * \param colour_len int
 * \param servis[] eServis
 * \param servis_len int
 * \return void
 *
 */

void report_carsByServis(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eServis servis[], int servis_len, eClient client[], int client_len)
{
    int id = servis_getIdInList(servis, servis_len);
    if (id != -1)
    {
        printf("\nID |  PATENTE  |    MARCA   |  COLOR | MODELO \n\n");

        for (int i=0; i<job_len; i++)
        {
            if (findServisById(servis, servis_len, job[i].id_servis) != -1)
            {
                int posCar = findCarById(car, car_len, job[i].id_car);
                if (posCar != -1)
                    printCar(car[posCar], marca, marca_len, colour, colour_len, client, client_len);
            }
        }
    }
    else
        printf("\nServicio no Encontrado");
    printf("\n\n");
}

/** \brief print all games into a clients
 *
 * \param job[] eJob
 * \param job_len int
 * \param car[] eCar
 * \param car_len int
 * \param marca[] eMarca
 * \param marca_len int
 * \param colour[] eColour
 * \param colour_len int
 * \param servis[] eServis
 * \param servis_len int
 * \return void
 *
 */

void report_jobByCar(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eServis servis[], int servis_len, eClient client[], int client_len)
{
    int id = car_getIdInList(car, car_len, marca, marca_len, colour, colour_len, client, client_len);
    if (id != -1)
    {
        printf("\n>>Lista de Trabajos\n\n");
        printf("ID |  PATENTE  |   SERVICIO |   FECHA    |    CLIENTE\n\n");
        for (int i=0; i<job_len; i++)
        {
            if (job[i].id_car == id && job[i].status == BUSY)
                printJob(job[i], car, car_len, servis, servis_len, client, client_len);
        }
    }
    else
        printf("\nAuto no Encontrado");
    printf("\n\n");

}

/** \brief print unpopular cars
 *
 * \param job[] eJob
 * \param job_len int
 * \param game[] eGame
 * \param game_len int
 * \return void
 *
 */

void report_unpopularCars(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len)
{
    int x[car_len];
    int min = job_len;

    for (int i=0; i<car_len; i++)
        x[i] = 0;   //inicializo vector paralelo a autos

    for (int i=0; i<car_len; i++)
    {
        if (car[i].status == BUSY)
        {
            for (int j=0; j<job_len; j++)
            {
                if (job[j].status == BUSY && job[j].id_car == car[i].id)
                    x[i]++;
            }
        }
    }

    for (int i=0; i<car_len; i++)
    {
        if (x[i] < min && car[i].status == BUSY)
            min = x[i];
    }

    printf("\nID |  PATENTE  |    MARCA   |  COLOR | MODELO \n\n");
    for (int i=0; i<car_len; i++)
    {
        if (x[i] == min && car[i].status == BUSY)
            printCar(car[i], marca, marca_len, colour, colour_len, client, client_len);
    }
    printf("\n\n");
}

/** \brief print unpopular services
 *
 * \param job[] eJob
 * \param job_len int
 * \param servis[] eServis
 * \param servis_len int
 * \return void
 *
 */

void report_unpopularServices(eJob job[], int job_len, eServis servis[], int servis_len)
{
    int x[servis_len];
    int min = job_len;

    for (int i=0; i<servis_len; i++)
        x[i] = 0;   //inicializo vector paralelo a servicios

    for (int i=0; i<servis_len; i++)
    {
        for (int j=0; j<job_len; j++)
        {
            if (job[j].id_servis == servis[i].id && job[j].status == BUSY)
                x[i]++;
        }
    }

    for (int i=0; i<servis_len; i++)
    {
        if (x[i] < min)
            min = x[i];
    }

    printf("\nID    |DESCRIPTION| PRECIO \n\n");
    for (int i=0; i<servis_len; i++)
    {
        if (x[i] == min)
            printServis(servis[i]);
    }
    printf("\n\n");
}


/** \brief print which car/s have more jobs
 *
 * \param job[] eJob
 * \param job_len int
 * \param car[] eCar
 * \param car_len int
 * \param marca[] eMarca
 * \param marca_len int
 * \param colour[] eColour
 * \param colour_len int
 * \return void
 *
 */

void report_popularCars(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len)
{
    int x[car_len];
    int max = 0;

    for (int i=0; i<car_len; i++)
        x[i] = 0;

    for (int i=0; i<car_len; i++)
    {
        if (car[i].status == BUSY)
        {
            for (int j=0; j<job_len; j++)
            {
                if (job[j].id_car == car[i].id && job[j].status == BUSY)
                    x[i]++;
            }
        }
    }

    for (int i=0; i<car_len; i++)
    {
        if (car[i].status == BUSY && x[i] > max)
            max = x[i];
    }

    printf("\nID |  PATENTE  |    MARCA   |  COLOR | MODELO \n\n");
    for (int i=0; i<car_len; i++)
    {
        if (x[i] == max && car[i].status == BUSY)
            printCar(car[i], marca, marca_len, colour, colour_len, client, client_len);
    }
    printf("\n\n");
}

/** \brief print popular serices
 *
 * \param job[] eJob
 * \param job_len int
 * \param servis[] eServis
 * \param servis_len int
 * \return void
 *
 */

void report_popularServices(eJob job[], int job_len, eServis servis[], int servis_len)
{
    int x[servis_len];
    int max = 0;

    for (int i=0; i<servis_len; i++)
        x[i] = 0;

    for (int i=0; i<servis_len; i++)
    {
        for (int j=0; j<job_len; j++)
        {
            if (servis[i].id == job[j].id_servis && job[j].status == BUSY)
                x[i]++;
        }
    }

    for (int i=0; i<servis_len; i++)
    {
        if (x[i] > max)
            max = x[i];
    }

    printf("\n>> Servicios\n\n");
    printf("\nID    |DESCRIPTION| PRECIO \n\n");
    for (int i=0; i<servis_len; i++)
    {
        if (x[i] == max)
            printServis(servis[i]);
    }
    printf("\n\n");
}


/** \brief print all services used in a specific date
 *
 * \param job[] eJob
 * \param job_len int
 * \param eServis servis[]
 * \param int servis_len
 * \return void
 *
 */

void report_servicesByDate(eJob job[], int job_len, eServis servis[], int servis_len)
{
    int day, month, year;
    if(getValidDate(&day, &month, &year))
    {
        printf("\nID    |DESCRIPTION| PRECIO \n\n");
        for(int i=0; i<job_len; i++)
        {
            if (job[i].fecha.day == day && job[i].fecha.month == month && job[i].fecha.year == year && job[i].status == BUSY)
            {
                int index = findServisById(servis, servis_len, job[i].id_servis);
                printServis(servis[index]);
            }
        }
    }
    printf("\n\n");
}

/** \brief print all cars rented in a specific date
 *
 * \param job[] eJob
 * \param job_len int
 * \param car[] eCar
 * \param car_len int
 * \param marca[] eMarca
 * \param marca_len int
 * \param colour[] eColour
 * \param colour_len int
 * \return void
 *
 */

void report_carsByDate(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len)
{
    int day, month, year;
    if(getValidDate(&day, &month, &year))
    {
        printf("\n>> Lista de Autos\n\n");
        printf("ID |  PATENTE  |    MARCA   |  COLOR | MODELO  |   CLIENTE  \n\n");
        for(int i=0; i<job_len; i++)
        {
            if (job[i].fecha.day == day && job[i].fecha.month == month && job[i].fecha.year == year && job[i].status == BUSY)
            {
                int index = findCarById(car, car_len, job[i].id_car);//entra al IF si existe el auto en el trabajo asignado
                printCar(car[index], marca, marca_len, colour, colour_len, client, client_len);
            }
        }
    }
    printf("\n\n");
}


/** \brief print the content of cars array
 *
 * \param car[] eCar
 * \param car_len int
 * \param marca[] eMarca
 * \param marca_len int
 * \return void
 *
 */

void report_sortCarsByMarca_Patente(eCar car[], int car_len, eMarca marca[], int marca_len)
{
    for (int i=0; i<marca_len; i++)
    {
        for (int j=0; j<car_len-1; j++)
        {
            if (car[j].status == BUSY)
            {
                for (int k=j+1; k<car_len; k++)
                {
                    if (car[j].idMarca != marca[i].id && car[k].status == BUSY)
                    {
                        eCar aux = car[j];
                        car[j] = car[k];
                        car[k] = aux;
                    }
                }
            }

        }
    }
    for (int i=0; i<car_len-1; i++)
    {
        for (int j=i+1; j<car_len; j++)
        {
            if (car[i].status == BUSY && car[j].status == BUSY)
            {
                if (car[i].idMarca == car[j].idMarca && strcmp(car[i].patente, car[j].patente)<0)
                {
                    eCar aux = car[i];
                    car[i] = car[j];
                    car[j] = aux;
                }
            }
        }
    }
}

/** \brief sort all cars used by Colour and Patente
 *
 * \param car[] eCar
 * \param car_len int
 * \param colour[] eColour
 * \param colour_len int
 * \return void
 *
 */

void report_sortCarsByColour_Patente(eCar car[], int car_len, eColour colour[], int colour_len)
{
    for (int i=0; i<colour_len; i++)
    {
        for (int j=0; j<car_len-1; j++)
        {
            for (int k=j+1; k<car_len; k++)
            {
                if (car[j].status == BUSY && car[k].status == BUSY)
                {
                    if (car[j].idColor != colour[i].id)
                    {
                        eCar aux = car[i];
                        car[j] = car[k];
                        car[k] = aux;
                    }
                }
            }
        }
    }
    for (int i=0; i<car_len-1; i++)
    {
        for (int j=i+1; j<car_len; j++)
        {
            if (car[i].status == BUSY && car[j].status == BUSY)
            {
                if (car[i].idColor == car[j].idColor && strcmp(car[i].patente, car[j].patente)<0)
                {
                    eCar aux = car[i];
                    car[i] = car[j];
                    car[j] = aux;
                }
            }
        }
    }
}

/** \brief sort all cars rented by Modelo and Marca
 *
 * \param car[] eCar
 * \param car_len int
 * \param marca[] eMarca
 * \param marca_len int
 * \return void
 *
 */

void report_sortCarsByModelo_Marca(eCar car[], int car_len, eMarca marca[], int marca_len)
{
    for (int i=0; i<marca_len; i++)
    {
        for (int j=0; j<car_len-1; j++)
        {
            for (int k=j+1; k<car_len; k++)
            {
                if (car[j].status == BUSY && car[k].status == BUSY)
                {
                    if (car[j].idMarca != marca[i].id)
                    {
                        eCar aux = car[i];
                        car[j] = car[k];
                        car[k] = aux;
                    }
                }
            }
        }
    }
    for (int i=0; i<car_len-1; i++)
    {
        for (int j=i+1; j<car_len; j++)
        {
            if (car[i].status == BUSY && car[j].status == BUSY)
            {
                if (car[i].idMarca == car[j].idMarca && car[i].modelo < car[j].modelo)
                {
                    eCar aux = car[i];
                    car[i] = car[j];
                    car[j] = aux;
                }
            }
        }
    }
}


/** \brief sort all cars rented by Modelo and Colour
 *
 * \param car[] eCar
 * \param car_len int
 * \param colour[] eColour
 * \param colour_len int
 * \return void
 *
 */

void report_sortCarsByModelo_Colour(eCar car[], int car_len, eColour colour[], int colour_len)
{
    for (int i=0; i<car_len-1; i++)
    {
        for (int j=i+1; j<car_len; j++)
        {
            if (car[i].status == BUSY && car[j].status == BUSY)
            {
                if (car[i].idColor < car[j].idColor)
                {
                    eCar aux = car[i];
                    car[i] = car[j];
                    car[j] = aux;
                }
            }
        }
    }
    for (int i=0; i<car_len-1; i++)
    {
        for (int j=i+1; j<car_len; j++)
        {
            if (car[i].status == BUSY && car[j].status == BUSY)
            {
                if (car[i].idColor == car[j].idColor && car[i].modelo > car[j].modelo)
                {
                    eCar aux = car[i];
                    car[i] = car[j];
                    car[j] = aux;
                }
            }
        }
    }
}

/** \brief print all cars by modelo
 *
 * \param car[] eCar
 * \param car_len int
 * \param colour[] eColour
 * \param colour_len int
 * \return void
 *
 */

void report_carsByModelo(eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len)
{
    int modelo;
    int valid = getValidInt("Modelo: ", "Fuera de Rango ", &modelo, 1950, 2019, 3);

    if (!valid)
    {
        printf("\nID |  PATENTE  |    MARCA   |  COLOR | MODELO \n\n");
        for (int i=0; i<car_len; i++)
        {
            if (car[i].modelo == modelo && car[i].status == BUSY)
                printCar(car[i], marca, marca_len, colour, colour_len, client, client_len);
        }
    }
}

/** \brief print all cars by color
 *
 * \param car[] eCar
 * \param car_len int
 * \param colour[] eColour
 * \param colour_len int
 * \return void
 *
 */

void report_carsByColor(eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len)
{
    int id = colour_getIdInList(colour, colour_len);

    if (id != -1)
    {
        printf("\n>> Lista de Autos\n\n");
        printf("ID |  PATENTE  |    MARCA   |  COLOR | MODELO  |   CLIENTE  \n\n");
        for (int i=0; i<car_len; i++)
        {
            if (car[i].idColor == id && car[i].status == BUSY)
                printCar(car[i], marca, marca_len, colour, colour_len, client, client_len);
        }
    }
    else
        printf("\nColor Inexistente\n\n");
}

/** \brief print all cars into a Service
 *
 * \param job[] eJob
 * \param job_len int
 * \param car[] eCar
 * \param car_len int
 * \param marca[] eMarca
 * \param marca_len int
 * \param colour[] eColour
 * \param colour_len int
 * \return void
 *
 */

void report_carsByMarca(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len)
{
    int id = marca_getIdInList(marca, marca_len);
    if (id != -1)
    {
        printf("\n>> Lista de Autos\n\n");
        printf("ID |  PATENTE  |    MARCA   |  COLOR | MODELO  |   CLIENTE  \n\n");

        for (int i=0; i<car_len; i++)
        {
            if (car[i].idMarca == id && car[i].status == BUSY)
                printCar(car[i], marca, marca_len, colour, colour_len, client, client_len);
        }
        printf("\n\n");
    }
    else
        printf("\nServicio no Encontrado\n\n");
}


/** \brief acum price of a det car (status 1)
 *
 *
 * \param job[] eJob
 * \param job_len int
 * \param car[] eCar
 * \param car_len int
 * \param marca[] eMarca
 * \param marca_len int
 * \param servis[] eServis
 * \param servis_len int
 * \param id_servis int
 * \return void
 *
 */

void report_acumOfADetCar(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eServis servis[], int servis_len, eClient client[], int client_len)
{
    float acum = 0;
    int id = car_getIdInList(car, car_len, marca, marca_len, colour, colour_len, client, client_len);
    if (id != -1)
    {
        for (int i=0; i<job_len; i++)
        {
            if (job[i].id_car == id && job[i].status == BUSY)
            {
                int x = findServisById(servis, servis_len, job[i].id_servis);
                acum += servis[x].price;
            }
        }
        printf("\n\n");
    }
    else
        printf("\nAuto no Encontrado\n\n");

    printf("Importe: $%.0f\n\n", acum);
}


/** \brief print all cars rented in a specific date
 *
 * \param job[] eJob
 * \param job_len int
 * \param servis[] eServis
 * \param servis_len int
 * \return void
 *
 */

void report_acumOfADetDate(eJob job[], int job_len, eServis servis[], int servis_len)
{
    int day, month, year;
    float acum = 0;
    if(getValidDate(&day, &month, &year))
    {
        for(int i=0; i<job_len; i++)
        {
            if (job[i].fecha.day == day && job[i].fecha.month == month && job[i].fecha.year == year)
            {
                if(job[i].status == BUSY)
                {
                    int index = findServisById(servis, servis_len, job[i].id_servis);
                    acum += servis[index].price;
                }
            }
        }
        printf("\nRecaudacion de la fecha %d/%d/%d : $%.0f\n\n", day, month, year, acum);
    }
    else
        printf("\nFecha Invalida\n\n");
}


/** \brief print all cars whose job is Encerado
 *
 * \param job[] eJob
 * \param job_len int
 * \param car[] eCar
 * \param car_len int
 * \param marca[] eMarca
 * \param marca_len int
 * \param colour[] eColour
 * \param colour_len int
 * \param servis[] eServis
 * \param servis_len int
 * \param client[] eClient
 * \param client_len int
 * \return void
 *
 */

void report_carsByServis_Date(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, int idServis, eClient client[], int client_len)
{
    printf("\n>> Lista de Autos\n\n");
    printf(" FECHA     | ID|  PATENTE  |    MARCA   |  COLOR | MODELO  |   CLIENTE  \n\n");

    for (int i=0; i<job_len; i++)
    {
        if (job[i].status == BUSY && job[i].id_servis == idServis)
        {
            printf("%0d-%0d-%0d  |", job[i].fecha.day, job[i].fecha.month, job[i].fecha.year);
            int index = findCarById(car, car_len, job[i].id_car);
            if (index != -1)
                printCar(car[index], marca, marca_len, colour, colour_len, client, client_len);
        }
    }
    printf("\n\n");
}

/** \brief print all cars whithout job
 *
 * \param job[] eJob
 * \param job_len int
 * \param car[] eCar
 * \param car_len int
 * \param marca[] eMarca
 * \param marca_len int
 * \param colour[] eColour
 * \param colour_len int
 * \param client[] eClient
 * \param client_len int
 * \return void
 *
 */

void report_carsWithoutJob(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len)
{
    printf("\n>> Lista de Autos\n\n");
    printf("ID |  PATENTE  |    MARCA   |  COLOR | MODELO  |   CLIENTE  \n\n");
    for (int i=0; i<car_len; i++)
    {
        if (car[i].status == BUSY && findJobByIdCar(job, job_len, car[i].id) == -1)
        {
            printCar(car[i], marca, marca_len, colour, colour_len, client, client_len);
        }
    }
    printf("\n\n");
}

/** \brief print all jobs with an especific colour
 *
 * \param job[] eJob
 * \param job_len int
 * \param car[] eCar
 * \param car_len int
 * \param servic[] eService
 * \param service_len int
 * \param client[] eClient
 * \param client_len int
 * \param id_colour int
 * \return void
 *
 */

void report_jobsByID_colourCars(eJob job[], int job_len, eCar car[], int car_len, eServis servis[], int servis_len, eClient client[], int client_len, int id_colour)
{
    if (id_colour != -1)
    {
        printf("\n>>Lista de Trabajos\n\n");
        printf("ID |  PATENTE  |   SERVICIO |   FECHA     |    CLIENTE \n\n");
        for (int i=0; i<car_len; i++)
        {
            if (car[i].status == BUSY && car[i].idColor == id_colour)
            {
                for (int j=0; j<job_len; j++)
                {
                    if (job[j].id_car == car[i].id && job[j].status == BUSY)
                        printJob(job[j], car, car_len, servis, servis_len, client, client_len);
                }
            }
        }
    }
    else
        printf("\nColor Inexistente\n\n");
}

/** \brief print all car with job in a Determinate Date
 *
 * \param job[] eJob
 * \param job_len int
 * \param car[] eCar
 * \param car_len int
 * \param servic[] eService
 * \param service_len int
 * \param client[] eClient
 * \param client_len int
 * \param id_colour int
 * \return void
 *
 */

void report_carsWithJobByDate(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len)
{
    int day, month, year;

    if (getValidDate(&day, &month, &year) != -1)
    {
        printf("\n>> Lista de Autos\n\n");
        printf("ID |  PATENTE  |    MARCA   |  COLOR | MODELO  |   CLIENTE  \n\n");

        for (int i=0; i<job_len; i++)
        {
            if (job[i].fecha.day == day && job[i].fecha.month == month && job[i].fecha.year == year && job[i].status == BUSY)
            {
                int index = findCarById(car, car_len, job[i].id_car);
                if (index != -1)
                    printCar(car[index], marca, marca_len, colour, colour_len, client, client_len);
            }
        }
    }
    else
        printf("\nFecha Invalida");
    printf("\n\n");
}

/** \brief acum price of a Determiante ID service
 *
 * \param job[] eJob
 * \param job_len int
 * \param service[] eService
 * \param service_len int
 * \param id_service int
 * \return void
 *
 */
void report_acumByIdService(eJob job[], int job_len, eServis servis[], int servis_len, int id_service)
{
    float acum = 0;
    int pos = findServisById(servis, servis_len, id_service);

    for (int i=0; i<job_len; i++)
    {
        if (job[i].status == BUSY && job[i].id_servis == id_service)
            acum += servis[pos].price;
    }
    printf("\nTotal por %s : $%.1f\n\n", servis[pos].description, acum);
}

/** \brief acum price of a Determiante ID service
 *
 * \param job[] eJob
 * \param job_len int
 * \param service[] eService
 * \param service_len int
 * \param id_service int
 * \return void
 *
 */
void report_popularMarcasByServis(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, int id_service)
{
    int x[car_len];
    int max = 0;

    for (int i=0; i<car_len; i++)
        x[i] = 0;

    for (int i=0; i<car_len; i++)
    {
        for (int j=0; j<job_len; j++)
        {
            if (car[i].status == BUSY && job[j].status == BUSY)
            {
                if (car[i].id == job[j].id_car)
                    x[i]++;
            }
        }
    }

    for (int i=0; i<car_len; i++)
    {
        if (car[i].status == BUSY && x[i] > max)
            max = x[i];
    }

    printf("\n>> MARCAS\n\n");
    printf("ID   |  NOMBRE  \n\n");
    for (int i=0; i<car_len; i++)
    {
        if (x[i] == max && car[i].status == BUSY)
        {
            int posMarca = findMarcaById(marca, marca_len, car[i].idMarca);
            printMarca(marca[posMarca]);
        }
    }
    printf("\n\n");
}


/** \brief print cantidad de autos cars into a marca y color
 *
 * \param job[] eJob
 * \param job_len int
 * \param car[] eCar
 * \param car_len int
 * \param marca[] eMarca
 * \param marca_len int
 * \param colour[] eColour
 * \param colour_len int
 * \return void
 *
 */

void report_QuantityByMarcaColour(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len)
{
    int vec[colour_len];

    for (int i=0; i<colour_len; i++)
        vec[i] =0;

    int idCar = marca_getIdInList(marca, marca_len);
    if (idCar != -1)
    {
        for(int i=0; i<colour_len; i++)
        {
            for (int j=0; j<car_len; j++)
            {
                if (car[j].idMarca == idCar && car[j].status == BUSY && car[j].idColor == colour[i].id)
                {
                    vec[i] ++;
                }
            }
        }

        printf(">> Colores\n\n");
        printf("ID   | NOMBRE \n\n");

        for(int i=0; i<colour_len; i++)
        {
            printf("%d ", vec[i]);
            printColour(colour[i]);
        }
        printf("\n\n");
    }
    else
        printf("\nServicio no Encontrado\n\n");
}


/** \brief print all cars by color
 *
 * \param car[] eCar
 * \param car_len int
 * \param colour[] eColour
 * \param colour_len int
 * \return void
 *
 */

void report_carsByPatente(eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len)
{
    char patente[52];
    printCars(car, car_len, marca, marca_len, colour, colour_len, client, client_len);
    getString("Patente: ", patente);

    if (findCarByPatente(car, car_len, patente) != -1)
    {
        printf("\n>> Lista de Autos\n\n");
        printf("ID |  PATENTE  |    MARCA   |  COLOR | MODELO  |   CLIENTE  \n\n");

        for (int i=0; i<car_len; i++)
        {
            if (strcmp(car[i].patente, patente) == 0)
            {
                for (int j=0; j<car_len; j++)
                {
                    if (car[i].idMarca == car[j].idMarca)
                        printCar(car[j], marca, marca_len, colour, colour_len, client, client_len);
                }
            }
        }
    }
    else
        printf("\nColor Inexistente\n\n");
}


/** \brief print all cars into a Service
 *
 * \param job[] eJob
 * \param job_len int
 * \param car[] eCar
 * \param car_len int
 * \param marca[] eMarca
 * \param marca_len int
 * \param colour[] eColour
 * \param colour_len int
 * \return void
 *
 */

void report_carsBySex(eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len)
{
    printf(">> Lista de Autos\n\n");
    printf("ID |  PATENTE  |    MARCA   |  COLOR | MODELO  |   CLIENTE  \n\n");

    for (int i=0; i<client_len; i++)
    {
        if (strcmp("m", client[i].sex) == 0)
        {
            int posCar = findCarById(car, car_len, client[i].id_auto);
            printCar(car[posCar], marca, marca_len, colour, colour_len, client, client_len);
        }
    }
    printf("\n\n");
}



/** \brief print all cars into a Service
 *
 * \param job[] eJob
 * \param job_len int
 * \param car[] eCar
 * \param car_len int
 * \param marca[] eMarca
 * \param marca_len int
 * \param colour[] eColour
 * \param colour_len int
 * \return void
 *
 */

void report_clientsByMarca(eCar car[], int car_len, eClient client[], int client_len, int idMarca)
{

    printf(">> Clientes\n\n");
    printf("ID |     NOMBRE       | SEXO \n\n");

    for (int i=0; i<car_len; i++)
    {
        if (car[i].idMarca == idMarca && car[i].status == BUSY)
        {
            int posClient =  findClientById(client, client_len, car[i].idClient);
            printClient(client[posClient]);
        }
    }
    printf("\n\n");
}




/** \brief print all cars into a Service
 *
 * \param job[] eJob
 * \param job_len int
 * \param car[] eCar
 * \param car_len int
 * \param marca[] eMarca
 * \param marca_len int
 * \param colour[] eColour
 * \param colour_len int
 * \param servis[] eServis
 * \param servis_len int
 * \return void
 *
 */

void report_contByServisWoman(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eServis servis[], int servis_len, eClient client[], int client_len)
{
    int cont = 0;
    for (int i=0; i<job_len; i++)
    {
        if (job[i].id_servis ==  20001)
        {
            int posClient = findClientById(client, client_len, job[i].id_client);
            if (strcmp(client[posClient].sex,"f") == 0)
                cont++;
        }
    }

    printf("%d", cont);
    printf("\n\n");
}



/** \brief print which car/s have more jobs
 *
 * \param job[] eJob
 * \param job_len int
 * \param car[] eCar
 * \param car_len int
 * \param marca[] eMarca
 * \param marca_len int
 * \param colour[] eColour
 * \param colour_len int
 * \return void
 *
 */

void report_popularMarcaByWoman(eCar car[], int car_len, eMarca marca[], int marca_len, eClient client[], int client_len)
{
    int x[marca_len];
    int max = 0;

    for (int i=0; i<marca_len; i++)
        x[i] = 0;

    for (int i=0; i<marca_len; i++)
    {
        for (int j=0; j<client_len; j++)
        {
            int posCar = findCarById(car, car_len, client[j].id_auto);
            if (strcmp(client[j].sex, "f") == 0 && posCar != -1 && car[posCar].idMarca == marca[i].id)
                x[i]++;
        }
    }

    for (int i=0; i<marca_len; i++)
    {
        if (x[i] > max)
            max = x[i];
    }

    printf("\n>> MARCAS\n\n");
    printf("ID   |  NOMBRE  \n\n");
    for (int i=0; i<marca_len; i++)
    {
        if (x[i] == max && x[i] > 0)
            printMarca(marca[i]);
    }
    printf("\n\n\n\n%d", max);
    printf("\n\n");
}



/** \brief print all cars into a Service
 *
 * \param job[] eJob
 * \param job_len int
 * \param car[] eCar
 * \param car_len int
 * \param marca[] eMarca
 * \param marca_len int
 * \param colour[] eColour
 * \param colour_len int
 * \param servis[] eServis
 * \param servis_len int
 * \return void
 *
 */

void report_clientsByServis(eJob job[], int job_len, eClient client[], int client_len)
{
    printf("\n>> Clientes\n\n");
    printf("ID |     NOMBRE       | SEXO \n\n");
    for (int i=0; i<job_len; i++)
    {
        if (job[i].id_servis ==  20000 && job[i].status == BUSY)
        {
            int posClient = findClientById(client, client_len, job[i].id_client);
            if (posClient != -1)
                printClient(client[posClient]);
        }
    }
    printf("\n\n");
}



/** \brief print the content of cars array
 *
 * \param car[] eCar
 * \param car_len int
 * \param marca[] eMarca
 * \param marca_len int
 * \return void
 *
 */

void report_sortById(eCar car[], int car_len, eMarca marca[], int marca_len)
{
    for (int i=0; i<car_len-1; i++)
    {
        for (int j=i+1; j<car_len; j++)
        {
            if (car[i].status == BUSY && car[j].status == BUSY)
            {
                if (car[i].id > car[j].id)
                {
                    eCar aux = car[i];
                    car[i] = car[j];
                    car[j] = aux;
                }
            }
        }
    }
}


/** \brief print all cars by color
 *
 * \param car[] eCar
 * \param car_len int
 * \param colour[] eColour
 * \param colour_len int
 * \return void
 *
 */

void report_patentesByColour(eCar car[], int car_len, eMarca marca[], int marca_len, eClient client[], int client_len, int idColour)
{
    printf("\n>> Lista de Patentes\n\n");
    printf("PATENTE  \n\n");
    for (int i=0; i<car_len; i++)
    {
        if (car[i].idColor == idColour && car[i].status == BUSY)
            printf("%s \n", car[i].patente);
    }
    printf("\n\n");
}
