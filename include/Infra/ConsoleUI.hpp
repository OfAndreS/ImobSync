#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <sstream>
#include <memory>

#include "Core/Cliente.h"
#include "Core/Corretor.h"
#include "Core/Pessoa.h"
#include "Core/Imovel.h"

namespace iSync
{

    class ConsoleUI
    {
        public:
            void printHeader();

            void printLista(std::vector<std::unique_ptr<iSync::Imovel>>& myListaDePessoa);
            
            void printLista(std::vector<std::unique_ptr<iSync::Corretor>>& myListaDePessoa);

            void printLista(std::vector<std::unique_ptr<iSync::Cliente>>& myListaDePessoa);

            void printErroLine(int numberOfTheLine, std::string typeOfInput);

            Tipo converteTipo(std::string userInput);

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