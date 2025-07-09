#pragma once

#include <string>
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
            const bool getAvaliador();
            const double getLat();
            const double getLng();
    };
    
} // namespace iSync