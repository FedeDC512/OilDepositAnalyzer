#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;

Graph::Graph(vector<vector<int>> mat) {
    // Riempie il vettore nodes con i dati dei nodi per sapere la loro posizione identificandoli
    size_t id = 0; 
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) { 
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

string Graph::getXY(size_t id) {
    auto node = nodes[id];
    return "(" + to_string(node->x) + "," + to_string(node->y) +")";
}

int Graph::size() {
    return nodes.size();
}

int Graph::getNodeId(size_t x, size_t y) {
    for (Node* n : nodes) {
        if (n->x == x && n->y == y) {
            return n->id;
        }
    }
    return -1;
}

void Graph::addEdge(size_t v, size_t u) {
    adjList[v].push_back(u);
}

vector<int> Graph::getNeighbours(size_t id) {
    return adjList[id];
}

void Graph::print() {
    cout << "Lista di adiacenza:" << endl;
    for (size_t i = 0; i < adjList.size(); i++) {
        cout << "Nodo[" << i << "]" << getXY(i) << " -> ";
        for (size_t j = 0; j < adjList[i].size(); j++) {
            int id = adjList[i][j];
            cout << "[" << id << "]" << getXY(id) << " - ";
        }
        cout << endl;
    }
}