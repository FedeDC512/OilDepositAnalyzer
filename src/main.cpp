#include <iostream>
#include <fstream>
#include "utils.h"
#include "depthFirstSearch.h"

using namespace std;

int main() {
    ifstream input("input.txt");
    //ifstream input("C:\\Users\\fedea\\repos\\lab_alg_unipa\\src\\input.txt");

    int choice;
    cout << "Scegli un'opzione:\n1. Leggi da file\n2. Crea una matrice casuale\n3. Esci\nScelta: ";
    cin >> choice;

    vector<vector<int>> mat;

    switch (choice) {
        case 1:
            mat = parseFileToMatrix(input);
            break;
        case 2:
            int rows, cols;
            cout << "Di quante righe e colonne vuoi la matrice? (es. 5 5)" << endl;
            cin >> rows >> cols;
            if (rows < 1 || rows > 100 || cols < 1 || cols > 100) {
                cout << "Inserisci valori validi" << endl;
                return 1;
            }
            mat = createRandomMatrix(rows, cols);
            break;
        default:
            return 1;
            break;
    }

    cout << endl << "Regione di terreno:" << endl;
    printMatrix(mat);

    Graph graph(mat);
    //graph.print();

    DepthFirstSearch dfs(graph);
    int trees = dfs.findTrees(true);
    cout << endl << "Numero di giacimenti: " << trees << endl;
}