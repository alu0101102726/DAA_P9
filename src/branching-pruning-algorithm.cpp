#include "branching-pruning-algorithm.hpp"

/**
 * @brief Construct a new Branching Pruning Algorithm:: Branching Pruning Algorithm object
 * 
 * @param newName 
 * @param newM 
 * @param alg 
 */
BranchingPruningAlgorithm::BranchingPruningAlgorithm(std::string newName, int newM, Solution alg, bool mode):
  tree() {
    isDepth = mode;
    name = newName;
    m = newM;
    inf = alg.getSolution();
}

void BranchingPruningAlgorithm::initializeTree() {
  for(int i = 0; i < currentVectors.getSize() - 1 - (m - 1); i++) {
    std::vector<int> nodes;
    nodes.push_back(i);
    Node currentNode(0,getUpperBound(nodes));
    currentNode.setVector(nodes);
    tree.push_back(currentNode);
  }
}

void BranchingPruningAlgorithm::expand(int position) {
  tree[position].setVisited(true);
  int currentK = tree[position].getVector().size();
  int first = tree[position].getVector().back() + 1;
  std::vector<int> pSol = tree[position].getVector();
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

float BranchingPruningAlgorithm::getUpperBound(std::vector<int> currentSolution) {
  std::vector<float> UPB2;
  std::vector<float> UPB3;
  std::vector<int> candidates = getCandidates(currentSolution);
  int k = currentSolution.size();

  for (int i = 0; i < currentSolution.size(); i++) {
    for(int j = 0; j < candidates.size(); j++) {
      float temp = currentVectors.getEuclideanDistance(currentSolution[i], candidates[j]);

      int pos = 0;
      for (int j = 0; j < UPB2.size(); j++) {
        if (temp < UPB2[j]) {
          pos++;
        }
      }
      UPB2.insert(UPB2.begin() + pos, temp);
    } 
  }

  int size = k * (m - k);
  float UB2 = 0;
  for (int i = 0; i < size; i++) {
    UB2 += UPB2[i];
  }

  for (int i = 0; i < candidates.size(); i++) {
    for(int j = i + 1; j < candidates.size(); j++) {
      float temp = currentVectors.getEuclideanDistance(candidates[i], candidates[j]);

      int pos = 0;
      for (int j = 0; j < UPB3.size(); j++) {
        if (temp < UPB3[j]) {
          pos++;
        }
      }
      UPB3.insert(UPB3.begin() + pos, temp);
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
 * @brief 
 * 
 * @return Solution 
 */
Solution BranchingPruningAlgorithm::run() {
  lowerBound = getTotalDistance(inf);
  initializeTree();
  std::vector<int> bestSol;

  while (tree.size() != 0) {

    // Miramos si el nodo del arbol se puede podar
    int pos = getMin();

    // Expandimos el nodo del árbol
    if (tree[pos].getValue() + tree[pos].getUpperBound() >= lowerBound) {
      if (tree[pos].getVector().size() < m && !tree[pos].isVisited()) {
        expand(pos);
      }

      if (tree[pos].getValue() >= lowerBound) {
        lowerBound = tree[pos].getValue();
        if (tree[pos].getVector().size() == m) {
          bestSol = tree[pos].getVector();
        }
      }
    }

    tree.erase(tree.begin() + pos);
  }

  Solution newSol(currentVectors, bestSol, "BPA");
  return newSol;

}

int BranchingPruningAlgorithm::getMin() {
  float min = INFINITY;
  int currentK = 0;
  if (!isDepth) {
    float smallUB = tree[0].getUpperBound();
    int minNode = 0;
    for (int i = 0; i < tree.size(); i++) {
      float UPB = getUpperBound(tree[i].getVector());
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