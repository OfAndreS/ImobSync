#include "Core/Pessoa.h"

iSync::Pessoa::Pessoa(const int nextId, const std::string nome, const std::string telefone) : nextId(nextId), nome(nome), telefone(telefone) 
{}

int const iSync::Pessoa::getId()
{
    return this->nextId;
}

std::string const iSync::Pessoa::getNome()
{
    return this->nome;
}

std::string const iSync::Pessoa::getTelefone()
{
    return this->telefone;
}