#include <stdio.h>
#include <stdlib.h>

// registro que define uma mensagem
typedef struct mensagemType{
    int emissor; // idêntificador único de quem envia a mensagem
    int receptor; // Idêntificador único de quem se destina a mensagem
    char texto[250]; //o conteúdo mda mensagem
    char data[10]; //a data do envio da mensagem DD/MM/AAAA
    int span; // define se uma mensagem é um span ou uma mensagem válida. 0 se a mensagem é uma mensagem válida e 1 se é um span
} MensagemT;


// registro que define uma lista de mensagens
typedef struct mensagemLista{
    MensagemT mensagem; // o valor nó da lista, neste caso a mensagem
    struct mensagemLista *prox; // um ponteiro que aponta para o próximo nó
} MensagemListaT;

MensagemListaT * inserirMensagem(MensagemListaT * mensagens, MensagemT mensagem);

void deletarLista(MensagemListaT * mensagens);
