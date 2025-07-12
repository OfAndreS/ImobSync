#include "Infra/ConsoleUI.hpp"

void iSync::ConsoleUI::printHeader()
{
    std::cout << "\n\n|  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *\n\n" << std::endl;
}

void iSync::ConsoleUI::printLista(std::vector<std::unique_ptr<iSync::Pessoa>>& myListaDePessoa)
{
    for (long unsigned int i = 0; i < myListaDePessoa.size(); i++)
    {
        myListaDePessoa[i]->printInfo();
    }
}

void iSync::ConsoleUI::printErroLine(int numberOfTheLine, std::string typeOfInput)
{   
    std::string erroLine;
    std::cin >> erroLine;
    std::cout << "| ERROR: Problema na formatação" << std::endl;
    std::cout << "\n| Log: Tipo da entrada ( " << typeOfInput << " ) / Linha do erro ( " << numberOfTheLine << " ) / Local do erro ( __ERRO__ " << erroLine << " )" << std::endl;
}