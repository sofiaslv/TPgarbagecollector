#include <stdio.h>
#include <stdlib.h>
#include "garbage.h"

/*
Hacer multiples arrays, tener un array de bloques, otro de punteros, y mantener todo sincronico o coherente, otro para identificadores, otro para instrucciones
Hacer 5 o 4 vectores por cada cosa que te pide:
    nombre de bloque tipo char
    numero de referencia tipo int
    puntero 
    cantidad de memoria


*/

//Declarar las variables del módulo

/**
 *Inicializacion del GC. Se indica cantidad de memoria.
 * @param max_mem cantidad de memoria que administrará el sistema
 * @pre max_mem número entero 
 * @returns 
*/
int init_gc(int max_mem)
{
    //TODO 
}

int new_block(int sz,char* name)//Creacion de un nuevo bloque de memoria.
{
    //TODO
}

int* mem_ptr(int block)//A donde esta apuntando la memoria    
{
    //TODO
}

int resize(int block, int sz)//Redimensionamiento de memoria. esto es con realloc    
{
    //TODO
}

int add_reference(int block)//Se agrega una referencia a un bloque de memoria existente.
{
    //TODO
}

int remove_reference(int block)//Se elimina una referencia a un bloque de memoria.
{
    //TODO
}

int cur_used_memory(void)//Calcula cuanta memoria queda
{
    //TODO
}

int cur_available_memory(void)//Calcula cuanta memoria queda disponible.
{
    //TODO
}


int destroy_agent()//Destructor del GC.
{
    //TODO
}