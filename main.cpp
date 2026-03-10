#include <iostream>
#include <random>

using namespace std;


// Constantes
const int MAX_NUMBER = 10;
const int MIN_NUMER = 1;

// Variáveis globais
vector<int> errors;

void mainMenu() {
    cout << "############################\n";
    cout << "#                          #\n";
    cout << "#     Adivinhe o numero    #\n";
    cout << "#                          #\n";
    cout << "############################\n";
    cout << "[1] Jogar\n\n";
}

void game(int pcNumber) {
    int playerChoice =0;
    bool winned = 0;

    while (winned == 0) {
        system("cls");
        int errorSize = sizeof(errors) / sizeof(errors[0]);
        
        cout << "Seus erros: ";

        if (errorSize >= 1) {
            for (int error : errors) {
                cout << "\n - " << error ;
            }

        } else {
            cout << "Nenhum erro";
        }

        cout << "\n" << pcNumber << "\n";
        cout << "\n\nSeu palpite: ";
        cin >> playerChoice;

        if (playerChoice == pcNumber) {
            cout << "Número correto!";
            winned = 1;
        } else {
            errors.push_back(playerChoice);
        }
    }

}

int main() {
    int option;

    while (true) {
        system("cls");
        mainMenu();

        cin >> option;

        switch (option) {
            case 1:
                int pcNumber = MIN_NUMER + rand() / (MAX_NUMBER - MIN_NUMER + 1);
                game(pcNumber);
                break;
        }
        cout << "\n";
        // system("pause");
    }

    
    return 0;
}