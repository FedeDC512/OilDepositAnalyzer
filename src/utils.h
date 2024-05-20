#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

vector<vector<int>> parseFileToMatrix(ifstream& file) {    
    if (!file.is_open()) {
        throw runtime_error("Errore durante l'apertura del file");
    }
    
    int rows, cols, numV = 0;
    file >> rows >> cols;
    vector<vector<int>> mat(rows, vector<int>(cols, 0));

    string line;
    int i = 0;
    while (i < cols) {
        file >> line;
        for (int j = 0; j < line.size(); j++) {
            if (line[j] == '@') {
                mat[i][j] = 1;
                numV++;
            }
        }
        i++;
    }

    return mat;
}