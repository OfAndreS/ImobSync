#pragma once

#include <string>
#include <iostream>

#include "Core/Pessoa.h"

namespace iSync
{
    class Cliente : public iSync::Pessoa
    {
        public:
            // // Construtor
            Cliente(const int nextId, const std::string nome, const std::string telefone);

            void printInfo() override;

    };
    
} // namespace iSync