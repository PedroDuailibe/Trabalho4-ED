#include "Trie.hpp"
#include <string>

TrieNode::TrieNode() {
    isEndOfTitle = false;
    game = nullptr;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        children[i] = nullptr;
    }
}

TrieNode::~TrieNode() {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (children[i] != nullptr) {
            delete children[i];
        }
    }
}

Trie::Trie() {
    root = new TrieNode();
}

Trie::~Trie() {
    delete root;
}

bool Trie::insert(Game* game) {
    return false;
}

bool Trie::contains(std::string title){
    return false;
}

std::vector<Game*> Trie::autocomplete(std::string prefix, int k) {

    return std::vector<Game*> ();
}

std::string Trie::toSearchKey(std::string text) {
    return "";
}

void Trie::sortResults(std::vector<Game*>& games) {
    
}

