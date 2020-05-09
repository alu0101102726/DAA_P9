#pragma once
#include <vector>
#include <cmath>
#include "vectors.hpp"
#include "solution.hpp"

/**
 * @brief Representa una clase que va a permitir aplicar
 * el patrón estrategia 
 */
class Algorithm {

    protected:
        Vectors currentVectors;

	public:
        Algorithm() {}
    
    /**
    * @brief Representa el método que es virtual y nulo que va a ser
    * sobreescrito por las clases hijas, debido a que todos los algoritmos
    * que se van a ejecutar son similares pero funcionan de forma distinta
    * 
    * @return int Que contiene la mejor solucion
    */
    virtual Solution run() = 0;
    void setInfo(Vectors newVector);
    float getMaxDiversity(Vectors currentVectors);
    std::vector <float> getGravityCenter(std::vector <int> currentElement);
    float getEuclideanDistance(int firstVect, int secondVect, std::vector < std::vector <float> > data);
};
