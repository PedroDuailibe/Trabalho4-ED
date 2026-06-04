#include "Trie.hpp"
#include <iostream>
#include <vector>

int main() {

  Trie jogos = Trie();
  Game* mine = new Game("mine", "jogo sandbox", 100);
  Game* minecraft = new Game("minecraft", "Jogo de fps", 70);
  Game* mineceraft = new Game("mineceraft", "Sandbox na cidade", 100);
  Game* gta5 = new Game("GTA5", "Sandbox foda", 100);
  jogos.insert(mine);
  jogos.insert(mineceraft);
  jogos.insert(minecraft);
  jogos.insert(gta5);

  std::vector<Game*> games = jogos.autocomplete("mine", 3);
  for(Game* game : games) {
    std::cout << game->getTitle() << std::endl;
  }
  std::cout << jogos.contains("minecraft") << std::endl;
  std::cout << jogos.contains("minea");
  delete mine;
  delete minecraft;
  delete mineceraft;
  delete gta5;
  return 0;
}
