#include <stdio.h>
#include <stdlib.h>
#include "mensagem.h"

int main()
{
    printf("Hello world!\n");

    MensagemListaT * msg;
    //msg = registrarMensagem(msg, 1, 2, "banana", "10/24/05/2000", 1);

    msg = listarMensagensEmissor(2, 2, 1);

    if(msg == NULL){
      printf("um erro aconteceu");
      exit(1);
    }

    while(msg != NULL){
        printf("%s\n", msg->mensagem.texto);
        msg = msg->prox;
    }


    return 0;
}
