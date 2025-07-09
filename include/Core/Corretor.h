#pragma once

#include <string>
#include "Pessoa.h"

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
            const double getLat();
            const double getLng();
            const bool getAvaliador();
    };
    
} // namespace iSync