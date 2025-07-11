#pragma once

#include <string>
#include <iostream>

#include "Core/Pessoa.h"

namespace iSync
{
    class Corretor : public iSync::Pessoa
    {
        private:
            bool avaliador;
            double lat;
            double lng;

        public:
            // // Construtor 
            Corretor(const int nextId, const std::string nome, const std::string telefone, bool avaliador, double lat, double lng);

            // // Geterrs
            bool getAvaliador();
            double getLat();
            double getLng();

            void printInfo() override;
    };
    
} // namespace