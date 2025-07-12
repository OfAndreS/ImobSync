#pragma once

#include <string>
#include <iostream>
#include <memory> 

#include "Core/Pessoa.h"
#include "Core/Cliente.h"
#include "Core/Corretor.h"
#include "Infra/ConsoleUI.hpp"


namespace iSync
{
    class PessoaFactory
    {
        public:
            std::unique_ptr<iSync::Corretor> criarNovoCorretor_PorTesteAutomatizado(int numberOfTheLine, std::string typeOfInput);

            std::unique_ptr<iSync::Cliente> criarNovoCliente_PorTesteAutomatizado(int numberOfTheLine, std::string typeOfInput);

    };

} // namespace iSync