#include <iostream>
#include <vector>
#include <memory>

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
        std::cout << "| ERRO: Falha na inicialização \n\n| Log: O número passado como argumento para ler a quantidade de entrada está incorreto! " << std::endl;

        myUI.printHeader();
        exit(1);
    }

    return userNumberOfInput;
}

void inicializarClientes(iSync::PessoaFactory& myPessoaFactory, std::vector<std::unique_ptr<iSync::Pessoa>>& myListaDePessoa, int userNumberOfInput)
{
    for (int i = 0; i < userNumberOfInput; i++)
    {
        myListaDePessoa.push_back(myPessoaFactory.criarNovoCliente_PorTesteAutomatizado(i, "Clientes"));
    }
}

void inicializarCorretor(iSync::PessoaFactory& myPessoaFactory, std::vector<std::unique_ptr<iSync::Pessoa>>& myListaDePessoa, int userNumberOfInput)
{
    for (int i = 0; i < userNumberOfInput; i++)
    {
        myListaDePessoa.push_back(myPessoaFactory.criarNovoCorretor_PorTesteAutomatizado(i, "Corretor"));
    }
}

int main()
{
    iSync::ConsoleUI myUI;
    iSync::PessoaFactory myPessoaFactory;

    std::vector<std::unique_ptr<iSync::Pessoa>> myListaDePessoa;

    inicializarCorretor(myPessoaFactory, myListaDePessoa, userNumberOfInput(myUI));
    inicializarClientes(myPessoaFactory, myListaDePessoa, userNumberOfInput(myUI));
    // // Lógica para inicializar os imóveis

    myUI.printLista(myListaDePessoa);
}

