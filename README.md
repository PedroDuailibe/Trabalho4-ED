# Sistema de Autocomplete de Jogos com Trie

## Descrição do Projeto

Este projeto consiste em um sistema de **autocomplete de jogos** desenvolvido em C++, utilizando a estrutura de dados **Trie** (Árvore de Prefixos). O sistema permite armazenar um catálogo de jogos e realizar buscas eficientes por prefixos de títulos, retornando sugestões ordenadas por popularidade e critérios alfabéticos.

A estrutura Trie armazena os títulos dos jogos caractere por caractere, permitindo buscas de prefixo em tempo linear em relação ao tamanho do prefixo pesquisado, independentemente do número de jogos cadastrados. 

## Instruções de Compilação

O projeto foi modularizado em classes e pode ser compilado diretamente pelo terminal utilizando o `g++` (ou qualquer compilador compatível com C++11 ou superior).

Para compilar o projeto completo, execute o seguinte comando no diretório raiz:

```bash
g++ main.cpp Game.cpp Trie.cpp GamesDatabase.cpp -o app
```
## Instruções de Execução

Após a compilação, o programa deve ser executado via linha de comando informando obrigatoriamente a quantidade máxima de sugestões (*k*) e o prefixo de busca:

```bash
./app k prefixo
```
## Organização dos Arquivos

A estrutura do projeto está organizada de forma modularizada nos seguintes arquivos:

* `main.cpp`: Ponto de entrada do programa. Responsável por validar os argumentos da linha de comando, inicializar a Trie, carregar a base de jogos fixa, chamar o autocomplete e formatar a saída para o usuário.

* `Game.hpp` / `Game.cpp`: Declaração e implementação da classe Game, que encapsula os dados de cada jogo (título, descrição curta e popularidade).

* `Trie.hpp` / `Trie.cpp`: Declaração e implementação das classes TrieNode e Trie. Contém toda a lógica de manipulação da árvore de prefixos (métodos `insert`, `contains`, `autocomplete`, `toSearchKey` e o método de ordenação `sortResults`).

* `GamesDatabase.hpp` / `GamesDatabase.cpp`: Base de dados estática fornecida para o projeto, contendo o array global de jogos (`games`) e a contagem total (`numberOfGames`).

## Exemplos de Uso

### Exemplo 1
```bash
./app 3 mine
```
Saída esperada:
```bash
Minecraft Dungeons | Fight your way through an exciting action adventure game inspired by classic dungeon crawlers and set in the Minecraft universe | 7832
Minecraft Legends | Discover the mysteries of Minecraft Legends a new action strategy game Explore a gentle land of rich resources and lush biomes on the brink of destruction The ravaging piglins have arrived and it s up to you to inspire your allies and lead them in strategic battles to save the Overworld | 1965
Mineirinho Director s Cut | A really cool 3d platform game lots of extreme adventures with our friend Miner now we have the option Double Miner and the adventure gets a lot cooler Director s Cut version has unpublished scenes that have never been seen | 912
```

### Exemplo 2
```bash
./app 3 "half l"
```

Saída esperada:
```bash
Half Life 2 | 1998 HALF LIFE sends a shock through the game industry with its combination of pounding action and continuous immersive storytelling Valve s debut title wins more than 50 game of the year awards on its way to being named Best PC Game Ever by PC Gamer and launches a franchise with more than eight million retail units sold worldwide | 131995
Half Life Alyx | Half Life Alyx is Valve s VR return to the Half Life series It s the story of an impossible fight against a vicious alien race known as the Combine set between the events of Half Life and Half Life 2 Playing as Alyx Vance you are humanity s only chance for survival | 71194
Half Life 2 Episode Two | Half Life 2 Episode Two is the second in a trilogy of new games created by Valve that extends the award winning and best selling Half Life adventure As Dr Gordon Freeman you were last seen exiting City 17 with Alyx Vance as the Citadel erupted amidst a storm of unknown proportions | 28291
```

### Exemplo 3
```bash
./app 100383 "God of 2"
```
Saída esperada:
```bash
No results found
```

