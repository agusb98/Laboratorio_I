#ifndef peliculas_h_INCLUDED
#define peliculas_h_INCLUDED

#endif

typedef struct
{
    int id;
    char titulo[200];
    int anio;
    char categoria[200];

}ePelicula;

ePelicula* _new();
LinkedList* depurarPeliculas (LinkedList* this);
ePelicula* _setters(char* var_1, char* var_2, char* var_3, char* var_4);

int _getters(ePelicula* this, int* var_1, char* var_2, int* var_3, char* var_4);

int _setId(ePelicula* this,int id);
int _getId(ePelicula* this,int* id);

int _setTitulo(ePelicula* this,char* titulo);
int _getTitulo(ePelicula* this,char* titulo);

int _setAnio(ePelicula* this,int anio);
int _getAnio(ePelicula* this,int* anio);

int _setCategoria(ePelicula* this,char* categoria);
int _getCategoria(ePelicula* this,char* categoria);

int _sortById(void* datoA, void* datoB);
int _sortByNombre(void* punteroA, void* punteroB);

int _show(ePelicula* this);
int filterByCategoria (void* this, void* aux);



