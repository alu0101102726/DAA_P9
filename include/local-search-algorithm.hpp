#include "algorithm.hpp"
#include "vectors.hpp"
#include <algorithm>

class LocalSearch : public Algorithm {

  private:
    std::string name;
    int m;
  
  public:
    LocalSearch(std::string newName, int newM);
    ~LocalSearch() {}

    Solution run();
    std::vector<int> randomSolution();
};