#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "utils.h"

using namespace std;

vector<vector<int>> parseFileToMatrix(ifstream& file) {
    // Verifica se il file è stato aperto correttamente
    if (!file.is_open()) {
        throw runtime_error("Errore durante l'apertura del file");
    }
    
    int rows, cols;
    file >> rows >> cols;
    vector<vector<int>> mat(rows, vector<int>(cols, 0)); // Inizializza la matrice con 0

    if (rows < 1 || rows > 100 || cols < 1 || cols > 100) {
        cout << "I valori di righe e colonne nel file non sono validi" << endl;
        return mat;
    }

    // Legge il file linea per linea e lo converte in una matrice di interi
    string line;
    for (int i = 0; i < rows; i++) { 
        file >> line;
        for (int j = 0; j < cols; j++) {
            if (line[j] == '@') { // Se il carattere è '@' allora il valore è 1, altrimenti rimane 0
                mat[i][j] = 1;
            }
        }
    }

    return mat;
}

vector<vector<int>> createRandomMatrix(int rows, int cols) {
    vector<vector<int>> mat(rows, vector<int>(cols, 0)); // Inizializza la matrice con 0

    srand(time(0)); // Inizializza il generatore di numeri casuali

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i][j] = rand() % 2; // Genera un numero casuale tra 0 e 1
        }
    }

    return mat;
}

void printMatrix(vector<vector<int>> mat) {
    for (size_t i = 0; i < mat.size(); i++) { 
        for (size_t j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] == 1) {
                cout << "■ ";
            } else {
                cout << "□ ";
            }
        }
        cout << endl;
    }
}