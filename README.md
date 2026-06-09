# Sistema de Autocomplete de Jogos com Trie

Este projeto consiste em um sistema de **autocomplete de jogos** desenvolvido em C++, utilizando a estrutura de dados **Trie** (Árvore de Prefixos). O sistema permite armazenar um catálogo de jogos e realizar buscas eficientes por prefixos de títulos, retornando sugestões ordenadas por popularidade e critérios alfabéticos.

## Descrição do Projeto

A estrutura Trie armazena os títulos dos jogos caractere por caractere, permitindo buscas de prefixo em tempo linear em relação ao tamanho do prefixo pesquisado, independentemente do número de jogos cadastrados. 

### Principais Características:
* **Busca Case-Insensitive:** O sistema não diferencia letras maiúsculas de minúsculas.
* **Ignora Espaços em Branco:** Espaços são desconsiderados na criação da chave de busca interna (ex: `"Half Life 2"` e `"halflife2"` são equivalentes).
* **Ordenação Personalizada:** Os resultados do autocomplete são retornados com até *k* sugestões, ordenados por:
  1. Maior popularidade;
  2. Ordem alfabética da chave de busca interna (em caso de empate na popularidade).

---

## Instruções de Compilação

O projeto foi modularizado em classes e pode ser compilado diretamente pelo terminal utilizando o `g++` (ou qualquer compilador compatível com C++11 ou superior).

Para compilar o projeto completo, execute o seguinte comando no diretório raiz:

```bash
g++ main.cpp Game.cpp Trie.cpp GamesDatabase.cpp -o app
```
## Instruções de Execução

Após a compilação, o programa deve ser executado via linha de comando informando obrigatoriamente a quantidade máxima de sugestões (*k*) e o prefixo de busca:

```bash
./app <k> <prefixo>
```


