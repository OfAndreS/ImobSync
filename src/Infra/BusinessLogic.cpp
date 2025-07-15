#include "Infra/BusinessLogic.h"

    iSync::resultadoAgendamento iSync::BusinessLogic::agendamento(std::vector<std::unique_ptr<iSync::Corretor>>& myListaDeCorretores, std::vector<std::unique_ptr<iSync::Imovel>>& myListaDeImoveis)
    {   
    // // Extrair da lista de corretores apenas os que sejam avaliadores
    std::vector<int> myListaDeAvaliadores;
    for (size_t i = 0; i < myListaDeCorretores.size(); ++i) {
        if (myListaDeCorretores[i]->getAvaliador() == 1) {
            myListaDeAvaliadores.push_back(static_cast<int>(i));
        }
    }
    
    // // Distribui os imóveis apenas entre os corretores avaliadores
    std::map<int, std::vector<std::unique_ptr<Imovel>>> agendaPorCorretor;
    for (size_t i = 0; i < myListaDeImoveis.size(); ++i) {
        int indexCorretor = myListaDeAvaliadores[i % myListaDeAvaliadores.size()];
        agendaPorCorretor[indexCorretor].push_back(std::move(myListaDeImoveis[i]));
    }

    for (size_t i = 0; i < myListaDeCorretores.size(); ++i) {
        auto& corretor = myListaDeCorretores[i];
        auto& agenda = agendaPorCorretor[i];

        std::cout << "\nCorretor " << corretor->getId() << "\n";

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
                double dist = haversine(atualLat, atualLng, agenda[k]->getLat(), agenda[k]->getLng());
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
/*
int iSync::BusinessLogic::retornaId(int line)
{

}
*/
