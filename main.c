#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "span.c"

int main(int argc, char *argv[]) {


    SpanTrieT * arvore = criarNoTrie();
    char str[TAMANHO_MAX_PALAVRA];
    arvore = carregarPalavras();
    registraPalavra(arvore, "katra");
    registraPalavra(arvore, "mandibula");
    registraPalavra(arvore, "tita");

    /*
    inserirNo(head, "hello");
    inserirNo(head, "hilario");
    inserirNo(head, "aaza");
    inserirNo(head, "bernardo");
    inserirNo(head, "bernardo");
    inserirNo(head, "zezito");
    inserirNo(head, "aa");


    exibirPalavras(head, str, 0);
    printf(" ---------\n ");
    exibirPalavras(head, str, 0);

    printf(" ---------\n ");
    system("pause");
    apagarArvore(head);
    printf("no: %p\n", head);
    inserirNo(head, "aa");
    exibirPalavras(head, str, 0);
    deletarNo(&head, "aa");

    printf("%d\n ", procurarPalavra(head, "aa"));
    printf("%d\n ", procurarPalavra(head, "aza"));
    printf("%d\n ", procurarPalavra(head, "hello"));
    deletarNo(&head, "aza");
    printf(" ---------\n ");
    printf("%d\n ", procurarPalavra(head, "aa"));
    printf("%d\n ", procurarPalavra(head, "aza"));


    */

    exibirPalavrasTrie(arvore, str, 0);
    printf("-----------------");
    printf("%d\n ",procurarPalavraTrie(arvore, "bernard"));
    



    apagarArvore(arvore);

    return 0;
}
