#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"
#include "marca.h"
#include "colour.h"
#include "cars.h"
#include "servis.h"
#include "job.h"
#include "reports.h"
#include "utn.h"
#include <ctype.h> //para toupper

/** \brief add in a existing list of cars the values valided
 * \param eCar car[]
 * \param car_len int
 * \param eMarca marca[]
 * \param marca_len int
 * \param eColour colour[]
 * \param colour_len int
 * \return int (1) if Ok - (0) if cancel adder
 */

int eject_addCar(eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len)
{
    char patente[12];
    int idModelo, idColour, idMarca, idClient;
    int flag= -1;

    system("cls");
    printf(">> Nuevo Auto\n");
    int id = car_findNextId(car, car_len); //en caso de entregar -1 => (1000 + -1)

    if (id == -1) //Caso en que llega a la maxima cantidad de empleados
        printf("\nNo hay mas Bacantes\n");

    else
    {
        getString("\nPatente: ", patente);
        {
            if (findCarByPatente(car, car_len, patente) == -1) //en el caso de no encontrar la patente, entra al IF
            {
                printMarcas(marca, marca_len);
                flag = getValidInt("\nMarca: ","\nNo es una Marca valido\n", &idMarca,1000,1000+marca_len, 3);
                if(!flag)
                {
                    printColours(colour, colour_len);
                    flag = getValidInt("\nColor: ","\nNo es un Color valido\n", &idColour,5000,5000+colour_len,3);

                    if (!flag)
                    {
                        flag = getValidInt("\nModelo: ","\nNo es un Modelo valido\n", &idModelo,1950,2019,3);
                        if (!flag)
                        {
                            idClient = client_getIdInList(client, client_len);
                            if(idClient != -1 && confirmation())
                            {
                                car_add(car, car_len, id, patente, idMarca, idColour, idModelo, idClient);
                                printf("\nAuto Agregado\n\n");
                                flag= 1;
                            }
                            else
                            {
                                printf("\nOperacion Cancelada\n\n");
                                flag= 0;
                            }
                        }
                    }

                }
            }
            else
                printf("\nLa patente ingresada ya Existe\n\n");
        }
    }
    return flag;
}

/** \brief search Id and wait for confirmation
 *
 * \param eCar car[]
 * \param car_len int
 * \param eMarca marca[]
 * \param marca_len int
 * \param eColour colour[]
 * \param colour_len int
 * \return int (1) if Ok - (0) operation cancelated
 *
 */

int eject_deleteCar(eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len)
{
    int flag= 0;
    system("cls");
    printf(">> Borrar Auto ");
    int id = car_getIdInList(car, car_len, marca, marca_len, colour, colour_len, client, client_len);

    if (id == -1)
        printf("\nAuto Inexistente\n\n");

    else
    {
        if (confirmation())
        {
            car_delete(car, car_len, id);
            printf("\nAuto Eliminado\n\n");
            flag= 1;
        }
        else
            printf("\nOperacion Cancelada\n\n");
    }
    return flag;
}

/** \brief print all option able to choose
 *
 * \param  void
 * \return char option choosed
 */

char principalMain()
{
    system("cls");

    printf(">> Menu de Opciones\n");
    printf("\nA_  ALTA AUTO");
    printf("\nB_  MODIFICAR AUTO");
    printf("\nC_  BAJA AUTO");
    printf("\nD_  LISTAR AUTOS");
    printf("\nE_  LISTAR MARCAS");
    printf("\nF_  LISTAR COLORES");
    printf("\nG_  LISTAR SERVICIOS");
    printf("\nH_  ALTA TRABAJO");
    printf("\nI_  LISTAR TRABAJOS");
    printf("\nJ_ INFORMES");
    printf("\nS_ Salir");

    fflush(stdin);
    int opt = getChar("\n\nIngrese opcion: ");
    opt = toupper(opt);
    return opt;
}

/** \brief modificate a detaille of a car
 * \param eCar car[]
 * \param car_len int
 * \param eMarca marca[]
 * \param marca_len int
 * \param eColour colour[]
 * \param colour_len int
 * \return int (1) if Ok - (0) if declaine operation
 */

int eject_editCar(eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len)
{
    int flag = 0;

    system("cls");
    printf(">> Modificar car ");
    int id = car_getIdInList(car, car_len, marca, marca_len, colour, colour_len, client, client_len);
    if (id != -1 && car_modificate(car, car_len, id, colour, colour_len, marca, marca_len))
    {
        printf("\nAuto Modificado\n\n");
        flag = 1;
    }
    else
    {
        printf("Auto Inexistente\n\n");
        flag = 0;
    }
    return flag;
}

