#include <iostream>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

// Función para ingresar eventos
void ingresarEventos(map<string, string>& eventos) {
    string fecha, evento;
    char opcion;

    do {
        cout << "Ingrese la fecha (dd-mm-aaaa): ";
        cin >> fecha;
        cin.ignore(); // Ignorar el carácter de nueva línea residual

        cout << "Ingrese el evento: ";
        getline(cin, evento);

        eventos[fecha] = evento;

        cout << "¿Desea ingresar otro evento? (s/n): ";
        cin >> opcion;
    } while (opcion == 's' || opcion == 'S');
}

// Función para mostrar eventos almacenados
void mostrarEventos(const map<string, string>& eventos) {
    cout << "\nEventos almacenados:\n";
    for (const auto& par : eventos) {
        cout << "Fecha: " << par.first << " -> Evento: " << par.second << endl;
    }
}

int main() {
    map<string, string> eventos;

    ingresarEventos(eventos);
    mostrarEventos(eventos);

    return 0;
}
