#pragma once

#include <iostream>
#include <vector>
#include "../graph/graph.h"

class DepthFirstSearch {
private:
    vector<bool> marked; // Array per marcare i nodi visitati
    Graph& graph;

    /**
     * Visita in profondità il grafo partendo da un nodo specifico.
     * @param graph Il grafo da visitare.
     * @param id Il nodo da cui partire.
     */
    void dfs(int id);
    
public:

    /**
     * Costruisce un oggetto DepthFirstSearch a partire da un grafo.
     * @param g Il grafo su cui eseguire la visita in profondità.
     */
    DepthFirstSearch(Graph& g);

    /**
     * Trova il numero di alberi presenti nel grafo non orientato.
     * @return Il numero di alberi presenti nel grafo.
     */
    int findTrees();
};