/** \brief add in a existing list of jobs the values valided
 * \param eJob job[]
 * \param job_len int
 * \param eCar car[]
 * \param car_len int
 * \param eMarca marca[]
 * \param marca_len int
 * \param eColour colour[]
 * \param colour_len int
 * \param eServis servis[]
 * \param servis_len int
 * \return int (1) id ok - (0) if there is no place
 */

int eject_addJob(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eServis servis[], int servis_len, eClient client[], int client_len)
{
    int day, month, year;
    int flag= 0;

    system("cls");
    printf(">> Nuevo Trabajo ");
    int id_job = job_findNextId(job, job_len);

    if (id_job == -1) //Caso en que llega a la maxima cantidad de alquileres
        printf("\nNo hay mas Bacantes\n");

    else
    {
        int id_car = car_getIdInList(car, car_len, marca, marca_len, colour, colour_len, client, client_len);
        if (id_car != -1)
        {
            int id_servis = servis_getIdInList(servis, servis_len);
            if (id_servis != -1)
            {
                int id_client = client_getIdInList(client, client_len);
                if (id_client != -1)
                {
                    if(getValidDate(&day, &month, &year))
                    {
                        if (!flag && confirmation())
                        {
                            job_add(job, job_len, id_job, id_car, id_servis, day, month, year, id_client);
                            printf("\nTrabajo Agregado\n\n");
                            flag= 1;
                        }
                        else
                        {
                            printf("\nOperacion Cancelada\n\n");
                            flag= 0;
                        }
                    }
                    else
                        printf("\nFecha Ingresada Invalida\n");
                }
            }
            else
                printf("\nServicion No Encontrado");
        }
        else
            printf("\nAuto No Encontrado\n");
    }
    return flag;
}

/** \brief report all information necesary of Jobs - Cars - Servises
 * \param eJob job[]
 * \param job_len int
 * \param eCar car[]
 * \param car_len int
 * \param eMarca marca[]
 * \param marca_len int
 * \param eColour colour[]
 * \param colour_len int
 * \param eServis servis[]
 * \param servis_len int
 * \return void
 */

void eject_reports(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eServis servis[], int servis_len, eClient client[], int client_len)
{
    switch(reportsMain())
    {
    case 1:
        report_carsByColor(car, car_len, marca, marca_len, colour, colour_len, client, client_len);
        break;
    case 2:
        report_carsByMarca(job, job_len, car, car_len, marca, marca_len, colour, colour_len, client, client_len);
        break;
    case 3:
        report_jobByCar(job, job_len, car, car_len, marca, marca_len, colour, colour_len, servis, servis_len, client, client_len);
        break;
    case 4:
        report_carsWithoutJob(job, job_len, car, car_len, marca, marca_len, colour, colour_len, client, client_len);
        break;
    case 5:
        report_acumOfADetCar(job, job_len, car, car_len, marca, marca_len, colour, colour_len, servis, servis_len, client, client_len);
        break;
    case 6:
        report_popularServices(job, job_len, servis, servis_len);
        break;
    case 7:
        report_acumOfADetDate(job, job_len, servis, servis_len);
        break;
    case 8:
        report_carsByServis_Date(job, job_len, car, car_len, marca, marca_len, colour, colour_len, 20002, client, client_len);
        break;
    case 9:
        report_jobsByID_colourCars(job, job_len, car, car_len, servis, servis_len, client, client_len, 5001);
        break;
    case 10:
        report_acumByIdService(job, job_len, servis, servis_len, 20001);
        break;
    case 11:
        report_popularMarcasByServis(job, job_len, car, car_len, marca, marca_len, 20000);
        break;
    case 12:
        report_carsWithJobByDate(job, job_len, car, car_len, marca, marca_len, colour, colour_len, client, client_len);
        break;
    case 13:
        report_QuantityByMarcaColour(job, job_len, car, car_len, marca, marca_len, colour, colour_len, client, client_len);
        break;
    case 14:
        report_patentesByColour(car, car_len, marca, marca_len, client, client_len, 5002);
        break;
    case 15:
        report_carsByPatente(car, car_len, marca, marca_len, colour, colour_len, client, client_len);
        break;
    case 16:
        report_carsBySex(car, car_len, marca, marca_len, colour, colour_len, client, client_len);
        break;
    case 17:
        report_clientsByMarca(car, car_len, client, client_len, 1000);
        break;
    case 18:
        report_contByServisWoman(job, job_len, car, car_len, marca, marca_len, colour, colour_len, servis, servis_len, client, client_len);
        break;
    case 19://PROBLEM
        //report_popularMarcaByWoman(car, car_len, marca, marca_len, colour, colour_len, client, client_len);
        break;
    case 20:
        report_clientsByServis(job, job_len, client, client_len);
        break;
    case 21:
        break;
    default:
        printf("\nOpcion ingresada Invalida\n\n");
        break;
    }
}
