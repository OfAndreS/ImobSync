#include "Infra/PessoaFactory.h"
#include "Infra/ConsoleUI.h"

iSync::Pessoa iSync::PessoaFactory::criarNovoCliente()
{
    iSync::ConsoleUI myUi;
    std::string nomeBuffer;
    std::string telefoneBuffer;


    myUi.printHeader();

    std::cout << "| Digite o nome: " << std::endl;
    // // Criar lógica para entrada padrão de dados
    std::cout << "| Digite o Telefone: " << std::endl;
    // // Criar lógica para randons IDs

    iSync::Cliente myCliente(0000, "Name", "4002-8922");

    return myCliente;
}