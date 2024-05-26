#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * Legge un file e convertirlo in una matrice di interi.
 * @param file Il file da leggere.
 * @return La matrice di interi ottenuta dal file.
 * @throws runtime_error se si verifica un errore durante l'apertura del file.
 */
vector<vector<int>> parseFileToMatrix(ifstream& file);

/**
 * Crea una matrice casuale di dimensioni specificate.
 * @param rows Il numero di righe della matrice.
 * @param cols Il numero di colonne della matrice.
 * @return La matrice casuale creata.
 */
vector<vector<int>> createRandomMatrix(int rows, int cols);

/**
 * Stampa una matrice di interi come una griglia di caratteri.
 * I valori 1 vengono rappresentati con il carattere "■", mentre i valori diversi da 1 vengono rappresentati con il carattere "□".
 * @param mat La matrice da stampare.
 */
void printMatrix(vector<vector<int>> mat);