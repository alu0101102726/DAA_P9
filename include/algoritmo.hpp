#pragma once
#include <vector>

/**
 * @brief Representa una clase que va a permitir aplicar
 * el patrón estrategia 
 */
class Algoritmo {

	public:
        /**
         * @brief Representa el método que es virtual y nulo que va a ser
         * sobreescrito por las clases hijas, debido a que todos los algoritmos
         * que se van a ejecutar son similares pero funcionan de forma distinta
         * 
         * @return std::vector<int> Vector que contiene la solución
         */
		virtual std::vector<int> run() = 0;

};
