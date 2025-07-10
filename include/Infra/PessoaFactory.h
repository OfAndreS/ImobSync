#pragma once

#include <string>
#include <iostream>

#include "Core/Pessoa.h"
#include "Core/Cliente.h"
#include "Core/Corretor.h"
#include "Infra/ConsoleUI.hpp"


namespace iSync
{
    class PessoaFactory 
    {
        public:
            iSync::Pessoa criarNovoCliente_PorTesteAutomatizado();
            iSync::Pessoa criarNovoCliente_PorConsole();

            iSync::Pessoa criarNovoCorretor();

    };

} // namespace iSync