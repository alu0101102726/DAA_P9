#pragma once

#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>

#include "vectors.hpp"

/**
 * @brief Representa una solucion, que va a contener el vector donde se
 * almacena la misma , la media y luego el tiempomque ha tardado en hallarla.
 * 
 */
class Solution {

  private:
    Vectors data;
    std::vector<int> solution;
    int runTime;
    std::string algorithmName;
    float distance;

  public:
    Solution(Vectors currentSolution, std::vector<int> newSolution, std::string newAlgorithmName);
    ~Solution() {}

    Vectors getInfo();
    std::vector <int> getSolution();
    int getRunTime();
    void setRunTime(int newRunTime);
    std::string getAlgorithmName();
    int getSolutionValue(int position);

    friend std::ostream& operator <<(std::ostream& os, Solution currentSolution);

};