#include <iostream>
#include <map>
#include <set>
#include <iomanip>
#include <vector>

using namespace std;

//Descomponer dia fecha y año
bool validarFecha(const string& fecha);
void ingresarEventos(map<string, string>& eventos);
void mostrarEventos(const map<string, string>& eventos);
void eliminarEvento(map<string, string>& eventos);


int main() {
    map<string, vector<string>> eventos;
    char opcion;

    do {
        cout << "Menú:\n";
        cout << "1. Ingresar evento\n";
        cout << "2. Mostrar eventos\n";
        cout << "3. Eliminar evento\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore(); 

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
        } else {
            if (diaInt <= 0) {
                cout << "El día debe ser mayor que 0.\n";
            }
            if (mesInt <= 0 || mesInt > 12) {
                cout << "El mes debe estar entre 1 y 12.\n";
            }
            return false;
        }
    } else {
        cout << "Formato de fecha incorrecto. Use dd-mm-aaaa.\n";
        return false;
    }
}

void ingresarEventos(map<string, vector<string>>& eventos) {
    string fecha, evento;
    char opcion, opcionMasEventos;

    do {
        do {
            cout << "Ingrese la fecha (dd-mm-aaaa): ";
            cin >> fecha;
            cin.ignore(); 
        } while (!validarFecha(fecha));

        do {
            cout << "Ingrese el evento: ";
            getline(cin, evento);

            eventos[fecha].push_back(evento);

            cout << "¿Desea agregar otro evento en la misma fecha? (s/n): ";
            cin >> opcionMasEventos;
            cin.ignore(); 
        } while (opcionMasEventos == 's' || opcionMasEventos == 'S');

        cout << "¿Desea ingresar un evento en otra fecha? (s/n): ";
        cin >> opcion;
        cin.ignore(); 
    } while (opcion == 's' || opcion == 'S');
}


void mostrarEventos(const map<string, vector<string>>& eventos) {
    cout << "\nEventos almacenados:\n";
    for (const auto& par : eventos) {
        cout << "Fecha: " << par.first << " -> Eventos: ";
        for (const auto& evento : par.second) {
            cout << evento << "; ";
        }
        cout <<endl;
    }
}

void eliminarEvento(map<string, vector<string>>& eventos) {
    string fecha, evento;

    cout << "Ingrese la fecha del evento a eliminar (dd-mm-aaaa): ";
    cin >> fecha;
    cin.ignore(); 

    if (!validarFecha(fecha)) {
        cout << "Fecha no válida.\n";
        return;
    }

    cout << "Ingrese el nombre del evento a eliminar: ";
    getline(cin, evento);

    auto it = eventos.find(fecha);
    if (it != eventos.end()) {
        auto& listaEventos = it->second;
        bool found = false;
        for (auto itEvento = listaEventos.begin(); itEvento != listaEventos.end(); ++itEvento) {
            if (*itEvento == evento) {
                listaEventos.erase(itEvento);
                found = true;
                break;
            }
        }
        if (found) {
            if (listaEventos.empty()) {
                eventos.erase(it);
            }
            cout << "Deleted successfully.\n";
        } else {
            cout << "Event not found.\n";
        }
    } else {
        cout << "Event not found.\n";
    }
}
