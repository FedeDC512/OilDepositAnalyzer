#pragma once

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    size_t x, y, id; // Coordinata x, coordinata y, ID del nodo
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
    string getXY(size_t id);

public:

    /**
    * Costruisce un grafo non orientato a partire da una matrice di adiacenza.
    * @param mat La matrice di adiacenza.
    */
    Graph(vector<vector<int>> mat);
    
    /**
    * Restituisce la dimensione del grafo.
    * @return La dimensione del grafo.
    */
    int size();

    /**
    * Restituisce l'ID del nodo corrispondente alle coordinate specificate.
    * @param x La coordinata x del nodo.
    * @param y La coordinata y del nodo.
    * @return L'ID del nodo corrispondente alle coordinate specificate, o -1 se non viene trovato alcun nodo corrispondente.
    */
    int getNodeId(size_t x, size_t y);

    /**
    * Aggiunge il nodo `u` alla lista di adiacenza di `v`.
    * @param v L'ID del nodo di partenza.
    * @param u L'ID del nodo di arrivo.
    */
    void addEdge(size_t v, size_t u);

    /**
    * Restituisce i nodi adiacenti al nodo specificato.
    * @param id L'ID del nodo di cui trovare i vicini.
    * @return Il vettore di nodi adiacenti al nodo specificato.
    */
    vector<int> getNeighbours(size_t id);

    /**
    * Stampa la lista di adiacenza.
    */
    void print();
};