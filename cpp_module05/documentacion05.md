# cpp modules 05

## Ex 00 -> Mommy, I want to be a bureaucrat.

### Subject
Diseñemos una pesadilla artificial de oficinas, pasillos, formularios y colas de espera.
¿Suena divertido? ¿No? Qué lástima.
Primero, comience por el engranaje más pequeño de esta vasta máquina burocrática: el burócrata.
Un **burócrata** debe tener:
• Un nombre de constante.
• Y una calificación que va desde 1 (la calificación más alta posible) hasta 150 (la calificación más baja posible).
Cualquier intento de instanciar un burócrata utilizando una calificación no válida debe generar una excepción:
ya sea una **Bureaucrat::GradeTooHighException** o una **Bureaucrat::GradeTooLowException.**
5C++ - Módulo 05
Repetición y excepciones
Proporcionará captadores para ambos atributos: getName() y getGrade(). Implemente también dos funciones miembro para incrementar o decrementar la calificación del burócrata. Si
la calificación está fuera de rango, ambas arrojarán las mismas excepciones que el constructor.
Recuerde. Dado que la calificación 1 es la más alta y 150 la más baja,
incrementar una calificación 3 debería darle una calificación 2 al burócrata.
Las excepciones arrojadas deben poder capturarse mediante bloques try y catch:
try
{
/* hacer algunas cosas con burócratas */
}
catch (std::exception & e)
{
/* manejar excepción */
}
Implementará una sobrecarga del operador de inserción («) para imprimir algo como
(sin los corchetes angulares):
<nombre>, calificación del burócrata <calificación>.
Como siempre, entregue algunas pruebas para demostrar que todo funciona como se espera.