#include "Trie.hpp"
#include <iostream>

int main() {

  Trie jogos = Trie();
  Game* minecraft = new Game("Minecraft", "jogo sandbox", 100);

  bool a = jogos.insert(minecraft);
  bool b = jogos.contains("Minecraft");
  bool c = jogos.contains("minecraft2");

  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << c << std::endl;
  delete minecraft;
  return 0;
}
