#include "variable-neighborhood-search-algorithm.hpp"

/**
 * @brief Crea el objeto y le asigna un nombre del algoritmo, además
 * de la búsqueda local seleccionada, el número de iteraciones con y
 * sin mejora. Además recibe el valor de kmax que representa el tamaño
 * máximo del entorno.
 * 
 * @param newName Nuevo nombre del algoritmo
 */
VariableNeighborhoodSearch::VariableNeighborhoodSearch(int currentLocalSearch, std::string newName, int newIterationsLimit, int newnoImprovementIterationLimit, int newKmax) {
  name = newName;
  iterationsLimit = newIterationsLimit;
  noImprovementiterationsLimit = newnoImprovementIterationLimit;
  kmax = newKmax;
  choosenLocalSearch = currentLocalSearch;
}

/**
 * @brief Representa el método que va a realizar la ejecución del algorimo
 * GVNS, para ello se va a partir de un conjunto de candidatos, que va a ser
 * todo el conjunto de nodos. Luego, una vez que hayamos hecho esto construimos
 * la solución inicial, usando el numero aleatorio que habíamos generado, hacemos una
 * búsqueda local greedy en el vector y buscamos el valor de la dispersión media.
 * 
 * Una vez que tenemos esto, vamos a iterar hasta
 * llegar a las iteraciones con o sin mejora, en cada una de ellas habrán iteraciones
 * hasta que se llegue al tamaño de entorno máximo. En cada una de ellas se hará shake,
 * luego se hará una búsqueda local y por último se buscará si la nueva solución tiene
 * una dispersion media mejor que las anteriores y se asignará.
 * 
 * @param currentGraph Representa las distancias entre los nodos del grafo
 * @return Solution Solución al aplicar el GVNS
 */
Solution VariableNeighborhoodSearch::run(Graph currentGraph) {
  std::vector < int > candidates;
  for (int currentNode = 0; currentNode < currentGraph.gentNodeNumber(); currentNode++) {
    candidates.push_back(currentNode);
  }
  int solutionSize = rand() % (currentGraph.gentNodeNumber() - 2) + 2;
  std::vector <int> solution = constructSolution(candidates, solutionSize);
  solution = localSearch(solution, currentGraph);
  float bestMd = getMeanDispersion(solution, currentGraph);
  int iterations = 0;
  int noImprovement = 0;
  while( iterations < getIterationsLimit() && noImprovement < getnoImprovementiterationsLimit()) {
    iterations++;
    int k = 1;
    while (k < getKmax()) {
      std::vector<int> newSolution = shake(candidates, k, solutionSize);
      std::vector<int> localOptimum = localSearch(newSolution, currentGraph);
      float currentMd = getMeanDispersion(localOptimum, currentGraph);
      if (currentMd > bestMd) {
        solution = localOptimum;
        bestMd = currentMd;
        solutionSize = localOptimum.size();
        k = 1;
        noImprovement = 0;
      }
      else {
        noImprovement++;
        k++;
      }
    }
  }
  Solution newSol(solution, getMeanDispersion(solution, currentGraph), getAlgorithmName(), getChoosenLocalSearch());
  return newSol;
}

/**
 * @brief Esta es la función encargada de coger una solución aleatoria en 
 * un determinado entorno
 * 
 * @param candidates Representa el vector de candidatos
 * @param currentK Representa el valor actual de la variable de entorno
 * @param newSolution Represenyta el valor del valor de la solucion
 * @return std::vector <int> Vector con la nueva solucion construida
 */
std::vector <int> VariableNeighborhoodSearch::shake(std::vector <int> candidates, int currentK, int newSolution) {
  int size = (rand() % 2 == 1) ? newSolution + currentK : newSolution - currentK;

  if ( size < newSolution + currentK) {
    size = newSolution + currentK;
  }
  else if (size >= candidates.size()) {
    size = candidates.size();
  }
  
  return constructSolution(candidates, size);
}

/**
 * @brief Se encarga de construir la solución, para ello se ha generado un número
 * aleatorio entre el número total de nodos y luego hace tantas iteraciones como de
 * grande sea ese elemento, cogiendo el valor del entorno y cogiendo un elemento del mismo.
 * 
 * @param candidates Vector del que se parte para construir la solución
 * @param size Tamaño del entorno
 * @return std::vector <int> Vector con la solución construida
 */
std::vector <int> VariableNeighborhoodSearch::constructSolution(std::vector <int> candidates, int size) {
  std::vector <int> solution;
  while(solution.size() < size) {
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
std::vector <int> VariableNeighborhoodSearch::localSearch(std::vector <int> solution, Graph currentGraph) {
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
std::string VariableNeighborhoodSearch::getAlgorithmName() {
  return name;
}

/**
 * @brief Devvuelve el tamaño del entorno máximo
 * 
 * @return int Valor del entorno máximo
 */
int VariableNeighborhoodSearch::getKmax() {
  return kmax;
}

/**
 * @brief Devuelve el límite de iteraciones
 * 
 * @return int Valor del límite de iteraciones
 */
int VariableNeighborhoodSearch::getIterationsLimit() {
  return iterationsLimit;
}

/**
 * @brief Obtiene el número de iteracions sin mejora
 * 
 * @return int Devuelve el valor de las iteraciones sin mejora
 */
int VariableNeighborhoodSearch::getnoImprovementiterationsLimit() {
  return noImprovementiterationsLimit;
}

/**
 * @brief Devuelve la búsqueda local que se ha seleccionado
 * 
 * @return int Valor de la búsqueda local seleccionda, en caso
 * de que sea 0 es ansiosa y 1 es greedy.
 */
int VariableNeighborhoodSearch::getChoosenLocalSearch() {
  return choosenLocalSearch;
}