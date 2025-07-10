#pragma once

#include <string>

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
            std::string getTelefone();
            std::string getNome();
            int getId();
    };
    
} // namespace iSync
