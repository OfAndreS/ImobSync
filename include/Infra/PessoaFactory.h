#pragma once

#include <string>
#include <iostream>

#include "Core/Pessoa.h"
#include "Core/Cliente.h"
#include "Core/Corretor.h"

namespace iSync
{
    class PessoaFactory 
    {
        public:
            iSync::Pessoa criarNovoCliente();

            iSync::Pessoa criarNovoCorretor();

    };

} // namespace iSync