#include <iostream>

// Función de exponenciación rápida
int potencia_rapida(int a, int n) {
  // Caso base
  if (n == 0) { return 1; }

  // Divide el problema
  int mitad = potencia_rapida(a, n / 2);

  // Combinar resultados
  if (n % 2 == 0) { // Si n es par
    return mitad * mitad;
  } 
  else { // Si n es impar
    return mitad * mitad * a;
  }
}

int main() {
  int a;
  int n;

  std::cout << "Introduce la base (a): ";
  std::cin >> a;
  std::cout << "Introduce el exponente (n): ";
  std::cin >> n;

  int resultado = potencia_rapida(a, n);
  std::cout << "\nResultado final: " << resultado << std::endl;

  return 0;
}
