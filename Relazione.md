# Relazione Tecnica sul Progetto in C++

_**Università degli Studi di Palermo**_

Corso di Laurea in Informatica - Esame di "Laboratorio di Algoritmi"

A.A. 2023/2024 Docente: Manuela Flores

Relazione della prova pratica - 31 Maggio 2024

_**Agnello Federico, Nicosia Daniele**_

## Introduzione

Il progetto sviluppato consiste in un programma C++ per determinare il numero di giacimenti petroliferi in una regione rettangolare di terreno. La regione è divisa in appezzamenti quadrati, e un appezzamento può contenere petrolio (indicato con '@'). Due appezzamenti contenenti petrolio sono considerati parte dello stesso giacimento se sono adiacenti orizzontalmente, verticalmente o diagonalmente. Il programma utilizza un algoritmo di ricerca in profondità (DFS, Depth First Search) per identificare e contare i giacimenti petroliferi.

## Soluzione Proposta

Il programma è composto dai seguenti componenti principali:

1. **Lettura e creazione della matrice**: La matrice che rappresenta la regione del terreno viene letta da un file, creata casualmente o letta da un file specificato dall'utente.
2. **Rappresentazione del grafo**: La matrice viene convertita in un grafo non orientato in cui ogni nodo rappresenta un appezzamento contenente petrolio.
3. **Algoritmo DFS**: Utilizzato per esplorare il grafo e contare i componenti connessi, ciascuno rappresentante un giacimento petrolifero.

## Descrizione del Codice

**1. Lettura e Creazione della Matrice**

Il programma offre diverse modalità per ottenere la matrice:

- Lettura da un file di esempio predefinito (`example.txt`).
- Lettura da un file scelto dall'utente.
- Creazione di una matrice casuale con dimensioni specificate dall'utente.

La funzione `parseFileToMatrix` converte un file di input in una matrice di interi, mentre `createRandomMatrix` genera una matrice casuale.

**2. Rappresentazione del Grafo**

La classe `Graph` rappresenta il grafo non orientato. Ogni nodo del grafo corrisponde a un appezzamento contenente petrolio nella matrice. I nodi adiacenti sono collegati da un arco.

```cpp
class Graph {
private:
    vector<Node*> nodes;
    vector<vector<int>> adjList;

    string getXY(int id);
public:
    Graph(vector<vector<int>> mat);
    int size();
    int getNodeId(int x, int y);
    void addEdge(int v, int u);
    vector<int> getNeighbours(int id);
    void print();
};
```

**3. Algoritmo DFS**

La classe `DepthFirstSearch` implementa l'algoritmo DFS per esplorare il grafo e contare i componenti connessi.

```cpp
class DepthFirstSearch {
private:
    vector<bool> marked;
    Graph& graph;

    void dfs(Graph& graph, int id);
public:
    DepthFirstSearch(Graph& g);
    int findTrees();
};
```

L'algoritmo DFS visita tutti i nodi di un componente connesso, marcandoli come visitati. Ogni volta che si trova un nodo non visitato, si incrementa il conteggio dei giacimenti petroliferi.


## Correttezza dell'Algoritmo

L'algoritmo è corretto in quanto esplora completamente ogni componente connesso del grafo utilizzando DFS. La funzione `dfs` visita ricorsivamente tutti i nodi connessi a partire da un nodo iniziale, assicurando che ogni giacimento sia conteggiato una sola volta. La funzione `findTrees` itera su tutti i nodi del grafo e inizia una nuova DFS ogni volta che trova un nodo non visitato, incrementando il contatore dei giacimenti.

## Complessità Temporale e Spaziale

- **Complessità Temporale**: L'algoritmo DFS ha una complessità di \(O(V + E)\), dove \(V\) è il numero di nodi (appezzamenti contenenti petrolio) ed \(E\) è il numero di archi (connessioni tra i nodi adiacenti). Questo è dovuto al fatto che ogni nodo e ogni arco vengono esplorati una sola volta.
- **Complessità Spaziale**: La complessità spaziale è \(O(V + E)\) per memorizzare la lista di adiacenza `adjList` e l'array dei nodi visitati `marked`.

## Strutture Dati Utilizzate

- **Matrice di Adiacenza**: Utilizzata inizialmente per rappresentare la griglia di terreno.
- **Grafo Non Orientato**: Implementato utilizzando una lista di adiacenza per rappresentare le connessioni tra i nodi.
- **DFS**: Utilizzato per esplorare il grafo e contare i componenti connessi.

## Conclusioni

Il programma sviluppato permette di determinare con efficacia il numero di giacimenti petroliferi in una regione di terreno. La soluzione proposta sfrutta algoritmi di base di teoria dei grafi per risolvere il problema in modo efficiente sia in termini di tempo che di spazio.

L'uso della rappresentazione grafica e dell'algoritmo DFS garantisce una soluzione robusta e scalabile, capace di gestire anche le dimensioni massime specificate nel problema (fino a 100x100 appezzamenti).