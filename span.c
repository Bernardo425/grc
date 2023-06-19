//importação das bibliotecas nativas da linguagem
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "span.h"

///////////////// Funções de manipulação da ESTRUTURA DE DADOS TRIE/////////////
// função responsáver por criar um nó de uma arvore TRIE
// valores de retorno:
// 1- Caso de sucesso: um ponteiro do tipo SpanTrieT;
// 2 - Caso de erro: NULL
SpanTrieT * criarNoTrie(){

    // aloca memória para um SpanTrieT
    SpanTrieT * no = (SpanTrieT*) malloc(sizeof(SpanTrieT));
    //caso não ser alocado, a função retorna NULL;
    if(no == NULL) return NULL;
    no->folha = 0;

    // para cada posição do vetor de SpanTrieT atribui um NULL
    for(int i = 0; i < TEMANHO_CARACTERES; i++){
        no->caracter[i] = NULL;
    }

    return no;
}

// função responsável por inserir um nó (uma palavra) a uma árvore TRIE
// parametros:
// 1- um ponteiro do tipo SpanTrieT
// 2- uma string (a palavra a ser adicionada)
// valores de retorno:
// 1- Caso de sucesso: TRUE;
// 2 - Caso de erro: FALSE;
bool inserirPalavraTrie(SpanTrieT * arvore, char * str){
    SpanTrieT * curr = arvore;

    // o loop é executado até ser encontrado o fim da string
    while(*str){
        if(curr->caracter[*str - CARACTER_INICIO] == NULL){
            curr->caracter[*str - CARACTER_INICIO] = criarNoTrie();
            if(curr->caracter[*str - CARACTER_INICIO] == NULL)  return FALSE;
        }
        curr = curr->caracter[*str - CARACTER_INICIO];
        str++;
    }
    curr->folha = 1;
    return TRUE;
}

// função responsável por procurar uma cadeia (uma palavra) em uma árvore TRIE
// parametros:
// 1- um ponteiro do tipo SpanTrieT
// 2- uma string (a palavra a ser procurada)
// valores de retorno:
// 1- Caso de extite: TRUE;
// 2 - Caso não exite : FALSE;
bool procurarPalavraTrie(SpanTrieT * arvore, char *str){
    //verifica se é uma árvore vazia
    if(arvore == NULL) return FALSE;

    SpanTrieT * curr = arvore;

    // para cada caracter que constitui a string s ser pesquisada na arvore, é comparado com cada nivel em cada sub nó
    while(*str){
        curr = curr->caracter[*str - CARACTER_INICIO];
        if(curr == NULL) return FALSE;
        str++;
    }
    return curr->folha;
}

// função responsável verificar se um no possui filhos
// parametros:
// 1- um ponteiro do tipo SpanTrieT
// valores de retorno:
// 1- Caso possua: TRUE;
// 2 - Caso não possua: FALSE;
bool noTrieFilhos(SpanTrieT * arvore){
    //percorre todo o vetor de caracteres do nó, na primeira ocorrência retorna TRUE
    for(int i = 0; i < TEMANHO_CARACTERES; i++){
        if(arvore->caracter[i]) return TRUE;
    }
    return FALSE;
}

// função responsável por deletar uma cadeia (uma palavra) em uma árvore TRIE
// parametros:
// 1- um ponteiro de um ponteiro do tipo SpanTrieT
// 2- uma string (a palavra a ser deletada)
// valores de retorno:
// 1- Caso foi deletada: TRUE;
// 2 - Caso não foi deletada : FALSE;
bool deletarNoTrie(SpanTrieT ** arvore, char * str){
    if(*arvore == NULL) return FALSE;

    if (*str){
        if (*arvore != NULL && (*arvore)->caracter[*str - CARACTER_INICIO] != NULL && deletarNoTrie(&((*arvore)->caracter[*str - CARACTER_INICIO]), str + 1) && (*arvore)->folha == 0){
            if (!noTrieFilhos(*arvore)){
                free(*arvore);
                (*arvore) = NULL;
                return TRUE;
            } else{
                return FALSE;
            }
        }
    }

    if (*str == '\0' && (*arvore)->folha){
        if (!noTrieFilhos(*arvore)){
            free(*arvore);
            (*arvore) = NULL;
            return 1;
        }else{
            (*arvore)->folha = 0;
            return FALSE;
        }
    }
    return FALSE;
}

