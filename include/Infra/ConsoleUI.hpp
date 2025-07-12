#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <sstream>
#include <memory>

#include "Core/Pessoa.h" 

namespace iSync
{

    class ConsoleUI
    {
        public:
            void printHeader();
            
            void printLista(std::vector<std::unique_ptr<iSync::Pessoa>>& myListaDePessoa);

            void printErroLine(int numberOfTheLine, std::string typeOfInput);

            template<typename T>
            bool input_iSync(T& value) 
            {
                std::string linha;
                std::string printErro;

                std::cin >> linha; 

                std::stringstream ss(linha);

                if ((ss >> value) && (ss.eof())) 
                {
                    return true;
                }

                return false; 
            }
            
    };
}