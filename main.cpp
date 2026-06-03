#include "Trie.hpp"
#include <iostream>

int main() {

  Trie b = Trie();
  std::string a = b.toSearchKey("Marcos 123 Pedro");

  std::cout << a << std::endl;
  return 0;
}
