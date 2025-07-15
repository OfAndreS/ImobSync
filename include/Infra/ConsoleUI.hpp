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
#include "Infra/BusinessLogic.h"

namespace iSync
{

    class ConsoleUI
    {
        public:
            void printHeader();

            void printAgenda(std::vector<std::unique_ptr<iSync::Corretor>>& myListaDeCorretores, iSync::resultadoAgendamento& resultado);

            void printLista(std::vector<std::unique_ptr<iSync::Imovel>>& myListaDeImovel);
            
            void printLista(std::vector<std::unique_ptr<iSync::Corretor>>& myListaDePessoa);

            void printLista(std::vector<std::unique_ptr<iSync::Cliente>>& myListaDePessoa);

            void printErroLine(int numberOfTheLine, std::string typeOfInput);

            template<typename T>
            bool input_iSync(T& value) 
            {
                std::string linha;
                std::cin >> linha; 

                std::stringstream ss(linha);

                if ((ss >> value) && (ss.eof())) 
                {
                    return true;
                }

                return false; 
            }

            template<typename Q>
            bool inputAnLine_iSync(Q& value) 
            {
                std::string linha;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin >> std::ws, linha);

                value = linha;

                return false; 
            }
            
    };
}