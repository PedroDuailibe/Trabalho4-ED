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
            n = c - 'a';
        } else if (c >= '0' && c <= '9') {
            n = c - '0' + 26;
        }

        if (n == -1) continue;

        if(curr->children[n] == nullptr) {
            curr->children[n] = new TrieNode();
        }

        curr = curr->children[n];
    }

    curr->isEndOfTitle = true;
    curr->game = game;

    return true;
}

bool Trie::contains(std::string title){

    // Normaliza o nome do jogo
    std::string name = toSearchKey(title);
    
    TrieNode* curr = root;
    // Procura o jogo pela Trie
    for(char c : name) {

        // Index referente ao caractere c
        int n = -1;

        if(c >= 'a' && c <= 'z') {
            n = c - 'a';
        } else if (c >= '0' && c <= '9') {
            n = c - '0' + 26;
        }
   
        if (n == -1) continue;

        if(curr->children[n] == nullptr) {
            return false;
        }

        curr = curr->children[n];
    }

    return curr->isEndOfTitle;
}

void Trie::recursive_find(std::vector<Game*>& games, TrieNode* curr) {
    if(curr == nullptr) {
        return;
    }

    if(curr->isEndOfTitle) {
        games.push_back(curr->game);
    }

    for(int i = 0; i < ALPHABET_SIZE; i++) {
        recursive_find(games, curr->children[i]);
    }
}

std::vector<Game*> Trie::autocomplete(std::string prefix, int k) {
    std::vector<Game*> games;

    if(k <= 0) {
        return games;
    }

    // Normaliza o prefixo
    std::string name = toSearchKey(prefix);

    // Node auxiliar
    TrieNode* curr = root;

    // Percorre a Trie pelo prefixo
    for(char c : name) {

        // Index referente ao caractere c
        int n = -1;

        if(c >= 'a' && c <= 'z') {
            n = c - 'a';
        } else if (c >= '0' && c <= '9') {
            n = c - '0' + 26;
        }
    
        if (n == -1) continue;

        // Nenhum jogo com tal prefixo, retorna vazio
        if(curr->children[n] == nullptr) {
            return games;
        }

        curr = curr->children[n];
    }

    recursive_find(games, curr);
    sortResults(games);

    if(k > games.size()) {
        return games;
    }

    std::vector<Game*> result;
    for(int i = 0; i < k; i++) {
        result.push_back(games[i]);
    }

    return result;
}

std::string Trie::toSearchKey(std::string text) {
    std::string key = "";

    for(char c : text) {
        if(c >= 'A' && c <= 'Z') {
            key+= (c - 'A' + 'a');
        } else if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            key += c;
        }
    }
    return key;
}

int Trie::aux(Game* game1, Game* game2){
    int pop1 = game1->getPopularity();
    int pop2 = game2->getPopularity();

    if(pop1 > pop2) return 1;
    if(pop2 > pop1) return 2;

    std::string name1 = toSearchKey(game1->getTitle());
    std::string name2 = toSearchKey(game2->getTitle());

    if (name1 < name2) return 1;
    return 2;
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

