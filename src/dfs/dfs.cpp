#include <iostream>
#include <vector>
#include "../graph/graph.h"
#include "dfs.h"

void DepthFirstSearch::dfs(int id) {
    marked[id] = true; // Marca il nodo in cui ci troviamo come visitato
    for (int node : graph.getNeighbours(id)) { // Per ogni nodo adiacente al nodo corrente
        if (!marked[node]) { // Se il nodo non è stato visitato, allora lo visita
            // cout << id << " -> " << node << ", ";
            dfs(node);
        }
    }
}

DepthFirstSearch::DepthFirstSearch(Graph& g) : marked(g.size(), false), graph(g) {}

int DepthFirstSearch::findTrees() {
    int trees = 0;

    // Verifica per tutti i nodi del grafo, se ci sono nodi non visitati (!marked[i])
    // allora incrementa il numero di alberi e chiama dfs() su quel nodo
    for (int i = 0; i < graph.size(); i++) {
        if (!marked[i]) {
            trees++;
            // cout << "Albero " << trees << " : ";

            dfs(i);

            /* Nella stampa all'interno di dfs() non vengono considerati i nodi senza vicini percio' li stampa qui con un if
            int neighbours = graph.getNeighbours(i).size();
            if (neighbours == 0) {
                cout << i;
            } else {
                dfs(i);
            }
            cout << endl; */
        }
    }
    return trees;
}