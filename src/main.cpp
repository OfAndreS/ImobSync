#include <iostream>
#include <vector>
#include <memory>

#include "Core/Pessoa.h"
#include "Core/Imovel.h"

#include "Infra/ConsoleUI.hpp"
#include "Infra/PessoaFactory.h"
#include "Infra/ImovelFactory.h"
#include "Infra/BusinessLogic.h"

int numberOfLineError;

int userNumberOfInput(iSync::ConsoleUI& myUI)
{
    int userNumberOfInput;

    numberOfLineError++;
    
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
    for (int ii = 0; ii < userNumberOfInput; ii++)
    {
        numberOfLineError++;
        myListaDeCorretores.push_back(myPessoaFactory.criarNovoCorretor_PorTesteAutomatizado(ii + 1, numberOfLineError, "Corretor"));
    }
}

void inicializarClientes(iSync::PessoaFactory& myPessoaFactory, std::vector<std::unique_ptr<iSync::Cliente>>& myListaDeClientes, int userNumberOfInput)
{
    numberOfLineError++;
    for (int ii = 0; ii < userNumberOfInput; ii++)
    {
        numberOfLineError++;
        myListaDeClientes.push_back(myPessoaFactory.criarNovoCliente_PorTesteAutomatizado(ii + 1, numberOfLineError, "Clientes"));
    }
}

void inicializarImoveis(iSync::ImovelFactory& myImovelFactory, std::vector<std::unique_ptr<iSync::Imovel>>& myListaDeImoveis, int userNumberOfInput)
{
    numberOfLineError++;
    for (int ii = 0; ii < userNumberOfInput; ii++)
    {
        numberOfLineError++;
        myListaDeImoveis.push_back(myImovelFactory.criarNovoImovel_PorTesteAutomatizado(ii + 1, numberOfLineError, "Imóvel"));
    }
}

int main()
{
    iSync::ConsoleUI myUI;
    iSync::PessoaFactory myPessoaFactory;
    iSync::ImovelFactory myImovelFactory;
    iSync::BusinessLogic business;

    std::vector<std::unique_ptr<iSync::Corretor>> myListaDeCorretores;
    std::vector<std::unique_ptr<iSync::Cliente>> myListaDeClientes;
    std::vector<std::unique_ptr<iSync::Imovel>> myListaDeImoveis;

    inicializarCorretor(myPessoaFactory, myListaDeCorretores, userNumberOfInput(myUI));
    inicializarClientes(myPessoaFactory, myListaDeClientes, userNumberOfInput(myUI));
    inicializarImoveis(myImovelFactory, myListaDeImoveis, userNumberOfInput(myUI));

    // myUI.printLista(myListaDeCorretores);
    // myUI.printLista(myListaDeClientes);
    // myUI.printLista(myListaDeImoveis);

    business.agendamento(myListaDeCorretores, myListaDeImoveis);
}