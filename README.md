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
Mi repositorio consta de un README que explica todo lo que contiene mi codigo, y una carpeta llamada CODE donde se encuentra el codigo y el ejecutable de dicho programa

*DESCRIPCION(funciones, estructuras, etc..)*
Funciones Principales:
 -Agregar Evento.- Esta funcion nos permitira agregar un evento y una fecha, primero validara la fecha, luego verificara si el evento que ingreso esta o no repetido, si no esta lo agregara y si estuviera repetido simplemente no lo agrega 
 -Eliminar Evento.- Esta funcion nos pedira tanto una fecha como el nombre del evento, primero validara la fecha, luego empezara a buscar en todos los eventos de esa fecha si encuentra el que ingreso el usuario, si lo encuentra lo borrara y devolvera la fecha sin ese evento, si en caso la fecha tuviera un solo evento eliminara la fecha mas, y luego mostrara un mensaje de que la operacion se realizo con exito
 -Eliminar Eventos de la Misma Fecha.- Esta funcion solo nos pedira la fecha y la validara, luebo buscara la fecha en eventos, y despues borrara los eventos, contando y mostrando la cantidad de eventos que borro.
 -Buscar Evento.- Esta funcion nos pedira una fecha primero validara la fecha, luego con el algoritmo sort nos mostrara los eventos contenidos en dicha fecha de forma ordenada.
 -Mostrar Evento.- Esta funcion se encarga de mostrarnos todas las fechas y eventos contenidas en nuestra base de datos 

 -Validar fecha.- Primero nuestra fecha la dividira en tres string y luego cada string la volvera entero haciendola anio mes dia segun corresponda, y verificara si esta dentro de rango
 -Evento Existe.- Agarra la lista de eventos y el evento que ingreso el usuario, y empieza a comparar cada evento de la lista de evento con el que dio el usuario, si llegase a ser igual devolvera verdad dando a entender que ese evento ya existe

 -Formatear Fecha.- Lo que hace es que nos devolvera la fecha ingresada por el usuario pero rellenada con 0 si lo fuera necesario, para cumplir el modelo aaaa-mm-dd

*DIAGRAMA O PSEUDOCODIGO*

Funcion validarFecha(fecha)
    Inicializar variables anioStr, mesStr, diaStr
    Dividir fecha en anioStr, mesStr, diaStr usando '-' como delimitador
    Intentar convertir anioStr, mesStr, diaStr a enteros
        Si mes es <= 0 o > 12, imprimir "Month value is invalid: mesStr"
        Si dia es <= 0 o > 31, imprimir "Day value is invalid: diaStr"
        Retornar verdadero si todo es válido
    Si hay una excepción, imprimir "Wrong date format: fecha"
    Retornar falso

Funcion formatearFecha(anio, mes, dia)
    Convertir anio, mes, dia a cadena con ceros a la izquierda (aaaa-mm-dd)
    Retornar la cadena formateada

Funcion eventoExiste(listaEventos, evento)
    Para cada e en listaEventos
        Si e es igual a evento, retornar verdadero
    Retornar falso

Funcion ingresarEventos(eventos)
    Inicializar variables fechaEvento, opcion
    Hacer
        Hacer
            Pedir al usuario que ingrese fecha y evento en formato "aaaa-mm-dd evento"
            Leer fechaEvento
            Dividir fechaEvento en anio, mes, dia, y evento
            Formatear fecha usando formatearFecha(anio, mes, dia)
            Si la fecha es válida
                Si evento no existe en eventos[fecha], agregar evento
                Salir del bucle
        Hasta que la fecha sea válida
        Preguntar al usuario si desea ingresar otro evento (s/n)
        Leer opcion
    Mientras opcion sea 's' o 'S'

Funcion mostrarEventos(eventos)
    Para cada par en eventos
        Imprimir fecha y eventos correspondientes

Funcion eliminarEvento(eventos)
    Inicializar variables fechaEvento, anio, mes, dia, evento
    Pedir al usuario que ingrese fecha y evento a eliminar en formato "aaaa-mm-dd evento"
    Leer fechaEvento
    Dividir fechaEvento en anio, mes, dia, y evento
    Formatear fecha usando formatearFecha(anio, mes, dia)
    Si la fecha es válida
        Buscar fecha en eventos
        Si fecha existe
            Si evento existe en lista de eventos, eliminar evento
            Si la lista de eventos está vacía, eliminar fecha de eventos
            Imprimir "Deleted successfully"
        Si no, imprimir "Event not found"
    Si no, imprimir "Fecha no válida"

Funcion eliminarEventosPorFecha(eventos)
    Inicializar variables fecha, anio, mes, dia
    Pedir al usuario que ingrese fecha en formato "aaaa-mm-dd"
    Leer anio, mes, dia
    Formatear fecha usando formatearFecha(anio, mes, dia)
    Si la fecha es válida
        Buscar fecha en eventos
        Si fecha existe, eliminar todos los eventos y contar cuántos fueron eliminados
            Imprimir "Deleted n events"
        Si no, imprimir "Deleted 0 events"
    Si no, imprimir "Fecha no válida"

Funcion buscarEventosPorFecha(eventos)
    Inicializar variable fecha
    Pedir al usuario que ingrese fecha en formato "aaaa-mm-dd"
    Leer fecha
    Si la fecha es válida
        Buscar fecha en eventos
        Si fecha existe
            Ordenar lista de eventos de forma ascendente
            Imprimir lista de eventos ordenada
        Si no, imprimir "No se encontraron eventos en la fecha"
    Si no, imprimir "Fecha no válida"

// Función principal
map<string, vector<string>> eventos
string opcion

Hacer
    Mostrar menú
    Leer opcion
    Si opcion es "1" o "Add", llamar a ingresarEventos(eventos)
    Si opcion es "2" o "Print", llamar a mostrarEventos(eventos)
    Si opcion es "3", llamar a eliminarEvento(eventos)
    Si opcion es "4", llamar a eliminarEventosPorFecha(eventos)
    Si opcion es "5" o "Find", llamar a buscarEventosPorFecha(eventos)
    Si opcion es "6", imprimir "Saliendo..."
    Si no, imprimir "Opción no válida"
Mientras opcion no sea "6"


*CREDITOS*
Erwin Alejandro Ojeda Justiniano

*HERRAMIENTAS UTILIZADAS*
Visual Studio Code 
Git Bash 
Github
Gemini
Youtube
Programarya(Pag Web con info de C++)