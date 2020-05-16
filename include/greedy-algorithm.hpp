#include "algorithm.hpp"
#include "vectors.hpp"
#include <algorithm>

class GreedyAlgorithm : public Algorithm {

  private:
    std::string name;
    int m;
  
  public:
    GreedyAlgorithm(){}
    GreedyAlgorithm(std::string newName, int newM);
    ~GreedyAlgorithm() {}

    float get_total(std::vector<int> sol);
    void setAtributtes(std::string name, int m);

    Solution run();
    int getFurthestElement(std::vector <int> currentElem, std::vector <float> currentSC);
};