#pragma once

#include <iostream>
#include <utility>
#include <vector>

/**
 * @brief Representa un grafo de al que se le van a aplicar
 * los diferentes algoritmos.
 * 
 */
class Graph {

  private:
    std::vector < std::vector < float > > information;
    int nodeNumber;

  public:
    Graph(std::string fileName);
    ~Graph() {}

    float getNodeValue (int positioni, int positionj);
    int getSize();
    int gentNodeNumber();
    friend std::ostream& operator <<(std::ostream& os, Graph printGraph);

};
