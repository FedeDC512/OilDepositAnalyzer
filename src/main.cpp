#include <iostream>
#include <fstream>
#include "utils.h"
#include "depthFirstSearch.h"

using namespace std;

int main() {
    //ifstream input("input.txt");
    ifstream input("C:\\Users\\fedea\\repos\\lab_alg_unipa\\src\\input.txt");

    auto mat = parseFileToMatrix(input);

    cout << "Matrice letta dal file:" << endl;
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    Graph graph(mat);

    graph.print();

    DepthFirstSearch dfs(graph, 0);
    
    //dfs.print();
}