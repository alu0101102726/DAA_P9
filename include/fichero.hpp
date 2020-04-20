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
class Fichero {

    public:
        std::ifstream grafo;

    public:
        Fichero(std::string nombreFichero);
        ~Fichero();

        int cerrarFichero();
        std::vector <std::vector < std::pair <int, float> > > comprobarSintaxis();
};