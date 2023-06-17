#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mensagem.h"


//Registrar mensagem
//Parametros:
//    1- O ponteiro da lista do tipo MensagemLista
//    2- um inteiro, que representa um emissor
//    3- um inteiro, que representa o receptor
//    4- uma string, do texto da mensagem
//    5- uma string, da data do envio da mensagem
//    6- um inteiro, indicando se a mensagem � span ou n�o
// fun��o insere os dados de uma mensagem em uma lista e registra em um ficheiro.
// Retorna um ponteiro do �ltimo n� inserido na lista, o primeiro n�
// Retorna NULL quando n�o foi possivel ler/escrever em um ficheiro ou ocorrer falha na inser��o na lista

MensagemListaT * registrarMensagem(MensagemListaT * mensagens, int emissor, int receptor, char *texto, char *data, int span){

    FILE * file;
    MensagemT *mensagem = (MensagemT*) malloc(sizeof(MensagemT));

    strcpy(mensagem->texto, texto);
    strcpy(mensagem->data, data);
    mensagem->emissor = emissor;
    mensagem->receptor = receptor;
    mensagem->span = span;

    file = fopen("mensagens.dat", "a+b");
    if(!file) return NULL;

    fwrite(mensagem, sizeof(MensagemT), 1, file); // escreve a mensagem em um ficheiro
    fclose(file);

    return inserirMensagem(mensagens, *mensagem);
}


//Litar mensagens de um emissor ou receptor
//Parametros:
//    1- um inteiro, que representa o tipo de usuario, 1 == emissor, 2 == receptor
//    2- um inteiro, que representa a entidade do emissor ou do receptor
//    3- um inteiro, que indica se a mensagem � um span ou n�o

// esta fun��o � respons�vel retornar uma lista de mensagens, de um emissor ou de um receptor, mensagens span o v�lidas, dependendo dos par�metros da fun��o
// Retorna um ponteiro de uma lista de mensagens
// Retorna NULL quando n�o foi possivel ler/escrever em um ficheiro ou ocorrer falha na inser��o na lista

MensagemListaT * listarMensagensEmissor(int tipo, int entidade, int span){
    FILE * file;
    MensagemListaT * mensagens;
    MensagemT *mensagem = (MensagemT*) malloc(sizeof(MensagemT));

    file = fopen("mensagens.dat", "rb");

    if(file == NULL) return NULL;

    while(1){
        fread(mensagem, sizeof(MensagemT), 1, file);

        if(feof(file)) break;
        if(tipo == 1)
            if((mensagem->emissor == entidade) && (mensagem->span == span))
                mensagens = inserirMensagem(mensagens, *mensagem);

        if(tipo == 2)
            if((mensagem->receptor == entidade) && (mensagem->span == span))
                mensagens = inserirMensagem(mensagens, *mensagem);

    }

    fclose(file);
    return mensagens;
}
