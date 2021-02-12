#ifndef REPORTS_H_INCLUDED
#define REPORTS_H_INCLUDED

#include "marca.h"
#include "colour.h"
#include "cars.h"
#include "servis.h"
#include "job.h"
#include "cliente.h"

int reportsMain();

int report_contBusyJobs(eJob job[], int len);

float report_acumBusyPrices(eJob job[], int job_len, eServis servis[], int servis_len);

float report_promPrices(eJob job[], int job_len, eServis servis[], int servis_len);

int report_contLessProm(eJob job[], int job_len, eServis servis[], int servis_len);

int report_contUpProm(eJob job[], int job_len, eServis servis[], int servis_len);

void report_carsInDetServis(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eServis servis[], int servis_len, eClient client[], int client_len);

void report_servicesInDetCar(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eServis servis[], int servis_len, eClient client[], int client_len);

void report_unpopularCars(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len);

void report_unpopularServices(eJob job[], int job_len, eServis servis[], int servis_len);

void report_popularCars(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marc_len, eColour colour[], int colour_len, eClient client[], int client_len);

void report_popularServices(eJob job[], int job_len, eServis servis[], int servis_len);

void report_servicesByDate(eJob job[], int job_len, eServis servis[], int servis_len);

void report_carsInDetDate(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marc_len, eColour colour[], int colour_len, eClient client[], int client_len);

void report_sortCarsByMarca_Patente(eCar car[], int car_len, eMarca marca[], int marca_len);

void report_sortCarsByColour_Patente(eCar car[], int car_len, eColour colour[], int colour_len);

void report_sortCarsByModelo_Marca(eCar car[], int car_len, eMarca marca[], int marca_len);

void report_sortCarsByModelo_Colour(eCar car[], int car_len, eColour colour[], int colour_len);

void report_carsByModelo(eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len);

void report_carsByColor(eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len);

void report_carsByMarca(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len);

void report_jobByCar(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eServis servis[], int servis_len, eClient client[], int client_len);

void report_acumOfADetCar(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eServis servis[], int servis_len, eClient client[], int client_len);

void report_carsByServis_Date(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, int idServis, eClient client[], int client_len);

void report_carsWithoutJob(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len);

void report_jobsByID_colourCars(eJob job[], int job_len, eCar car[], int car_len, eServis servis[], int servis_len, eClient client[], int client_len, int id_colour);

void report_carsWithJobByDate(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len);

void report_acumByIdService(eJob job[], int job_len, eServis servis[], int servis_len, int id_service);

void report_acumOfADetDate(eJob job[], int job_len,  eServis servis[], int servis_len);

void report_popularMarcasByServis(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, int id_service);

void report_QuantityByMarcaColour(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len);

void report_carsByPatente(eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len);

void report_carsBySex(eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len);

void report_clientsByMarca(eCar car[], int car_len, eClient client[], int client_len, int idMarca);

void report_contByServisWoman(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eServis servis[], int servis_len, eClient client[], int client_len);

void report_popularMarcaByWoman(eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len);

void report_clientsByServis(eJob job[], int job_len, eClient client[], int client_len);

void report_patentesByColour(eCar car[], int car_len, eMarca marca[], int marca_len, eClient client[], int client_len, int idColour);

void report_sortById(eCar car[], int car_len, eMarca marca[], int marca_len);



#endif // REPORTS_H_INCLUDED
