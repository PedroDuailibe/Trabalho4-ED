#include "Trie.hpp"
#include "GamesDatabase.hpp" 
#include <iostream>
#include <vector>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Formato: ./app k prefix" << std::endl;
        return 1;
    }

    int k = std::stoi(argv[1]);
    std::string prefix = argv[2];

    Trie jogos;

    for (int i = 0; i < numberOfGames; i++) {
        jogos.insert(&games[i]); 
    }

    std::vector<Game*> resultados = jogos.autocomplete(prefix, k);

    if (resultados.empty()) {
        std::cout << "No results found" << std::endl;
    } else {
        for (Game* game : resultados) {
            std::cout << game->getTitle() << " | " 
                      << game->getShortDescription() << " | " 
                      << game->getPopularity() << std::endl;
        }
    }

    return 0;
}
