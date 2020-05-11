#include "grasp-algorithm.hpp"
#include <algorithm>
#include <cmath>

/**
 * @brief Crea el objeto y le asigna un nombre del algoritmo, además
 * de la búsqueda local seleccionada, el número de iteraciones con y
 * sin mejora.
 * 
 * @param newName Nuevo nombre del algoritmo
 */
GraspAlgorithm::GraspAlgorithm(std::string newName, int newIterationsLimit, int newM, int newRCLsize) {
  name = newName;
  iterationsLimit = newIterationsLimit;
  m = newM;
  RCLsize = newRCLsize;
}

/**
 * @brief Este método se encarga de ejecutar el algoritmo grasp,
 * para ello se hace un preprocesamiento, teniendo un conjunto de candidatos.
 * Una vez esto, se definen como condiciones de parada las iteraciones con y
 * sin mejora, y luego en cada iteración se va construyendo la solución, se hace
 * la búsqueda local y se asigna al máximo la solución que tenga mayor
 * dispersión media.
 * 
 * @param currentGraph Representa el grafo actual
 * @return Solution Solucion del problema
 */
Solution GraspAlgorithm::run() {
  std::vector <int> candidates = preprocessing();
  float max = -INFINITY;
  int iterations = 0;
  std::vector <int> bestSolution = candidates;
  while(iterations < iterationsLimit) {
    iterations++;
    std::vector<int> solution = constructSolution();
    solution = localSearch(solution);
    float newMax = getTotalDistance(solution);
    if (newMax > max) {
      max = newMax;
      bestSolution = solution;
    }
  }

  Solution newSolution(currentVectors, bestSolution, name);
  return newSolution;
}

/**
 * @brief Esta funcion se encarga de hacer el preprocesamiento, para ello, se va a escoger
 * de forma aleatoria una solución inicial de acuerdo al tamaño de m.
 * @return std::vector <int> Representa un vector con el resultado del preprocesamiento
 */
std::vector <int> GraspAlgorithm::preprocessing() {
  std::vector<int> auxSolution;
  for (int currentSolution = 0; currentSolution < m; currentSolution++) {
    int randomSol = rand() % currentVectors.getSize();
    auxSolution.push_back(randomSol);
  }
  return auxSolution;
}

/**
 * @brief Se encarga de construir la solución, para ello se ha generado un número
 * aleatorio entre el número total de nodos y luego hace tantas iteraciones como de
 * grande sea ese elemento, creando el RCL, luego cogiendo un elemento aleatorio del
 * RCL y por último añadiendo a la solucion.
 * 
 * @param candidates Vector del que se parte para construir la solución
 * @return std::vector <int> Vector con la solución construida
 */
std::vector <int> GraspAlgorithm::constructSolution() {
  int n = currentVectors.getSize();
  int k = rand() %  (n - 2) + 2;
  std::vector <int> solution;
  solution.push_back(rand() % n);
  while(solution.size() < m) {
    std::vector<int> newRCL = makeRCL(solution);
    int chossenElemment = newRCL[rand() % newRCL.size()];
    solution.push_back(chossenElemment);
  }
  return solution;
}

/**
 * @brief Crea el RCL, para ello se le pasa un vector que es del que va a partir
 * para obtener el RCL. En nuestro caso, se ha decidido, que se escojan aquellos valores
 * que sean mayores al 80 % del valor máximo.
 * 
 * @param RCL Vector del que se va a hallar el RCL
 * @return std::vector <int> Nuevo RCL que se ha creado
 */
std::vector <int> GraspAlgorithm::makeRCL(std::vector<int> currentSolution) {
  std::vector<int> aux;
  std::vector<int> distance;
  std::vector<int> candidates = getCandidates(currentSolution);

  for (int i = 0; i < candidates.size(); i++) {
    currentSolution.push_back(candidates[i]);
    float temp = getTotalDistance(currentSolution);
    currentSolution.pop_back();

    int pos = 0;
    for (int j = 0; j < distance.size(); j++) {
      if (temp < distance[j]) {
        pos++;
      }
    }
    distance.insert(distance.begin() + pos, temp);
    aux.insert(aux.begin() + pos, candidates[i]);
  }

  std::vector<int> RCL;
  for (int i = 0; i < RCLsize; i++) {
    RCL.push_back(aux[i]);
  }
  return RCL;
}

/**
 * @brief Representa la búsqueda local
 * 
 * @param solution Representa el vector sobre el que vamos a generar la
 * búsqueda local
 * @param currentGraph Grafo con la información de las distacias entre nodos
 * @return std::vector <int> Valor del vector
 */
std::vector <int> GraspAlgorithm::localSearch(std::vector <int> solution) {
  std::vector<int> candidates = getCandidates(solution);
  float distance = getTotalDistance(solution);
  std::vector<int> bestSol = solution;
  for (int i = 0; i < solution.size(); i++) {
    int auxValue = solution[i];
    for (int j = 0; j < candidates.size(); j++) {
      solution[i] = candidates[j];
      float newDistance = getTotalDistance(solution);
      if (newDistance > distance) {
        distance = newDistance;
        bestSol = solution;
      }
    }
    solution[i] = auxValue;
  }
  return bestSol;
}