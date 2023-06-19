// definição de constantes
#define TEMANHO_CARACTERES 256 // intervalo de caracteres possíveis a serem armazenados na árvore, baseado na tabela ASCII
#define TAMANHO_MAX_PALAVRA 50 // tamanho máximo de uma palavra
#define CARACTER_INICIO 97 // primeiro caracter que forma uma frase ou palavra da tabela ASCII

#define TRUE 1 // esta constante simboliza um valor verdadeiro
#define FALSE 0 // esta constante simboliza um valor falso

typedef int bool; // renomeia o tipo int para bool, de booleano

// registro de um nó de uma arvore TRIE
typedef struct spanTrieT{
    int folha; // indica se o nó é uma folha (1) ou não (0)
    struct spanTrieT * caracter[TEMANHO_CARACTERES]; // um vetor do tipo struct spanTrieT (representação dos caracteres da tabela ASCII)
}SpanTrieT;


///////////////// Funções de manipulação da ESTRUTURA DE DADOS TRIE/////////////
// função responsáver por criar um nó de uma arvore TRIE
// valores de retorno:
// 1- Caso de sucesso: um ponteiro do tipo SpanTrieT;
// 2 - Caso de erro: NULL
SpanTrieT * criarNoTrie();

// função responsável por inserir um nó (uma palavra) a uma árvore TRIE
// parametros:
// 1- um ponteiro do tipo SpanTrieT
// 2- uma string (a palavra a ser adicionada)
// valores de retorno:
// 1- Caso de sucesso: TRUE;
// 2 - Caso de erro: FALSE;
bool inserirPalavraTrie(SpanTrieT * arvore, char * str);

// função responsável por procurar uma cadeia (uma palavra) em uma árvore TRIE
// parametros:
// 1- um ponteiro do tipo SpanTrieT
// 2- uma string (a palavra a ser procurada)
// valores de retorno:
// 1- Caso de extite: TRUE;
// 2 - Caso não exite : FALSE;
bool procurarNoTrie(SpanTrieT * arvore, char *str);

// função responsável verificar se um no possui filhos
// parametros:
// 1- um ponteiro do tipo SpanTrieT
// valores de retorno:
// 1- Caso possua: TRUE;
// 2 - Caso não possua: FALSE;
bool noTrieFilhos(SpanTrieT * arvore);

// função responsável por deletar uma cadeia (uma palavra) em uma árvore TRIE
// parametros:
// 1- um ponteiro de um ponteiro do tipo SpanTrieT
// 2- uma string (a palavra a ser deletada)
// valores de retorno:
// 1- Caso foi deletada: TRUE;
// 2 - Caso não foi deletada : FALSE;
bool deletarNoTrie(SpanTrieT ** arvore, char * str);

// função recursiva responsável por listar todas as palavras armazenadas em uma árvore TRIE
// parametros:
// 1- um  ponteiro do tipo SpanTrieT
// 2- uma string em acumulo (o valor inicial deve ser uma string vazia)
// 3- um inteiro (o valor inicial deve ser0)
// valores de retorno:
void exibirPalavrasTrie(SpanTrieT * arvore, char *str, int nivel);


// função recursiva para excluir todos os nós de uma árvore trie
// parametros:
// 1- um  ponteiro do tipo SpanTrieT
void apagarArvore(SpanTrieT * arvore);

/////////////////////////////////////// funções de manipaçãp de SPAN //////////////////////

// função responsável por registrar um span
// parametros:
// 1- um ponteiro do tipo SpanTrieT
// 2- uma string (a palavra a ser registrada)
// valores de retorno:
// 1- Caso de sucesso: TRUE;
// 2- caso de erro : FALSE;
int registraPalavra(SpanTrieT * raiz, char *str);

// função responsável carregar na memoria as palavras registradas continhas em um ficheiro
// parametros:
// valores de retorno:
// 1- Caso de sucesso: SpanTrieT;
// 2- caso de erro : NULL;
SpanTrieT * carregarPalavras();


// função responsável por excluir uma palavra do ficheiro de palavras de span e remover da arvore TRIE
// parametros:
// valores de retorno:
// 1- Caso de sucesso: SpanTrieT;
// 2- caso de erro : NULL;
void apagarPalavra();





