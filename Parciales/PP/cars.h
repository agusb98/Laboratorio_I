#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include "colour.h"
#include "marca.h"
#include "cars.h"
#include "cliente.h"

#define EMPTY 0
#define BUSY 1
#define DELETED -1

typedef struct{

    int id;
    char patente[8];
    int idMarca;
    int idColor;
    int modelo;
    int status;
    int idClient;

}eCar;

int car_init(eCar car[], int len);

void car_add(eCar car[], int len, int id, char patente[],int idMarca, int idColour,int modelo, int idClient);

int car_findEmptyPlace(eCar car[], int len);

int car_findEmptyId(eCar car[], int len);

void car_delete(eCar car[], int len, int id);

int findCarByPatente(eCar car[], int len, char patente[]);

int findCarById(eCar car[], int len, int id);

int findDeletedCarByPatente(eCar car[], int len, char patente[]);

int findDeletedCarById(eCar car[], int len, int id);

int car_getIdInList(eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int idClient);

int car_modificate(eCar car[], int len, int id, eColour colour[], int colour_len, eMarca marca[], int marca_len);

void car_hardcore(eCar y[]);

void printCars(eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int idClient);

void printCar (eCar car, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len);

int car_findPosArray (eCar car[], int len, int id);

int car_findNextId(eCar car[], int len);

int editCarMain();

#endif // CAR_H_INCLUDED

