#include <stdio.h>
#include <stdlib.h>
#include "mensagemLista.h"

//Inserir elementos em uma lista de mensagens
//Parametros:
//    1- O ponteiro da lista do tipo MensagemLista
//    2- Variavel do tipo Mensagem
//função que insere um nó no inicio da lista, retorna o nó inserido, em caso de falha, retorna NULL
MensagemListaT * inserirMensagem(MensagemListaT * mensagens, MensagemT mensagem){

    MensagemListaT * no = NULL;
    no = (MensagemListaT*) malloc(sizeof(MensagemListaT)); // aloca memoria para um MensagemLista
    if(no == NULL) return no; //se o no for nulo, retorna NULL


    no->mensagem = mensagem; // no membro mensagem do nó, é atribuido o valor da mensagem
    no->prox = (!mensagens)? NULL:mensagens; //caso seja o primeiro nó da lista, ao valor do prox é atribuido NULL, caso não, é atribuido o valor no primeiro nó da lista

    return no;
}

//Deletar Lista de mensagens
//Parametros:
//    1- O ponteiro da lista do tipo MensagemLista
//função recursiva que apaga todos os nós de uma lista de mensagens
void deletarLista(MensagemListaT * mensagens){
    if(mensagens){
        MensagemListaT * aux = mensagens->prox;
        free(mensagens);
        deletarLista(aux);
    }

}
