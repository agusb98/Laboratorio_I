#include "cars.h"
#include "servis.h"
#include "marca.h"
#include "fecha.h"
#include "marca.h"
#include "colour.h"

#ifndef INCLUDE_H_JOB
#define INCLUDE_H_JOB

#define DELETED -1
#define EMPTY 0
#define BUSY 1

typedef struct
{
    int id_job;
    int id_car;
    int id_servis;
    eFecha fecha;
    int status;
    int id_client;

}eJob;

int job_init(eJob job[], int len);

void job_add(eJob job[], int job_len, int id_job, int id_car, int id_servis, int day, int month, int year, int id_client);

int job_findNextId(eJob job[], int len);

int job_findEmptyPlace(eJob job[], int len);

int job_getIdInList(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eServis servis[], int servis_len, eClient client[], int client_len);

void job_hardcore(eJob y[]);

int findJobById(eJob job[], int len,int id);

int findJobByIdCar(eJob job[], int len,int id);

void printJob(eJob job, eCar car[], int car_len, eServis servis[], int servis_len, eClient client[], int client_len);

void printJobs(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eServis servis[], int servis_len, eClient client[], int client_len);

void job_hardcore(eJob y[]);

#endif // INCLUDE_H_JOBS

