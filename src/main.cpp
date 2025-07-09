#include <iostream>
#include <vector>

#include "Core/Pessoa.h"
#include "Infra/ConsoleUI.h"
#include "Infra/PessoaFactory.h"

int main()
{
    iSync::ConsoleUI myUi;
    std::vector<iSync::Pessoa> allPessoas;

    iSync::PessoaFactory myPessoaFactory;

    allPessoas.push_back(myPessoaFactory.criarNovoCliente());
    
        myUi.printHeader();

    for (long unsigned int i = 0; i < allPessoas.size(); i++)
    {

        iSync::Pessoa bufferPessoa = allPessoas.at(i);

        std::cout << "| ID: " << bufferPessoa.getId() << " , Nome: " << bufferPessoa.getNome() << " , Telefone: " << bufferPessoa.getTelefone() << std::endl;
    }
}