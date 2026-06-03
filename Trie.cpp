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

    if(game == nullptr) {
        return false;
    }

    TrieNode* curr = root;

    // Normaliza o nome do jogo
    std::string name = toSearchKey(game->getTitle());

    // Caminha pela Trie
    for(char c : name) {

        int n = -1;

        if(c >= 'a' && c <= 'z') {
            n = c - 97;
        } else {
            n = c - 22;
        }

        if(curr->children[n] == nullptr) {
            curr->children[n] = new TrieNode();
        }

        curr = curr->children[n];
    }

    // children[36] carrega o jogo
    curr->children[36] = new TrieNode();
    curr->children[36]->isEndOfTitle = true;
    curr->game = game;

    return true;
}

bool Trie::contains(std::string title){

    // Normaliza o nome do jogo
    std::string name = toSearchKey(title);

    // Node auxiliar
    TrieNode* curr = root;

    // Procura o jogo pela Trie
    for(char c : name) {

        // Index referente ao caractere c
        int n = -1;

        if(c >= 'a' && c <= 'z') {
            n = c - 97;
        } else {
            n = c - 22;
        }
    
        if(curr->children[n] == nullptr) {
            return false;
        }

        curr = curr->children[n];
    }

    if(curr->children[36] == nullptr) {
        return false;
    }

    return true;
}

std::vector<Game*> Trie::autocomplete(std::string prefix, int k) {

    return std::vector<Game*> ();
}

std::string Trie::toSearchKey(std::string text) {
    std::string key = "";
    for(char c : text) {
        if (c == ' '){
            continue;
        }

        char aux = std::tolower(c);
        key += aux;
    }
    return key;
}

void Trie::sortResults(std::vector<Game*>& games) {
    
}

