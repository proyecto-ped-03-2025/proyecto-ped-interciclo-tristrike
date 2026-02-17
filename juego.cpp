#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <limits>

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

    void setSiguiente(Jugador* sig) {
        siguiente = sig;
    }

    Jugador* getSiguiente() {
        return siguiente;
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
            while (temp->getSiguiente() != primero) {
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

    int jugarRonda(int j1, int j2) {
        if (j1 == j2) return 0;
        if ((j1 == 1 && j2 == 3) ||
            (j1 == 2 && j2 == 1) ||
            (j1 == 3 && j2 == 2))
            return 1;
        return 2;
    }

    void realizarJuego() {
        if (cantidad < 2) {
            cout << "Se necesitan al menos 2 jugadores.\n";
            return;
        }

        srand(time(0));
        Jugador* actual = primero;

        do {
            Jugador* rival = actual->getSiguiente();

            while (rival != primero) {

                cout << "\nTurno de: " << actual->getNombre()
                     << " (ID: " << actual->getID() << ")\n";

                int jugada1 = rand() % 3 + 1;
                cout << "Numero obtenido: " << jugada1 << endl;
                cout << "Jugada: " << convertirJugada(jugada1) << endl;

                cout << "\nPresione ENTER para continuar...";
                cin.get();
                system("cls");

                cout << "\nTurno de: " << rival->getNombre()
                     << " (ID: " << rival->getID() << ")\n";

                int jugada2 = rand() % 3 + 1;
                cout << "Numero obtenido: " << jugada2 << endl;
                cout << "Jugada: " << convertirJugada(jugada2) << endl;

                cout << "\nPresione ENTER para ver resultado...";
                cin.get();
                system("cls");

                cout << actual->getNombre() << " jugo: "
                     << convertirJugada(jugada1) << endl;

                cout << rival->getNombre() << " jugo: "
                     << convertirJugada(jugada2) << endl;

                int resultado = jugarRonda(jugada1, jugada2);

                if (resultado == 0) {
                    cout << "\nResultado: Empate\n";
                    actual->sumarPunto(1);
                    rival->sumarPunto(1);
                } 
                else if (resultado == 1) {
                    cout << "\nResultado: Gana "
                         << actual->getNombre() << endl;
                    actual->sumarPunto(3);
                } 
                else {
                    cout << "\nResultado: Gana "
                         << rival->getNombre() << endl;
                    rival->sumarPunto(3);
                }

                cout << "\nPresione ENTER para continuar...";
                cin.get();
                system("cls");

                rival = rival->getSiguiente();
            }

            actual = actual->getSiguiente();

        } while (actual != primero);
    }
};

  void mostrarGanador() {
        if (primero == nullptr) {
            cout << "No hay jugadores.\n";
            return;
        }

        Jugador* temp = primero;
        Jugador* ganador = primero;

        do {
            if (temp->getPuntaje() > ganador->getPuntaje()) {
                ganador = temp;
            }
            temp = temp->getSiguiente();
        } while (temp != primero);

        cout << "\n🏆 Ganador: " << ganador->getNombre()
             << " (ID: " << ganador->getID() << ")"
             << " con " << ganador->getPuntaje()
             << " puntos.\n";
    }
};

void ayuda() {
    cout << "\n===== AYUDA =====\n";
    cout << "1. Inscribe a los jugadores con su nombre y un ID.\n";
    cout << "2. Verifica el listado de los jugadores inscritos.\n";
    cout << "3. Comienza a realizar el juego que es un todos contra todos.\n";
    cout << "4. Muestra el ganador del juego.\n";
}

int main() {
    ListaCircular lista;
    int opcion;
    string nombre, id;

    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Inscribir jugador\n";
        cout << "2. Mostrar jugadores\n";
        cout << "3. Realizar juego\n";
        cout << "4. Mostrar ganador\n";
        cout << "5. Ayuda\n";
        cout << "7. Salir\n";
        cout << "Seleccione opcion: ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
            case 4;
                lista.mostrarGanador();
                break;
            case 5;
              ayuda();
              break;
        }

    } while (opcion != 6);

    return 0;
}
