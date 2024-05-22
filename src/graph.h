#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int x, y, id;
};

class Graph {
private:
    vector<Node*> nodes;
    vector<vector<int>> adjList; // TODO: meglio questo o un vector<Node*> con liste

public:
    Graph(vector<vector<int>> mat) {
        // Riempiamo il vettore nodes con i dati dei nodi per sapere la loro posizione identificandoli
        int id = 0; 
        for (int i = 0; i < mat.size(); i++) { // Scorriamo le righe
            for (int j = 0; j < mat[i].size(); j++) { // Scorriamo le colonne
                if (mat[i][j] == 1) { // Se 
                    Node* node = new Node { i, j, id++ }; // Creiamo un nodo con i dati
                    nodes.push_back(node); // Lo aggiungiamo alla lista di adiacenza
                }
            }
        }

        // Inizializziamo la lista di adiacenza
        adjList.resize(nodes.size());

        // Riempiamo la lista di adiacenze
        for (Node* n : nodes) {
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
                            addEdge(n->id, getNodeId(ni, nj));
                        }
                    }
                }
            }
        }
    }

    int size() {
        return nodes.size();
    }

    int getNodeId(int x, int y) { // TODO: ottimizza con #algorithm
        for (Node* n : nodes) {
            if (n->x == x && n->y == y) {
                return n->id;
            }
        }
        return -1;
    }

    void addEdge(int v, int u){
        adjList[v].push_back(u);
    }

    vector<int> getNeighbours(int id) {
        return adjList[id];
    }

    string getXY(int id) {
        auto node = nodes[id];
        return "(" + to_string(node->x) + "," + to_string(node->y) +")";
    }
    
    void print() {
        cout << "Lista di adiacenza:" << endl;
        for (int i = 0; i < adjList.size(); i++) {
            cout << "Nodo[" << i << "]" << getXY(i) << " -> ";
            for (int j = 0; j < adjList[i].size(); j++) {
                int id = adjList[i][j];
                cout << "[" << id << "]" << getXY(id) << " - ";
            }
            cout << endl;
        }
    }
};