#include "Infra/PessoaFactory.h"
#include "Infra/ConsoleUI.h"

iSync::Pessoa iSync::PessoaFactory::criarNovoCliente_PorTesteAutomatizado()
{
    std::string nomeBuffer;
    std::string telefoneBuffer;

    // // Alterar por modelo de entrada padrão do sistema
    std::cin >> nomeBuffer;
    
    // // Alterar por modelo de entrada padrão do sistema
    std::cin >> telefoneBuffer;

    // // Criar lógica para randons IDs

    iSync::Cliente myCliente(0000, nomeBuffer, telefoneBuffer);

    return myCliente;
}

iSync::Pessoa iSync::PessoaFactory::criarNovoCliente_PorConsole()
{
    iSync::ConsoleUI myUi;
    std::string nomeBuffer;
    std::string telefoneBuffer;

    myUi.printHeader();

    std::cout << "| Digite o nome: " << std::endl;
    // // Alterar por modelo de entrada padrão do sistema
    std::cin >> nomeBuffer;
    
    std::cout << "| Digite o Telefone: " << std::endl;
    // // Alterar por modelo de entrada padrão do sistema
    std::cin >> telefoneBuffer;

    // // Criar lógica para randons IDs

    iSync::Cliente myCliente(0000, nomeBuffer, telefoneBuffer);

    return myCliente;
}
