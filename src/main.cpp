#include <iostream>
#include <vector>
#include <memory>

#include "Core/Pessoa.h"
#include "Infra/ConsoleUI.hpp"
#include "Infra/PessoaFactory.h"

int userNumberOfInput(iSync::ConsoleUI& myUI)
{
    int userNumberOfInput;

    if(!myUI.input_iSync(userNumberOfInput))
    {

        myUI.printHeader();

        std::cout << "| ERRO: Falha na inicialização \n\n| Log: O número passado como argumento para ler a quantidade de entrada está incorreto! " << std::endl;

        myUI.printHeader();
        exit(1);
    }

    return userNumberOfInput;
}

void inicializarCorretor(iSync::PessoaFactory& myPessoaFactory, std::vector<std::unique_ptr<iSync::Corretor>>& myListaDeCorretores, int userNumberOfInput)
{
    for (int i = 0; i < userNumberOfInput; i++)
    {
        myListaDeCorretores.push_back(myPessoaFactory.criarNovoCorretor_PorTesteAutomatizado(i + 1, "Corretor"));
    }
}

void inicializarClientes(iSync::PessoaFactory& myPessoaFactory, std::vector<std::unique_ptr<iSync::Cliente>>& myListaDeClientes, int userNumberOfInput)
{
    for (int i = 0; i < userNumberOfInput; i++)
    {
        myListaDeClientes.push_back(myPessoaFactory.criarNovoCliente_PorTesteAutomatizado(i + 1, "Clientes"));
    }
}


int main()
{
    iSync::ConsoleUI myUI;
    iSync::PessoaFactory myPessoaFactory;

    std::vector<std::unique_ptr<iSync::Corretor>> myListaDeCorretores;
    std::vector<std::unique_ptr<iSync::Cliente>> myListaDeClientes;

    inicializarCorretor(myPessoaFactory, myListaDeCorretores, userNumberOfInput(myUI));
    inicializarClientes(myPessoaFactory, myListaDeClientes, userNumberOfInput(myUI));
    // // Lógica para inicializar os imóveis

    myUI.printLista(myListaDeCorretores);
    myUI.printLista(myListaDeClientes);
}