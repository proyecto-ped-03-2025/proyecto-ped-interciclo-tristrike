#include <iostream>
#include <string>
using namespace std;

class Jugador {
private:
    string nombre;
    string id;
    int puntaje;

public:
    Jugador(string n, string i) {
        nombre = n;
        id = i;
        puntaje = 0;
    }

    string getNombre() {
        return nombre;
    }

    string getID() {
        return id;
    }

    int getPuntaje() {
        return puntaje;
    }

    void sumarPunto(int p) {
        puntaje += p;
    }
class ListaCircular {
    private:
    Jugador* primero;
    int cantidad;

    public:
    ListaCircular() {
        primero = nullptr;
        cantidad = 0;
    }
};

};
int main() {
    int opcion;
    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Inscribir jugador\n";
        cout << "0. Salir\n";
        cout << "Seleccione opcion: ";
        cin >> opcion;
    } while (opcion != 0);

    return 0;
}
