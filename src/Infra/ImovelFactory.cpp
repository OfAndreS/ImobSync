#include "Infra/ImovelFactory.h"

std::unique_ptr<iSync::Imovel> iSync::ImovelFactory::criarNovoImovel_PorTesteAutomatizado(int numberOfTheLine, int numberOfLineError, std::string typeOfInput)
{
    iSync::ConsoleUI myUI;


    int bufferPropId;
    std::string bufferTipo, bufferEndereco;
    double bufferLat, bufferLng, bufferPreco;

    if(myUI.input_iSync(bufferTipo) && myUI.input_iSync(bufferPropId) && myUI.input_iSync(bufferLat) && myUI.input_iSync(bufferLng) && myUI.input_iSync(bufferPreco) && myUI.inputAnLine_iSync(bufferEndereco))
    {
        return std::make_unique<iSync::Imovel>(numberOfTheLine, iSync::Imovel::convertToTipo(bufferTipo), bufferPropId, bufferLat, bufferLng, bufferEndereco, bufferPreco);
    }

    myUI.printErroLine(numberOfLineError, typeOfInput);
    myUI.printHeader();

    exit(1);
}
