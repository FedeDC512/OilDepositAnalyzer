# Relazione Tecnica sul Progetto in C++

<div align="center">
<img src="https://survey.unipa.it/tmp/assets/af617fb7/logo-unipa-2020.png" height="192"/>
<br>
<p>
Corso di Laurea in Informatica<br>
Esame di "Laboratorio di Algoritmi"<br>
A.A. 2023/2024 - Docente: Manuela Flores<br>
Relazione della prova pratica - 31 Maggio 2024<br>
<strong><i>Agnello Federico, Nicosia Daniele</i></strong>
</p>
</div>

## Introduzione

Il progetto sviluppato consiste in un programma C++ per determinare il numero di giacimenti petroliferi in una regione rettangolare di terreno. La regione è divisa in appezzamenti quadrati, e un appezzamento può contenere petrolio (indicato con '@'). Due appezzamenti contenenti petrolio sono considerati parte dello stesso giacimento se sono adiacenti orizzontalmente, verticalmente o diagonalmente. Il programma utilizza un algoritmo di ricerca in profondità (DFS, Depth First Search) per identificare e contare i giacimenti petroliferi.

## Soluzione Proposta

Il programma è composto dai seguenti componenti principali:

1. **Lettura e creazione della matrice**: La matrice che rappresenta la regione del terreno viene letta da un file d'esempio, creata casualmente o letta da un file specificato dall'utente.
2. **Rappresentazione del grafo**: La matrice viene convertita in un grafo non orientato in cui ogni nodo rappresenta un appezzamento contenente petrolio e ogni albero un giacimento.
3. **Algoritmo DFS**: Viene utilizzato per esplorare il grafo e visitare i componenti adiacenti tra loro. Una volta identificato un albero, passerà a cercare il nodo successivo non ancora visitato per effettuare un'altra ricerca in modo da esplorare e contare tutti i diversi giacimenti petroliferi.

### Descrizione del Codice

#### 1. Lettura e Creazione della Matrice

Il programma offre diverse modalità per ottenere la matrice:

- Lettura da un file di esempio predefinito (`example.txt`).
- Lettura da un file scelto dall'utente.
- Creazione di una matrice casuale con dimensioni specificate dall'utente.

La funzione `parseFileToMatrix` converte un file di input in una matrice di interi, mentre `createRandomMatrix` genera una matrice casuale.

#### 2. Rappresentazione del Grafo

La classe `Graph` rappresenta il grafo non orientato. Ogni nodo del grafo corrisponde a un appezzamento contenente petrolio nella matrice. I nodi adiacenti sono collegati da un arco. Tutti i nodi connessi formano un albero, che rappresenta un giacimento petrolifero.

```cpp
class Graph {
private:
    vector<Node*> nodes;
    vector<vector<int>> adjList;

    string getXY(size_t id);
public:
    Graph(vector<vector<int>> mat);
    int size();
    int getNodeId(size_t x, size_t y);
    void addEdge(size_t v, size_t u);
    vector<int> getNeighbours(size_t id);
    void print();
};
```

#### 3. Algoritmo DFS

La classe `DepthFirstSearch` implementa l'algoritmo DFS per esplorare il grafo e contare i giacimenti di petrolio isolati.

```cpp
class DepthFirstSearch {
private:
    vector<bool> marked;
    Graph& graph;
    void dfs(size_t id);
public:
    DepthFirstSearch(Graph& g);
    int findTrees();
};
```

L'algoritmo DFS visita tutti i nodi di un giacimento connessi, marcandoli come visitati. Una volta visitati tutti i nodi di un giacimento, l'algoritmo sarà effettuato sul successivo nodo non ancora marcato, incrementando il contatore di giacimenti, finchè tutti i nodi non saranno stati visitati e marcati.

## Correttezza dell'Algoritmo

L'algoritmo è corretto in quanto esplora completamente ogni componente connesso del grafo utilizzando il DFS in tempo proporzionale alla somma dei loro gradi. La funzione `dfs` visita ricorsivamente tutti i nodi connessi a partire da un nodo iniziale, assicurando che ogni giacimento sia conteggiato una sola volta. La funzione `findTrees` itera su tutti i nodi del grafo e inizia una nuova DFS ogni volta che trova un nodo non visitato, incrementando il contatore dei giacimenti.

<!--
- **TEOREMA:** DFS esegue la marcatura di tutti i vertici connessi ad una sorgente s in tempo proporzionale alla somma dei loro gradi.
- **DIMOSTRAZIONE:** L’algoritmo trova i vertici seguendo archi a partire da s e quindi, se w è marcato allora è connesso ad s. D’altra parte, se w è connesso ad s allora risulta marcato: se non fosse marcato, ogni cammino da s (che è marcato) a w avrebbe un arco da un nodo marcato v a un nodo non marcato x, ma l’algoritmo lo avrebbe trovato e marcato. La marcatura assicura che ogni vertice connesso a s è visitato una volta, e il controllo di marcatura richiede tempo proporzionale al grado.
- **OSSERVAZIONE:** Se tutti i vertici sono connessi a s, allora il tempo è proporzionale ad |E|. Il tempo totale della visita DFS è $O(n + \sum_{v\in V}\space deg(v)) = O(n + m)$
-->

## Complessità Temporale e Spaziale

- **Complessità Temporale**: L'algoritmo DFS ha una complessità Lineare di $O(V + E)$, dove $V$ è il numero di nodi (appezzamenti contenenti petrolio) ed $E$ è il numero di archi (connessioni tra i nodi adiacenti). Questo è dovuto al fatto che ogni nodo e ogni arco vengono esplorati una sola volta.
- **Complessità Spaziale**: La complessità spaziale è $O(V + E)$ per memorizzare la lista di adiacenza `adjList` e l'array dei nodi visitati `marked`.

## Strutture Dati Utilizzate

- **Matrice bidimensionale**: Utilizzata inizialmente per rappresentare la griglia di terreno.
- **Grafo Non Orientato**: Implementato utilizzando una lista di adiacenza per rappresentare le connessioni tra i nodi.
- **Depth First Search (DFS)**: Utilizzato per esplorare i grafi e marcare i nodi visitati.

## Conclusioni

Il programma che abbiamo sviluppato permette di determinare con efficacia il numero di giacimenti petroliferi in una regione di terreno. Abbiamo utilizzato algoritmi di base di teoria dei grafi per risolvere il problema in modo efficiente sia in termini di tempo che di spazio.

L'uso della rappresentazione grafica e dell'algoritmo DFS ci ha permesso di creare una soluzione robusta e scalabile, capace di gestire anche le dimensioni massime del problema (fino a una griglia di 100x100 appezzamenti).

A livello personale, questo progetto è stato molto utile per approfondire la nostra comprensione e applicazione degli algoritmi e delle strutture dati. Inoltre, lavorare in gruppo ci ha permesso di migliorare e di affinare le nostre capacità di collaborazione e risoluzione dei problemi.
