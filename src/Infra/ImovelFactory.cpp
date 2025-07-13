#include "Infra/ImovelFactory.h"

std::unique_ptr<iSync::Imovel> iSync::ImovelFactory::criarNovoImovel_PorTesteAutomatizado(int numberOfTheLine, std::string typeOfInput)
{
    iSync::ConsoleUI myUI;


    int bufferPropId;
    std::string bufferTipo, bufferEndereco;
    double bufferLat, bufferLng, bufferPreco;

    if(myUI.input_iSync(bufferTipo) && myUI.input_iSync(bufferPropId) && myUI.input_iSync(bufferLat) && myUI.input_iSync(bufferLng) && myUI.input_iSync(bufferPreco) && myUI.input_iSync(bufferEndereco))
    {
        std::cout << bufferTipo << std::endl;
        return std::make_unique<iSync::Imovel>(0, myUI.converteTipo(bufferTipo), bufferPropId, bufferLat, bufferLng, bufferEndereco, bufferPreco);
    }

    myUI.printErroLine(numberOfTheLine, typeOfInput);
    myUI.printHeader();

    exit(1);
}
