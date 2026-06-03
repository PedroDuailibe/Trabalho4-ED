#include "Trie.hpp"
#include <iostream>

int main() {

  Trie jogos = Trie();
  Game* minecraft = new Game("Minecraft", "jogo sandbox", 100);
  Game* valorant = nullptr;
  bool a = jogos.insert(minecraft);
  bool b = jogos.insert(valorant);

  std::cout << a << std::endl;
  std::cout << b << std::endl;
  delete minecraft;
  return 0;
}
