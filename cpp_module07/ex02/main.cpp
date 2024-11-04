
/*Desarrollar una plantilla de clase Array que contenga elementos de tipo T y que implemente
el siguiente comportamiento y funciones:
• Construcción sin parámetros: crea una matriz vacía.
• Construcción con un int sin signo n como parámetro: crea una matriz de n elementos
inicializada de forma predeterminada.
Consejo: intente compilar int * a = new int(); luego muestre *a.
• Construcción mediante el operador de copia y asignación. En ambos casos, modificar la matriz original o su copia después de copiar no debe afectar a la otra matriz.
• DEBE usar el operador new[] para asignar memoria. La asignación preventiva (asignar memoria por adelantado) está prohibida. Su programa nunca debe acceder a memoria no asignada.
• Se puede acceder a los elementos a través del operador de subíndice: [ ].
• Al acceder a un elemento con el operador [ ], si su índice está fuera de los límites, se lanza una
std::exception.
• Una función miembro size() que devuelve la cantidad de elementos en la matriz. Esta
función miembro no toma ningún parámetro y no debe modificar la instancia actual.
Como siempre, asegúrese de que todo funcione como se espera y envíe un archivo main.cpp que contenga sus pruebas..*/

#include <iostream>
#include "Array.hpp"
#include <ctime>
#include <cstdlib>


#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}
