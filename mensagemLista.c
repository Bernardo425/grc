#include <stdio.h>
#include <stdlib.h>
#include "mensagemLista.h"

//Inserir elementos em uma lista de mensagens
//Parametros:
//    1- O ponteiro da lista do tipo MensagemLista
//    2- Variavel do tipo Mensagem
//fun��o que insere um n� no inicio da lista, retorna o n� inserido, em caso de falha, retorna NULL
MensagemListaT * inserirMensagem(MensagemListaT * mensagens, MensagemT mensagem){

    MensagemListaT * no = NULL;
    no = (MensagemListaT*) malloc(sizeof(MensagemListaT)); // aloca memoria para um MensagemLista
    if(no == NULL) return no; //se o no for nulo, retorna NULL


    no->mensagem = mensagem; // no membro mensagem do n�, � atribuido o valor da mensagem
    no->prox = (!mensagens)? NULL:mensagens; //caso seja o primeiro n� da lista, ao valor do prox � atribuido NULL, caso n�o, � atribuido o valor no primeiro n� da lista

    return no;
}

//Deletar Lista de mensagens
//Parametros:
//    1- O ponteiro da lista do tipo MensagemLista
//fun��o recursiva que apaga todos os n�s de uma lista de mensagens
void deletarLista(MensagemListaT * mensagens){
    if(mensagens){
        MensagemListaT * aux = mensagens->prox;
        free(mensagens);
        deletarLista(aux);
    }

}
