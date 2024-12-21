#include <iostream>
using namespace std;

// Función para combinar dos subarreglos ordenados
void merge(int arr[], int left, int mid, int right) {
    cout << "Combinando subarreglos: ";
    cout << "[";
    for (int i = left; i <= mid; i++) cout << arr[i] << " ";
    cout << "] y [";
    for (int i = mid + 1; i <= right; i++) cout << arr[i] << " ";
    cout << "]\n";

    int n1 = mid - left + 1; // Tamaño del primer subarreglo
    int n2 = right - mid;    // Tamaño del segundo subarreglo

    // Crear subarreglos temporales
    int L[n1], R[n2];

    // Copiar datos a los subarreglos temporales
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Fusionar los subarreglos L[] y R[]
    int i = 0;    // Índice inicial de L[]
    int j = 0;    // Índice inicial de R[]
    int k = left; // Índice inicial del arreglo original

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si hay alguno
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si hay alguno
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    cout << "Resultado combinado: [";
    for (int i = left; i <= right; i++) cout << arr[i] << " ";
    cout << "]\n";
}

// Función principal que implementa Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Encuentra el punto medio
        int mid = left + (right - left) / 2;

        cout << "Dividiendo: [";
        for (int i = left; i <= right; i++) cout << arr[i] << " ";
        cout << "] en [" << left << "-" << mid << "] y [" << mid + 1 << "-" << right << "]\n";

        // Ordena la primera y la segunda mitad recursivamente
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Combina las dos mitades ordenadas
        merge(arr, left, mid, right);
    }
}

// Función para imprimir un arreglo
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Programa principal
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Arreglo original: \n";
    printArray(arr, arr_size);

    // Llamada a Merge Sort
    mergeSort(arr, 0, arr_size - 1);

    cout << "Arreglo ordenado: \n";
    printArray(arr, arr_size);
    return 0;
}
