#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream> // Necessário para stringstream

#include "Core/Pessoa.h" 

namespace iSync
{

    class ConsoleUI
    {
        public:
            void printHeader();
            
            void printLista(std::vector<iSync::Pessoa>& myPessoa);
    };
}