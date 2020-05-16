#pragma once
#include "algorithm.hpp"
#include "greedy-algorithm.hpp"
#include "vectors.hpp"
#include <algorithm>

class LocalSearch : public Algorithm {

  private:
    std::string name;
    int m;
    GreedyAlgorithm greedy;
    std::vector<int> sol;
  
  public:
    LocalSearch(std::string newName, int newM, std::string otherAlgorithm, Solution Greedy);
    ~LocalSearch() {}

    Solution run();
    std::vector <int> localSearch(std::vector <int> solution);
};