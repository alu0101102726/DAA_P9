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
GraspAlgorithm::GraspAlgorithm(int currentLocalSearch, std::string newName, int newIterationsLimit, int newnoImprovementIterationLimit) {
  name = newName;
  iterationsLimit = newIterationsLimit;
  noImprovementiterationsLimit = newnoImprovementIterationLimit;
  choosenLocalSearch = currentLocalSearch;
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
Solution GraspAlgorithm::run(Graph currentGraph) {
  std::vector <int> candidates = preprocessing(currentGraph);
  float max = -INFINITY;
  int iterations = 0;
  int noImprovement = 0;
  std::vector <int> bestSolution = candidates;
  while( iterations < getIterationsLimit() && noImprovement < getnoImprovementiterationsLimit()) {
    iterations++;
    std::vector<int> solution = constructSolution(candidates, currentGraph);
    solution = localSearch(solution, currentGraph);
    float newMax = getMeanDispersion(solution, currentGraph);
    if (newMax > max) {
      max = newMax;
      bestSolution = solution;
      noImprovement = 0;
    }
    else {
      noImprovement++;
    }
  }
  
  Solution newSolution(bestSolution, getMeanDispersion(bestSolution, currentGraph), getAlgorithmName(), getChoosenLocalSearch());
  return newSolution;
}

/**
 * @brief Esta funcion se encarga de hacer el preprocesamiento, para ello, va a escoger
 * los nodos cuyas aristas (todas), sean no negativas, es decir, mayores o iguales a 0.
 * 
 * @param currentGraph Representa el grafo con las distancias entre los nodos.
 * @return std::vector <int> Representa un vector con el resultado del preprocesamiento
 */
std::vector <int> GraspAlgorithm::preprocessing(Graph currentGraph) {
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
 * grande sea ese elemento, creando el RCL, luego cogiendo un elemento aleatorio del
 * RCL y por último añadiendo a la solucion.
 * 
 * @param currentSolution Vector del que se parte para construir la solución
 * @param totalNodes Numero total de nodos del grafo
 * @return std::vector <int> Vector con la solución construida
 */
std::vector <int> GraspAlgorithm::constructSolution(std::vector <int> candidates, Graph currentGraph) {
  int vectorSize = rand() % (candidates.size() - 2) + 2;
  std::vector <int> solution;
  solution.push_back(candidates[rand() % candidates.size()]);
  while(solution.size() < vectorSize) {
    std::vector<int> newRCL = makeRCL(solution, candidates, currentGraph);
    int chossenElemment = newRCL[rand() % newRCL.size()];
    solution.push_back(chossenElemment);
  }

  return solution;
}

/**
 * @brief Crea el RCL, para ello se le pasa un vector que es del que va a partir
 * para obtener el RCL. En nuestro caso, se ha decidido, que se escojan aquellos valores
 * que sean mayores al 60 % del valor máximo.
 * 
 * @param RCL Vector del que se va a hallar el RCL
 * @return std::vector <int> Nuevo RCL que se ha creado
 */
std::vector <int> GraspAlgorithm::makeRCL(std::vector<int> currentSolution, std::vector <int> candidates, Graph currentGraph) {
  std::vector<int> aux;
  std::vector<float> media;
  float temp;
  float alfa = 0.6;

  for (int i = 0; i < candidates.size(); i++) {
    if (std::find(currentSolution.begin(), currentSolution.end(), candidates[i]) == currentSolution.end()) {
      currentSolution.push_back(candidates[i]);
      temp = getMeanDispersion(currentSolution, currentGraph);
      currentSolution.pop_back();
      int pos = 0;
      for (int j = 0; j < media.size(); j++) {
        if (temp < media[j]) {
          pos++;
        }
      }
      media.insert(media.begin() + pos, temp);
      aux.insert(aux.begin() + pos, candidates[i]);
    }
  }

  std::vector<int> RCL;
  int val = aux.size() / (1/alfa);
  val = val == 0 ? 1 : val;
  std::copy(aux.begin(), aux.begin() + val, std::back_inserter(RCL));

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
std::vector <int> GraspAlgorithm::localSearch(std::vector <int> solution, Graph currentGraph) {
  bool localOptimum = true;
  while(localOptimum) {
    localOptimum = false;
    int worstNode = (getChoosenLocalSearch() == 0) ? getWorstMeanDispersionAnxious(solution, currentGraph) : getWorstMeanDispersionGreedy(solution, currentGraph);
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
std::string GraspAlgorithm::getAlgorithmName() {
  return name;
}

/**
 * @brief Devuelve el límite de iteraciones
 * 
 * @return int Valor del límite de iteraciones
 */
int GraspAlgorithm::getIterationsLimit() {
  return iterationsLimit;
}

/**
 * @brief Obtiene el número de iteracions sin mejora
 * 
 * @return int Devuelve el valor de las iteraciones sin mejora
 */
int GraspAlgorithm::getnoImprovementiterationsLimit() {
  return noImprovementiterationsLimit;
}

/**
 * @brief Devuelve la búsqueda local que se ha seleccionado
 * 
 * @return int Valor de la búsqueda local seleccionda, en caso
 * de que sea 0 es ansiosa y 1 es greedy.
 */
int GraspAlgorithm::getChoosenLocalSearch() {
  return choosenLocalSearch;
}