#include <stdlib.h>
#include <stdio.h>
#define TEMANHO_CARACTERES 26

typedef struct spanTrieT{
    int folha;
    struct spanTrieT * caracter[TEMANHO_CARACTERES];
}SpanTrieT;

SpanTrieT * criarNo(){
    SpanTrieT * no = (SpanTrieT*) malloc(sizeof(SpanTrieT));
    no->folha = 0;

    for(int i = 0; i < TEMANHO_CARACTERES; i++){
        no->caracter[i] = NULL;
    }

    return no;
}

int inserirNo(SpanTrieT * raiz, char * str){

    SpanTrieT * curr = raiz;

    while(*str){
        if(curr->caracter[*str - 'a'] == NULL){
            curr->caracter[*str - 'a'] = criarNo();
            if(curr->caracter[*str - 'a'] == NULL)  return NULL;
        }
        curr = curr->caracter[*str - 'a'];
        str++;
    }

    curr->folha = 1;
    return 1;
}

int procurarPalavra(SpanTrieT * raiz, char *str){
    if(raiz == NULL) return 0;

    SpanTrieT * curr = raiz;

    while(*str){
        curr = curr->caracter[*str - 'a'];
        if(curr == NULL) return 0;
        str++;
    }

    return curr->folha;

}

int temFilhos(SpanTrieT * raiz){
    for(int i = 0; i < TEMANHO_CARACTERES; i++){
        if(raiz->caracter[i]) return 1;
    }
}

int deletarNo(SpanTrieT ** raiz, char * str){
    if(*raiz == NULL) return 0;

    if (*str){
        if (*raiz != NULL && (*raiz)->caracter[*str - 'a'] != NULL && deletarNo(&((*raiz)->caracter[*str - 'a']), str + 1) && (*raiz)->folha == 0){
            if (!temFilhos(*raiz)){
                free(*raiz);
                (*raiz) = NULL;
                return 1;
            } else{
                return 0;
            }
        }
    }

    if (*str == '\0' && (*raiz)->folha){
        if (!temFilhos(*raiz)){
            free(*raiz);
            (*raiz) = NULL;
            return 1;
        }else{
            (*raiz)->folha = 0;
            return 0;
        }
    }
    return 0;
}

void exibirPalavras(SpanTrieT * arvore, char *str, int nivel){
    if(arvore->folha == 1){
        str[nivel] = '\0';
        printf("%s\n", str);
    }

    for(int i = 0; i < TEMANHO_CARACTERES;i++ ){
        if(arvore->caracter[i]){
            str[nivel] = i + 'a';
            exibirPalavras(arvore->caracter[i], str, nivel + 1);
        }
    }
}

/*
int apagarArvore(SpanTrieT * arvore, int num){
    if(arvore != NULL){
        for(int i = 0;i < TEMANHO_CARACTERES; i++){
            if(arvore->caracter[i]){
                    printf("%c\n",  i + 'a');
                num = apagarArvore(arvore->caracter[i], num) + 1;
            }
        }
    }
    return num;

}
*/

void apagarArvore(SpanTrieT * arvore){
    if(arvore != NULL){
        for(int i = 0;i < TEMANHO_CARACTERES; i++){
            if(arvore->caracter[i]){
                apagarArvore(arvore->caracter[i]);
                arvore->caracter[i] = NULL;
            }
        }
    }
}
