#pragma once

#include <string>

//nome
//id
//telefone

namespace ib
{
    class Pessoa 
    {
        protected:
            const std::string telefone;
            const std::string nome;
            const int nextId;

            // // Geterrs
            const std::string getNome();
            const std::string getTelefone();
            const int getId();

            // // Construtor 
            Pessoa(const int nextId, const std::string nome, const std::string telefone);
    };
    
} // namespace ib
