# CPP_modules 01

## Ex01 -> Zombie!

El objetivo de este ejercicio es practicar el uso de clases, la creación de nuevos objetos y la asignación de memoria.
Conceptos a tener en cuenta:
* **operador new->** Asigna dinámicamente memoria en el heap, creando un nuevo objeto en
heap y devuelve un puntero a él.
* **heap->** Es una región de memoria del sistema que se utiliza para la asignación de memoria dinámica de memoria. A diferencia de la pila(donde se almacenan las variables locales) el heap no tiene un orden de asignación y liberación de memoria específicopor lo que hay que liberar la memoria despues de su uso con el operador delete y establecer el puntero a nullptr.


### ¿Porqué crear objetos en la pila o en el heap?

Depende de las necesidades quie tengamos, aqui tenemos unas consideraciones específicas:

1. **Tiempo de vida**-> Los objetos creados en la pila se destruyen automáticamente cuando salen de su ámbito. Si necesitamos que un objeto sobreviva más alla del ámbito de la función deberíamos crearlos en el heap.
2. **Tamaño**-> La pila tiene un tamaño limitado (menor que el del heap). Si necesitamos crear un objeto grande o muchos objetos sería conveniente crearlos en el heap.
3. **Rendimiento**-> La asignación y liberación de memoria en la pila es mas rápida en la pila que en el heap, porque la pila solo necesita mover un puntero mientras que el heap necesita buscar un bloque de memoria suficientemente grande.
4. **Gestión de memoria**-> Los objetos creados en el heap deben ser eliminados manualmente con delete para evitar fugas de memoria mientras que los objetos en la pila se eliminan automáticamente y no hay que preocuparse por las fugas de memoria.