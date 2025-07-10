#include <iostream>
#include <vector>

#include "Core/Pessoa.h"
#include "Infra/ConsoleUI.hpp"
#include "Infra/PessoaFactory.h"

void inicializarClientes(iSync::ConsoleUI& myUI, iSync::PessoaFactory& myPessoaFactory, std::vector<iSync::Pessoa>& myListaDePessoa)
{
    int userInput;

    myUI.printHeader();

    std::cin >> userInput;

    for (int i = 0; i < userInput; i++)
    {
        myListaDePessoa.push_back(myPessoaFactory.criarNovoCliente_PorTesteAutomatizado());
    }

}

int main()
{
    iSync::ConsoleUI myUI;
    iSync::PessoaFactory myPessoaFactory;

    std::vector<iSync::Pessoa> myListaDePessoa;

    inicializarClientes(myUI, myPessoaFactory, myListaDePessoa);

    myUI.printLista(myListaDePessoa);
}

