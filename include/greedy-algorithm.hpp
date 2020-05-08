#include "algorithm.hpp"
#include "vectors.hpp"
#include <algorithm>

class GreedyAlgorithm : public Algorithm {

  private:
    std::string name;
    int m;
    Vectors currentVectors;
  
  public:
    GreedyAlgorithm(std::string newName, int newM);
    ~GreedyAlgorithm() {}

    int getMvalue();
    std::string getAlgorithmName();
    void setInfo(Vectors newVector);
    float get_total(std::vector<int> sol);

    Solution run();
    int getFurthestElement(std::vector <int> currentElem, std::vector <float> currentSC);
};