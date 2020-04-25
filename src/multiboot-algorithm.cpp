#include "multiboot-algorithm.hpp"
/**
 * @brief Crea el objeto y le asigna un nombre del algoritmo
 * 
 * @param newName Nuevo nombre del algoritmo
 */
MultibootAlgorithm::MultibootAlgorithm(std::string newName, int newIterationsLimit, int newnoImprovementIterationLimit) {
  name = newName;
  iterationsLimit = newIterationsLimit;
  noImprovementiterationsLimit = newnoImprovementIterationLimit;
}

/**
 * @brief Este método se encarga de ejecutar el algoritmo multiarranque,
 * para ello se hace un preprocesamiento, teniendo un conjunto de candidatos.
 * Una vez esto, se definen como condiciones de parada las iteraciones con y
 * sin mejora, y luego en cada iteración se va construyendo la solución, se hace
 * la búsqueda local (greedy) y se asigna al máximo la solución que tenga mayor
 * dispersión media.
 * 
 * @param currentGraph Representa el grafo con las distancias entre nodos
 * @return Solution Solucion del problema
 */
Solution MultibootAlgorithm::run(Graph currentGraph) {
  std::vector <int> candidates = preprocessing(currentGraph);
  float max = -INFINITY;
  int iterations = 0;
  int noImprovement = 0;
  std::vector <int> bestSolution = candidates;
  while( iterations < getIterationsLimit() && noImprovement < getnoImprovementiterationsLimit()) {
    iterations++;
    std::vector<int> solution = constructSolution(candidates, currentGraph);
    solution = greedyLocalSearch(solution, currentGraph);
    float newMax = getMedianDispersion(solution, currentGraph);
    if (newMax > max) {
      max = newMax;
      bestSolution = solution;
      noImprovement = 0;
    }
    else {
      noImprovement++;
    }
  }

  Solution newSolution(bestSolution, getMedianDispersion(bestSolution, currentGraph), getAlgorithmName());
  return newSolution;
}

/**
 * @brief Esta funcion se encarga de hacer el preprocesamiento, para ello, va a escoger
 * los nodos cuyas aristas (todas), sean no negativas, es decir, mayores o iguales a 0.
 * 
 * @param currentGraph Representa el grafo con las distancias entre los nodos.
 * @return std::vector <int> Representa un vector con el resultado del preprocesamiento
 */
std::vector <int> MultibootAlgorithm::preprocessing(Graph currentGraph) {
  std::vector <int> positiveEdges;
  for (int currentRow = 0; currentRow < currentGraph.getSize(); currentRow++) {
    bool hasPositiveEdges = false;
    for (int currentCol = 0; currentCol < currentGraph.getSize(); currentCol++) {
      if (currentGraph.getNodeValue(currentRow, currentCol) >= 0) {
        hasPositiveEdges = true;
      }
    }

    if(hasPositiveEdges) {
      positiveEdges.push_back(currentRow);
    }
  }

  return positiveEdges;
}

/**
 * @brief Se encarga de construir la solución, para ello se ha generado un número
 * aleatorio entre el número total de nodos y luego hace tantas iteraciones como de
 * grande sea ese elemento, luego se asigna a un elemento una posición aleatoria del
 * vector de candidatos, y en caso que ese elemento en el array no esté en la solución,
 * pues se añade en la misma.
 * 
 * @param currentSolution Vector del que se parte para construir la solución
 * @param totalNodes Numero total de nodos del grafo
 * @return std::vector <int> Vector con la solución construida
 */
std::vector <int> MultibootAlgorithm::constructSolution(std::vector <int> candidates, Graph currentGraph) {
  int vectorSize = rand() % (candidates.size() - 2) + 2;
  std::vector <int> solution;
  solution.push_back(candidates[rand() % candidates.size()]);
  while(solution.size() < vectorSize) {
    int randPosition = rand() % candidates.size();
    if (std::find(solution.begin(), solution.end(), candidates[randPosition]) == solution.end()) {
      solution.push_back(candidates[randPosition]);
    }
  }

  return solution;
}

/**
 * @brief Representa la búsqueda local greedy
 * 
 * @param solution Representa el vector sobre el que vamos a generar la
 * búsqueda local
 * @param currentGraph Grafo con la información de las distacias entre nodos
 * @return std::vector <int> Valor del vector
 */
std::vector <int> MultibootAlgorithm::greedyLocalSearch(std::vector <int> solution, Graph currentGraph) {
  bool localOptimum = true;
  while(localOptimum) {
    localOptimum = false;
    int worstNode = getWorstMediaDispersion(solution, currentGraph);
    if (worstNode != -1 ) {
      localOptimum = true;
      solution.erase(solution.begin() + worstNode);
    }
  }

  return solution;
}

/**
 * @brief Devuelve el nombre del algoritmo
 * 
 * @return std::string nombre del algoritmo
 */
std::string MultibootAlgorithm::getAlgorithmName() {
  return name;
}

/**
 * @brief Devuelve el límite de iteraciones
 * 
 * @return int Valor del límite de iteraciones
 */
int MultibootAlgorithm::getIterationsLimit() {
  return iterationsLimit;
}

/**
 * @brief Obtiene el número de iteracions sin mejora
 * 
 * @return int Devuelve el valor de las iteraciones sin mejora
 */
int MultibootAlgorithm::getnoImprovementiterationsLimit() {
  return noImprovementiterationsLimit;
}