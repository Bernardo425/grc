#include <stdio.h>
#include <stdlib.h>

// registro que define uma mensagem
typedef struct mensagemType{
    int emissor; // id�ntificador �nico de quem envia a mensagem
    int receptor; // Id�ntificador �nico de quem se destina a mensagem
    char texto[250]; //o conte�do mda mensagem
    char data[10]; //a data do envio da mensagem DD/MM/AAAA
    int span; // define se uma mensagem � um span ou uma mensagem v�lida. 0 se a mensagem � uma mensagem v�lida e 1 se � um span
} MensagemT;


// registro que define uma lista de mensagens
typedef struct mensagemLista{
    MensagemT mensagem; // o valor n� da lista, neste caso a mensagem
    struct mensagemLista *prox; // um ponteiro que aponta para o pr�ximo n�
} MensagemListaT;

MensagemListaT * inserirMensagem(MensagemListaT * mensagens, MensagemT mensagem);

void deletarLista(MensagemListaT * mensagens);
