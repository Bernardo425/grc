#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "mensagem.h"

int main() {
    MensagemListaT * mensagens = NULL;

    if(mensagens = registrarMensagem(NULL, 1, 2, "12345678909876543", "12/12/2004", 1))
        printf("mensagem registrada com sucesso\n");
    if(mensagens = registrarMensagem(NULL, 1, 2, "dsdsdsdssd", "12/12/2004", 1))
        printf("mensagem registrada com sucesso\n");
    mensagens =  listarMensagens(1, 1, 1);
    while(mensagens != NULL){
        printf("%s\n", mensagens->mensagem.texto);
        mensagens = mensagens->prox;
    }
    exit(0);
}
