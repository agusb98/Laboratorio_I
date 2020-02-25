#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"
#include "marca.h"
#include "colour.h"
#include "cars.h"
#include "servis.h"
#include "job.h"
#include "eject.h"
#include "reports.h"
#include "cliente.h"

#define CAR_CUANTITY 1000
#define SERVIS_CUANTITY 5
#define COLOUR_CUANTITY 5
#define MARCA_CUANTITY 5
#define CLIENT_CUANTITY 22
#define JOB_CUANTITY SERVIS_CUANTITY * CAR_CUANTITY

int main()
{
    int exit = 0, statusCar = 1, statusJob = 1; //Banderas

    //DECLARACION E INICIALIZACION DEL VECTOR AUTOS:
    eCar car[CAR_CUANTITY];
    car_init(car,CAR_CUANTITY);

    //DECLARACION DE SERVICIOS, COLORES, MARCAS Y CLIENTES:
    eServis servis[SERVIS_CUANTITY];
    eColour colour[COLOUR_CUANTITY];
    eMarca marca[CAR_CUANTITY];
    eClient client[CLIENT_CUANTITY];

    //DECLARACION E INICIALIZACION DE TRABAJOS:
    eJob job[JOB_CUANTITY];
    job_init(job,JOB_CUANTITY);

    //HARCODEO DE AUTOS MARCAS, COLORES, SERVICIOS, TRABAJOS Y CLIENTES:
    car_hardcore(car);
    marca_hardcore(marca);
    colour_hardcore(colour);
    servis_hardcore(servis);
    job_hardcore(job);
    client_hardcore(client);

    do
    {
        switch(principalMain())
        {
        case 'A':
            if (eject_addCar(car,CAR_CUANTITY, marca, MARCA_CUANTITY, colour, COLOUR_CUANTITY, client, CLIENT_CUANTITY))
                statusCar = 1; //bandera indicando que se ingreso al menos un auto
            break;
        case 'B':
            if (statusCar)
                eject_editCar(car,CAR_CUANTITY, marca, MARCA_CUANTITY, colour, COLOUR_CUANTITY, client, CLIENT_CUANTITY);
            else
                printf("Ingrese al menos un Auto\n\n");
            break;
        case 'C':
            if (statusCar)
                eject_deleteCar(car,CAR_CUANTITY, marca, MARCA_CUANTITY, colour, COLOUR_CUANTITY, client, CLIENT_CUANTITY);
            else
                printf("Ingrese al menos un Auto\n\n");
            break;
        case 'D':
            if (statusCar)
            {
                system("cls");
                report_sortCarsByMarca_Patente(car,CAR_CUANTITY, marca, MARCA_CUANTITY);
                printCars(car,CAR_CUANTITY, marca, MARCA_CUANTITY, colour, COLOUR_CUANTITY, client, CLIENT_CUANTITY);
            }
            else
                printf("Ingrese al menos un Auto\n\n");
            break;
        case 'E':
            system("cls");
            printMarcas(marca,MARCA_CUANTITY);
            break;
        case 'F':
            system("cls");
            printColours(colour,COLOUR_CUANTITY);
            break;
        case 'G':
            system("cls");
            printServises(servis,SERVIS_CUANTITY);
            break;
        case 'H':
            if (statusCar) //bandera indicando que se ingreso al menos un trabajo
            {
                eject_addJob(job, JOB_CUANTITY, car, CAR_CUANTITY, marca, MARCA_CUANTITY, colour, COLOUR_CUANTITY, servis, SERVIS_CUANTITY, client, CLIENT_CUANTITY);
                statusJob = 1;
            }
            else
                printf("\nIngrese al menos un Auto\n\n");
            break;
        case 'I':
            if (statusJob)
            {
                system("cls");
                printJobs(job, JOB_CUANTITY, car, CAR_CUANTITY, marca, MARCA_CUANTITY, colour, COLOUR_CUANTITY, servis, SERVIS_CUANTITY, client, CLIENT_CUANTITY);
            }
            else
                printf("\nIngrese al menos un Trabajo\n\n");
            break;
        case 'J':
            if (statusJob && statusCar)
                eject_reports(job, JOB_CUANTITY, car, CAR_CUANTITY, marca, MARCA_CUANTITY, colour, COLOUR_CUANTITY, servis, SERVIS_CUANTITY, client, CLIENT_CUANTITY);
            else
                printf("\nIngrese al menos un Trabajo\n\n");
            break;
        case 'S':
            exit = 1;
            break;
        default:
            printf("\nOpcion Invalida\n\n");
            break;
        }
        system("pause");
    }
    while(!exit);

    return 0;
}
