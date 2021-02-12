#ifndef SERVIS_H_INCLUDED
#define SERVIS_H_INCLUDED

typedef struct{

    int id;
    char description[26];
    float price;

}eServis;

#endif // SERVIS_H_INCLUDED

int servis_init(eServis servis[], int len);

int findServisById(eServis servis[], int len,int id);

int printServises(eServis clients[], int len);

void printServis(eServis servis);

int servis_getIdInList(eServis servis[], int len);

void servis_hardcore(eServis y[]);

int servis_getEncerado(eServis servis[], int len);
