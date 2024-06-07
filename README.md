*PROBLEMA*
Me piden realizar un modelo de base de datos simple.
Para añadir, quitar, mostrar y buscar eventos junto a su fecha correspondiente, ambos datos seran ingresados por el usuario.
Ademas se pide que el programa debe ser eficiente y eficaz en comparacion a otros modelos.

*EXPLICACION DE BASE DE DATOS EXISTENTES, COMPARATIVA Y JUSTIFICACION DEL NUEVO DESARROLLO*
-Base de Datos Relacionales.- Aqui se organizan los datos en filas y columnas. Ahora bien es complejo el diseñar esquemas para datos no    estructurados
-Base de Datos NoSQL.- Diseñadas para manejar grandes cantidades de datos no estructurados y semiestructurados. Flexibles para manejar muchos   datos distribuidos y diversos tipos de datos. Pueden ser mas dificiles de usar y requieren mayor planificación antes de ejecutar el proyecto.   (clave-valor)
-Base de Datos en Memoria.- Estos almacenan los datos directamente en la RAM, por lo tanto nos proporciona un acceso rápido a los datos. Aunque tambien podemos perder todo si hubiera un fallo de energia, es un tipo de BD caro por que exige mas RAM.

Ofrezco este nuevo tipo de Base de Datos porque es un modelo SIMPLE, que se amolda a la necesidad de una base de datos ligera, rápida y facil de integrar al uso que se le quiera dar sin la sobrecarga de un modelo Relacional o la complejidad de un NoSQL, o los peligros que implican los que son en Memoria. Ademas que se tiene el control total de todas las funciones para añadir o quitar funcionalidades, asi mismo reajustar algunas a comodidad del cliente

*ESTRUCTURA DEL REPOSITORIO*

*DESCRIPCION(funciones, estructuras, etc..)*
Funciones Principales:
 -Agregar Evento.- Esta funcion nos permitira agregar un evento a una fecha ya conocida o una nueva fecha
 -Eliminar Evento.- Esta funcion nos pedira tanto una fecha como el nombre del evento para eliminarla una vez eliminado nos mostrara el mensaje de que se borro correctamente
 -Eliminar Eventos de la Misma Fecha.- Esta funcion solo nos pedira la fecha, y borrara todos los elementos contenidos en dicha fecha, asi mismo nos mostrara la cantidad de elementos que borro
 -Buscar Evento.- Esta funcion nos pedira una fecha y nos mostrara todos los eventos contenidos en esta fecha
 -Mostrar Evento.- Esta funcion se encarga de mostrarnos todas las fechas y eventos contenidas en nuestra base de datos 

*DIAGRAMA O PSEUDOCODIGO*

*CREDITOS*
Erwin Alejandro Ojeda Justiniano

*HERRAMIENTAS UTILIZADAS*
Visual Studio Code 
Git Bash 
Github
Gemini
Programarya(Pag Web con info de C++)