#include "algorithm.hpp"
#include "vectors.hpp"
#include <algorithm>

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