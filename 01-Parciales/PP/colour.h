#ifndef INCLUDE_H_COLOUR
#define INCLUDE_H_COLOUR

typedef struct
{
    int id;
    char name[21];

}eColour;

int colour_init(eColour colour[], int len);

int colour_getIdInList(eColour colour[], int len);

int removeColour(eColour colour[], int len, int id);

int findColourById(eColour colour[], int len,int id);

void printColour(eColour colour);

void printColours(eColour colour[], int len);

void colour_hardcore(eColour y[]);

#endif // INCLUDE_H_COLOURS

