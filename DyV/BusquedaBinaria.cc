#include <iostream>

using namespace std;

// Función recursiva para búsqueda binaria
int bb_recursiva(int x, int A[], int i, int j) {
    // Caso base: si hemos reducido a un solo elemento
    if (i == j) {
        if (A[i] == x) return i; // Valor encontrado
        return -1;              // Valor no encontrado
    }

    // Calcular el punto medio
    int p = (i + j) / 2;
    cout << "Dividiendo: [" << i << ".." << j << "] con p = " << p << "\n";

    // Decidir en qué mitad buscar
    if (x <= A[p]) {
        return bb_recursiva(x, A, i, p); // Buscar en la mitad izquierda
    } else {
        return bb_recursiva(x, A, p + 1, j); // Buscar en la mitad derecha
    }
}

// Función principal para búsqueda binaria
int busqueda_binaria(int x, int A[], int n) {
    if (n == 0 || x < A[0] || x > A[n - 1]) {
        return -1; // Valor no encontrado
    } else {
        return bb_recursiva(x, A, 0, n - 1);
    }
}

// Programa principal
int main() {
    int A[] = {1, 3, 5, 7, 9, 11, 13}; // Arreglo ordenado
    int n = sizeof(A) / sizeof(A[0]);
    int x;

    cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << "\n\n";

    cout << "Introduce el valor a buscar: ";
    cin >> x;

    int resultado = busqueda_binaria(x, A, n);

    if (resultado != -1) {
        cout << "Valor encontrado en la posición: " << resultado << "\n";
    } else {
        cout << "Valor no encontrado en el arreglo.\n";
    }

    return 0;
}
