#include <iostream>
#include <vector>
#include "graph.h"

class DepthFirstSearch {
private:
    vector<bool> marked; // Array per marcare i nodi visitati
    Graph& graph;

    /**
     * Visita in profondità il grafo partendo da un nodo specifico.
     * @param graph Il grafo da visitare.
     * @param id Il nodo da cui partire.
     */
    void dfs(Graph& graph, int id) {
        marked[id] = true; // Marca il nodo in cui ci troviamo come visitato
        for (int node : graph.getNeighbours(id)) { // Per ogni nodo adiacente al nodo corrente
            if (!marked[node]) { // Se il nodo non è stato visitato, allora lo visita
                // cout << id << " -> " << node << ", ";
                dfs(graph, node);
            }
        }
    }

public:
    /**
     * Costruisce un oggetto DepthFirstSearch a partire da un grafo.
     * @param g Il grafo su cui eseguire la visita in profondità.
     */
    DepthFirstSearch(Graph& g) : graph(g), marked(g.size(), false) {}

    /**
     * Trova il numero di alberi presenti nel grafo non orientato.
     * @return Il numero di alberi presenti nel grafo.
     */
    int findTrees() {
        int trees = 0;

        // Verifica per tutti i nodi del grafo, se ci sono nodi non visitati (!marked[i])
        // allora incrementa il numero di alberi e chiama dfs() su quel nodo
        for (int i = 0; i < graph.size(); i++) {
            if (!marked[i]) {
                trees++;
                // cout << "Albero " << trees << " : ";

                dfs(graph, i);

                /* Nella stampa all'interno di dfs() non vengono considerati i nodi senza vicini percio' li stampa qui con un if
                int neighbours = graph.getNeighbours(i).size();
                if (neighbours == 0) {
                    cout << i;
                } else {
                    dfs(graph, i);
                }
                cout << endl; */
            }
        }
        return trees;
    }
};