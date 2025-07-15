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
    
    return {
        std::move(myListaDeAvaliadores), std::move(agendaPorCorretor)
    };
}