#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spanTrie.h"

int main()
{
    printf("Hello world!\n");

    SpanTrieT * head = criarNo();
    printf("no: %p\n", head);
    char str[100];


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
    /*
    deletarNo(&head, "aa");

    printf("%d\n ", procurarPalavra(head, "aa"));
    printf("%d\n ", procurarPalavra(head, "aza"));
    printf("%d\n ", procurarPalavra(head, "hello"));
    deletarNo(&head, "aza");
    printf(" ---------\n ");
    printf("%d\n ", procurarPalavra(head, "aa"));
    printf("%d\n ", procurarPalavra(head, "aza"));
    printf("%d\n ", procurarPalavra(head, "hello"));
    */
    return 0;
}
