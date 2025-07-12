#pragma once

#include <string>
#include <iostream>

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

            virtual ~Pessoa() = default; // Adicione esta linha
            virtual void printInfo();
    };
    
} // namespace iSync
