#include <iostream>
#include <vector>
#include "graph.h"

class DepthFirstSearch {
private:
    vector<bool> marked; // Array per marcare i nodi visitati
    vector<int> edgeTo; // Array per tenere traccia degli archi usati per raggiungere i nodi
    Graph& graph;

    void dfs(Graph& graph, int id) {
        marked[id] = true;
        for (int node : graph.getNeighbours(id)) {
            if (!marked[node]) {
                edgeTo[node] = id;
                cout << id << " -> " << node << ", ";
                dfs(graph, node);
            }
        }
    }

public:
    DepthFirstSearch(Graph& g) : graph(g), marked(g.size(), false), edgeTo(g.size()) {}

    int findTrees() {
        int trees = 0;
        for (int i = 0; i < graph.size(); i++) {
            if (!marked[i]) {
                trees++;
                cout << "Albero " << trees << " : ";
                dfs(graph, i);
                cout << endl;
            }
        }
        return trees;
    }
};