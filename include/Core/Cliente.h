#pragma once

#include <string>
#include "Core/Pessoa.h"

namespace iSync
{
    class Cliente : public iSync::Pessoa
    {
        public:

            Cliente(const int nextId, const std::string nome, const std::string telefone);

    };
    
} // namespace iSync