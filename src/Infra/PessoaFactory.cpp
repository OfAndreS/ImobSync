#include "Infra/PessoaFactory.h"

iSync::Pessoa iSync::PessoaFactory::criarNovoCliente_PorTesteAutomatizado()
{
    std::string nomeBuffer, telefoneBuffer;

    std::cin >> telefoneBuffer;

    std::cin >> nomeBuffer;

    return iSync::Cliente( 000 , nomeBuffer, telefoneBuffer);
}

iSync::Pessoa iSync::PessoaFactory::criarNovoCliente_PorConsole()
{
    std::string nomeBuffer, telefoneBuffer;

    iSync::ConsoleUI myUI;

    myUI.printHeader();

    std::cout << "| Digite o nome: " << std::endl;
    std::cin >> nomeBuffer;

    std::cout << "| Digite o Telefone: " << std::endl;
    std::cin >> telefoneBuffer;

    // // Criar lógica para randons IDs

    iSync::Cliente myCliente(0000, nomeBuffer, telefoneBuffer);

    return myCliente;
}
