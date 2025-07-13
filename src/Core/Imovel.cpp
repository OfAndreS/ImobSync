#include "Core/Imovel.h"

iSync::Imovel::Imovel(int nextId, Tipo tipo, int propId, double lat, double lng, std::string endereco, double preco) : nextId(nextId), tipo(tipo), propId(propId), lat(lat), lng(lng), endereco(endereco), preco(preco)
{}

void iSync::Imovel::printInfo()
{
    std::cout << "| ID: " << getId() << "| Tipo: " << convertTipoToString(getTipo()) << "| Prop. ID: " << getPropId() << "| Lat: " << getLat() << "| Lng: " << getLng() << "| Endereço: " << getEndereco() << "| Preço: " << getPreco() << std::endl;
}

int iSync::Imovel::getId()
{
    return this->nextId;
}

iSync::Imovel::Tipo iSync::Imovel::getTipo()
{
    return this->tipo;
}

int iSync::Imovel::getPropId()
{
    return this->propId;
}

double iSync::Imovel::getLat()
{
    return this->lat;
}

double iSync::Imovel::getLng()
{
    return this->lng;
}

std::string iSync::Imovel::getEndereco()
{
    return this->endereco;
}

double iSync::Imovel::getPreco()
{
    return this->preco;
}