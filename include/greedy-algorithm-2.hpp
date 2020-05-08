#include "algorithm.hpp"
#include "vectors.hpp"
#include <algorithm>

class NewGreedyAlgorithm : public Algorithm {

  private:
    std::string name;
    int m;
    Vectors currentVectors;
  
  public:
    NewGreedyAlgorithm(std::string newName, int newM);
    ~NewGreedyAlgorithm() {}

    int getMvalue();
    std::string getAlgorithmName();
    void setInfo(Vectors newVector);
    float get_total(std::vector<int> sol);

    Solution run();
    int getClosestElement(std::vector <int> currentElem, std::vector <float> currentSC);
};