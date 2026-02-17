#include <iostream>
#include <string>
using namespace std;


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
