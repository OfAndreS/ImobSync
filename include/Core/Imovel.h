#pragma once

#include <string>
#include <iostream>

namespace iSync
{
    enum class Tipo {Casa, Apartamento, Terreno};

    class Imovel
    {   
        private:
            const int nextId;
            Tipo tipo;
            int propId;
            double lat;
            double lng;
            std::string endereco;
            double preco;
        
        public:
            // // Construtor
            Imovel(const int nextId, Tipo tipo, int propId, double lat, double lng, std::string endereco, double preco);

            // // Geterrs
            int getId();
            std::string getTipo();

            int getPropId();
            double getLat();
            double getLng();
            std::string getEndereco();
            double getPreco();

            void printInfo();

    };
    
} // namespace iSync