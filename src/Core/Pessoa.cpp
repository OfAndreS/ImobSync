#include "Core/Pessoa.h"

iSync::Pessoa::Pessoa(const int nextId, const std::string nome, const std::string telefone) : nextId(nextId), nome(nome), telefone(telefone) 
{}

void iSync::Pessoa::printInfo()
{
    std::cout << "| ID: " << getId() << " | Nome: " << getNome() << " | Telefone: " << getTelefone() << std::endl;
}

int iSync::Pessoa::getId()
{
    return this->nextId;
}

std::string iSync::Pessoa::getNome()
{
    return this->nome;
}

std::string iSync::Pessoa::getTelefone()
{
    return this->telefone;
}