#ifndef EJECT_H_INCLUDED
#define EJECT_H_INCLUDED

char principalMain();

int eject_addCar(eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len);

int eject_deleteCar(eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len);

int eject_editCar(eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eClient client[], int client_len);

int eject_addJob(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eServis servis[], int servis_len, eClient client[], int client_len);

void eject_reports(eJob job[], int job_len, eCar car[], int car_len, eMarca marca[], int marca_len, eColour colour[], int colour_len, eServis servis[], int servis_len, eClient client[], int client_len);

#endif // EJECT_H_INCLUDED

