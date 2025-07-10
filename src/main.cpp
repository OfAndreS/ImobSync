#include <iostream>
#include <vector>

#include "Core/Pessoa.h"
#include "Infra/ConsoleUI.h"
#include "Infra/PessoaFactory.h"

void inicializarClientes(iSync::ConsoleUI& myUi, iSync::PessoaFactory& myPessoaFactory, std::vector<iSync::Pessoa>& myListaDePessoa)
{
    myUi.printHeader();
    // // Alterar por modelo de entrada padrão do sistema
    int userInput;
    std::cin >> userInput;

    for (int i = 0; i < userInput; i++)
    {
        myListaDePessoa.push_back(myPessoaFactory.criarNovoCliente_PorTesteAutomatizado());
    }

}

int main()
{
    iSync::ConsoleUI myUi;
    iSync::PessoaFactory myPessoaFactory;

    std::vector<iSync::Pessoa> myListaDePessoa;

    inicializarClientes(myUi, myPessoaFactory, myListaDePessoa);

    myUi.printLista(myListaDePessoa);
}