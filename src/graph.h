#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int x, y, id;
    Node* next;
};

class Graph {
private:
    vector<Node*> adjList; // TODO: meglio questo o un vector<vector<node/int>>

public:
    Graph(vector<vector<int>> mat) {
        int id = 0; 
        for (int i = 0; i < mat.size(); i++) { // Scorriamo le righe
            for (int j = 0; j < mat[i].size(); j++) { // Scorriamo le colonne
                if (mat[i][j] == 1) { // Se 
                    Node* node = new Node { i, j, id, nullptr }; // Creiamo un nodo con i dati
                    id++;
                    adjList.push_back(node); // Lo aggiungiamo alla lista di adiacenza
                }
            }
        }

        for (Node* n : adjList) {
            Node* nodePtr = n;
            // I cicli for controllano i nodi adiacenti al nodo corrente
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    // Salta la posizione corrente
                    if (di == 0 && dj == 0) continue;

                    int ni = n->x + di, nj = n->y + dj;

                    // Controlla se la posizione è valida, cioè dentro la matrice
                    if (ni >= 0 && ni < mat.size() && nj >= 0 && nj < mat[n->x].size()) {
                        // Se il nodo adiacente contiene un 1, lo aggiunge alla lista di adiacenza
                        if (mat[ni][nj] == 1) {
                            Node* neighbor = new Node { ni, nj, getNodeId(ni, nj), nullptr };
                            //cout << "Aggiungo nodo (" << ni << ", " << nj << ") a (" << i << ", " << j << ")" << endl;
                            nodePtr->next = neighbor;
                            nodePtr = nodePtr->next;
                        }
                    }
                }
            }
        }
    }

    int getNodeId(int x, int y) { // TODO: ottimizza con #algorithm
        for (Node* n : adjList) {
            if (n->x == x && n->y == y) {
                return n->id;
            }
        }
        return -1;
    }
    
    void printGraph() {
        cout << endl << "Lista di adiacenza:" << endl;
        for (int i = 0; i < adjList.size(); i++) {
            Node* current = adjList[i];
            cout << "Nodo[" << current->id << "](" << current->x << ", " << current->y << ") -> ";
            while (current->next != nullptr) {
                current = current->next;
                cout << "[" << current->id << "](" << current->x << ", " << current->y << ") - ";
            }
            cout << endl;
        }
    }
};