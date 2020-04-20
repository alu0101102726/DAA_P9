#pragma once
#include <vector>
#include "algoritmo.hpp"

/**
 * @brief Esta clase representa el algoritmo constructivo
 * voraz del cual teniamos el pseudocódigo.
 * 
 */
class AlgoritmoVorazConstructivo : public Algoritmo{
    
    public:
        AlgoritmoVorazConstructivo();
        ~AlgoritmoVorazConstructivo();

        std::vector<int> run(); 

};