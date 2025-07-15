#pragma once

#include <string>
#include <iostream>
#include <iomanip>

#include <vector>
#include <cmath>
#include <map>
#include <memory> 

#include "Core/Corretor.h"
#include "Core/Imovel.h"

namespace iSync
{
    struct resultadoAgendamento {
        std::vector<int> myListaDeAvaliadores;
        std::map<int, std::vector<std::unique_ptr<iSync::Imovel>>> agendaPorCorretor;
    };

    class BusinessLogic
    {
        public:
            resultadoAgendamento agendamento(std::vector<std::unique_ptr<iSync::Corretor>>& myListaDeCorretores, std::vector<std::unique_ptr<iSync::Imovel>>& myListaDeImoveis);  
        
            static constexpr double EARTH_R = 6371.0;

            static double haversine(double lat1, double lon1, double lat2, double lon2) {
                auto deg2rad = [](double d) { return d * M_PI / 180.0; };
                double dlat = deg2rad(lat2 - lat1);
                double dlon = deg2rad(lon2 - lon1);
                double a = std::pow(std::sin(dlat / 2), 2) +
                        std::cos(deg2rad(lat1)) * std::cos(deg2rad(lat2)) *
                        std::pow(std::sin(dlon / 2), 2);
                double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
                return EARTH_R * c;
            }

    };

} // namespace iSync