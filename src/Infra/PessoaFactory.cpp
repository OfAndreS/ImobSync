#include "Infra/PessoaFactory.h"

iSync::Pessoa iSync::PessoaFactory::criarNovoCliente_PorTesteAutomatizado()
{
    std::string bufferNome, bufferTelefone;

    std::cin >> bufferTelefone >> bufferNome;

    return iSync::Cliente( 000 , bufferNome, bufferTelefone);
}

iSync::Pessoa iSync::PessoaFactory::criarNovoCorretor_PorTesteAutomatizado()
{
    std::string bufferNome, bufferTelefone;
    double bufferLat, bufferLng;
    bool bufferAvaliador;

    std::cin >> bufferTelefone >> bufferAvaliador >> bufferLat >> bufferLng >> bufferNome;

    return iSync::Cliente( 000 , bufferNome, bufferTelefone);
}

// // Criação de objetos pelo console 

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
