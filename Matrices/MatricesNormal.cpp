#include <iostream>
#include <vector>
#include <fstream> 

using namespace std;

void Multiplicar(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    ifstream inFile("matrices.in"); 
    ofstream outFile("resultado.out"); 

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    int n;
    inFile >> n;

    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));
    vector<vector<int>> C(n, vector<int>(n));


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inFile >> A[i][j];
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inFile >> B[i][j];
        }
    }


    inFile.close();


    Multiplicar(A, B, C);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            outFile << C[i][j] << " ";
        }
        outFile << endl;
    }

    // Cerrar el archivo de salida
    outFile.close();

    return 0;
}