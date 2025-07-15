#include "Infra/PessoaFactory.h"

std::unique_ptr<iSync::Cliente> iSync::PessoaFactory::criarNovoCliente_PorTesteAutomatizado(int numberOfTheLine, int numberOfLineError, std::string typeOfInput)
{
    iSync::ConsoleUI myUI;
    
    std::string bufferNome, bufferTelefone;

    if (myUI.input_iSync(bufferTelefone) && myUI.input_iSync(bufferNome))
    {
        return std::make_unique<iSync::Cliente>(numberOfTheLine, bufferNome, bufferTelefone);
    }

    myUI.printErroLine(numberOfLineError, typeOfInput);
    myUI.printHeader();

    exit(1);
}

std::unique_ptr<iSync::Corretor> iSync::PessoaFactory::criarNovoCorretor_PorTesteAutomatizado(int numberOfTheLine, int numberOfLineError, std::string typeOfInput)
{
    iSync::ConsoleUI myUI;

    std::string bufferNome, bufferTelefone;
    double bufferLat, bufferLng;
    bool bufferAvaliador;

    if(myUI.input_iSync(bufferTelefone) && myUI.input_iSync(bufferAvaliador) && myUI.input_iSync(bufferLat) && myUI.input_iSync(bufferLng) && myUI.input_iSync(bufferNome))
    {
        return std::make_unique<iSync::Corretor>(numberOfTheLine, bufferNome, bufferTelefone, bufferAvaliador, bufferLat, bufferLng);
    }

    myUI.printErroLine(numberOfLineError, typeOfInput);
    myUI.printHeader();

    exit(1);
}
