#pragma once

#include <iostream>
#include <vector>

#include "Core/Pessoa.h" 

// include/Infra/ConsoleUI.h
namespace iSync
{
    class ConsoleUI
    {
        public:
            void printHeader();

            void entradaDeDados();

            void printLista(std::vector<iSync::Pessoa>& myPessoa);
    };
}