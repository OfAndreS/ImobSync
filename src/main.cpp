#include <iostream>
#include <vector>

#include "Core/Pessoa.h"
#include "Infra/ConsoleUI.hpp"
#include "Infra/PessoaFactory.h"

int userNumberOfInput(iSync::ConsoleUI& myUI)
{
    int userNumberOfInput;

    myUI.printHeader();

    // // Entrada padrão de dados para o sistema com tratamento de exceções 
    if(!myUI.input_iSync(userNumberOfInput))
    {
        std::cout << "| Falha na inicialização " << std::endl;
        exit(1);
    }

    return userNumberOfInput;
}

void inicializarClientes(iSync::PessoaFactory& myPessoaFactory, std::vector<iSync::Pessoa>& myListaDePessoa, int userNumberOfInput)
{
    for (int i = 0; i < userNumberOfInput; i++)
    {
        myListaDePessoa.push_back(myPessoaFactory.criarNovoCliente_PorTesteAutomatizado());
    }
}

void inicializarCorretor(iSync::PessoaFactory& myPessoaFactory, std::vector<iSync::Pessoa>& myListaDePessoa, int userNumberOfInput)
{
    for (int i = 0; i < userNumberOfInput; i++)
    {
        myListaDePessoa.push_back(myPessoaFactory.criarNovoCorretor_PorTesteAutomatizado());
    }
}

int main()
{
    iSync::ConsoleUI myUI;
    iSync::PessoaFactory myPessoaFactory;

    std::vector<iSync::Pessoa> myListaDePessoa;

    inicializarCorretor(myPessoaFactory, myListaDePessoa, userNumberOfInput(myUI));
    inicializarClientes(myPessoaFactory, myListaDePessoa, userNumberOfInput(myUI));
    // // Lógica para inicializar os imóveis

    myUI.printLista(myListaDePessoa);
}

