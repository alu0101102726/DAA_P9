#include "branching-pruning-algorithm.hpp"

/**
 * @brief Construye el algoritmo de ramificación y poda con un nombre, un valor m que representa
 * el tamaño de la solucióm, una solución inicial de la que va a partir el algoritmo y un booleano
 * que indica cual va a la función de exploración (cota mínima o profundidad).
 * 
 * @param newName Representa el nombre del algoritmo
 * @param newM Representa el valor del tamaño de la solución
 * @param alg Solución que es obtenida de otro algoritmo que va a ser la solución inicial de este.
 * @param mode Representa cual va a la función de exploración (cota mínima o profundidad).
 */
BranchingPruningAlgorithm::BranchingPruningAlgorithm(std::string newName, int newM, Solution alg, bool mode):
  tree() {
    expandNodes = 0;
    isDepth = mode;
    name = newName;
    m = newM;
    inf = alg.getSolution();
}

/**
 * @brief Este método se encarga de inicializar el árbol, para ello se centra
 * en crear los nodos que se encuentran en el primer nivel del arbol, añadiendolos
 * al árbol. 
 */
void BranchingPruningAlgorithm::initializeTree() {
  for(int i = 0; i < currentVectors.getSize() - 1 - (m - 1); i++) {
    std::vector<int> nodes;
    nodes.push_back(i);
    Node currentNode(0,getUpperBound(nodes));
    currentNode.setVector(nodes);
    tree.push_back(currentNode);
  }
}

/**
 * @brief Funcion que se encarga de expandir el nodo que se ha seleccionado,
 * para ello, pone el mismo a visitado y se pasa a generar los nodos hijos
 * del mismo (teniendo en cuenta que partimos de la idea de que se ha implementado
 * un arbol mejorado, es decir, impide que hayan nodos duplicados), creando cada nodo
 * y añadiendolo al arbol.
 * 
 * @param nodeToExpand Representa el nodo elegido que se va a expander
 */
void BranchingPruningAlgorithm::expand(int nodeToExpand) {
  tree[nodeToExpand].setVisited(true);
  int currentK = tree[nodeToExpand].getVector().size();
  int first = tree[nodeToExpand].getVector().back() + 1;
  std::vector<int> pSol = tree[nodeToExpand].getVector();
  int n = currentVectors.getSize();

  for(int i = first; i < n - (m - currentK); i++) {
    std::vector<int> solution = pSol;
    solution.push_back(i);
    float UPB = getUpperBound(solution);
    Node current(getTotalDistance(solution), UPB);
    current.setVector(solution);
    tree.push_back(current);
  }
}

/**
 * @brief Esta función se encarga de determinar la cota superior, para ello hay que tener en cuenta,
 * que UPB2 va a formarse a partir de las p mejores aristas que est ́an entre sel y unsel y UPB3
 * van a ser las mejores aristas de unsel y unsel. Con esto en mente, sabemos que nuestra cota superior
 * va a ser la suma de UPB2 Y UPB3.
 * 
 * @param currentSolution Representa la solución parcial que tenemos en este momento y sobre la que
 * se va a determinar la cota superior.
 * @return float Representa el valor de la cota superior
 */
