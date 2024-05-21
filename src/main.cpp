#include <iostream>
#include <fstream>
#include "utils.h"

using namespace std;

struct Node {
    int x, y;
    Node* next;
};

int main() {
    ifstream input("input.txt");

    auto mat = parseFileToMatrix(input);

    cout << "Matrice letta dal file:" << endl;
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    // Step by step:
    // 1. Creo una lista di adiacenza per ogni nodo
    // 2. Per ogni nodo, controllo se ha nodi adiacenti ad esso e li inserisco nella sua lista di adiacenza
    // 3. Se il nodo è presente in una lista di adiacenza, allora non fare niente
    // 4. Se il nodo non è presente a nessuna delle liste di adiacenza, allora aggiungilo alla lista generale
    // 5. Conto il numero di elementi nella lista generale e ottengo il numero di giacimenti

    vector<Node*> adjList;
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] == 1) {
                Node* node = new Node{i, j, nullptr};
                Node* nodePtr = node;

                // I cicli for controllano i nodi adiacenti al nodo corrente
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        // Salta la posizione corrente
                        if (di == 0 && dj == 0) continue;

                        int ni = i + di, nj = j + dj;

                        // Controlla se la posizione è valida, cioè dentro la matrice
                        if (ni >= 0 && ni < mat.size() && nj >= 0 && nj < mat[i].size()) {
                            // Se il nodo adiacente contiene un 1, lo aggiunge alla lista di adiacenza
                            if (mat[ni][nj] == 1) {
                                Node* neighbor = new Node{ni, nj, nullptr};
                                //cout << "Aggiungo nodo (" << ni << ", " << nj << ") a (" << i << ", " << j << ")" << endl;
                                nodePtr->next = neighbor;
                                nodePtr = nodePtr->next;
                            }
                        }
                    }
                }
                adjList.push_back(node);
            }
        }
    }

    cout << endl << "Lista di adiacenza:" << endl;
    for (int i = 0; i < adjList.size(); i++) {
        Node* current = adjList[i];
        cout << "Nodo (" << current->x << ", " << current->y << "): ";
        while (current->next != nullptr) {
            current = current->next;
            cout << "(" << current->x << ", " << current->y << ") ";
        }
        cout << endl;
    }
}