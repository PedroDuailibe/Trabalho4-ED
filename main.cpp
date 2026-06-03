#include "Trie.hpp"
#include <iostream>
#include <vector>

int main() {

  Trie jogos = Trie();
  Game* minecraft = new Game("Minecraft", "jogo sandbox", 100);
  Game* valorant = new Game("Valorant", "Jogo de fps", 70);
  Game* gta = new Game("GTA", "Sandbox na cidade", 100);
  Game* gta5 = new Game("GTA5", "Sandbox foda", 100);

  std::vector<Game*> g = {minecraft, gta5, valorant, gta};
  jogos.sortResults(g);

  for(Game* game : g) {
    std::cout << game->getTitle() << std::endl;
  }

  delete minecraft;
  delete valorant;
  delete gta;
  delete gta5;
  return 0;
}