float BranchingPruningAlgorithm::getUpperBound(std::vector<int> currentSolution) {
  std::vector<float> UPB2;
  std::vector<float> UPB3;
  std::vector<int> unSel = getCandidates(currentSolution);
  int k = currentSolution.size();

  for (int i = 0; i < currentSolution.size(); i++) {
    for(int j = 0; j < unSel.size(); j++) {
      float distance = currentVectors.getEuclideanDistance(currentSolution[i], unSel[j]);

      int pos = 0;
      for (int j = 0; j < UPB2.size(); j++) {
        if (distance < UPB2[j]) {
          pos++;
        }
      }
      UPB2.insert(UPB2.begin() + pos, distance);
    } 
  }

  int size = k * (m - k);
  float UB2 = 0;
  for (int i = 0; i < size; i++) {
    UB2 += UPB2[i];
  }

  for (int i = 0; i < unSel.size(); i++) {
    for(int j = i + 1; j < unSel.size(); j++) {
      float distance = currentVectors.getEuclideanDistance(unSel[i], unSel[j]);

      int pos = 0;
      for (int j = 0; j < UPB3.size(); j++) {
        if (distance < UPB3[j]) {
          pos++;
        }
      }
      UPB3.insert(UPB3.begin() + pos, distance);
    } 
  }
  
  int sizeUB3 = 0;
  for (int i = m - k - 1; i > 0; i--) {
    sizeUB3 += i;
  }

  float UB3 = 0;
  for (int i = 0; i < sizeUB3; i++) {
    UB3 += UPB3[i];
  }

  return (UB2 + UB3);
}

/**
 * @brief Función de apoyo para evitar problemas con la comparación de números
 * flotantes, con un pequeño valor de tolerancia.
 * 
 * @param a Primer valor a comparar
 * @param b Segundo valor a comparar
 * @return true El primer número es mayor o igual
 * @return false El segundo número es mayors
 */
bool greaterEqual(float a, float b) {
  return (a-b) >= -0.0001;
}

/**
 * @brief Función principal del algoritmo, esta se encarga de asignar la cota inferior
 * al valor de la distancia de la solución inicial, inicializar el arbol e iterar en un bucle
 * que se haya recorrido todo el árbol, en cada iteracion se determina el nodo con el menor
 * valor y este se comprueba si mejora la solución, en caso de que lo haga y no esté visitado
 * se expande. Si con la solución parcial actual, el valor de la distancia es superior a la
 * cota inferior esta se actualiza. Además si se ha llegado al tamaño de la solución indicado
 * se almacena dicha solución y retorna.
 * 
 * @return Solution Representa la solución del algoritmo
 */
Solution BranchingPruningAlgorithm::run() {
  lowerBound = getTotalDistance(inf);
  initializeTree();
  std::vector<int> bestSol;

  while (tree.size() != 0) {

    // Miramos si el nodo del arbol se puede podar
    int pos = getMin();
    expandNodes++;

    // Expandimos el nodo del árbol
    if (greaterEqual(tree[pos].getValue() + tree[pos].getUpperBound(), lowerBound)) {
      if (tree[pos].getVector().size() < m && !tree[pos].isVisited()) {
        expand(pos);
      }

      if (greaterEqual(tree[pos].getValue(), lowerBound)) {
        lowerBound = tree[pos].getValue();
        if (tree[pos].getVector().size() == m) {
          bestSol = tree[pos].getVector();
        }
      }
    }

    tree.erase(tree.begin() + pos);
  }

  Solution newSol(currentVectors, bestSol, name);
  newSol.setNodes(expandNodes);
  return newSol;

}

/**
 * @brief Funcion que se encarga de determinar cual es el siguiente
 * nodo a escoger para luego expandir, en el caso de que se den las
 * condiciones. Depende de la función de exploración asignada, se hará con
 * cota mínima o por profundidad.
 * 
 * @return int Valor del nodo a escoger
 */
int BranchingPruningAlgorithm::getMin() {
  float min = INFINITY;
  int currentK = 0;
  if (!isDepth) {
    float smallUB = tree[0].getUpperBound();
    int minNode = 0;
    for (int i = 1; i < tree.size(); i++) {
      float UPB = tree[i].getUpperBound();
      if (UPB <= min) {
        min = UPB;
        minNode = i;
      }
    }
    return minNode;
  }
  else {
    int deepestK = tree[0].getVector().size();
    int minNode = 0;
    for (int i = 0; i < tree.size(); i++) {
      int val = tree[i].getVector().size();
      if (val > deepestK) {
        deepestK = val;
        minNode = i;
      }
    }
    return minNode;
  }
}