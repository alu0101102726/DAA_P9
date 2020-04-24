
#include "../include/solution.hpp"

Solution::Solution(std::vector <int> currentSolution, float currentMedia, std::string newAlgorithmName):
  solution(currentSolution) {
    mediaValue = currentMedia;
    algorithmName = newAlgorithmName;
}

float Solution::getMedia () {
  return mediaValue;
}

std::vector <int> Solution::getSolution() {
  return solution;
}

int Solution::getSolutionValue(int position) {
  return solution[position];
}

int Solution::getRunTime() {
  return runTime;
}

std::string Solution::getAlgorithmName() {
  return algorithmName;
}

void Solution::setRunTime(int newRunTime) {
  runTime = newRunTime;
}

std::ostream& operator <<(std::ostream& os, Solution currentSolution) {
  std::cout << "La solución al aplicar el algoritmo " << currentSolution.getAlgorithmName() << " es: S = { ";
  for(int i = 0; i < currentSolution.solution.size(); i++) {
    std::cout << currentSolution.getSolutionValue(i) << " ";
  }
  std::cout << "} \n";
  std::cout << "Median dispersion: " << currentSolution.getMedia() << "\n";
  std::cout << "Run Time: " << currentSolution.getRunTime() << " milliseconds \n";
  std::cout << " - - - - - - - - - - - - - - - - - - - \n";
}