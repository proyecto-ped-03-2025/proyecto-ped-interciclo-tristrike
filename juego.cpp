#include <iostream>
#include <string>
using namespace std;
class Jugador {
private:
    string nombre;
    string id;
    int puntaje;
    Jugador* siguiente;

public:
    Jugador(string n, string i) {
        nombre = n;
        id = i;
        puntaje = 0;
        siguiente = nullptr;
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

    void setSiguiente(Jugador* sig) {
        siguiente = sig;
    }

    Jugador* getSiguiente() {
        return siguiente;
    }
};

class ListaCircular {
private:
    Jugador* primero;
    int cantidad;

public:
    ListaCircular() {
        primero = nullptr;
        cantidad = 0;
    }
void inscribir(string nombre, string id) {
    Jugador* nuevo = new Jugador(nombre, id);

    if (primero == nullptr) {
        primero = nuevo;
         primero->setSiguiente(primero); 
    } else {
        Jugador* temp = primero;
        while (temp->getSiguiente() != nullptr) {
            temp = temp->getSiguiente();
        }
        temp->setSiguiente(nuevo);
         nuevo->setSiguiente(primero);
    }

    cantidad++;
}

    
};

int main() {
    ListaCircular lista;
    int opcion;
    string nombre, id;

    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Inscribir jugador\n";
        cout << "0. Salir\n";
        cout << "Seleccione opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                cout << "Ingrese nombre: ";
                getline(cin, nombre);
                cout << "Ingrese ID: ";
                getline(cin, id);
                lista.inscribir(nombre, id);
                break;
        }

    } while (opcion != 0);

    return 0;
}
