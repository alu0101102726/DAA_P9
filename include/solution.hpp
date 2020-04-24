#pragma once

#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>

/**
 * @brief Representa una solucion, que va a contener el vector donde se
 * almacena la misma , la media y luego el tiempomque ha tardado en hallarla.
 * 
 */
class Solution {

  private:
    std::vector < int > solution;
    float mediaValue;
    int runTime;
    std::string algorithmName;

  public:
    Solution(std::vector <int> currentSolution, float currentMedia, std::string newAlgorithmName);
    ~Solution() {}

    float getMedia ();
    std::vector <int> getSolution();
    int getRunTime();
    void setRunTime(int newRunTime);
    std::string getAlgorithmName();
    int getSolutionValue(int position);
    friend std::ostream& operator <<(std::ostream& os, Solution currentSolution);

};