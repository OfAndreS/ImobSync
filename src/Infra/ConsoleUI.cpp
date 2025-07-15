#include "Infra/ConsoleUI.hpp"

void iSync::ConsoleUI::printHeader()
{
    std::cout << "\n\n|  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *\n\n" << std::endl;
}

void iSync::ConsoleUI::printAgenda(std::vector<std::unique_ptr<iSync::Corretor>>& myListaDeCorretores, iSync::resultadoAgendamento& resultado)
{
    printHeader();
    std::cout << "| Agendamento: \n" << std::endl;

    for (size_t i = 0; i < resultado.myListaDeAvaliadores.size(); ++i) {
        int indexCorretorReal = resultado.myListaDeAvaliadores[i];
        auto& corretor = myListaDeCorretores[indexCorretorReal];
        auto& agenda = resultado.agendaPorCorretor[indexCorretorReal];


        std::cout << "Corretor " << corretor->getId() << "\n";

        double atualLat = corretor->getLat();
        double atualLng = corretor->getLng();

        int hora = 9;
        int minuto = 0;
        std::vector<bool> visitado(agenda.size(), false);

        for (size_t j = 0; j < agenda.size(); ++j) {
            double menorDist = std::numeric_limits<double>::max();
            int proximo = -1;

            for (size_t k = 0; k < agenda.size(); ++k) {
                if (visitado[k]) continue;
                double dist = iSync::BusinessLogic::haversine(atualLat, atualLng, agenda[k]->getLat(), agenda[k]->getLng());
                if (dist < menorDist) {
                    menorDist = dist;
                    proximo = static_cast<int>(k);
                }
            }

            if (proximo == -1) break;
            visitado[proximo] = true;

            double tempoDesloc = menorDist * 2.0;
            minuto += static_cast<int>(tempoDesloc);
            while (minuto >= 60) { minuto -= 60; hora++; }

            std::cout << std::setw(2) << std::setfill('0') << hora << ":"
                    << std::setw(2) << std::setfill('0') << minuto
                    << " Imóvel " << agenda[proximo]->getId() << "\n";

            minuto += 60;
            while (minuto >= 60) { minuto -= 60; hora++; }

            atualLat = agenda[proximo]->getLat();
            atualLng = agenda[proximo]->getLng();
        }

        std::cout << "\n";
    }
}

void iSync::ConsoleUI::printLista(std::vector<std::unique_ptr<iSync::Imovel>>& myListaDeImovel)
{
    printHeader();
    std::cout << "| Lista de Imóveis: \n" << std::endl;

    for (long unsigned int i = 0; i < myListaDeImovel.size(); i++)
    {
        myListaDeImovel[i]->printInfo();
    }
}

void iSync::ConsoleUI::printLista(std::vector<std::unique_ptr<iSync::Corretor>>& myListaDePessoa)
{
    printHeader();
    std::cout << "| Lista de Corretores: \n" << std::endl;

    for (long unsigned int i = 0; i < myListaDePessoa.size(); i++)
    {
        myListaDePessoa[i]->printInfo();
    }
}

void iSync::ConsoleUI::printLista(std::vector<std::unique_ptr<iSync::Cliente>>& myListaDePessoa)
{
    printHeader();
    std::cout << "| Lista de Clientes: \n" << std::endl;

    for (long unsigned int i = 0; i < myListaDePessoa.size(); i++)
    {
        myListaDePessoa[i]->printInfo();
    }
}

void iSync::ConsoleUI::printErroLine(int numberOfTheLine, std::string typeOfInput)
{   
    std::string erroLine;
    printHeader();
    std::cin >> erroLine;
    std::cout << "| ERROR: Problema na formatação" << std::endl;
    std::cout << "\n| Log: Tipo da entrada ( " << typeOfInput << " ) / Linha do erro ( " << numberOfTheLine << " ) / Local do erro ( __ERRO__ " << erroLine << " )" << std::endl;
}