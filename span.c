#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spanTrie.h"

#define TAMANHO_MAX_PALAVRA 50


int registraPalavra(SpanTrieT * raiz, char *str){
    FILE * file;
    file = fopen("palavras.tx", "a+");
    if(file == NULL ) return 0;
    fprintf(file, "%s" str);

    inserirNo(raiz, str);
    fclose(file);
    return 0;
}

SpanTrieT * carregarPalavras(){

    char palavra[TAMANHO_MAX_PALAVRA];
    FILE * file;
    SpanTrieT * arvore = NULL;

    file = fopen("palavras.txt", "r");
    if(file == NULL) return NULL;
    arvore = criarNo();

    while(1){
        fscanf(file, "%s", palavra);
        if(feof(file)) break;
        if(strlen(palavra) > 0) inserirNo(arvore, palavra);

    }

    return arvore;
}



