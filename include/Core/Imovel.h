#pragma once

#include <string>
#include <iostream>

namespace iSync
{
    class Imovel
    {   
        public:
            enum Tipo {Casa, Apartamento, Terreno};

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
            Tipo getTipo();

            int getPropId();
            double getLat();
            double getLng();
            std::string getEndereco();
            double getPreco();

            void printInfo();
            static std::string convertTipoToString(Tipo tipo) {
                if (tipo == Casa) {
                    return "Casa";
                } else if (tipo == Apartamento) {
                    return "Apartamento";
                } else if (tipo == Terreno) {
                    return "Terreno";
                } else {
                    return "Desconhecido";
                }
            }
            static Tipo convertToTipo(const std::string& tipoString) {
                if (tipoString == "Casa") {
                    return Casa;
                } else if (tipoString == "Apartamento") {
                    return Apartamento;
                } else if (tipoString == "Terreno") {
                    return Terreno;
                } else {
                    return Casa; // Valor Default
                }
            }


    };
    
} // namespace iSync