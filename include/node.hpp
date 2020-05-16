#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

class Node {

  private:
    std::vector<int> partialSol;
    float value;
    bool is_prun;
    bool visited;
    float upperBound;

  public:
    Node() {}
    Node(float newValue, float newUpperBound);
    ~Node(){}

    float getUpperBound();
    void setUpperBound(float newUpperBound);

    float getValue();
    void setValue(float newValue);
    
    bool isPrun();
    void setPruned(bool newValue);
    
    bool isVisited();
    void setVisited(bool newValue);

    std::vector<int> getVector();
    void setVector(std::vector<int> newVect);

    void addChilds(int newNode);
    
    friend std::ostream& operator<<(std::ostream& os, Node otherNode);
};