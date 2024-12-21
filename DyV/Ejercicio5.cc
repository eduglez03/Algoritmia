#include<iostream>
#include<vector>


std::pair<int, int> min_y_max(std::vector<int> vector, int i, int d) {
  if (i == d) { return std::pair<int, int>(vector[i], vector[d]); }
  if ((i + 1) == d) {
    if (vector[i] <= vector[d]) { return std::pair<int, int>(vector[i], vector[d]); }
    else { return std::pair<int, int>(vector[d], vector[i]); }
  }


  int mitad = (i + d) / 2;
  std::pair<int, int> primera_mitad = min_y_max(vector, i, mitad);
  std::pair<int, int> segunda_mitad = min_y_max(vector, mitad + 1, d);

  std::pair<int, int> resultado;

  if (primera_mitad.first <= segunda_mitad.first) { resultado.first = primera_mitad.first; }
  else { resultado.first = segunda_mitad.first; }

  if (primera_mitad.second <= segunda_mitad.second) { resultado.second = segunda_mitad.second; }
  else { resultado.second = primera_mitad.second; }


  return resultado;
}


int main() {
  std::vector<int> vector;
  vector.push_back(494);
  vector.push_back(626);
  vector.push_back(270);
  vector.push_back(4);
  vector.push_back(465);
  vector.push_back(618);
  vector.push_back(884);
  vector.push_back(796);
  vector.push_back(881);
  vector.push_back(718);


  std::pair<int, int> resultado = min_y_max(vector, 0, vector.size());
  std::cout << "min: " << resultado.first << " max: " << resultado.second << std::endl;
  return 0; 
}