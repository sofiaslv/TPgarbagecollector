## TPgarbagecollector
###Trabajo práctico - Programación 1 

**Implementación**
1- Definimos variables globales con las cuales vamos a trabajar a traves de todo el archivo garbage.c
1- La función *void init_gc(int max_mem)* iniccializa los vectores en NULL y las variables en 0, además se le asigna la memoria máxima a la variable local.
2- La función *int new_block(int sz, char name)* redimensiona los vectores cada vez que se le agrega un nuevo bloque, agregando un nuevo elemento al vector. Después actualiza las variables con su nueva dimensión y al bloque en cada posicion se le reserva la memoria ingresada por *int sz* 
3- La función *int resize(int block, int sz)* redimensiona un bloque especifico dentro del vector de bloques según la cantidad de memoria ingresada por *int sz*, verifica si el procedimiento esta bien, si es asi, guarda el nuevo bloque en la posicion del bloque a redimensionar, actualiza el tamaño en el vector de los tamaños y retorna OK, en caso de que no se haya podido redimensionar, retornará ERROR.
4- Por lo que entendimos, las referencias se utilizan para contar cuántas variables están utilizando un bloque de memoria en particular, entonces referencias estaba inicializado en 0 en cada elemento del vector y a medida que se llamaba la función, en *int add_reference(int block)* el contador incrementaba, si el identificador que se ingresaba no se encontraba dentro del vector, se imprime un aviso de error y se retorna ERROR.
5- En *int remove_reference(int block)* al remover una referencia significa que ya no se está utilizando la variable ya no se utiliza en ese bloque de memoria, cuando la referencia queda en cero significa que ese bloque de memoria no se esta utilizando, entonces se libera la memoria.
6- En *int cur_used_memory(void)* se crea una variable de memoria usada inicializada en 0, dentro de un for que recorre la cantidad de bloques en su vector, por cada bloque que no sea nulo se le suma el tamaño de ese bloque a la variable de memoria usada y se retorna esa cantidad.
7- en *int cur_available_memory()* se calcula la memoria disponible asignandole la memoria maxima a una variable y retandole la memoria usada.
8. Se libera toda la memoria en *int destroy_agent()*  eliminando la memoria de cada bloque dentro del vector de bloques y liberando la memoria de los vectores en general, se vuelve a "inicializar" todo y se confirma que la memoria este liberada.




