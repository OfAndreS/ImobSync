#include "Infra/PessoaFactory.h"

iSync::Pessoa iSync::PessoaFactory::criarNovoCliente_PorTesteAutomatizado()
{
    iSync::ConsoleUI myUI;
    
    std::string bufferNome, bufferTelefone;

    myUI.input_iSync(bufferNome);
    myUI.input_iSync(bufferTelefone);

    return iSync::Cliente( 000 , bufferNome, bufferTelefone);
}

iSync::Pessoa iSync::PessoaFactory::criarNovoCorretor_PorTesteAutomatizado()
{
    iSync::ConsoleUI myUI;

    std::string bufferNome, bufferTelefone;
    double bufferLat, bufferLng;
    bool bufferAvaliador;

    if(myUI.input_iSync(bufferTelefone) && myUI.input_iSync(bufferAvaliador) && myUI.input_iSync(bufferLat) && myUI.input_iSync(bufferLng) && myUI.input_iSync(bufferNome))
    {
        return iSync::Corretor(0, bufferNome, bufferTelefone, bufferAvaliador, bufferLat, bufferLng);
    }
    
    std::cout << "| ERROR: Problema na formatação" << std::endl;
    return NULL; 
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
