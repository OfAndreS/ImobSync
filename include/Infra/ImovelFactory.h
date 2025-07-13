#pragma once

#include <string>
#include <iostream>
#include <memory> 

#include "Core/Imovel.h"
#include "Infra/ConsoleUI.hpp"


namespace iSync
{
    class ImovelFactory
    {
        public:
            std::unique_ptr<iSync::Imovel> criarNovoImovel_PorTesteAutomatizado(int numberOfTheLine, std::string typeOfInput);

    };

} // namespace iSync