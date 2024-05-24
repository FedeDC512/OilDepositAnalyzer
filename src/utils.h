#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * Legge un file e convertirlo in una matrice di interi.
 * @param file Il file da leggere.
 * @return La matrice di interi ottenuta dal file.
 * @throws runtime_error se si verifica un errore durante l'apertura del file.
 */
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
    int i = 0;
    while (i < cols) { 
        file >> line;
        for (int j = 0; j < line.size(); j++) {
            if (line[j] == '@') { // Se il carattere è '@' allora il valore è 1, altrimenti rimane 0
                mat[i][j] = 1;
            }
        }
        i++;
    }

    return mat;
}

/**
 * Crea una matrice casuale di dimensioni specificate.
 * @param rows Il numero di righe della matrice.
 * @param cols Il numero di colonne della matrice.
 * @return La matrice casuale creata.
 */
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

/**
 * Stampa una matrice di interi come una griglia di caratteri.
 * I valori 1 vengono rappresentati con il carattere "■", mentre i valori diversi da 1 vengono rappresentati con il carattere "□".
 * @param mat La matrice da stampare.
 */
void printMatrix(vector<vector<int>> mat) {
    for (int i = 0; i < mat.size(); i++) { 
        for (int j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] == 1) {
                cout << "■ ";
            } else {
                cout << "□ ";
            }
        }
        cout << endl;
    }
}