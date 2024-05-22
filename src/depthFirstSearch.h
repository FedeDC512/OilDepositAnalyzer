#include <iostream>
#include <vector>
#include "graph.h"

class DepthFirstSearch {
private:
    vector<bool> marked; // Array per marcare i nodi visitati
    vector<int> edgeTo; // Array per tenere traccia degli archi usati per raggiungere i nodi
    int trees = 0;

    void dfs(Graph& graph, int id) {
        marked[id] = true;
        cout << id << " - ";
        for (int node : graph.getNeighbours(id)) {
            if (!marked[node]) {
                edgeTo[node] = id;
                dfs(graph, node);
            }
        }
    }

public:
    DepthFirstSearch(Graph& graph, int id) : marked(graph.size(), false), edgeTo(graph.size()) {
        for (int i = 0; i < graph.size(); i++) {
            if (!marked[i]) {
                dfs(graph, i);
                trees++;
            }
        }
        cout << "Ci sono " << trees << " alberi" << endl;
    }

    void print() {
        cout << "Passaggi del DFS:" << endl;
        int startVertex = 0; // Vertice di partenza per la ricerca
        for (int v = 0; v < marked.size(); v++) {
            if (marked[v]) {
                startVertex = v;
                cout << startVertex << " to " << v << " via " << edgeTo[v] << endl;
            }
        }
    }
};