// função recursiva responsável por listar todas as palavras armazenadas em uma árvore TRIE
// parametros:
// 1- um  ponteiro do tipo SpanTrieT
// 2- uma string em acumulo (o valor inicial deve ser uma string vazia)
// 3- um inteiro (o valor inicial deve ser0)
// valores de retorno:
void exibirPalavrasTrie(SpanTrieT * arvore, char *str, int nivel){
    if(arvore->folha == 1){
        str[nivel] = '\0';
        printf("%s\n", str);
    }

    for(int i = 0; i < TEMANHO_CARACTERES;i++ ){
        if(arvore->caracter[i]){
            str[nivel] = i + CARACTER_INICIO;
            exibirPalavrasTrie(arvore->caracter[i], str, nivel + 1);
        }
    }
}

/*
int apagarArvore(SpanTrieT * arvore, int num){
    if(arvore != NULL){
        for(int i = 0;i < TEMANHO_CARACTERES; i++){
            if(arvore->caracter[i]){
                    printf("%c\n",  i + CARACTER_INICIO);
                num = apagarArvore(arvore->caracter[i], num) + 1;
            }
        }
    }
    return num;

}
*/

// função recursiva para excluir todos os nós de uma árvore trie
// parametros:
// 1- um  ponteiro do tipo SpanTrieT
void apagarArvore(SpanTrieT * arvore){
    if(arvore != NULL){
        for(int i = 0;i < TEMANHO_CARACTERES; i++){
            if(arvore->caracter[i]){
                apagarArvore(arvore->caracter[i]);
                arvore->caracter[i] = NULL;
            }
        }
        free(arvore);
    }
}

/////////////////////////////////////// funções de manipaçãp de SPAN //////////////////////

// função para converter letras de uma palavra de maiusculas para minuscaulas
// parametros:
// 1 - uma string
char * converterMaiuscula(char *str){
    char * str2 = (char*) malloc(sizeof(char) * (strlen(str) + 1) );
    int i = 0;
    for(; i < strlen(str); i++)
    str2[i] = (str[i] >=65 && str[i] <= 90)? str[i] + 32 : str[i];
    str2[i] = '\0';
    return str2;
}

// função responsável por registrar um span
// parametros:
// 1- um ponteiro do tipo SpanTrieT
// 2- uma string (a palavra a ser registrada)
// valores de retorno:
// 1- Caso de sucesso: TRUE;
// 2- caso de erro : FALSE;
bool registraPalavra(SpanTrieT * raiz, char *str){
    FILE * file;

    // abre o ficheiro
    file = fopen("./dados/palavras.txt", "a+");
    if(file == NULL ) return FALSE;

    str = converterMaiuscula(str);
    // escreve a palavra no ficheiro
    fprintf(file, "%s\n" ,converterMaiuscula(str));
    // insere a paalvra na arvore TRIE
    if(!inserirPalavraTrie(raiz, str)) {
        return FALSE;
    }

    free(str);
    //fecha o ficheiro
    fclose(file);
    return TRUE;
}

// função responsável carregar na memoria as palavras registradas continhas em um ficheiro
// parametros:
// valores de retorno:
// 1- Caso de sucesso: SpanTrieT;
// 2- caso de erro : NULL;
SpanTrieT * carregarPalavras(){

    char palavra[TAMANHO_MAX_PALAVRA];
    FILE * file;
    SpanTrieT * arvore = NULL;

    file = fopen("./dados/palavras.txt", "r");
    if(file == NULL) return NULL;
    arvore = criarNoTrie();

    while(1){
        fscanf(file, "%s", palavra);
        if(feof(file)) break;
        if(strlen(palavra) > 0) inserirPalavraTrie(arvore, palavra);

    }
    return arvore;
}


// função responsável por excluir uma palavra do ficheiro de palavras de span e remover da arvore TRIE
// parametros:
// valores de retorno:
// 1- Caso de sucesso: SpanTrieT;
// 2- caso de erro : NULL;
void apagarPalavra(){
    return;
}





