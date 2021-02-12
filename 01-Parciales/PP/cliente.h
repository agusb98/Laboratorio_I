#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{

    int id;
    int id_auto;
    char name[51];
    char sex[3];

}eClient;

int findClientById(eClient client[], int len,int id);

int findClientByIdCar(eClient client[], int len,int id);

int printClients(eClient client[], int len);

void printClient(eClient x);

int client_getIdInList(eClient client[], int len);

void client_hardcore(eClient y[]);

#endif // CLIENTE_H_INCLUDED
