#include <iostream>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

//Descomponer dia fecha y año
bool validarFecha(const string& fecha);
void ingresarEventos(map<string, string>& eventos);
void mostrarEventos(const map<string, string>& eventos);
void eliminarEvento(map<string, string>& eventos);

int main() {
    map<string, string> eventos;

    char opcion;

    do {
        std::cout << "Menú:\n";
        std::cout << "1. Ingresar evento\n";
        std::cout << "2. Mostrar eventos\n";
        std::cout << "3. Eliminar evento\n";
        std::cout << "4. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;
        std::cin.ignore(); // Ignorar el carácter de nueva línea residual

        switch (opcion) {
            case '1':
                ingresarEventos(eventos);
                break;
            case '2':
                mostrarEventos(eventos);
                break;
            case '3':
                eliminarEvento(eventos);
                break;
            case '4':
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción no válida.\n";
                break;
        }
    } while (opcion != '4');

    return 0;
}

bool validarFecha(const string& fecha) {
    istringstream iss(fecha);
    string dia, mes, anio;

    if (getline(iss, dia, '-') && getline(iss, mes, '-') && getline(iss, anio)) {
        
        int diaInt = stoi(dia);
        int mesInt = stoi(mes);
        
        if (diaInt > 0 && mesInt > 0 && mesInt <= 12) {
            return true;
        } 
        else {
            if (diaInt <= 0 || 31 <= diaInt) {
                cout << "El día debe estar entre 0 y 31.\n";
            }
            if (mesInt <= 0 || mesInt > 12) {
                cout << "El mes debe estar entre 1 y 12.\n";
            }
            return false;
        }
    } 
    else {
        cout << "Formato de fecha incorrecto. Use dd-mm-aaaa.\n";
        return false;
    }
}


void ingresarEventos(map<string, string>& eventos) {
    string fecha, evento;
    char opcion;

    do {
        do {
            cout << "Ingrese la fecha (dd-mm-aaaa): ";
            cin >> fecha;
            cin.ignore(); // Ignorar el carácter de nueva línea residual
        } while (!validarFecha(fecha));

        cout << "Ingrese el evento: ";
        getline(cin, evento);

        eventos[fecha] = evento;

        cout << "¿Desea ingresar otro evento? (s/n): ";
        cin >> opcion;
    } while (opcion == 's' || opcion == 'S');
}


void mostrarEventos(const map<string, string>& eventos) {
    cout << "\nEventos almacenados:\n";
    for (const auto& par : eventos) {
        cout << "Fecha: " << par.first << " -> Evento: " << par.second << endl;
    }
}

void eliminarEvento(map<string, string>& eventos) {
    string fecha, evento;

    cout << "Ingrese la fecha del evento a eliminar (dd-mm-aaaa): ";
    cin >> fecha;
    cin.ignore(); // Ignorar el carácter de nueva línea residual

    if (!validarFecha(fecha)) {
        cout << "Fecha no válida.\n";
        return;
    }

    cout << "Ingrese el nombre del evento a eliminar: ";
    getline(cin, evento);

    auto it = eventos.find(fecha);
    if (it != eventos.end() && it->second == evento) {
        eventos.erase(it);
        cout << "Deleted successfully.\n";
    } else {
        cout << "Event not found.\n";
    }
}