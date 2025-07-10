#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <sstream>


#include "Core/Pessoa.h" 

namespace iSync
{

    class ConsoleUI
    {
        public:
            void printHeader();
            
            void printLista(std::vector<iSync::Pessoa>& myPessoa);

            bool itIsAnDigit(const std::string& tipo)
            {
                if(tipo.empty()) return false;
                for (char a : tipo)
                {
                    if (!std::isdigit(a))
                    {
                        return false;
                    }
                }
                return true;
            }

            template<typename T>
            bool input_iSync(T& value) 
            {
                std::string linha;
                std::cin >> linha; 

                std::stringstream ss(linha);

                if ((ss >> value) && (ss.eof())) 
                {
                    return true; // Sucesso!
                }

                return false; 
            }




            
    };
}