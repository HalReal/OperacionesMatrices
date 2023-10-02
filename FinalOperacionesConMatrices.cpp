#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Función para calcular el determinante de una matriz
double calcularDeterminante(vector<vector<double>> matriz);

// Función para resolver una matriz por el método de Gauss-Jordan
void gaussJordan(vector<vector<double>>& matriz);

// Función para calcular la inversa de una matriz
void calcularInversa(vector<vector<double>>& matriz);

// Función para calcular la traspuesta de una matriz
vector<vector<double>> calcularTraspuesta(const vector<vector<double>>& matriz);

// Función para multiplicar dos matrices
vector<vector<double>> multiplicarMatrices(const vector<vector<double>>& matrizA, const vector<vector<double>>& matrizB);

// Función para imprimir una matriz
void imprimirMatriz(const vector<vector<double>>& matriz);

int main() {
    int opcion;
    int filasA, columnasA, filasB, columnasB;

    cout << "Ingrese el número de filas de la matriz A: ";
    cin >> filasA;
    cout << "Ingrese el número de columnas de la matriz A: ";
    cin >> columnasA;

    vector<vector<double>> matrizA(filasA, vector<double>(columnasA));

    cout << "Ingrese los elementos de la matriz A:" << endl;
    for (int i = 0; i < filasA; ++i) {
        for (int j = 0; j < columnasA; ++j) {
            cin >> matrizA[i][j];
        }
    }

    cout << "Ingrese el número de filas de la matriz B: ";
    cin >> filasB;
    cout << "Ingrese el número de columnas de la matriz B: ";
    cin >> columnasB;

    vector<vector<double>> matrizB(filasB, vector<double>(columnasB));

    cout << "Ingrese los elementos de la matriz B:" << endl;
    for (int i = 0; i < filasB; ++i) {
        for (int j = 0; j < columnasB; ++j) {
            cin >> matrizB[i][j];
        }
    }

    while (true) {
        cout << "\nMenú de Operaciones:" << endl;
        cout << "1. Calcular el determinante de la matriz A" << endl;
        cout << "2. Resolver la matriz A por el método de Gauss-Jordan" << endl;
        cout << "3. Calcular la inversa de la matriz A" << endl;
        cout << "4. Calcular la traspuesta de la matriz A" << endl;
        cout << "5. Multiplicar las matrices A y B" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "El determinante de la matriz A es: " << calcularDeterminante(matrizA) << endl;
                break;
            case 2:
                gaussJordan(matrizA);
                cout << "Matriz A en forma escalonada:" << endl;
                imprimirMatriz(matrizA);
                break;
            case 3:
                calcularInversa(matrizA);
                cout << "La inversa de la matriz A es:" << endl;
                imprimirMatriz(matrizA);
                break;
            case 4:
                cout << "La traspuesta de la matriz A es:" << endl;
                imprimirMatriz(calcularTraspuesta(matrizA));
                break;
            case 5:
                if (columnasA != filasB) {
                    cout << "Error: El número de columnas de A debe ser igual al número de filas de B para multiplicar las matrices." << endl;
                } else {
                    vector<vector<double>> resultado = multiplicarMatrices(matrizA, matrizB);
                    cout << "El resultado de la multiplicación de las matrices A y B es:" << endl;
                    imprimirMatriz(resultado);
                }
                break;
            case 6:
                return 0;
            default:
                cout << "Opción inválida. Por favor, seleccione una opción válida." << endl;
        }
    }

    return 0;
}

double calcularDeterminante(vector<vector<double>> matriz) {
    int n = matriz.size();
    
    // Validar que la matriz sea cuadrada
    if (n != matriz[0].size()) {
        cerr << "Error: La matriz no es cuadrada, no se puede calcular el determinante." << endl;
        return 0.0;
    }
    
    double det = 1.0;

    for (int i = 0; i < n; ++i) {
        // Buscar la fila con el elemento máximo en la columna actual
        int maxRow = i;
        for (int j = i + 1; j < n; ++j) {
            if (abs(matriz[j][i]) > abs(matriz[maxRow][i])) {
                maxRow = j;
            }
        }

        // Intercambiar filas si es necesario
        if (maxRow != i) {
            swap(matriz[i], matriz[maxRow]);
            det *= -1.0; // Cambio de signo al intercambiar filas
        }

        // Hacer ceros por debajo del elemento diagonal actual
        for (int j = i + 1; j < n; ++j) {
            double factor = matriz[j][i] / matriz[i][i];
            for (int k = i; k < n; ++k) {
                matriz[j][k] -= factor * matriz[i][k];
            }
        }

        // Multiplicar el determinante por el elemento diagonal actual
        det *= matriz[i][i];

        // Si algún elemento de la diagonal se vuelve cero, el determinante es cero
        if (matriz[i][i] == 0.0) {
            return 0.0;
        }
    }

    return det;
    
}


void gaussJordan(vector<vector<double>>& matriz) {
    int n = matriz.size();
    int m = matriz[0].size();
    
    // Validar que la matriz tenga más filas que columnas para poder aplicar Gauss-Jordan
    if (n < m) {
        cerr << "Error: La matriz tiene más columnas que filas, no se puede resolver por Gauss-Jordan." << endl;
        return;
    }
    
    // Implementar método de Gauss-Jordan (eliminación gaussiana)
    // Actualizar la matriz con el resultado en forma escalonada
}



// Función para calcular la inversa de una matriz





vector<vector<double>> calcularTraspuesta(const vector<vector<double>>& matriz) {
    int n = matriz.size();
    int m = matriz[0].size();
    
    // Crear una nueva matriz transpuesta
    vector<vector<double>> transpuesta(m, vector<double>(n));
    
    // Calcular la traspuesta
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            transpuesta[j][i] = matriz[i][j];
        }
    }
    
    return transpuesta;
}

vector<vector<double>> multiplicarMatrices(const vector<vector<double>>& matrizA, const vector<vector<double>>& matrizB) {
    int nA = matrizA.size();
    int mA = matrizA[0].size();
    int nB = matrizB.size();
    int mB = matrizB[0].size();
    
    // Validar que las matrices sean multiplicables
    if (mA != nB) {
        cerr << "Error: El número de columnas de A debe ser igual al número de filas de B para multiplicar las matrices." << endl;
        return vector<vector<double>>();
}

 // Crear una nueva matriz para el resultado
    vector<vector<double>> resultado(nA, vector<double>(mB));
    
    // Implementar la multiplicación de matrices
    for (int i = 0; i < nA; ++i) {
        for (int j = 0; j < mB; ++j) {
            resultado[i][j] = 0;
            for (int k = 0; k < mA; ++k) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
    
    return resultado;
}


void imprimirMatriz(const vector<vector<double>>& matriz) {
    int n = matriz.size();
    int m = matriz[0].size();
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}
