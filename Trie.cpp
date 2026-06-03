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

    // Normaliza o prefixo
    std::string name = toSearchKey(prefix);


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

int alphabetically(std::string name1, std::string name2) {
    int size1 = name1.size();
    int size2 = name2.size();
    int size = size1;

    if (size1 > size2) {
        size = size2;
    }

    for(int i = 0; i < size; i++) {
        if(name1[i] > name2[i]) {
            return 2;
        }
        if(name2[i] > name1[i]) {
            return 1;
        }
    }

    if(size1 > size2) {
        return 2;
    }

    return 1;
}

int Trie::aux(Game* game1, Game* game2){
    int pop1 = game1->getPopularity();
    int pop2 = game2->getPopularity();

    if(pop1 > pop2) {
        return 1;
    }

    if(pop2 > pop1) {
        return 2;
    }

    std::string name1 = toSearchKey(game1->getTitle());
    std::string name2 = toSearchKey(game2->getTitle());

    return alphabetically(name1, name2);
}

void Trie::sortResults(std::vector<Game*>& games) {

    // Tamanho do vetor
    int size = games.size();

    // Loop pelo vetor
    for(int i = 1; i < size; i++) {
        Game* curr = games[i];
        int j = i - 1;

        // Leva o jogo até sua posição
        while(j >= 0 && aux(curr, games[j]) == 1) {
            games[j + 1] = games[j];
            j--;
        }

        games[j + 1] = curr;
    }
}

