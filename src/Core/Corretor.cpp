#include "Corretor.h"

iSync::Corretor::Corretor(const int nextId, const std::string nome, const std::string telefone, bool avaliador, double lat, double lng) : iSync::Pessoa(nextId, nome, telefone), avaliador(avaliador), lat(lat), lng(lng)
{}

const bool iSync::Corretor::getAvaliador()
{
    return this->avaliador;
}

double const iSync::Corretor::getLat()
{
    return this->lat;
}

double const iSync::Corretor::getLng()
{
    return this->lng;
}