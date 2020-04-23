#include "../include/algorithm.hpp"

float Algorithm::getMedianDispersion(std::vector<int> solution, Graph currentGraph) {
  float sumOfEdges = 0;
  for(int i = 0; i < solution.size() - 1; i++) {
    for(int j = i + 1; j < solution.size(); j++) {
      sumOfEdges += currentGraph.getNodeValue(solution[i], solution[j]);
    }
  }
  return sumOfEdges / solution.size();
}