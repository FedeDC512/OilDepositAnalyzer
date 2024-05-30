#include <iostream>
#include <fstream>
#include <filesystem>
#include "utils/utils.h"
#include "graph/graph.h"
#include "dfs/dfs.h"

using namespace std;

int main() {
    #ifdef _WIN32
        string path = "..\\inputs\\"; // Windows path
    #else
        string path = "../inputs/"; // Unix or macOS path
    #endif

    int choice;
    cout << "Scegli un'opzione:\n1. Leggi file di esempio\n2. Usa un tuo file\n3. Crea una matrice casuale\n4. Esci\nScelta: ";
    cin >> choice;
    cout << endl;

    vector<vector<int>> mat;

    switch (choice) {
        case 1: {
            ifstream input(path + "example.txt");
            mat = parseFileToMatrix(input);
            break;
        }
        case 2: {
            cout << "File trovati:" << endl;
            for (const auto &entry : filesystem::directory_iterator(path)) { // Itera attraverso i file e le directory nella cartella specificata
                if (entry.is_regular_file()) { // Stampa il nome di ogni file/directory
                    cout << entry.path().filename() << endl;
                }
            }
            cout << "Quale file vuoi leggere?" << endl;
            string name;
            cin >> name;
            if (!filesystem::exists(path + name)) {
                cout << "File non trovato" << endl;
                return 1;
            }
            ifstream input(path + name);
            mat = parseFileToMatrix(input);
            break;
        }
        case 3: {
            int rows, cols;
            cout << "Di quante righe e colonne vuoi la matrice? (es. 5 5)" << endl;
            cin >> rows >> cols;
            if (rows < 1 || rows > 100 || cols < 1 || cols > 100) {
                cout << "Inserisci valori validi" << endl;
                return 1;
            }
            mat = createRandomMatrix(rows, cols);
            break;
        }
        default:
            return 1;
            break;
    }

    cout << "Regione di terreno:" << endl;
    printMatrix(mat);

    Graph graph(mat);
    cout << endl;
    graph.print(); // Stampa la lista di adiacenza
    cout << endl;

    DepthFirstSearch dfs(graph);
    int trees = dfs.findTrees();
    cout << endl << "Numero di giacimenti: " << trees << endl;
}