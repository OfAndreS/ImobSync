#include "Core/Corretor.h"

iSync::Corretor::Corretor(const int nextId, const std::string nome, const std::string telefone, bool avaliador, double lat, double lng) : iSync::Pessoa(nextId, nome, telefone), avaliador(avaliador), lat(lat), lng(lng)
{}

void iSync::Corretor::printInfo()
{
    std::cout << "| ID: " << getId() << "| Nome: " << getNome() << "| Telefone: " << getTelefone() << "| Avaliador: " << getAvaliador() << "| Lat: " << getLat() << "| Lng: " << getLng() << std::endl;
}

bool iSync::Corretor::getAvaliador()
{
    return this->avaliador;
}

double iSync::Corretor::getLat()
{
    return this->lat;
}

double iSync::Corretor::getLng()
{
    return this->lng;
}