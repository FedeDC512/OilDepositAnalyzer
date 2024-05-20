#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct GraphNode {
    int x, y;
    GraphNode* next;
};

class Graph {
private:
    int numV = 0; // Numero di vertici
    int numE = 0; // Numero di archi
    vector<GraphNode> adjList; // Lista delle adiacenze

public:
    Graph(vector<vector<int>> input, int vxs) {
        numV = vxs;
        adjList = vector<GraphNode>(vxs);
        for (int i = 0; i < input.size(); i++) {
            for (int j = 0; j < input[i].size(); j++) {
                if (input[i][j] == 1) {
                    // Crea il primo nodo con i dati i e j
                    // Poi vede i suoi collegamenti, e li salva come next del Graphnode
                    // Infine salva nella con il pushback nel vector
                    GraphNode node = { i, j, nullptr };
                    adjList.push_back(node);
                    addEdge(&adjList[i], i, j);
                    numE++;
                }
            }
        }
    }

    void addEdge(GraphNode* node, int x, int y) {
        GraphNode newNode = { x, y, node };
        node = &newNode;
    }

    // Metodo per verificare se due vertici sono adiacenti
    bool isAdjacent(int v, int u) {
        return false;
    }

    // Metodo per ottenere i vicini di un nodo v
    vector<GraphNode> getNeighbors(int v) {
        vector<GraphNode> neighbors;
        GraphNode* current = &adjList[v];
        while (current != nullptr) {
            neighbors.push_back(*current);
            current = current->next;
        }
        return neighbors;
    }

    // Metodo per calcolare il grado di un nodo v
    int getDegree(GraphNode* node) {
        int len = 0;
        GraphNode* current = node;
        while (current != nullptr) {
            len++;
            current = current->next;
        }
        return len;
    }

    // Metodo per stampare il grafo
    void printGraph() {
        cout << "Ha " << numV << " vertici e " << numE << " archi" << endl;
        if (numE == 0) {
            cout << "Il grafo è vuoto." << endl;
            return;
        }
        // Stampo la lista delle adiacenze
        for (int i = 0; i < numV; i++) {
            GraphNode* current = &adjList[i];
            while (current != nullptr) {
                cout << "(" << current->x << ", " << current->y << ")";
                current = current->next;
            }
            cout << endl;
        }
    }
};