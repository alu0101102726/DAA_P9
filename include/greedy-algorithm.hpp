#include "algorithm.hpp"
#include "vectors.hpp"
#include <algorithm>

/**
 * @brief Esta clase representa el algoritmo Greedy que se va a aplicar,
 * obtenido a partir del pseudocódigo
 */
class GreedyAlgorithm : public Algorithm {

  private:
    std::string name;
    int m;
  
  public:
    GreedyAlgorithm(){}
    GreedyAlgorithm(std::string newName, int newM);
    ~GreedyAlgorithm() {}

    float get_total(std::vector<int> sol);

    Solution run();
    int getFurthestElement(std::vector <int> currentElem, std::vector <float> currentSC);
};