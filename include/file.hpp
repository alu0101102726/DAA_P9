#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

/**
 * @brief Esta clase se va a encargar del manejo de ficheros
 * asi como su análisis y extracción de datos. Asimismo, comprueba
 * si la sintaxis del mismo es correcta.
 * 
 */
class File {

    public:
        std::ifstream fileGraph;
        int nodeNumber;

    public:
        File(std::string fileName);
        ~File();

        int closeFile();
        std::vector < std::vector < float > > checkFileSyntax();
        int getNumberNodes();
};