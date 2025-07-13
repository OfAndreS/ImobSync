#include "Core/Imovel.h"

iSync::Imovel::Imovel(int nextId, Tipo tipo, int propId, double lat, double lng, std::string endereco, double preco) : nextId(nextId), tipo(tipo), propId(propId), lat(lat), lng(lng), endereco(endereco), preco(preco)
{}

void iSync::Imovel::printInfo()
{
    std::cout << "| ID: " << getId() << "| Tipo: " << getTipo() << "| Prop. ID: " << getPropId() << "| Lat: " << getLat() << "| Lng: " << getLng() << "| Endereço: " << getEndereco() << "| Preço: " << getPreco() << std::endl;
}

int iSync::Imovel::getId()
{
    return this->nextId;
}

std::string iSync::Imovel::getTipo()
{
    std::string tipoStr;
        switch (tipo) {
            case Tipo::Casa: tipoStr = "Casa"; break;
            case Tipo::Apartamento: tipoStr = "Apartamento"; break;
            case Tipo::Terreno: tipoStr = "Terreno"; break;
        }
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