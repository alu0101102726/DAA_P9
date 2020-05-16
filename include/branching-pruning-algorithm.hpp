#pragma once
#include "algorithm.hpp"
#include "node.hpp"

/**
 * @brief Representa una clase que va a permitir aplicar
 * el patrón estrategia 
 */
class BranchingPruningAlgorithm : public Algorithm {

    private:
        std::string name;
        int m;
        std::vector<int> inf;
        float lowerBound;
        std::vector <Node> tree;
        bool isDepth;

	public:
        BranchingPruningAlgorithm(std::string newName, int m, Solution alg, bool mode);
        void initializeTree();
        float getUpperBound(std::vector<int> solution);
        void expand(int position);
        int getMin();
        Solution run();
};