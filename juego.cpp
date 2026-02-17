#include <iostream>
#include <string>
#include <ctime>
using namespace std;
string convertirJugada(int num) {
    if (num == 1) return "Piedra";
    if (num == 2) return "Papel";
    else return "Tijera";
}
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
    void mostrarJugadores() {   
        if (primero == nullptr) {
            cout << "No hay jugadores inscritos.\n";
            return;
        }

        Jugador* temp = primero;
        do {
            cout << "Jugador: " << temp->getNombre()
                 << " | ID: " << temp->getID()
                 << " | Puntaje: " << temp->getPuntaje() << endl;
            temp = temp->getSiguiente();
        } while (temp != primero);
    }
void realizarJuego() {

    if (cantidad < 2) {
        cout << "No hay suficientes jugadores\n";
        return;
    }

    srand(time(0));

    Jugador* actual = primero;

    while (actual != nullptr) {

        Jugador* rival = actual->getSiguiente();

        while (rival != nullptr) {

            int j1 = rand() % 3 + 1;
            int j2 = rand() % 3 + 1;

            cout << actual->getNombre() << " saco "
                 << convertirJugada(j1) << endl;

            cout << rival->getNombre() << " saco "
                 << convertirJugada(j2) << endl;

            if (j1 == j2) {
                cout << "Empate\n";
                actual->sumarPunto(1);
                rival->sumarPunto(1);
            }
            else if ((j1 == 1 && j2 == 3) ||
                     (j1 == 2 && j2 == 1) ||
                     (j1 == 3 && j2 == 2)) {

                cout << "Gana " << actual->getNombre() << endl;
                actual->sumarPunto(3);
            }
            else {
                cout << "Gana " << rival->getNombre() << endl;
                rival->sumarPunto(3);
            }

            rival = rival->getSiguiente();
        }

        actual = actual->getSiguiente();
    }
}

    
};

int main() {
    ListaCircular lista;
    int opcion;
    string nombre, id;

    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Inscribir jugador\n";
        cout << "2. Mostrar jugadores\n";
        cout << "3. Realizar juego\n";
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
                case 2:
                lista.mostrarJugadores();
                 break;
                 case 3:
                 lista.realizarJuego();
                  break;


        }

    } while (opcion != 0);

    return 0;
}
