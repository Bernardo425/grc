// importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "membroLista.h"

//Inserir elementos em uma lista de membros
//Parametros:
//    1- O ponteiro da lista do tipo MembroLista
//    2- Variavel do tipo Mensagem
//funcao que insere um nó no inicio da lista, retorna o nó inserido, em caso de falha, retorna NULL
MembroListaT * inserirMembroLista(MembroListaT * membros,MembroT membro){

    MembroListaT * no = NULL;
    no = (MembroListaT*) malloc(sizeof(MembroListaT)); // aloca memoria para um MembroLista
    if(no == NULL) return no; //se o no for nulo, retorna NULL

    //o id de cada membro é a sequeência do membro anterior, quando não existir nenhum membro, a contagem começa apartir de 1
    membro.id = (membros == NULL)? 1: membros->membro.id + 1;

    no->membro = membro; // no membro membro do n�, � atribuido o valor da membro
    no->prox = (!membros)? NULL:membros; //caso seja o primeiro n� da lista, ao valor do prox � atribuido NULL, caso n�o, � atribuido o valor no primeiro n� da lista

    return no;
}

//remover elementos em uma lista de membros
//Parametros:
//    1- o endereço da variavel externa que armazena a lista
//    2- Variavel do tipo int que representa o id do membro
//retorna TRUE em caso de sucesso e FALSe em caso de erro ou não ser encontrado nenhum membro
bool removerMembroLista(MembroListaT ** membros, int id){
    if(membros != NULL){
        if((*membros)->membro.id == id){
            *membros = (*membros)->prox;
            return TRUE;
        }
        MembroListaT * aux = *membros;
        MembroListaT * prox = NULL;
        while (aux != NULL){
            prox = aux->prox;
            if(prox != NULL){
                if(prox->membro.id == id){
                    aux->prox = prox->prox;
                    free(prox);
                    return TRUE;
                }
            }
            aux = aux->prox;
        }
    }
    return FALSE;
}

//função para procurar um membro na lista, retorna o membro caso o mesmo é encontrado, NULL caso negativo
MembroListaT * procurarMEmbroLista(MembroListaT * membros, int id){
    if(membros != NULL){
        MembroListaT * aux = membros;
        while (aux != NULL){
            if(aux->membro.id == id) return aux;
            aux = aux->prox;
        }
    }
    return NULL;
}

//função recusiva para apresentar todos os membros registrados
void apresentaMembrosLista(MembroListaT * membros){
    if(membros != NULL){
        printf("Id - %d\n", membros->membro.id);
        printf("Nome - %s\n", membros->membro.nome);
        printf("Email - %d\n", membros->membro.email);
        printf("---------------------------------\n");
        apresentaMembrosLista(membros->prox);
    }
}

//função recusiva para deletar a lista de membros
void deletarListaMembros(MembroListaT * membros){
    if(membros){
        MembroListaT * aux = membros->prox;
        free(membros);
        deletarListaMembros(aux);
    }
}
