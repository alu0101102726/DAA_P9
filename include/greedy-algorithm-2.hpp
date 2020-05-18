#include "algorithm.hpp"
#include "vectors.hpp"
#include <algorithm>

/**
 * @brief Esta clase representa el algoritmo Greedy que se va a aplicar.
 * Es una versión destructiva del algoritmo Greedy del pseudocódigo
 */
class NewGreedyAlgorithm : public Algorithm {

  private:
    std::string name;
    int m;
  
  public:
    NewGreedyAlgorithm(std::string newName, int newM);
    ~NewGreedyAlgorithm() {}

    float get_total(std::vector<int> sol);

    Solution run();
    int getClosestElement(std::vector <int> currentElem, std::vector <float> currentSC);
};