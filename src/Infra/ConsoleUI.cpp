#include "Infra/ConsoleUI.h"

void iSync::ConsoleUI::printHeader()
{
    std::cout << "\n\n|  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *\n\n" << std::endl;
}

void iSync::ConsoleUI::printLista(std::vector<iSync::Pessoa>& myListaDePessoa)
{
    for (long unsigned int i = 0; i < myListaDePessoa.size(); i++)
    {

        iSync::Pessoa bufferPessoa = myListaDePessoa.at(i);

        std::cout << "| ID: " << bufferPessoa.getId() << " , Nome: " << bufferPessoa.getNome() << " , Telefone: " << bufferPessoa.getTelefone() << std::endl;
    }
}