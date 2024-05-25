#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int x, y, id; // Coordinata x, coordinata y, ID del nodo
};

class Graph {
private:
    vector<Node*> nodes; // Lista dei nodi con le loro coordinate e id
    vector<vector<int>> adjList; // Lista di adiacenza

    /**
     * Restituisce le coordinate del nodo specificato.
     * @param id L'ID del nodo di cui trovare le coordinate.
     * @return Le coordinate del nodo specificato.
     */
    string getXY(int id) {
        auto node = nodes[id];
        return "(" + to_string(node->x) + "," + to_string(node->y) +")";
    }

public:
    /**
     * Costruisce un grafo non orientato a partire da una matrice di adiacenza.
     * @param mat La matrice di adiacenza.
     */
    Graph(vector<vector<int>> mat) {
        // Riempie il vettore nodes con i dati dei nodi per sapere la loro posizione identificandoli
        int id = 0; 
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) { 
                if (mat[i][j] == 1) { // Se il nodo contiene un 1
                    Node* node = new Node { i, j, id++ }; // Crea un nodo con i dati
                    nodes.push_back(node); // E lo aggiunge alla lista dei nodi
                }
            }
        }

        adjList.resize(nodes.size()); // Inizializza la lista di adiacenza

        for (Node* n : nodes) { // Riempie la lista di adiacenza
            for (int di = -1; di <= 1; di++) { // Controlla i nodi adiacenti al nodo corrente
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) continue; // Salta la posizione corrente

                    int ni = n->x + di, nj = n->y + dj; // Calcola la posizione del nodo adiacente

                    if (ni >= 0 && ni < mat.size() && nj >= 0 && nj < mat[n->x].size()) { // Controlla se la posizione è valida, cioè dentro la matrice
                        if (mat[ni][nj] == 1) { // Se il nodo adiacente contiene un 1, lo aggiunge alla lista di adiacenza
                            addEdge(n->id, getNodeId(ni, nj));
                        }
                    }
                }
            }
        }
    }

    /**
     * Restituisce la dimensione del grafo.
     * @return La dimensione del grafo.
     */
    int size() {
        return nodes.size();
    }

    /**
     * Restituisce l'ID del nodo corrispondente alle coordinate specificate.
     * @param x La coordinata x del nodo.
     * @param y La coordinata y del nodo.
     * @return L'ID del nodo corrispondente alle coordinate specificate, o -1 se non viene trovato alcun nodo corrispondente.
     */
    int getNodeId(int x, int y) {
        for (Node* n : nodes) {
            if (n->x == x && n->y == y) {
                return n->id;
            }
        }
        return -1;
    }

    /**
     * Aggiunge il nodo `u` alla lista di adiacenza di `v`.
     * @param v L'ID del nodo di partenza.
     * @param u L'ID del nodo di arrivo.
     */
    void addEdge(int v, int u) {
        adjList[v].push_back(u);
    }

    /**
     * Restituisce i nodi adiacenti al nodo specificato.
     * @param id L'ID del nodo di cui trovare i vicini.
     * @return Il vettore di nodi adiacenti al nodo specificato.
     */
    vector<int> getNeighbours(int id) {
        return adjList[id];
    }
    
    /**
     * Stampa la lista di adiacenza.
     */
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