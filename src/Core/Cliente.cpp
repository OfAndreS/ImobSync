#include "Core/Cliente.h"

iSync::Cliente::Cliente(const int nextId, const std::string nome, const std::string telefone) : iSync::Pessoa(nextId, nome, telefone) 
{}

void iSync::Cliente::printInfo()
{
    std::cout << "| ID: " << getId() << "| Nome: " << getNome() << "| Telefone: " << getTelefone() << std::endl;
}