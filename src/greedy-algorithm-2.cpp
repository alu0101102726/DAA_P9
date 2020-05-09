#include "greedy-algorithm-2.hpp"

/**
 * @brief Construye la segunda version del algoritmo greedy con un nombre asociado, además
 * de una dimensión que es la que va a tener los vectores
 * 
 * @param newName Nuevo nombre del algoritmo
 * @param newM Tamaño de la solución
 */
NewGreedyAlgorithm::NewGreedyAlgorithm(std::string newName, int newM) {
  name = newName;
  m = newM;
}

/**
 * @brief Se encarga de ejecutar el segundo algoritmo Greedy. Para ello lo que hace es crear
 * un vector con todos los candidatos. Calcula el centro de gravedad respecto a todos
 * los elementos del vector. Luego se van a hacer tantas iteraciones hasta que el vector
 * de solución tenga el tamaño que le hemos definido. En todo este proceso, se va a obtener
 * el punto más cercano respecto al centro y se elimina del vector de solución,
 * teniendo en cuenta que este parte con todos los elementos, al igual que Elem, quitándolo a su
 * vez del vector con todos los elementos. Para acabar se calcula el centro de gravedad de
 * la nueva solución (esto ocurre hasta que la solución tenga el tamaño m definido).
 * 
 * @return Solution Devuelve la solución al problema en formato Solucion
 */
Solution NewGreedyAlgorithm::run() {
  std::vector <int> Elem;
  for (int i = 0; i < currentVectors.getSize(); i++) {
    Elem.push_back(i);
  }
  std::vector <int> S = Elem;
  std::vector <float> SC = getGravityCenter(Elem);
  while(S.size() != m) {
    int closest = getClosestElement(Elem, SC);
    S.erase(std::find(S.begin(), S.end(), closest));
    Elem.erase(std::find(Elem.begin(), Elem.end(), closest));
    SC = getGravityCenter(S);
  }

  Solution newSolution(currentVectors, S, name);
  return newSolution;
}

/**
 * @brief Se encarga de obtener el elemento más cerca del centro (que contiene los elementos
 * que no son solución)
 * 
 * @param currentElem Representa el vector que contiene los elementos restantes (no solución)
 * @param currentSC Representa el vector con los valores
 * @return int Devuelve el índice en la matriz del elemento más alejado.
 */
int NewGreedyAlgorithm::getClosestElement(std::vector <int> currentElem, std::vector <float> currentSC) {
    float distance = INFINITY;
    int sol;
    std::vector<int> repeat;

    for (int i = 0; i < currentElem.size(); i++){
      float aux = 0;
      for(int j = 0; j < currentVectors.getDimension(); j++){
        aux += pow(currentSC[j] - currentVectors.getDataValue(currentElem[i], j), 2);
      }

      aux = sqrt(aux);
      if (aux < distance) {
        distance = aux;
        sol = currentElem[i];
        repeat.clear();
        repeat.push_back(currentElem[i]);
      } else if (aux == distance) {
        repeat.push_back(currentElem[i]);
      }
    }

    if (repeat.size() > 1){
      int index = rand() % repeat.size();
      return repeat[index];
    }
    return sol;
}