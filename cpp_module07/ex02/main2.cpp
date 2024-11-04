
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

#include "Array.hpp"

int main()
{
    Array<int> numbers(5);
    Array<int> numbers2(5);

    for (unsigned int i = 0; i < numbers.size(); i++)
    {
        numbers[i] = i;
        numbers2[i] = i + 10;
    }

    std::cout << numbers << std::endl;
    std::cout << numbers2 << std::endl;

    return 0;
}
