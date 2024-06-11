#include <iostream>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;


bool validarFecha(const string& fecha);//Descomponer dia fecha y año
bool eventoExiste(const vector<string>& listaEventos, const string& evento);
void ingresarEventos(map<string, vector<string>>& eventos);
void mostrarEventos(const map<string, vector<string>>& eventos);
void eliminarEvento(map<string, vector<string>>& eventos);
void eliminarEventosPorFecha(map<string, vector<string>>& eventos);
void buscarEventosPorFecha(const map<string, vector<string>>& eventos);


int main() {
    map<string, vector<string>> eventos;
    string opcion;

    do {
        cout << "Menú:\n";
        cout << "1. Ingresar evento\n";
        cout << "2. Mostrar eventos\n";
        cout << "3. Eliminar evento\n";
        cout << "4. Eliminar todos los eventos de una fecha\n";
        cout << "5. Buscar eventos por fecha\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == "1" || opcion == "Add") {
            ingresarEventos(eventos);
        } else if (opcion == "2" || opcion == "Print") {
            mostrarEventos(eventos);
        } else if (opcion == "3") {
            eliminarEvento(eventos);
        } else if (opcion == "4") {
            eliminarEventosPorFecha(eventos);
        } else if (opcion == "5" || opcion == "Find") {
            buscarEventosPorFecha(eventos);
        } else if (opcion == "6") {
            std::cout << "Saliendo...\n";
        } else {
            std::cout << "Opción no válida.\n";
        }
    } while (opcion != "6");

    return 0;
}



bool validarFecha(const string& fecha) {
    istringstream iss(fecha);
    string anioStr, mesStr, diaStr;

    if (getline(iss, anioStr, '-') && getline(iss, mesStr, '-') && getline(iss, diaStr)) {
        try {
            int anio = stoi(anioStr);
            int mes = stoi(mesStr);
            int dia = stoi(diaStr);

            if (mes <= 0 || mes > 12) {
                cout << "Month value is invalid: " << mesStr << "\n";
                return false;
            }

            if (dia <= 0 || dia > 31) {
                cout << "Day value is invalid: " << diaStr << "\n";
                return false;
            }

            return true;
        } 
        catch (...) {
            cout <<"Wrong date format: "<<fecha<<"\n";
            return false;
        }
    } 
    else {
        cout << "Wrong date format: "<<fecha<<"\n";
        return false;
    }
}

string formatearFecha(int anio, int mes, int dia) {
    ostringstream newf;
    newf << setw(4) << setfill('0') << anio << "-"
        << setw(2) << setfill('0') << mes << "-"
        << setw(2) << setfill('0') << dia;
    return newf.str();
}

void ingresarEventos(map<string, vector<string>>& eventos) {
    string fechaEvento;
    char opcion;

    do {
        do {
            cout << "Add ";
            getline(cin, fechaEvento);

            istringstream iss(fechaEvento);
            string fecha, evento;

            int anio, mes, dia;

            iss >> anio;
            iss.ignore(1); 
            iss >> mes;
            iss.ignore(1); 
            iss >> dia;
            getline(iss, evento);

            fecha = formatearFecha(anio, mes, dia);

            if (validarFecha(fecha)) {
                auto& listaEventos = eventos[fecha];
                if (!eventoExiste(listaEventos, evento)) {
                    listaEventos.push_back(evento);
                } else {
                    continue;
                }
                break;
            }
        } while (true);

        cout << "¿Desea ingresar otro evento? (s/n): ";
        cin >> opcion;
        cin.ignore(); 
    } while (opcion == 's' || opcion == 'S');
}


void mostrarEventos(const map<string, vector<string>>& eventos) {
    for (const auto& par : eventos) {
        cout << par.first << " ";
        for (const auto& evento : par.second) {
            cout << evento <<endl;
        }
        cout <<endl;
    }
}

void eliminarEvento(map<string, vector<string>>& eventos) {
    string fechaEvento;
    
    cout << "Del ";
    getline(cin, fechaEvento);

    istringstream iss(fechaEvento);
    string fecha, evento;
    int anio, mes, dia;

    iss >> anio;
    iss.ignore(1); 
    iss >> mes;
    iss.ignore(1); 
    iss >> dia;
    getline(iss, evento);

    fecha = formatearFecha(anio, mes, dia);

    if (!validarFecha(fecha)) {
        cout << "Fecha no válida.\n";
        return;
    }

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


void eliminarEventosPorFecha(map<string, vector<string>>& eventos) {
    string fecha;
    int anio, mes, dia;

    cout << "Del ";
    cin >> anio >> mes >> dia;
    cin.ignore(); 
    fecha = formatearFecha(anio, mes, dia);

    if (!validarFecha(fecha)) {
        cout << "Fecha no válida.\n";
        return;
    }

    auto it = eventos.find(fecha);
    if (it != eventos.end()) {
        int eventosEliminados = it->second.size();
        eventos.erase(it);
        cout << "Deleted " << eventosEliminados << " events\n";
    } 
    else {
        cout << "Deleted 0 events\n";
    }
}

void buscarEventosPorFecha(const map<string, vector<string>>& eventos) {
    string fecha;

    cout << "Find ";
    cin >> fecha;
    cin.ignore(); 

    if (!validarFecha(fecha)) {
        cout << "Fecha no válida.\n";
        return;
    }

    auto it = eventos.find(fecha);
    if (it != eventos.end()) {
        vector<string> eventosOrdenados = it->second;
        sort(eventosOrdenados.begin(), eventosOrdenados.end()); // Ordenar eventos

        //cout << "Eventos en la fecha " << fecha << " (ordenados):\n";
        for (const auto& evento : eventosOrdenados) {
            cout << "- " << evento << endl;
        }
    } else {
        cout << "No se encontraron eventos en la fecha " << fecha << ".\n";
    }
}

bool eventoExiste(const vector<string>& listaEventos, const string& evento) {
    for (const auto& e : listaEventos) {
        if (e == evento) {
            return true;
        }
    }
    return false;
}