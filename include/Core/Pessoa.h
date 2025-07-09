#pragma once

#include <string>

//nome
//id
//telefone

namespace iSync
{
    class Pessoa 
    {
        protected:
            const std::string telefone;
            const std::string nome;
            const int nextId;
            
            // // Construtor 
            Pessoa(const int nextId, const std::string nome, const std::string telefone);
        public:
            // // Geterrs
            const std::string getTelefone();
            const std::string getNome();
            const int getId();
    };
    
} // namespace iSync
