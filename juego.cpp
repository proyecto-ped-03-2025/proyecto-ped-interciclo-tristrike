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

