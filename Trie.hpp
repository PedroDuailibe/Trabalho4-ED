#ifndef TRIE_HPP
#define TRIE_HPP

#include <vector>
#include "Game.hpp"

const int ALPHABET_SIZE = 36; 

class TrieNode {

public:

    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfTitle;
    Game* game;

    TrieNode();
    ~TrieNode();
};

class Trie {

private:

    TrieNode* root;
    int aux(Game* game1, Game* game2);

    // Outros métodos auxiliares, se necessário
    void recursive_find(std::vector<Game*>& games, TrieNode* curr);

public:

    Trie();
    ~Trie();

    bool insert(Game* game);
    bool contains(std::string title);

    std::vector<Game*> autocomplete(std::string prefix, int k);

    std::string toSearchKey(std::string text);
    void sortResults(std::vector<Game*>& games);

};

#endif
