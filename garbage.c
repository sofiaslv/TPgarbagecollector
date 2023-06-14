#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "garbage.h"

int** bloque;
int* tamaño;
int* referencia;
char** firma;
int cantidad;
int maxmemory;
int id;
void init_gc(int max_mem)
{
    maxmemory = max_mem;
    bloque = NULL;
    tamaño = NULL;
    referencia = NULL;
    firma = NULL;
    id = 0;
    cantidad = 0;
}


int new_block(int sz, char* name)
{
    int** redi_bloque = (int**)realloc(bloque, (cantidad+1)* sizeof(int*)); //Aca redimensiona el vector
    int* redi_tamaño = (int*)realloc(tamaño, (cantidad + 1) * sizeof(int));
    int* redi_referencias = (int*)realloc(referencia, (cantidad + 1) * sizeof(int));
    char** redi_firma = (char**)realloc(firma, (cantidad + 1) * sizeof(char*));

    if (redi_bloque == NULL || redi_tamaño == NULL || redi_referencias == NULL || redi_firma == NULL) {
        printf("ERROR: No se pudo asignar memoria para los bloques.\n");
        return ERROR;
    }


    bloque = redi_bloque;
    tamaño = redi_tamaño;
    referencia = redi_referencias;
    firma = redi_firma;

    bloque[cantidad] = malloc(sz * sizeof(int)); 
    if (bloque[cantidad] == NULL) 
    {
        printf("ERROR: No se pudo asignar memoria para el bloque %d.\n", cantidad);
        return ERROR;
    }

    tamaño[cantidad] = sz; 
    firma[cantidad] = name; 
    referencia[cantidad] = 0; 
    
    id++;
    cantidad++;

    return id;
}

int resize(int block, int sz)
{
    if (block < 0 || block > cantidad) 
    {
        printf("ERROR: Identificador de bloque inválido.\n");
        return ERROR;
    }

    int* nuevo_bloque = (int*)realloc(bloque[block], sz * sizeof(int));
    if (nuevo_bloque == NULL) {
        printf("ERROR: No se pudo redimensionar el bloque.\n");
        return ERROR;
    }

    bloque[block] = nuevo_bloque;
    tamaño[block] = sz;

    return OK;
}



int add_reference(int block)
{

    if (block < 0 || block >= cantidad) {
        printf("ERROR: Identificador de bloque inválido.\n");
        return ERROR;
    }

    referencia[block]++;
    printf("Referencia agregada al bloque %d. Referencias actuales: %d\n", block, referencia[block]);


    return OK;
}


int remove_reference(int block)
{
    if (block < 0 || block >= cantidad) {
        printf("ERROR: Identificador de bloque inválido.\n");
        return ERROR;
    }

    referencia[block]--;
    printf("Referencia removida del bloque %d. Referencias actuales: %d\n", block, referencia[block]);
    if (referencia[block] == 0)
    {
        free(bloque[block]);
        bloque[block] = NULL;
        tamaño[block] = 0
        if (bloque[block] == NULL)
        {
            printf("Se libero la memoria del bloque: %d\n", block);
            return OK;
        }
        else
        {
            printf("ERROR: No se libero la memoria del bloque: %d\n", block);
            return ERROR;
        }
    }
}


int cur_used_memory(void)
{
    int memoria_usada = 0;
    for (int i = 0; i < cantidad; i++) {
        if (bloque[i] != NULL) 
        {
            memoria_usada += tamaño[i];
        }
    }
    return memoria_usada;
}



int cur_available_memory()
{
    int available_mem = maxmemory;
    int used_memory = 0;
    for (int i = 0; i < cantidad; i++) {
        if (bloque[i] != NULL) 
        {
            used_memory += tamaño[i];
        }
    }
    available_mem -= used_memory;
    return available_mem;
}



int destroy_agent()
{
    for (int i = 0; i < cantidad; i++) {
        if (bloque[i] != NULL) {
            free(bloque[i]);
            bloque[i] = NULL;
            tamaño[i] = 0;
            referencia[i] = 0;
            firma[i] = NULL;
        }
    }

    free(bloque);
    free(tamaño);
    free(referencia);
    free(firma);

    bloque = NULL;
    tamaño = NULL;
    referencia = NULL;
    firma = NULL;
    cantidad = 0;
    maxmemory = 0;
    id = 0;

    if (bloque == NULL || tamaño == NULL || referencia == NULL || firma == NULL) {
        printf("Memoria liberada\n");
        return OK;
    }

}
